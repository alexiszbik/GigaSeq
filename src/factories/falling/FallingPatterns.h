#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace FallingPatterns
{
constexpr uint8_t hatC = 40;
constexpr uint8_t hatO = 42;

constexpr PatternStep kFallingHatsSteps[] = {
    _NO_STEP,
    {1, {hatC}, 127, 1},
    {2, {hatC, hatO}, 127, 1},
    {1, {hatC}, 127, 1},

    {1, {hatC}, 90, 1},
    _NO_STEP,
    {1, {hatO}, 127, 1},
    _NO_STEP,

    _NO_STEP,
    {1, {hatC}, 127, 1},
    {2, {hatC, hatO}, 127, 1},
    {1, {hatC}, 127, 1},

    _NO_STEP,
    _NO_STEP,
    {1, {hatO}, 127, 1},
    _NO_STEP,
};

MAKE_PATTERN(kFallingHats, kFallingHatsSteps, 16);

} // namespace FallingPatterns
