#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


bool equalMatrix(int8_t rows, int8_t cols, f32_t matrixA[rows][cols], f32_t matrixB[rows][cols]) {
    for (size_t y = 0; y < rows; y++) {
        for (size_t x = 0; x < cols; x++) {
            if (!equalF32(matrixA[y][x], matrixB[y][x])) {
                return false;
            }
        }
    }
    return true;
}

void mulMatrix(size_t yA, size_t xA, f32_t matrixA[yA][xA], size_t yB, size_t xB,
               f32_t matrixB[yB][xB], f32_t matrixC[yB][xA]) {
    if (xA != yB) {
        printf("Matrix multiplication not possible!\n");
        exit(EXIT_FAILURE);
    }

    for (size_t y = 0; y < yA; y++) {
        for (size_t x = 0; x < xB; x++) {
            f32_t sum = 0;
            for (size_t i = 0; i < xA; i++) {
                sum += matrixA[y][i] * matrixB[i][x];
            }
            matrixC[y][x] = sum;
        }
    }
}