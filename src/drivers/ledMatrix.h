#pragma once
#include <stdint.h>

#define SCREENWIDTH 64
#define SCREENHEIGHT 32
#define SCREENSIZE (SCREENWIDTH * SCREENHEIGHT)
#define SCANRATE (SCREENHEIGHT / 2)
#define BUFFERSIZE (SCREENWIDTH * SCANRATE)
#define COLOR_OFFSET 0
#define ROW_OFFSET 6

typedef enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    WHITE
} COLOR;

#ifdef __cplusplus
extern "C" {
#endif

void bufferInit();
void matrixDisplay();
void setPixel(uint8_t x, uint8_t y, uint8_t color);

#ifdef __cplusplus
}
#endif

uint8_t screenBuffer[BUFFERSIZE]; // screenBuffer[currRow][currColumn]
