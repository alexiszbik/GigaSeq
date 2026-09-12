#pragma once

#include "LedStripRandom.h"
#include "LEDStrips.h"

namespace LedStrips {

constexpr uint8_t kWhiteLeds[] = {
    kWhite_A,
    kWhite_B,
    kWhite_C,
    kWhite_D,
};

constexpr uint8_t kWhiteLedCount = sizeof(kWhiteLeds) / sizeof(kWhiteLeds[0]);

constexpr uint8_t kGreenLeds[] = {
    kGreen_A,
    kGreen_B,
    kGreen_C,
    kGreen_D,
};

constexpr uint8_t kGreenLedCount = sizeof(kGreenLeds) / sizeof(kGreenLeds[0]);

extern const LedStripRandom kWhiteLedsRandom;
extern const LedStripRandom kGreenLedsRandom;

} // namespace LedStrips
