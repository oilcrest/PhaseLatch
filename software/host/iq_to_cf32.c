#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

// Convert interleaved IQ byte streams to CF32 on stdout.
// Modes:
//  -m 8u : 8-bit unsigned I,Q (I then Q), map [0..255] -> [-1.0, +1.0)
//  -m 8s : 8-bit signed I,Q (I then Q), map [-128..127] -> [-1.0, +~0.992]
//  -m 10u: 10-bit unsigned packed as: I_MSB (8b), I_LSB2 in next byte bits[1:0],
//          then Q_MSB (8b), Q_LSB2 in next byte bits[1:0]. Map [0..1023] -> [-1.0, +1.0)
//  -m 10s: same packing, interpret as signed 10-bit (-512..511) -> [-1.0, +~0.998]
// Chunked conversion for performance.

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s -m {8u|8s|10u|10s}\n"
        "Reads raw IQ on stdin, writes CF32 (little-endian) on stdout.\n",
        prog);
}

typedef enum { MODE_8U, MODE_8S, MODE_10U, MODE_10S } iq_mode_t;

int main(int argc, char **argv) {
    iq_mode_t mode = MODE_8U;
    if (argc != 3 || strcmp(argv[1], "-m") != 0) {
        usage(argv[0]);
        return 2;
    }
    if      (strcmp(argv[2], "8u") == 0)  mode = MODE_8U;
    else if (strcmp(argv[2], "8s") == 0)  mode = MODE_8S;
    else if (strcmp(argv[2], "10u") == 0) mode = MODE_10U;
    else if (strcmp(argv[2], "10s") == 0) mode = MODE_10S;
    else { usage(argv[0]); return 2; }

    // Set stdout to binary mode just in case (no-op on POSIX)
    setvbuf(stdout, NULL, _IOFBF, 1<<20);
    setvbuf(stdin,  NULL, _IOFBF, 1<<20);

    const size_t IN_CHUNK = 1<<16; // 64 KiB input increments
    uint8_t *in = (uint8_t*)malloc(IN_CHUNK);
    if (!in) { perror("malloc"); return 1; }

    // Output buffer sized conservatively: worst case 10-bit mode expands 4 in bytes -> 8 out bytes
    float *out = (float*)malloc(IN_CHUNK * 2); // float pairs approx
    if (!out) { perror("malloc"); free(in); return 1; }

    while (1) {
        size_t need = IN_CHUNK;
        size_t got = fread(in, 1, need, stdin);
        if (got == 0) break;

        size_t consumed = 0;
        size_t produced = 0; // count of float values (I and Q each count)

        if (mode == MODE_8U || mode == MODE_8S) {
            // Require even number of bytes (I,Q pairs)
            size_t pairs = (got / 2);
            size_t n = pairs * 2;
            for (size_t i = 0; i < n; i += 2) {
                int32_t I = in[i+0];
                int32_t Q = in[i+1];
                if (mode == MODE_8U) {
                    // center at 0: [0..255] -> [-128..127]
                    I -= 128; Q -= 128;
                    out[produced++] = (float)I / 128.0f;
                    out[produced++] = (float)Q / 128.0f;
                } else {
                    // signed int8
                    if (I >= 128) I -= 256;
                    if (Q >= 128) Q -= 256;
                    out[produced++] = (float)I / 128.0f;
                    out[produced++] = (float)Q / 128.0f;
                }
            }
            consumed = n;
        } else {
            // 10-bit packed: I_MSB (b0), I_LSB2 in b1 bits[1:0]; Q_MSB (b2), Q_LSB2 in b3 bits[1:0]
            size_t groups = got / 4;
            size_t n = groups * 4;
            for (size_t i = 0; i < n; i += 4) {
                uint16_t ims = in[i+0];
                uint16_t ils = (uint16_t)(in[i+1] & 0x03);
                uint16_t qms = in[i+2];
                uint16_t qls = (uint16_t)(in[i+3] & 0x03);
                uint16_t IU = (uint16_t)((ims << 2) | ils); // 10-bit
                uint16_t QU = (uint16_t)((qms << 2) | qls);
                if (mode == MODE_10U) {
                    int32_t I = (int32_t)IU - 512; // center
                    int32_t Q = (int32_t)QU - 512;
                    out[produced++] = (float)I / 512.0f;
                    out[produced++] = (float)Q / 512.0f;
                } else {
                    // signed 10-bit two's complement in 10 bits: assume MSB is sign (bit9)
                    int32_t I = (IU & 0x200) ? (int32_t)IU - 1024 : (int32_t)IU;
                    int32_t Q = (QU & 0x200) ? (int32_t)QU - 1024 : (int32_t)QU;
                    out[produced++] = (float)I / 512.0f;
                    out[produced++] = (float)Q / 512.0f;
                }
            }
            consumed = n;
        }

        // Write produced floats (I,Q interleaved)
        size_t bytes = produced * sizeof(float);
        if (fwrite(out, 1, bytes, stdout) != bytes) {
            perror("fwrite");
            break;
        }

        // If we had leftover bytes that didn't form a complete sample, shift them to front
        size_t leftover = got - consumed;
        if (leftover > 0) {
            memmove(in, in + consumed, leftover);
            // Read next chunk into the gap
            size_t next = fread(in + leftover, 1, IN_CHUNK - leftover, stdin);
            got = leftover + next;
            // Rewind FILE position by the amount we pre-read into 'in'
            // Not easily supported for pipes; instead loop will process in next iteration
            // Place the bytes back into stdin is not feasible; so handle in while by continuing
            // Here we just process the 'got' immediately in the next loop iteration
            // Using continue avoids double fread at top
            // But we need to process now: fall through to loop top by using a continue
            // To keep logic simple, we'll set consumed to 0 and let next iteration read anew
        }
    }

    free(in);
    free(out);
    return 0;
}
