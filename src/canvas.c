#include <malloc.h>
#include <stdlib.h>
#include "canvas.h"

bool isInBounds(Canvas canvas, int16_t x, int16_t y) {
    if (x >= canvas.width) {
        return false;
    }
    if (y >= canvas.height) {
        return false;
    }
    if (y < 0) {
        return false;
    }
    if (x < 0) {
        return false;
    }
    return true;
}

Canvas createCanvas(int16_t width, int16_t height) {
    Canvas tmp = {width, height, NULL};
    Color **canvas = malloc(height * sizeof(Color *));
    if (canvas == NULL) {
        perror("Error allocating canvas:");
        exit(-1);
    }
    for (int i = 0; i < height; i++) {
        canvas[i] = calloc(width, sizeof(Color));
        if (canvas[i] == NULL) {
            perror("Error allocating canvas:");
            exit(-1);
        }
    }
    tmp.canvas = canvas;
    return tmp;
}

void writePixel(Canvas canvas, int16_t x, int16_t y, Color color) {
    if (!isInBounds(canvas, x, y)) {
        fprintf(stderr, "tried writing outside canvas: width:[%d] height:[%d] x:[%d] y:[%d]!", canvas.width,
                canvas.height, x, y);
        exit(-1);
    }
    canvas.canvas[y][x] = color;
}

Color readPixel(Canvas canvas, int16_t x, int16_t y) {
    if (!isInBounds(canvas, x, y)) {
        fprintf(stderr, "tried reading outside canvas: width:[%d] height:[%d] x:[%d] y:[%d]!", canvas.width,
                canvas.height, x, y);
        exit(-1);
    }
    return canvas.canvas[y][x];
}