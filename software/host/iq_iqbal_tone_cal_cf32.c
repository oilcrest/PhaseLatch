#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Tone-based IQ imbalance calibration (image cancellation).
//
// Assumes your (DC-removed) complex stream can be modeled as:
//   x[n] = a * e^{+j w n} + b * e^{-j w n} + noise
//
// Where b is the image term caused by IQ imbalance.
// A simple widely-linear image canceller is:
//   y[n] = x[n] - k * conj(x[n])
// Choosing k = b / conj(a) cancels the -w term (for a single-tone calibration).
//
// Practical note:
// Depending on your IQ sign conventions (swapped I/Q, conjugation, FFT display),
// the observed tone may land at -w instead of +w. In that case |b| >> |a|.
// We auto-detect which side is dominant and choose k to cancel the weaker side.
//
// Input:  CF32 stream on stdin as interleaved float32 I,Q.
// Output: two floats on stdout: kRe kIm

typedef struct {
    float re;
    float im;
} cf32_t;

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s (--tone-hz F --fs-hz FS | --tone-norm FN | --tone-rad W) [--samples N] [--desired {auto|+|-}]\n"
        "\n"
        "Reads CF32 IQ on stdin, estimates image-canceller coefficient k for a known tone.\n"
        "\n"
        "Frequency options:\n"
        "  --tone-hz F    Tone frequency in Hz (positive, < FS/2). Requires --fs-hz.\n"
        "  --fs-hz FS     Sample rate in Hz.\n"
        "  --tone-norm FN Tone frequency in cycles/sample (0..0.5).\n"
        "  --tone-rad W   Tone frequency in rad/sample (0..pi).\n"
        "\n"
        "Other options:\n"
        "  --samples N    Number of complex samples to use (default: 131072).\n"
        "  --desired X    Which sideband is treated as desired tone: auto (default), +, or -.\n"
        "\n"
        "Output (stdout): kRe kIm\n"
        "Diagnostics (stderr): DC mean, |a|, |b|, chosen side (+/-), image ratio dB.\n",
        prog);
}

static inline cf32_t c_add(cf32_t a, cf32_t b) {
    cf32_t r = { a.re + b.re, a.im + b.im };
    return r;
}

static inline cf32_t c_sub(cf32_t a, cf32_t b) {
    cf32_t r = { a.re - b.re, a.im - b.im };
    return r;
}

static inline cf32_t c_mul(cf32_t a, cf32_t b) {
    cf32_t r = { a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re };
    return r;
}

static inline cf32_t c_conj(cf32_t a) {
    cf32_t r = { a.re, -a.im };
    return r;
}

static inline double c_absd(cf32_t a) {
    return sqrt((double)a.re * (double)a.re + (double)a.im * (double)a.im);
}

static inline cf32_t c_div(cf32_t num, cf32_t den) {
    // num/den
    double dr = (double)den.re;
    double di = (double)den.im;
    double denom = dr*dr + di*di;
    cf32_t r;
    if (denom == 0.0) {
        r.re = 0.0f;
        r.im = 0.0f;
        return r;
    }
    double nr = (double)num.re;
    double ni = (double)num.im;
    r.re = (float)((nr*dr + ni*di) / denom);
    r.im = (float)((ni*dr - nr*di) / denom);
    return r;
}

int main(int argc, char **argv) {
    long long samples = 131072;
    int have_w = 0;
    double w = 0.0;

    enum { DESIRED_AUTO = 0, DESIRED_PLUS = 1, DESIRED_MINUS = 2 } desired_mode = DESIRED_AUTO;

    double tone_hz = 0.0, fs_hz = 0.0;
    int have_tone_hz = 0, have_fs_hz = 0;
    double tone_norm = 0.0;
    int have_tone_norm = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--samples") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            samples = atoll(argv[++i]);
        } else if (strcmp(argv[i], "--tone-hz") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            tone_hz = strtod(argv[++i], NULL);
            have_tone_hz = 1;
        } else if (strcmp(argv[i], "--fs-hz") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            fs_hz = strtod(argv[++i], NULL);
            have_fs_hz = 1;
        } else if (strcmp(argv[i], "--tone-norm") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            tone_norm = strtod(argv[++i], NULL);
            have_tone_norm = 1;
        } else if (strcmp(argv[i], "--tone-rad") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            w = strtod(argv[++i], NULL);
            have_w = 1;
        } else if (strcmp(argv[i], "--desired") == 0) {
            if (i + 1 >= argc) { usage(argv[0]); return 2; }
            const char *m = argv[++i];
            if (strcmp(m, "auto") == 0) desired_mode = DESIRED_AUTO;
            else if (strcmp(m, "+") == 0) desired_mode = DESIRED_PLUS;
            else if (strcmp(m, "-") == 0) desired_mode = DESIRED_MINUS;
            else {
                fprintf(stderr, "--desired must be one of: auto, +, -\n");
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

    if (samples <= 0) {
        fprintf(stderr, "--samples must be > 0\n");
        return 2;
    }

    if (!have_w) {
        if (have_tone_norm) {
            if (!(tone_norm > 0.0 && tone_norm < 0.5)) {
                fprintf(stderr, "--tone-norm must be in (0, 0.5)\n");
                return 2;
            }
            w = 2.0 * M_PI * tone_norm;
            have_w = 1;
        } else if (have_tone_hz || have_fs_hz) {
            if (!have_tone_hz || !have_fs_hz) {
                fprintf(stderr, "--tone-hz requires --fs-hz\n");
                return 2;
            }
            if (!(tone_hz > 0.0 && fs_hz > 0.0 && tone_hz < 0.5 * fs_hz)) {
                fprintf(stderr, "Require 0 < tone_hz < fs_hz/2\n");
                return 2;
            }
            w = 2.0 * M_PI * (tone_hz / fs_hz);
            have_w = 1;
        }
    }

    if (!have_w) {
        fprintf(stderr, "Missing tone frequency (use --tone-hz/--fs-hz or --tone-norm or --tone-rad)\n");
        return 2;
    }

    setvbuf(stdin, NULL, _IOFBF, 1 << 20);

    cf32_t *x = (cf32_t *)calloc((size_t)samples, sizeof(cf32_t));
    if (!x) {
        perror("calloc");
        return 1;
    }

    size_t nread = fread(x, sizeof(cf32_t), (size_t)samples, stdin);
    if (nread == 0) {
        fprintf(stderr, "iq_iqbal_tone_cal_cf32: no input\n");
        free(x);
        return 3;
    }

    // Remove mean (DC)
    double mu_re = 0.0, mu_im = 0.0;
    for (size_t i = 0; i < nread; i++) {
        mu_re += x[i].re;
        mu_im += x[i].im;
    }
    mu_re /= (double)nread;
    mu_im /= (double)nread;

    cf32_t mu = { (float)mu_re, (float)mu_im };

    // Complex accumulators for a and b
    cf32_t sum_a = {0.0f, 0.0f};
    cf32_t sum_b = {0.0f, 0.0f};

    // e^{-jw} step
    double c = cos(w);
    double s = sin(w);
    cf32_t step_minus = { (float)c, (float)(-s) }; // cos - j sin
    cf32_t z_minus = { 1.0f, 0.0f };

    for (size_t n = 0; n < nread; n++) {
        cf32_t xn = c_sub(x[n], mu);

        // a = mean(x * e^{-jwn})
        sum_a = c_add(sum_a, c_mul(xn, z_minus));

        // b = mean(x * e^{+jwn}) = mean(x * conj(e^{-jwn}))
        sum_b = c_add(sum_b, c_mul(xn, c_conj(z_minus)));

        z_minus = c_mul(z_minus, step_minus);
    }

    float invN = 1.0f / (float)nread;
    cf32_t a = { sum_a.re * invN, sum_a.im * invN };
    cf32_t b = { sum_b.re * invN, sum_b.im * invN };

    // k = b / conj(a)
    double a_abs = c_absd(a);
    double b_abs = c_absd(b);

    const double tone_abs = (a_abs > b_abs) ? a_abs : b_abs;
    if (tone_abs < 1e-9) {
        fprintf(stderr,
            "iq_iqbal_tone_cal_cf32: tone too weak or frequency mismatch (|a|=%.6g |b|=%.6g); check --tone-* and sample rate\n",
            a_abs, b_abs);
        free(x);
        return 4;
    }

    // Decide which side contains the desired tone.
    // a corresponds to +w, b corresponds to -w.
    int desired_is_plus;
    if (desired_mode == DESIRED_PLUS) desired_is_plus = 1;
    else if (desired_mode == DESIRED_MINUS) desired_is_plus = 0;
    else desired_is_plus = (a_abs >= b_abs);

    cf32_t k = {0.0f, 0.0f};
    double img_db = -INFINITY;
    if (desired_is_plus) {
        if (a_abs > 1e-12) k = c_div(b, c_conj(a));
        if (a_abs > 0.0 && b_abs > 0.0) img_db = 20.0 * log10(b_abs / a_abs);
    } else {
        if (b_abs > 1e-12) k = c_div(a, c_conj(b));
        if (a_abs > 0.0 && b_abs > 0.0) img_db = 20.0 * log10(a_abs / b_abs);
    }

    const char *mode_str = (desired_mode == DESIRED_AUTO) ? "auto" : (desired_mode == DESIRED_PLUS) ? "+" : "-";
    fprintf(stderr,
        "iq_iqbal_tone_cal_cf32: n=%zu mu=(%.6g,%.6g) |a|=%.6g |b|=%.6g desired=%c(mode=%s) image=%.2f dB k=(%.6g,%.6g)\n",
        nread, mu_re, mu_im, a_abs, b_abs, desired_is_plus ? '+' : '-', mode_str, img_db, (double)k.re, (double)k.im);

    // stdout parseable
    printf("%.12g %.12g\n", (double)k.re, (double)k.im);

    free(x);
    return 0;
}
