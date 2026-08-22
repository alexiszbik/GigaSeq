#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace DummyPatterns
{

constexpr PatternStep kDummyArpSteps[] = {
    {1, {C3}, 127, 1},
};

MAKE_PATTERN(kDummyArp, kDummyArpSteps, 16);

} // namespace DummyPatterns
