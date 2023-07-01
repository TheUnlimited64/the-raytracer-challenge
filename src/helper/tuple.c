#include "tuple.h"
#include "floatingpoint.h"
#include <math.h>


Tuple createVector(f32_t x, f32_t y, f32_t z) {
    Tuple tuple = {x, y, z, 0};
    return tuple;
}

Tuple createPoint(f32_t x, f32_t y, f32_t z) {
    Tuple tuple = {x, y, z, 1};
    return tuple;
}

bool equalTuple(Tuple a, Tuple b) {
    if (!equalF32(a.x, b.x)) {
        return false;
    }
    if (!equalF32(a.y, b.y)) {
        return false;
    }
    if (!equalF32(a.z, b.z)) {
        return false;
    }
    if (!equalF32(a.w, b.w)) {
        return false;
    }
    return true;
}

Tuple addTuple(Tuple a, Tuple b) {
    Tuple tuple = {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
    return tuple;
}

Tuple subTuple(Tuple a, Tuple b) {
    Tuple tuple = {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
    return tuple;
}

Tuple negateTuple(Tuple a) {
    Tuple tmp = {a.x * -1, a.y * -1, a.z * -1, a.w * -1};
    return tmp;
}

Tuple mulScalarTuple(Tuple a, f32_t scalar) {
    Tuple tmp = {a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar};
    return tmp;
}

Tuple divScalarTuple(Tuple a, f32_t scalar) {
    Tuple tmp = {a.x / scalar, a.y / scalar, a.z / scalar, a.w / scalar};
    return tmp;
}

f32_t magnitudeTuple(Tuple a) {
    return sqrtf(powf(a.x, 2.0f) + powf(a.y, 2) + pow(a.z, 2) +
                 pow(a.w, 2)); //TODO a.w can be left out theoretically cause its only for vectors
}

Tuple normalizeTuple(Tuple a) {
    f32_t magnitude = magnitudeTuple(a);
    return divScalarTuple(a, magnitude);
}

f32_t dotTuple(Tuple a, Tuple b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; //TODO w can be left out theoretically
}

Tuple crossTuple(Tuple a, Tuple b) {
    return createVector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}