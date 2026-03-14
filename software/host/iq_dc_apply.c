#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s --dcI N --dcQ N\n"
        "\n"
        "Applies a fixed DC correction to interleaved unsigned 8-bit IQ.\n"
        "Reads u8 IQ bytes on stdin; writes corrected u8 IQ bytes on stdout.\n"
        "\n"
        "dcI/dcQ are integer codes to subtract from I and Q respectively.\n",
        prog);
}

static inline uint8_t clamp_u8(int v) {
    if (v < 0) return 0;
    if (v > 255) return 255;
    return (uint8_t)v;
}

int main(int argc, char **argv) {
    int have_dcI = 0;
    int have_dcQ = 0;
    int dcI = 0;
    int dcQ = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--dcI") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            dcI = atoi(argv[++i]);
            have_dcI = 1;
        } else if (strcmp(argv[i], "--dcQ") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            dcQ = atoi(argv[++i]);
            have_dcQ = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Unknown arg: %s\n", argv[i]);
            usage(argv[0]);
            return 2;
        }
    }

    if (!have_dcI || !have_dcQ) {
        fprintf(stderr, "Missing --dcI/--dcQ\n");
        usage(argv[0]);
        return 2;
    }

    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);

    const size_t CHUNK = 1 << 16;
    uint8_t *buf = (uint8_t *)malloc(CHUNK);
    if (!buf) { perror("malloc"); return 1; }

    int have_I = 0;
    uint8_t I_hold = 0;

    while (1) {
        size_t got = fread(buf, 1, CHUNK, stdin);
        if (got == 0) break;

        size_t out_idx = 0;
        for (size_t idx = 0; idx < got; idx++) {
            uint8_t b = buf[idx];
            if (!have_I) {
                I_hold = b;
                have_I = 1;
                continue;
            }

            uint8_t Iu = I_hold;
            uint8_t Qu = b;
            have_I = 0;

            buf[out_idx++] = clamp_u8((int)Iu - dcI);
            buf[out_idx++] = clamp_u8((int)Qu - dcQ);
        }

        if (out_idx > 0) {
            size_t w = fwrite(buf, 1, out_idx, stdout);
            if (w != out_idx) {
                if (errno == EPIPE) break;
                perror("fwrite");
                free(buf);
                return 1;
            }
        }
    }

    free(buf);
    return 0;
}
