#include <malloc.h>
#include <stdlib.h>
#include "canvas.h"
#include "helper/defines.h"

bool isInBounds(Canvas canvas, uint16_t x, uint16_t y) {
    if (x >= canvas.width) {
        return false;
    }
    if (y >= canvas.height) {
        return false;
    }
    return true;
}

Canvas createCanvas(uint16_t width, uint16_t height) {
    Canvas tmp = {width, height, nullptr};
    Color **canvas = malloc(height * sizeof(Color *));
    if (canvas == nullptr) {
        perror("Error allocating canvas:");
        exit(-1);
    }
    for (int y = 0; y < height; y++) {
        canvas[y] = calloc(width, sizeof(Color));
        if (canvas[y] == nullptr) {
            perror("Error allocating canvas:");
            exit(-1);
        }
    }
    tmp.canvas = canvas;
    return tmp;
}

void writePixel(Canvas canvas, uint16_t x, uint16_t y, Color color) {
    if (!isInBounds(canvas, x, y)) {
        fprintf(stderr, "tried writing outside canvas: width:[%d] height:[%d] x:[%d] y:[%d]!", canvas.width,
                canvas.height, x, y);
        exit(-1);
    }
    canvas.canvas[y][x] = color;
}

Color readPixel(Canvas canvas, uint16_t x, uint16_t y) {
    if (!isInBounds(canvas, x, y)) {
        fprintf(stderr, "tried reading outside canvas: width:[%d] height:[%d] x:[%d] y:[%d]!", canvas.width,
                canvas.height, x, y);
        exit(-1);
    }
    return canvas.canvas[y][x];
}