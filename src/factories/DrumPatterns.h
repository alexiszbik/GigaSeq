#pragma once

#include "TrackPattern.h"

namespace DrumPatterns
{

constexpr uint8_t kick = 36;
constexpr uint8_t snare = 38;

constexpr uint8_t ride = 51;

constexpr PatternStep kKickFourSteps[] = {
    {{kick}, 127, 1},
};

MAKE_PATTERN(kKickFour, kKickFourSteps, 4);

constexpr PatternStep kSnareFourSteps[] = {
    _NO_STEP,
    {{snare}, 127, 1},
    _NO_STEP,
    {{snare}, 127, 1},
};

MAKE_PATTERN(kSnareFour, kSnareFourSteps, 4);

constexpr PatternStep kRideOffSteps[] = {
    _NO_STEP, {{ride}, 127, 1},
};

MAKE_PATTERN(kRideOff, kRideOffSteps, 8);

} // namespace DrumPatterns
