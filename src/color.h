#ifndef THE_RAYTRACER_CHALLANGE_COLOR_H
#define THE_RAYTRACER_CHALLANGE_COLOR_H

#include "helper/tuple.h"

#define Color Tuple

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

static inline Color mulColor(Color a, Color b){
    //TODO
}


#endif //THE_RAYTRACER_CHALLANGE_COLOR_H
