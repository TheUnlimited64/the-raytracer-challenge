#include "bmpWriter.h"
#include <stdint.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

struct BitmapFileHeader {
    uint8_t bfType[2];
    uint32_t sizeInBytes;
    uint32_t bfReserved;
    uint32_t offsetOfFileData;
}__attribute__((packed));

struct BitmapInfoHeader {
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount; //32
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
}__attribute__((packed));

struct BitmapPixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;//not used, but easier to use
};

struct BitmapData {
    struct BitmapFileHeader bitmapFileHeader;
    struct BitmapInfoHeader bitmapInfoHeader;
    struct BitmapPixel *pixelData;
};

int32_t calculatePixelDataSize(uint16_t width, uint16_t height);

struct BitmapFileHeader createBitmapFileHeader(uint16_t width, uint16_t height);

struct BitmapInfoHeader createBitmapInfoHeader(uint16_t width, uint16_t height);

void convertCanvas(struct BitmapData bitmapData, Canvas canvas);

struct BitmapPixel convertToBitmapColor(Color color);

void writeToFile(struct BitmapData bitmapData, char *filename);

/*
 * *****************************************************************************************
 *  functions
 * *****************************************************************************************
 */

void writeCanvasToBmp(Canvas canvas, char *filename) {
    struct BitmapData bitmapData;
    bitmapData.bitmapFileHeader = createBitmapFileHeader(canvas.width, canvas.height);
    bitmapData.bitmapInfoHeader = createBitmapInfoHeader(canvas.width, canvas.height);
    bitmapData.pixelData = (struct BitmapPixel *) malloc(bitmapData.bitmapInfoHeader.biSizeImage);
    convertCanvas(bitmapData, canvas);
    writeToFile(bitmapData, filename);
}

void writeToFile(struct BitmapData bitmapData, char *filename) {

    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        perror("Cannot write file");
        exit(-1);
    }
    fwrite(&bitmapData.bitmapFileHeader, sizeof(struct BitmapFileHeader), 1, fp);
    fwrite(&bitmapData.bitmapInfoHeader, sizeof(struct BitmapInfoHeader), 1, fp);
    fwrite(bitmapData.pixelData,
           calculatePixelDataSize(bitmapData.bitmapInfoHeader.biWidth, bitmapData.bitmapInfoHeader.biHeight), 1, fp);
    free(bitmapData.pixelData);
    fclose(fp);
}

void convertCanvas(struct BitmapData bitmapData, Canvas canvas) {
    for (uint16_t y = 0; y < canvas.height; y++) {
        for (uint16_t x = 0; x < canvas.width; x++) {
            Color color = readPixel(canvas, x, y);
            bitmapData.pixelData[y * canvas.width + x] = convertToBitmapColor(color);
        }
    }
}

int32_t calculatePixelDataSize(uint16_t width, uint16_t height) {
    return (int32_t) (ceilf((((sizeof(struct BitmapPixel) * 8) * (f32_t) width) / 32.f)) * 4.f) * height;
}

struct BitmapFileHeader createBitmapFileHeader(uint16_t width, uint16_t height) {
    return (struct BitmapFileHeader) {
            {0x42, 0x4D},
            calculatePixelDataSize(width, height) + sizeof(struct BitmapInfoHeader) +
            sizeof(struct BitmapFileHeader), //calculate via width, height
            0,
            sizeof(struct BitmapInfoHeader) + sizeof(struct BitmapFileHeader)
    };
}

struct BitmapInfoHeader createBitmapInfoHeader(uint16_t width, uint16_t height) {
    return (struct BitmapInfoHeader) {
            sizeof(struct BitmapInfoHeader),
            width,
            height,
            1,
            sizeof(struct BitmapPixel) * 8,
            0,
            calculatePixelDataSize(width, height),
            2835,
            2835,
            0,
            0

    };
}

struct BitmapPixel convertToBitmapColor(Color color) {
    struct BitmapPixel tmp;
    tmp.red = (uint8_t) clampF32(color.x * 255, 0, 255);
    tmp.green = (uint8_t) clampF32(color.y * 255, 0, 255);
    tmp.blue = (uint8_t) clampF32(color.z * 255, 0, 255);
    tmp.alpha = 0;
    return tmp;
}
