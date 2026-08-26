#include "TrackSpec.h"

TrackSpec& TrackSpec::withProgramChange(uint8_t program, tick_t tick)
{
    programChanges_.push_back({ tick, program });
    return *this;
}


TrackSpec& TrackSpec::withCC(uint8_t controller, uint8_t value, tick_t tick)
{
    controlChanges_.push_back({ tick, controller, value });
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
    muteEvents_.push_back({ tick, mute });
    return *this;
}

TrackSpec& TrackSpec::withNote(uint8_t pitch, uint8_t velocity, tick_t tick, tick_t duration)
{
    notes_.push_back({ tick, duration, { pitch, velocity } });
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
