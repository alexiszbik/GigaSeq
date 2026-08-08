#pragma once

#include "Arduino_GigaDisplay_GFX.h"

void printTextInRect(GigaDisplay_GFX& display,
                     int x, int y, int w, int h,
                     const char* text,
                     uint8_t textSize,
                     uint8_t maxCharsPerLine);
