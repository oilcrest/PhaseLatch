// Minimal SYNCDELAY macro for SDCC FX2 firmware

#ifndef SYNCDELAY_H
#define SYNCDELAY_H

#define SYNCDELAY { __asm nop __endasm; __asm nop __endasm;  __asm nop __endasm; __asm nop __endasm;}

#endif // SYNCDELAY_H