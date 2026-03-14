// Small helper macros for FX2 SFR operations
#ifndef FX2_HELPERS_H
#define FX2_HELPERS_H

#include <fx2types.h>

/* FX2 masked write helper: operate directly on the SFR symbol (no pointer passing).
   This avoids mismatched pointer qualifiers (near SFR vs __xdata) when using SDCC. */
#define FX2_MASKED_WRITE(reg, mask, value) do { \
    BYTE _mcur = (reg); \
    _mcur = (_mcur & (BYTE)(~(mask))) | ((value) & (mask)); \
    (reg) = _mcur; \
} while(0)

#endif
