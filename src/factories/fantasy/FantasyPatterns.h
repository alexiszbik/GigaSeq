#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace FantasyPatterns
{

constexpr PatternStep kFantasyArpSteps[] = {
    {{C3}, 127, 1},
};

MAKE_PATTERN(kFantasyArp, kFantasyArpSteps, 16);

} // namespace FantasyPatterns
