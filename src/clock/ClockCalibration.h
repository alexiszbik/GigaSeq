#pragma once

#include <cstdint>

namespace GigaSeq {

// Positive: the Giga crystal runs fast (measured BPM is higher than requested).
// Keep at 0 to measure, then set:
//   ppm = (measuredBpm - requestedBpm) / requestedBpm * 1'000'000
static constexpr int32_t kHardwareClockPpmFast = 80;

}  // namespace GigaSeq
