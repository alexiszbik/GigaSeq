#pragma once

#include "MyDisplay.h"

namespace GigaSeq {

void printTextInRect(MyDisplay& display,
                     int x, int y, int w, int h,
                     const char* text,
                     uint8_t textSize,
                     uint8_t maxCharsPerLine);

}  // namespace GigaSeq
