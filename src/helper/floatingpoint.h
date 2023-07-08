#ifndef THE_RAYTRACER_CHALLENGE_FLOATINGPOINT_H
#define THE_RAYTRACER_CHALLENGE_FLOATINGPOINT_H

#include <stdbool.h>
#include <math.h>

#define f32_t float
#define f64_t double

#define EPSILON 0.00001

static inline bool equalF64(f64_t a, f64_t b) {
    if (fabs(a - b) < EPSILON) {
        return true;
    }
    return false;
}

static inline bool equalF32(f32_t a, f32_t b) {
    return equalF64(a, b);
}

static inline f32_t clampF32(f32_t value, f32_t lower, f32_t upper) {
    f32_t res = value > lower ? value : lower;
    res = res < upper ? res : upper;
    return res;
}


#endif
