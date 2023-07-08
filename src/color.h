#ifndef THE_RAYTRACER_CHALLENGE_COLOR_H
#define THE_RAYTRACER_CHALLENGE_COLOR_H

#include "helper/tuple.h"

#define Color Tuple

static const Color BLACK = {0, 0, 0};
static const Color WHITE = {1, 1, 1};
static const Color RED = {1, 0, 0};
static const Color GREEN = {0, 1, 0};
static const Color BLUE = {0, 0, 1};


static inline Color createColor(f32_t r, f32_t g, f32_t b) {
    return createVector(r, g, b);
}

static inline Color addColor(Color a, Color b) {
    return addTuple(a, b);
}

static inline Color subColor(Color a, Color b) {
    return subTuple(a, b);
}

static inline Color mulColorScalar(Color a, f32_t scalar) {
    return mulScalarTuple(a, scalar);
}

static inline Color mulColor(Color a, Color b) {
    return mulTuple(a, b);
}

static inline Color hamadProduct(Color a, Color b) {
    return mulColor(a, b);
}


#endif //THE_RAYTRACER_CHALLENGE_COLOR_H
