#include "TrackSpec.h"

TrackSpec& TrackSpec::withCC(uint8_t control, uint8_t value)
{
    controlChanges_.push_back({control, value});
    return *this;
}

TrackSpec& TrackSpec::withCCs(std::vector<CCPair> controlChanges)
{
    controlChanges_ = std::move(controlChanges);
    return *this;
}

TrackSpec& TrackSpec::withMuteEvent(tick_t tick)
{
    muteEvents_.push_back(tick);
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
