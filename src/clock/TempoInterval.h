#pragma once

#include <cstdint>

namespace GigaSeq {

// Bresenham spreader for tick periods. The us ticker only accepts whole
// microseconds; this yields floor/ceil intervals so the long-term average
// matches 60e6 / (bpm * PPQN), including optional crystal PPM correction.
class TempoInterval {
public:
    explicit TempoInterval(uint16_t bpm = 120);

    void reset(uint16_t bpm);
    uint32_t next();

private:
    uint32_t baseUs_ = 0;
    uint32_t ticksPerMinute_ = 1;
    uint32_t remainderUs_ = 0;
    uint32_t errorUs_ = 0;
};

}  // namespace GigaSeq
