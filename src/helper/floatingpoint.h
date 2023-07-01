//
// Created by theun on 30.06.2023.
//

#ifndef THE_RAYTRACER_CHALLANGE_FLOATINGPOINT_H
#define THE_RAYTRACER_CHALLANGE_FLOATINGPOINT_H

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
    equalF64(a, b);
}


#endif //THE_RAYTRACER_CHALLANGE_FLOATINGPOINT_H
