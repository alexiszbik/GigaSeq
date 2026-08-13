#pragma once

#include "MyDisplay.h"

#include <cstdint>

namespace GigaSeq
{
    enum class ViewActionType : uint8_t
    {
        None,
        DrawStaticLayout,
        UpdateSequenceName,
        UpdatePosition,
        DrawTrack,
    };

    struct ViewAction
    {
        ViewActionType type = ViewActionType::None;
        uint8_t trackIndex = 0;
        bool state = false;
        uint16_t bar = 0;
        uint8_t beat = 0;
        char text[31] = {0};
    };

    class SequencerView
    {
    public:
        void begin(MyDisplay &display);
        void drawStaticLayout();
        void updateSequenceName(const char *name);
        void updatePosition(uint16_t bar, uint8_t beat);
        void drawTrack(uint8_t trackIndex, const char *text, bool state);

        // Execute one queued action. Returns true if an action was executed.
        bool processOne();

    private:
        void enqueueAction(const ViewAction &action);
        void copyActionText(char *dest, const char *src);

        void executeDrawStaticLayout();
        void executeUpdateSequenceName(const char *name);
        void executeUpdatePosition(uint16_t bar, uint8_t beat);
        void executeDrawTrack(uint8_t trackIndex, const char *text, bool state);

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
        static constexpr int kSequenceNameWidth = 12 * kHeaderCaracSize;
        static constexpr int kPositionX = kWidth / 2;
        static constexpr int kPositionWidth = 280;
        static constexpr int kHeaderHeight = 40;

        static constexpr uint8_t kQueueCapacity = 32;
        ViewAction queue_[kQueueCapacity];
        uint8_t queueHead_ = 0;
        uint8_t queueTail_ = 0;
        uint8_t queueCount_ = 0;

        bool disable = false;
    };

} // namespace GigaSeq
