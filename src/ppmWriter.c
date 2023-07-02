#include "ppmWriter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PPMPixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};


struct PPMPixel convertColor(Color color) {
    struct PPMPixel tmp;
    tmp.r = (uint8_t) clampF32(color.x * 255, 0, 255);
    tmp.g = (uint8_t) clampF32(color.y * 255, 0, 255);
    tmp.b = (uint8_t) clampF32(color.z * 255, 0, 255);
    return tmp;
}

int writeSingleColor(FILE *fp, int currentLineWidth, uint8_t color) {
    char tempString[5];
    snprintf(tempString, sizeof(tempString), "%d", color);
    int len = (int) strlen(tempString);
    if (currentLineWidth + len > 70) {
        fprintf(fp, "\n");
        currentLineWidth = 0;
    }
    currentLineWidth += len + 1;
    fprintf(fp, "%s ", tempString);
    return currentLineWidth;
}

void writeCanvasToPPM(Canvas canvas, char *filename) {
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        perror("Could not open file: ");
        exit(-1);
    }

    fprintf(fp, "P3\n%d %d\n255\n", canvas.width, canvas.height);

    struct PPMPixel currentPixel;
    int currentLineWidth = 0;
    for (int16_t y = 0; y < canvas.height; y++) {
        for (int16_t x = 0; x < canvas.width; x++) {
            currentPixel = convertColor(readPixel(canvas, x, y));
            currentLineWidth = writeSingleColor(fp, currentLineWidth, currentPixel.r);
            currentLineWidth = writeSingleColor(fp, currentLineWidth, currentPixel.g);
            currentLineWidth = writeSingleColor(fp, currentLineWidth, currentPixel.b);
        }
        fprintf(fp, "\n");
        currentLineWidth = 0;
    }
    fclose(fp);
}