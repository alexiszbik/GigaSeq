#include "TextBox.h"

#include <cstring>

namespace GigaSeq {

namespace {
constexpr int kPadding = 4;
constexpr int kFontHeight = 8;
constexpr uint8_t kMaxLineLength = 32;
}

void printTextInRect(MyDisplay& display,
                     int x, int y, int w, int h,
                     const char* text,
                     uint8_t textSize,
                     uint8_t maxCharsPerLine) {
    if (!text || maxCharsPerLine == 0 || w <= 0 || h <= 0) {
        return;
    }

    const uint8_t charsPerLine = maxCharsPerLine < kMaxLineLength ? maxCharsPerLine : kMaxLineLength;

    display.setTextSize(textSize);

    const int lineHeight = kFontHeight * textSize;
    const int maxLines = (h - 2 * kPadding) / lineHeight;
    if (maxLines <= 0) {
        return;
    }

    const size_t textLen = strlen(text);
    size_t index = 0;
    int lineIndex = 0;

    while (index < textLen && lineIndex < maxLines) {
        while (index < textLen && text[index] == ' ') {
            index++;
        }
        if (index >= textLen) {
            break;
        }

        const size_t remaining = textLen - index;
        size_t chunk = remaining < charsPerLine ? remaining : charsPerLine;
        size_t lineEnd = index + chunk;

        if (chunk == charsPerLine && lineEnd < textLen) {
            size_t lastSpace = 0;
            for (size_t i = lineEnd; i > index; i--) {
                if (text[i - 1] == ' ') {
                    lastSpace = i;
                    break;
                }
            }
            if (lastSpace > index) {
                lineEnd = lastSpace;
            }
        }

        size_t len = lineEnd - index;
        while (len > 0 && text[index + len - 1] == ' ') {
            len--;
        }

        char line[kMaxLineLength + 1];
        memcpy(line, text + index, len);
        line[len] = '\0';

        display.setCursor(x + kPadding, y + kPadding + lineIndex * lineHeight);
        display.print(line);

        index = lineEnd;
        lineIndex++;
    }
}

}  // namespace GigaSeq
