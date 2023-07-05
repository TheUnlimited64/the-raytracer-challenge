#ifndef THE_RAYTRACER_CHALLENGE_CANVAS_H
#define THE_RAYTRACER_CHALLENGE_CANVAS_H

#include "color.h"
#include "stdint.h"

typedef struct Canvas {
    uint16_t width;
    uint16_t height;
    Color **canvas;
} Canvas;

Canvas createCanvas(uint16_t width, uint16_t height);

void writePixel(Canvas canvas, uint16_t x, uint16_t y, Color color);

Color readPixel(Canvas canvas, uint16_t x, uint16_t y);

bool isInBounds(Canvas canvas, uint16_t x, uint16_t y);

#endif
