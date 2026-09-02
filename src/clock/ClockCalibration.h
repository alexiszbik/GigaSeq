#pragma once

#include <cstdint>

namespace GigaSeq {

static constexpr int32_t kHardwareClockPpmFast = 195; //pas trop de diff entre 200 et 210
// pareil entre 190 et 195

inline uint32_t applyHardwareClockPpmCorrection(uint32_t intervalUs)
{
    if (kHardwareClockPpmFast == 0) {
        return intervalUs;
    }

    return static_cast<uint32_t>(
        (static_cast<uint64_t>(intervalUs) * 1'000'000u)
        / (1'000'000 - static_cast<int64_t>(kHardwareClockPpmFast)));
}

}  // namespace GigaSeq
