//
// Created by theun on 08.07.2023.
//

#ifndef THE_RAYTRACER_CHALLENGE_MATRIX_H
#define THE_RAYTRACER_CHALLENGE_MATRIX_H

#include "floatingpoint.h"
#include <stdint.h>
#include <stddef.h>


typedef f32_t Matrix4[4][4];
typedef f32_t Matrix3[3][3];
typedef f32_t Matrix2[2][2];



bool equalMatrix(int8_t rows, int8_t cols, f32_t matrixA[rows][cols], f32_t matrixB[rows][cols]);


static inline bool equalMatrix4(Matrix4 a, Matrix4 b) {
    return equalMatrix(4, 4, a, b);
}

static inline bool equalMatrix3(Matrix3 a, Matrix3 b) {
    return equalMatrix(3, 3, a, b);
}

static inline bool equalMatrix2(Matrix2 a, Matrix2 b) {
    return equalMatrix(2, 2, a, b);
}

void mulMatrix(size_t yA, size_t xA, f32_t a[yA][xA], size_t yB, size_t xB, f32_t b[yB][xB],
               f32_t result[yB][xB]);

static inline void mulMatrix4(Matrix4 a, Matrix4 b, Matrix4 res) {
    mulMatrix(4, 4, a, 4, 4, b, res);
}

static inline void mulMatrix3(Matrix3 a, Matrix3 b, Matrix3 res) {
    mulMatrix(3, 3, a, 3, 3, b, res);
}

static inline void mulMatrix2(Matrix2 a, Matrix2 b, Matrix2 res) {
    mulMatrix(2, 2, a, 2, 2, b, res);
}


#endif //THE_RAYTRACER_CHALLENGE_MATRIX_H
