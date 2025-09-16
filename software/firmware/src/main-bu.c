// FX2 firmware: External IFCLK + Slave FIFO + AUTOIN (EP6 IN, 512 B)
// Build: SDCC + fx2lib headers

#include <fx2regs.h>
#include <fx2macros.h>
#include <syncdelay.h>
#include "config.h"

// Uncomment to enable internal firmware pattern generator test (bypasses Slave FIFO producer)
//#define PATTERN_TEST 1

#define SD() SYNCDELAY; SYNCDELAY;

void main(void)
{
    EA = 0;              // disable ints during setup

    // --- init_cpu() ---
    CPUCS = 0x12; SD(); // 48 MHz
    // CLKOUT is enabled by default; if not, set bit 3 (CLKOE)
    // CPUCS |= 0x08; // Uncomment if needed

    // --- REVCTL for improved packet handling ---
    REVCTL = 0x03; SD();

    // --- fifo_reset() ---
    FIFORESET = 0x80; SD();   // NAK-ALL
    FIFORESET = 0x02; SD();   // reset EP2 OUT FIFO
    FIFORESET = 0x04; SD();   // reset EP4 OUT FIFO
    FIFORESET = 0x06; SD();   // reset EP6 IN FIFO
    FIFORESET = 0x08; SD();   // reset EP8 IN FIFO
    FIFORESET = 0x00; SD();   // release NAK-ALL

#ifndef PATTERN_TEST
    // Normal Slave FIFO AUTOIN configuration
    // EP8FIFOCFG: AUTOIN + WORDWIDE; common value 0x0D
    EP8FIFOCFG = 0x0D; SD();
#else
    // Pattern test: manual 16-bit IN endpoint (no AUTOIN)
    EP8FIFOCFG = 0x01; SD(); // WORDWIDE only
#endif

    // EP8 IN, bulk, 512B, 4x buffers => 0xE0
    EP8CFG = 0xE0; SD();
    PINFLAGSAB = 0x00; SD();
    PINFLAGSCD = 0x00; SD();
    PORTACFG = 0x00; SD(); // All port A pins normal
    FIFOPINPOLAR = 0x00; SD(); // All FIFO pins normal
    // AUTOIN length = 512 bytes (ignored in manual mode)
    EP8AUTOINLENH = (AUTOIN_LEN >> 8) & 0xFF; SD();
    EP8AUTOINLENL = (AUTOIN_LEN & 0xFF);      SD();

    EP2BCL = 0x80; SD();
    EP2BCL = 0x80; SD();
    EP4BCL = 0x80; SD();
    EP4BCL = 0x80; SD();

    SD();
#ifndef PATTERN_TEST
    IFCONFIG = 0xE3; SD(); // Internal IFCLK, Slave FIFO, 16-bit, synchronous, IFCLK out
#else
    // For pattern test we can still leave Slave FIFO mode enabled; CPU writes directly.
    // If you want to completely detach the external interface, you could switch to GPIF (00) here.
    IFCONFIG = 0xE3; SD();
#endif
   
    EA = 1;              // enable if you later add ISRs
    OEA |= 0x03; // PA0 and PA1 output

#ifndef PATTERN_TEST
    // Monitor EP8 FIFO status and blink LED if buffer is full
    while (1) {
        if (EP8CS & 0x02) {
            PA0 = 1; // FIFO full
        } else {
            PA0 = 0; // not full
        }
        PA1 = !PA1;
        for (volatile unsigned long i = 0; i < 50000; ++i);
    }
#else
    // Firmware pattern generator: continuously queue 512-byte packets on EP8
    // Optimized: remove long delay, keep quad buffers filled.
    static unsigned char pattern = 0;
    while (1) {
        // While there is at least one free buffer (FULL bit clear) fill and commit.
        while (!(EP8CS & 0x02)) {
            unsigned char __xdata *p = (unsigned char __xdata *) &EP8FIFOBUF;
            // Fill 512 bytes with incrementing pattern
            for (unsigned int i = 0; i < 512; ++i) {
                p[i] = pattern++;
            }
            // Commit 512 bytes
            EP8BCH = 0x02; SD();
            EP8BCL = 0x00; SD();
            // Optional: small LED pulse for activity (comment out for max speed)
            PA0 = !PA0;
        }
        // Brief housekeeping; toggle PA1 slower (software divider)
        static unsigned char div = 0; if(++div==0) PA1 = !PA1;
    }
#endif
}
