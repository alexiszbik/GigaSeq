#pragma once

#include "TrackPattern.h"
#include "TiredSamples.h"
#include "factories/MidiNotes.h"

namespace TiredPatterns
{


constexpr PatternStep kTiredIntroSteps[] = {
    {{Tired::tiredIntro}, 127, 1},
    _NO_STEP
};

MAKE_PATTERN(kTiredIntro, kTiredIntroSteps, 1);


constexpr PatternStep kTiredHatSoloSteps[] = {
    {{Tired::tiredSolohat}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,

    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP
};

MAKE_PATTERN(kTiredHatSolo, kTiredHatSoloSteps, 1);


constexpr PatternStep kTiredCongasSteps[] = {
    {{Tired::tiredConga}, 127, 1},
};

MAKE_PATTERN(kTiredCongas, kTiredCongasSteps, 1);


constexpr PatternStep kTiredRobotoSteps[] = {
    {{Tired::tiredPsysynth}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,

    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP
};

MAKE_PATTERN(kTiredRoboto, kTiredRobotoSteps, 1);


constexpr PatternStep kTiredHatsSteps[] = {
    {{Tired::tiredHat}, 66, 1},
    {{Tired::tiredHat}, 91, 1},
    {{Tired::tiredHat}, 127, 1},
    {{Tired::tiredHat}, 91, 1},

};

MAKE_PATTERN(kTiredHats, kTiredHatsSteps, 16);


constexpr PatternStep kTiredSyncSteps[] = {
    {{Tired::tiredSync}, 127, 1},
};

MAKE_PATTERN(kTiredSync, kTiredSyncSteps, 1);


constexpr PatternStep kTiredPhazeHatSteps[] = {
    {{Tired::tiredPhzhat}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kTiredPhazeHat, kTiredPhazeHatSteps, 1);

} // namespace TiredPatterns
