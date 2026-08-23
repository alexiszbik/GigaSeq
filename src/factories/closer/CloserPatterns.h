#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace CloserPatterns
{

constexpr PatternStep kCloserArpSteps[] = {
    {{C3}, 127, 1},
};

MAKE_PATTERN(kCloserArp, kCloserArpSteps, 16);

} // namespace CloserPatterns
