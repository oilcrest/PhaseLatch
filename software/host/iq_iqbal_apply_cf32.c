#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Apply widely-linear image canceller:
//   y = x - k * conj(x)
//
// Input/Output: CF32 as interleaved float32 I,Q.

typedef struct {
    float re;
    float im;
} cf32_t;

static void usage(const char *prog) {
    fprintf(stderr, "Usage: %s --kRe R --kIm I\n", prog);
}

int main(int argc, char **argv) {
    double kRe = 0.0, kIm = 0.0;
    int haveRe = 0, haveIm = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--kRe") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            kRe = strtod(argv[++i], NULL);
            haveRe = 1;
        } else if (strcmp(argv[i], "--kIm") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            kIm = strtod(argv[++i], NULL);
            haveIm = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Unknown arg: %s\n", argv[i]);
            usage(argv[0]);
            return 2;
        }
    }

    if (!haveRe || !haveIm) {
        usage(argv[0]);
        return 2;
    }

    const float c = (float)kRe;
    const float d = (float)kIm;

    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);

    cf32_t buf[8192];
    while (1) {
        size_t n = fread(buf, sizeof(cf32_t), 8192, stdin);
        if (n == 0) break;

        for (size_t i = 0; i < n; i++) {
            float a = buf[i].re;
            float b = buf[i].im;

            // conj(x) = (a, -b)
            // k*conj(x) = (c+jd)*(a-jb) = (c a + d b) + j(d a - c b)
            float t_re = c * a + d * b;
            float t_im = d * a - c * b;

            buf[i].re = a - t_re;
            buf[i].im = b - t_im;
        }

        fwrite(buf, sizeof(cf32_t), n, stdout);
    }

    return 0;
}
