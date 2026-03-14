// Minimal callbacks to satisfy fx2lib setupdat expectations and handle strings

#include <fx2regs.h>
#include <fx2macros.h>
#include <setupdat.h>

// String descriptors from descriptors.c
extern __code const BYTE str0_dscr[];
extern __code const BYTE str1_dscr[];
extern __code const BYTE str2_dscr[];

// Provide dev_strings symbol expected by fx2lib setupdat
__code const BYTE* const dev_strings[] = {
    str0_dscr,
    str1_dscr,
    str2_dscr
};

// Handle only string descriptors here; let library handle others
BOOL handle_get_descriptor(void) {
    if (SETUPDAT[3] == DSCR_STRING_TYPE) {
        BYTE idx = SETUPDAT[2];
        __code const BYTE* p = 0;
        switch (idx) {
            case 0: p = str0_dscr; break;
            case 1: p = str1_dscr; break;
            case 2: p = str2_dscr; break;
            default: return FALSE;
        }
        SUDPTRH = MSB((WORD)p);
        SUDPTRL = LSB((WORD)p);
        return TRUE;
    }
    return FALSE;
}

BYTE handle_get_configuration(void) {
    return 1; // single configuration
}

BOOL handle_set_configuration(BYTE cfg) {
    // Accept any valid config value; single config so ignore cfg
    return TRUE;
}

BOOL handle_get_interface(BYTE ifc, BYTE* alt_ifc) {
    // Single interface, alt setting 0
    if (alt_ifc) *alt_ifc = 0;
    return TRUE;
}

BOOL handle_set_interface(BYTE ifc, BYTE alt_ifc) {
    // No alternate interfaces; accept request
    return TRUE;
}

void handle_reset_ep(BYTE ep) {
    // No-op: endpoints are managed by firmware init; library may call RESETTOGGLE elsewhere
}
