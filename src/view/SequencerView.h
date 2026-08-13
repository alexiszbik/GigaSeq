#pragma once

#include <Arduino_GigaDisplay_GFX.h>

namespace GigaSeq
{

    class SequencerView
    {
    public:
        void begin(GigaDisplay_GFX &display);
        void drawStaticLayout();
        void updatePosition(uint16_t bar, uint8_t beat, uint8_t tick);
        void drawTrack(uint8_t trackIndex, const char *text, bool state);

    private:

        GigaDisplay_GFX *display_ = nullptr;

        static constexpr int kWidth = 800;
        static constexpr int kHeight = 480;
        static constexpr int kTracksHeight = 380;
        static constexpr int kColCount = 4;
        static constexpr int kTrackCount = 16;
        static constexpr uint8_t kTrackTextSize = 3;
        static constexpr uint8_t kCharsPerLine = 9;
        static constexpr uint8_t kHeaderTextSize = 5;
        static constexpr int kPositionX = kWidth / 2;
        static constexpr int kPositionWidth = 210;
        static constexpr int kHeaderHeight = 40;
    };

} // namespace GigaSeq
