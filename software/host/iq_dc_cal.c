#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <math.h>

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s --samples N\n"
        "\n"
        "Reads interleaved unsigned 8-bit IQ on stdin and estimates DC offset\n"
        "over the first N complex samples (I,Q pairs).\n"
        "\n"
        "Outputs two integers to stdout: dcI dcQ\n"
        "Where dcI = round(meanI - 128) and dcQ = round(meanQ - 128).\n"
        "\n"
        "Notes:\n"
        "  - This tool CONSUMES N samples and then exits (no passthrough).\n"
        "  - Designed to be run as a separate calibration step with silence at input.\n",
        prog);
}

int main(int argc, char **argv) {
    long long samples = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--samples") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            samples = atoll(argv[++i]);
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Unknown arg: %s\n", argv[i]);
            usage(argv[0]);
            return 2;
        }
    }

    if (samples <= 0) {
        fprintf(stderr, "--samples must be > 0\n");
        usage(argv[0]);
        return 2;
    }

    setvbuf(stdin, NULL, _IOFBF, 1 << 20);

    const size_t CHUNK = 1 << 16;
    uint8_t *buf = (uint8_t *)malloc(CHUNK);
    if (!buf) { perror("malloc"); return 1; }

    long long remaining = samples;
    long long count = 0;
    long long sumI = 0;
    long long sumQ = 0;

    int have_I = 0;
    uint8_t I_hold = 0;

    while (remaining > 0) {
        size_t got = fread(buf, 1, CHUNK, stdin);
        if (got == 0) break;

        for (size_t idx = 0; idx < got && remaining > 0; idx++) {
            uint8_t b = buf[idx];
            if (!have_I) {
                I_hold = b;
                have_I = 1;
                continue;
            }

            uint8_t Iu = I_hold;
            uint8_t Qu = b;
            have_I = 0;

            sumI += (long long)Iu;
            sumQ += (long long)Qu;
            count++;
            remaining--;
        }
    }

    free(buf);

    if (count == 0) {
        fprintf(stderr, "iq_dc_cal: no samples read\n");
        return 3;
    }

    float meanI = (float)sumI / (float)count;
    float meanQ = (float)sumQ / (float)count;

    int dcI = (int)lrintf(meanI - 128.0f);
    int dcQ = (int)lrintf(meanQ - 128.0f);

    fprintf(stderr,
        "iq_dc_cal: %lld samples, meanI=%.3f meanQ=%.3f (dcI=%d dcQ=%d)\n",
        count, meanI, meanQ, dcI, dcQ);

    // stdout is parseable: "<dcI> <dcQ>\n"
    printf("%d %d\n", dcI, dcQ);
    return 0;
}
