#pragma once

#include "TrackPattern.h"

namespace DrumPatterns
{
constexpr PatternStep kKickFourSteps[] = {
    {{36}, 127, 1},
};

MAKE_PATTERN(kKickFour, kKickFourSteps, 4);

constexpr PatternStep kSnareFourSteps[] = {
    _NO_STEP,
    {{38}, 127, 1},
    _NO_STEP,
    {{38}, 127, 1},
};

MAKE_PATTERN(kSnareFour, kSnareFourSteps, 4);

} // namespace DrumPatterns
