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

        updatePosition(1, 1, 0);

        for (uint8_t trackIndex = 0; trackIndex < kTrackCount; trackIndex++)
        {
            drawTrack(trackIndex);
        }
    }

    void SequencerView::updatePosition(uint16_t bar, uint8_t beat, uint8_t tick)
    {
        if (!display_)
        {
            return;
        }

        char positionText[16];
        snprintf(positionText, sizeof(positionText), "%u.%u.%02u", bar, beat, tick);

        display_->fillRect(kPositionX, 0, kPositionWidth, kHeaderHeight, kBlack);
        display_->setTextSize(kHeaderTextSize);
        display_->setTextColor(kWhite);
        display_->setCursor(kPositionX, 0);
        display_->print(positionText);
    }

    void SequencerView::setTrackLabel(uint8_t trackIndex, const char *text)
    {
        if (trackIndex >= kTrackCount)
        {
            return;
        }

        trackLabels_[trackIndex] = text;
        drawTrack(trackIndex);
    }

    void SequencerView::drawTrack(uint8_t trackIndex)
    {
        if (!display_ || trackIndex >= kTrackCount)
        {
            return;
        }

        const int tracksY = kHeight - kTracksHeight;
        const int trackW = kWidth / kColCount;
        const int trackH = kTracksHeight / kColCount;

        const uint8_t col = trackIndex % kColCount;
        const uint8_t row = trackIndex / kColCount;
        const int x = col * trackW;
        const int y = tracksY + row * trackH;

        display_->drawRect(x, y, trackW, trackH, kWhite);

        const char *label = trackLabels_[trackIndex];
        if (label && label[0] != '\0')
        {
            printTextInRect(*display_, x, y, trackW, trackH, label, kTrackTextSize, kCharsPerLine);
        }
    }

} // namespace GigaSeq
