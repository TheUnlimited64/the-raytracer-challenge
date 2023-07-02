#ifndef THE_RAYTRACER_CHALLANGE_CANVAS_H
#define THE_RAYTRACER_CHALLANGE_CANVAS_H

#include "color.h"
#include "stdint.h"
#include "helper/defines.h"

typedef struct Canvas {
    int16_t width;
    int16_t height;
    Color **canvas;
} Canvas;

Canvas createCanvas(int16_t width, int16_t height);

void writePixel(Canvas canvas, int16_t x, int16_t y, Color color);

Color readPixel(Canvas canvas, int16_t x, int16_t y);

bool isInBounds(Canvas canvas, int16_t x, int16_t y);


#endif //THE_RAYTRACER_CHALLANGE_CANVAS_H
