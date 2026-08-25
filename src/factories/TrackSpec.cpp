#include "TrackSpec.h"

TrackSpec& TrackSpec::withCC(uint8_t control, uint8_t value, tick_t tick)
{
    controlChanges_.push_back({control, value, tick});
    return *this;
}

TrackSpec& TrackSpec::withCCs(std::vector<CCPair> controlChanges)
{
    controlChanges_ = std::move(controlChanges);
    return *this;
}

TrackSpec& TrackSpec::withAutomation(
    tick_t startTick,
    tick_t endTick,
    uint8_t controller,
    uint8_t startValue,
    uint8_t endValue)
{
    controlAutomations_.push_back({
        startTick,
        endTick,
        controller,
        startValue,
        endValue,
    });
    return *this;
}

TrackSpec& TrackSpec::withMuteEvent(tick_t tick, bool mute)
{
    muteEvents_.push_back({tick, mute});
    return *this;
}

TrackSpec& TrackSpec::asFill()
{
    isFill_ = true;
    return *this;
}

TrackSpec& TrackSpec::withLength(tick_t tick)
{
    customLength_ = tick;
    hasCustomLength_ = true;
    return *this;
}

TrackSpec& TrackSpec::withStart(tick_t start)
{
    startInTicks_ = start;
    hasCustomStart_ = true;
    return *this;
}

TrackSpec& TrackSpec::withPitchOffset(int offset)
{
    pitchOffset_ = offset;
    hasPitchOffset_ = true;
    return *this;
}
