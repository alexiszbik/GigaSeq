#include "SequencerView.h"

#include "TextBox.h"

#include <cstdio>
#include <cstring>

namespace GigaSeq
{

    namespace
    {
        constexpr uint16_t kBlack = 0x0000;
        constexpr uint16_t kWhite = 0xFFFF;
    }

    void SequencerView::begin(GigaDisplay_GFX &display)
    {
        display_ = &display;
        display_->fillScreen(kBlack);
        display_->setTextColor(kWhite);
    }

    void SequencerView::drawStaticLayout()
    {
        if (!display_)
        {
            return;
        }

        display_->setTextSize(kHeaderTextSize);
        display_->setCursor(0, 0);
        display_->print("Sequence 01");

        updatePosition(1, 1);
    }

    void SequencerView::updatePosition(uint16_t bar, uint8_t beat)
    {
        if (!display_)
        {
            return;
        }

        char positionText[16];
        snprintf(positionText, sizeof(positionText), "%u.%u", bar, beat);

        display_->fillRect(kPositionX, 0, kPositionWidth, kHeaderHeight, kBlack);
        display_->setTextSize(kHeaderTextSize);
        display_->setTextColor(kWhite);
        display_->setCursor(kPositionX, 0);
        display_->print(positionText);
    }

    void SequencerView::drawTrack(uint8_t trackIndex, const char *text, bool state)
    {
        if (!display_ || trackIndex >= kTrackCount)
        {
            return;
        }

        display_->setTextColor(state ? kBlack : kWhite);

        const int tracksY = kHeight - kTracksHeight;
        const int trackW = kWidth / kColCount;
        const int trackH = kTracksHeight / kColCount;

        const uint8_t col = trackIndex % kColCount;
        const uint8_t row = kColCount - 1 - (trackIndex / kColCount);
        const int x = col * trackW;
        const int y = tracksY + row * trackH;

        if (state) {
            display_->fillRect(x, y, trackW, trackH, kWhite);
        } else {
            display_->fillRect(x, y, trackW, trackH, kBlack);
            display_->drawRect(x, y, trackW, trackH, kWhite);
        }

        const char *label = text;
        if (label && label[0] != '\0')
        {
            printTextInRect(*display_, x, y, trackW, trackH, label, kTrackTextSize, kCharsPerLine);
        }
    }

} // namespace GigaSeq
