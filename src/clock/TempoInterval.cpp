#include "TempoInterval.h"

#include "ClockCalibration.h"
#include "TickHelper.h"

namespace GigaSeq {

namespace {

uint64_t microsecondsPerMinute()
{
    constexpr uint64_t kNominalUsPerMinute = 60'000'000ull;
    if (kHardwareClockPpmFast == 0) {
        return kNominalUsPerMinute;
    }

    const int64_t denom = 1'000'000 - static_cast<int64_t>(kHardwareClockPpmFast);
    return (kNominalUsPerMinute * 1'000'000ull) / static_cast<uint64_t>(denom);
}

}  // namespace

TempoInterval::TempoInterval(uint16_t bpm)
{
    reset(bpm);
}

void TempoInterval::reset(uint16_t bpm)
{
    ticksPerMinute_ = static_cast<uint32_t>(bpm) * TickHelper::kTicksPerQuarterNote;
    const uint64_t usPerMinute = microsecondsPerMinute();
    baseUs_ = static_cast<uint32_t>(usPerMinute / ticksPerMinute_);
    remainderUs_ = static_cast<uint32_t>(usPerMinute % ticksPerMinute_);
    errorUs_ = 0;
}

uint32_t TempoInterval::next()
{
    errorUs_ += remainderUs_;
    if (errorUs_ >= ticksPerMinute_) {
        errorUs_ -= ticksPerMinute_;
        return baseUs_ + 1;
    }
    return baseUs_;
}

}  // namespace GigaSeq
