#pragma once

#include "MyDisplay.h"

namespace GigaSeq
{
    class SequencerView
    {
    public:
        void begin(MyDisplay &display);
        void drawStaticLayout();
        void updateSequenceName(const char *name);
        void updatePosition(uint16_t bar, uint8_t beat);
        void drawTrack(uint8_t trackIndex, const char *text, bool state);

    private:

        MyDisplay *display_ = nullptr;

        static constexpr int kWidth = 800;
        static constexpr int kHeight = 480;
        static constexpr int kTracksHeight = 380;
        static constexpr int kColCount = 4;
        static constexpr int kTrackCount = 16;
        static constexpr uint8_t kTrackTextSize = 3;
        static constexpr uint8_t kCharsPerLine = 10;
        static constexpr uint8_t kHeaderTextSize = 5;
        static constexpr int kHeaderCaracSize = 30;
        static constexpr int kSequenceNameWidth = 12*kHeaderCaracSize;
        static constexpr int kPositionX = kWidth / 2;
        static constexpr int kPositionWidth = 280;
        static constexpr int kHeaderHeight = 40;

        bool disable = false;
    };

} // namespace GigaSeq
