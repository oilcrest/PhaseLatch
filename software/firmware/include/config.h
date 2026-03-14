#pragma once

// AUTOIN packet commit length (512 bytes for HS bulk max packet)
#define AUTOIN_LEN 512

// IFCONFIG preset: internal IFCLK, Slave FIFO, 16-bit, synchronous
// The actual value is set in firmware based on FX2 TRM; change if you need a different polarity/mode.

  // IFCONFIG bits (CY7C68013A datasheet):
    // Bit 7: IFCLKSRC   (1 = internal IFCLK, 0 = external IFCLK)
    // Bit 6: 3048MHZ    (1 = 48 MHz, 0 = 30 MHz)
    // Bit 5: IFCLKOE    (1 = IFCLK output enabled, 0 = tristate)
    // Bit 4: IFCLKPOL   (IFCLK polarity)
    // Bit 3: ASYNC      (1 = async, 0 = sync)
    // Bit 2: GSTATE     (GPIF only)
    // Bit 1: IFCFG1     (interface mode)
    // Bit 0: IFCFG0     (interface mode)
// Target: external IFCLK (IFCLKSRC=0), IFCLK output disabled (IFCLKOE=0),
// synchronous (ASYNC=0), Slave FIFO (IFCFG=11), 16-bit wordwide
// Bit layout: 0b0100_0011 => 0x43
#define IFCONFIG_VALUE 0x03


// --------------------------------------