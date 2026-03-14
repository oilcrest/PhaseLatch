// FX2 firmware: Internal IFCLK + Slave FIFO + AUTOIN (EP6 IN, 512 B)
// Build: SDCC + fx2lib headers

#include <fx2regs.h>
#include <fx2macros.h>
#include <syncdelay.h>
#include "config.h"
#include "fx2_helpers.h"
#include <setupdat.h>

// Uncomment to enable internal firmware pattern generator test (bypasses external producer)
//#define PATTERN_TEST 1

#define SD() SYNCDELAY; SYNCDELAY;

// ---------------- Vendor command support -----------------
// We preserve your original CPUCS bit comments EXACTLY as provided below.

// Simple vendor protocol (control endpoint):
//  OUT (Host->Device) commands expect 2 bytes: MASK, VALUE. Bits where MASK=1 are replaced.
//  IN  (Device->Host) commands return 1 byte.
//  Codes (avoid 0xA0–0xAF reserved by EZ-USB):
//    0xB0: SET CPUCS
//    0xB1: GET CPUCS
//    0xB2: SET IFCONFIG
//    0xB3: GET IFCONFIG
//    0xB4: SET PORTA (IOA)
//    0xB5: GET PORTA (IOA)
//    0xB6: SET OEA
//    0xB7: GET OEA
//    0xB8: GET EP6CS
//    0xB9: GET PINFLAGSAB
//    0xBA: GET PINFLAGSCD
//    0xBB: GET IFCONFIG snapshot (captured right after firmware init)

// Use the shared helper macro for masked writes
// FX2_MASKED_WRITE(reg, mask, value)

// Handle vendor commands (called by fx2lib's handle_setupdata flow)
// fx2lib will call this for vendor commands (weak symbol override)
BOOL handle_vendorcommand(BYTE cmd) {
    switch(cmd) {
        case 0xB0: // SET CPUCS
        case 0xB2: // SET IFCONFIG
        case 0xB4: // SET PORTA
        case 0xB6: // SET OEA
        {
            // Expect 2 OUT bytes
            if(EP0BCL != 2) return FALSE; // not enough data yet
            BYTE mask = EP0BUF[0];
            BYTE val  = EP0BUF[1];
                if(cmd == 0xB0) FX2_MASKED_WRITE(CPUCS, mask, val);
                else if(cmd == 0xB2) FX2_MASKED_WRITE(IFCONFIG, mask, val);
                else if(cmd == 0xB4) FX2_MASKED_WRITE(IOA, mask, val);
                else FX2_MASKED_WRITE(OEA, mask, val);
            return TRUE;
        }
            case 0xB1: // GET CPUCS
            EP0BUF[0] = CPUCS; EP0BCL = 1; return TRUE;
            case 0xB3: // GET IFCONFIG
            EP0BUF[0] = IFCONFIG; EP0BCL = 1; return TRUE;
            case 0xB5: // GET PORTA
            EP0BUF[0] = IOA; EP0BCL = 1; return TRUE;
            case 0xB7: // GET OEA
            EP0BUF[0] = OEA; EP0BCL = 1; return TRUE;
            case 0xB8: // GET EP6CS (FIFO status)
                EP0BUF[0] = EP6CS; SD(); EP0BCL = 1; SD(); return TRUE;
            case 0xB9: // GET PINFLAGSAB
                EP0BUF[0] = PINFLAGSAB; SD(); EP0BCL = 1; SD(); return TRUE;
            case 0xBA: // GET PINFLAGSCD
                EP0BUF[0] = PINFLAGSCD; SD(); EP0BCL = 1; SD(); return TRUE;
            case 0xBB: // GET IFCONFIG snapshot
                extern BYTE boot_ifconfig_snapshot;
                EP0BUF[0] = boot_ifconfig_snapshot; SD(); EP0BCL = 1; SD(); return TRUE;
    }
    return FALSE; // not handled
}

// Optional simple pattern generator for AUTOIN endpoint 6 (16-bit wide)
#ifdef PATTERN_TEST
static void push_pattern_ep6(void) {
    // Fill exactly AUTOIN_LEN bytes. We assume AUTOIN length = 512 (set below)
    // Write 16-bit words incrementing.
    static WORD w = 0;
    BYTE __xdata *p = (BYTE __xdata*) &EP6FIFOBUF; // fx2lib symbol
    WORD count = 0;
    while(count < 512) {
        p[count++] = (BYTE)(w & 0xFF);
        p[count++] = (BYTE)((w >> 8) & 0xFF);
        ++w;
    }
    // Arm packet if manual commit needed (AUTOIN handles length threshold auto-commit)
}
#endif

// Snapshot of IFCONFIG captured during init
BYTE boot_ifconfig_snapshot = 0x00;

void main(void) {
    //Bits
    //7-6: Reserved
    //5: PortCSTB
    //4-3: 00 = 12MHz, 01 = 24MHz, 10 = 48MHz, 11 = Reserved
    //2: CLKINV 
    //1: CLKOE
    //0 - reserved
    CPUCS = 0x0A;  SD(); // 24 MHz, CLKOUT enabled

    IFCONFIG = IFCONFIG_VALUE;  SYNCDELAY;
    // Capture IFCONFIG immediately after we set it
    {
        extern BYTE boot_ifconfig_snapshot;
        boot_ifconfig_snapshot = IFCONFIG;
    }
    REVCTL = 0x03;    SYNCDELAY;  // Enhanced Packet Handling (TRM recommendation for slave FIFO)

    // Configure EP6 (IN) for bulk input, quad-buffered (4*512 bytes).
    EP6CFG = 0xE0;  SYNCDELAY; // 1110 0000: VALID + IN + BULK + Quad

    // FIFO Reset sequence (TRM)
    FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests
    FIFORESET = 0x82;  SYNCDELAY;  // Reset EP2
    FIFORESET = 0x84;  SYNCDELAY;  // Reset EP4
    FIFORESET = 0x86;  SYNCDELAY;  // Reset EP6
    FIFORESET = 0x88;  SYNCDELAY;  // Reset EP8
    FIFORESET = 0x00;  SYNCDELAY;  // Release NAKs

    // Configure EP6 for AUTOIN, 16bit wide bus. Bits: 0000 1110 ( AUTOIN=1 / ZEROLENIN=1, Wordwide=1 )
    EP6FIFOCFG = 0x0C;  SYNCDELAY;

    // PORTACFG: FLAGD SLCS(*) 0 0 0 0 INT1 INT0
    PORTACFG = 0x00;  SYNCDELAY;

    // All default polarities: SLWR active low, etc.
    FIFOPINPOLAR=0x00;  SYNCDELAY;

    // AUTOIN packet commit length (512 bytes)
    EP6AUTOINLENH = 0x02; SYNCDELAY;  // MSB
    EP6AUTOINLENL = 0x00; SYNCDELAY;  // LSB

    PINFLAGSAB = 0x00; SYNCDELAY; // No special flags on Port A/B pins  
    PINFLAGSCD = 0x00; SYNCDELAY; // No special flags on Port C/D pins

    // LED on PA0 for heartbeat
    OEA |= 0x01; // PA0 output

    // Main superloop: blink + optional pattern fill (control transfers handled by fx2lib core)
    unsigned long blink = 0UL;
    for(;;) {
        // Poll for setup data so vendor commands are handled
        handle_setupdata();
        if(++blink == 40000UL) { PA0 = 1; }
        else if(blink == 80000UL) { PA0 = 0; blink = 0UL; }
#ifdef PATTERN_TEST
        if(!(EP6CS & 0x02)) { // 0x02 == FULL bit
            push_pattern_ep6();
        }
#endif
    }
}
