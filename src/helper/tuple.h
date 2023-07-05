#ifndef THE_RAYTRACER_CHALLENGE_TUPLE_H
#define THE_RAYTRACER_CHALLENGE_TUPLE_H

#include "floatingpoint.h"
#include <stdint.h>

typedef struct Tuple {
    f32_t x;
    f32_t y;
    f32_t z;
    f32_t w;
} Tuple, PTuple;

#define Vector Tuple
#define Point Tuple

static inline bool isVector(Tuple a) {
    return a.w == 0;
}

static inline bool isPoint(Tuple a) {
    return a.w == 1;
}


Tuple createVector(f32_t x, f32_t y, f32_t z);

Tuple createPoint(f32_t x, f32_t y, f32_t z);

bool equalTuple(Tuple a, Tuple b);

Tuple addTuple(Tuple a, Tuple b);

Tuple subTuple(Tuple a, Tuple b);

Tuple negateTuple(Tuple a);

Tuple mulScalarTuple(Tuple a, f32_t scalar);

Tuple divScalarTuple(Tuple a, f32_t scalar);

f32_t magnitudeTuple(Tuple a);

Tuple normalizeTuple(Tuple a);

f32_t dotTuple(Tuple a, Tuple b);

Tuple crossTuple(Tuple a, Tuple b);

Tuple mulTuple(Tuple a, Tuple b);
#endif
