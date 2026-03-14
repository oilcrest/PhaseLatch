#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <math.h>

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s [--calib-samples N] [--pass-calib] [--iir-shift K]\n"
        "\n"
        "Streaming DC offset estimator/subtractor for interleaved unsigned 8-bit IQ.\n"
        "Reads u8 I,Q bytes on stdin; writes u8 I,Q bytes on stdout.\n"
        "\n"
        "Modes:\n"
        "  --calib-samples N   Use first N complex samples to estimate DC (mean), then subtract.\n"
        "                      Default: 32768. Use 0 to enable continuous IIR tracking.\n"
        "  --pass-calib        If set, calibration samples are passed through unmodified.\n"
        "                      Default behavior is to DROP them (assumed silence).\n"
        "  --iir-shift K       Only when --calib-samples 0. IIR mean tracker alpha=1/2^K.\n"
        "                      Default: 12.\n"
        "\n"
        "Notes:\n"
        "  - Ideal u8 zero is 128. DC is reported in raw codes and as (mean-128).\n",
        prog);
}

static inline uint8_t clamp_u8(int v) {
    if (v < 0) return 0;
    if (v > 255) return 255;
    return (uint8_t)v;
}

static int flush_out(uint8_t *out, size_t *out_len) {
    if (*out_len == 0) return 0;
    size_t w = fwrite(out, 1, *out_len, stdout);
    if (w != *out_len) {
        if (errno == EPIPE) return 1;
        return -1;
    }
    *out_len = 0;
    return 0;
}

int main(int argc, char **argv) {
    long long calib_samples = 32768; // complex samples
    int pass_calib = 0;
    int iir_shift = 12;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--calib-samples") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            calib_samples = atoll(argv[++i]);
            if (calib_samples < 0) {
                fprintf(stderr, "--calib-samples must be >= 0\n");
                return 2;
            }
        } else if (strcmp(argv[i], "--pass-calib") == 0) {
            pass_calib = 1;
        } else if (strcmp(argv[i], "--iir-shift") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            iir_shift = atoi(argv[++i]);
            if (iir_shift < 1 || iir_shift > 30) {
                fprintf(stderr, "--iir-shift must be in [1..30]\n");
                return 2;
            }
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Unknown arg: %s\n", argv[i]);
            usage(argv[0]);
            return 2;
        }
    }

    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);

    const size_t CHUNK = 1 << 16;
    uint8_t *in = (uint8_t *)malloc(CHUNK);
    uint8_t *out = (uint8_t *)malloc(CHUNK);
    if (!in || !out) {
        perror("malloc");
        free(in);
        free(out);
        return 1;
    }

    int have_I = 0;
    uint8_t I_hold = 0;
    size_t out_len = 0;

    if (calib_samples > 0) {
        long long remaining = calib_samples;
        long long count = 0;
        long long sumI = 0;
        long long sumQ = 0;

        int calibrated = 0;
        float meanI = 128.0f;
        float meanQ = 128.0f;
        int dcI = 0;
        int dcQ = 0;

        while (1) {
            size_t got = fread(in, 1, CHUNK, stdin);
            if (got == 0) break;

            for (size_t idx = 0; idx < got; idx++) {
                uint8_t b = in[idx];
                if (!have_I) {
                    I_hold = b;
                    have_I = 1;
                    continue;
                }

                uint8_t Iu = I_hold;
                uint8_t Qu = b;
                have_I = 0;

                if (!calibrated) {
                    if (remaining > 0) {
                        sumI += (long long)Iu;
                        sumQ += (long long)Qu;
                        count++;
                        remaining--;

                        if (pass_calib) {
                            if (out_len + 2 > CHUNK) {
                                int fr = flush_out(out, &out_len);
                                if (fr == 1) { free(in); free(out); return 0; }
                                if (fr < 0) { perror("fwrite"); free(in); free(out); return 1; }
                            }
                            out[out_len++] = Iu;
                            out[out_len++] = Qu;
                        }

                        if (remaining == 0) {
                            meanI = (float)sumI / (float)count;
                            meanQ = (float)sumQ / (float)count;
                            dcI = (int)lrintf(meanI - 128.0f);
                            dcQ = (int)lrintf(meanQ - 128.0f);
                            calibrated = 1;
                            fprintf(stderr,
                                "iq_dc_block: calibrated over %lld samples: meanI=%.3f meanQ=%.3f (dcI=%d dcQ=%d)\n",
                                count, meanI, meanQ, dcI, dcQ);
                        }
                        continue;
                    }

                    // Should not happen (remaining hits 0 sets calibrated), but keep safe.
                    meanI = (count > 0) ? (float)sumI / (float)count : 128.0f;
                    meanQ = (count > 0) ? (float)sumQ / (float)count : 128.0f;
                    dcI = (int)lrintf(meanI - 128.0f);
                    dcQ = (int)lrintf(meanQ - 128.0f);
                    calibrated = 1;
                    fprintf(stderr,
                        "iq_dc_block: calibrated over %lld samples: meanI=%.3f meanQ=%.3f (dcI=%d dcQ=%d)\n",
                        count, meanI, meanQ, dcI, dcQ);
                }

                // Correction stage
                int Ic = (int)Iu - dcI;
                int Qc = (int)Qu - dcQ;

                if (out_len + 2 > CHUNK) {
                    int fr = flush_out(out, &out_len);
                    if (fr == 1) { free(in); free(out); return 0; }
                    if (fr < 0) { perror("fwrite"); free(in); free(out); return 1; }
                }
                out[out_len++] = clamp_u8(Ic);
                out[out_len++] = clamp_u8(Qc);
            }

            int fr = flush_out(out, &out_len);
            if (fr == 1) { free(in); free(out); return 0; }
            if (fr < 0) { perror("fwrite"); free(in); free(out); return 1; }
        }

        // End of stream: if calibration never completed, still report what we saw.
        if (!calibrated) {
            if (count > 0) {
                meanI = (float)sumI / (float)count;
                meanQ = (float)sumQ / (float)count;
                dcI = (int)lrintf(meanI - 128.0f);
                dcQ = (int)lrintf(meanQ - 128.0f);
                fprintf(stderr,
                    "iq_dc_block: stream ended during calibration (%lld/%lld). meanI=%.3f meanQ=%.3f (dcI=%d dcQ=%d)\n",
                    count, calib_samples, meanI, meanQ, dcI, dcQ);
            } else {
                fprintf(stderr, "iq_dc_block: empty input\n");
            }
        }

        free(in);
        free(out);
        return 0;
    }

    // Continuous IIR tracking mode: calib_samples == 0
    float meanI = 128.0f;
    float meanQ = 128.0f;
    const float alpha = 1.0f / (float)(1u << (unsigned)iir_shift);
    fprintf(stderr, "iq_dc_block: IIR tracking enabled (shift=%d alpha=%g)\n", iir_shift, alpha);

    while (1) {
        size_t got = fread(in, 1, CHUNK, stdin);
        if (got == 0) break;

        for (size_t idx = 0; idx < got; idx++) {
            uint8_t b = in[idx];
            if (!have_I) {
                I_hold = b;
                have_I = 1;
                continue;
            }

            uint8_t Iu = I_hold;
            uint8_t Qu = b;
            have_I = 0;

            meanI += ((float)Iu - meanI) * alpha;
            meanQ += ((float)Qu - meanQ) * alpha;

            int Ic = (int)lrintf((float)Iu - meanI + 128.0f);
            int Qc = (int)lrintf((float)Qu - meanQ + 128.0f);

            if (out_len + 2 > CHUNK) {
                int fr = flush_out(out, &out_len);
                if (fr == 1) { free(in); free(out); return 0; }
                if (fr < 0) { perror("fwrite"); free(in); free(out); return 1; }
            }
            out[out_len++] = clamp_u8(Ic);
            out[out_len++] = clamp_u8(Qc);
        }

        int fr = flush_out(out, &out_len);
        if (fr == 1) { free(in); free(out); return 0; }
        if (fr < 0) { perror("fwrite"); free(in); free(out); return 1; }
    }

    free(in);
    free(out);
    return 0;
}
