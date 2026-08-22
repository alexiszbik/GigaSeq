#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace FallingPatterns
{
constexpr uint8_t hatC = 40;
constexpr uint8_t hatO = 42;

constexpr uint8_t pads = 66;
constexpr uint8_t kick = 36;

constexpr uint8_t riz = 52;

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


constexpr PatternStep kFallingPadsSteps[] = {
    {1, {pads}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kFallingPads, kFallingPadsSteps, 1);


#define KICK_STEP {1, {kick}, 127, 1}

constexpr PatternStep kFallingKickSteps[] = {
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, KICK_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, KICK_STEP,
    KICK_STEP, _NO_STEP, KICK_STEP, _NO_STEP,
};

MAKE_PATTERN(kFallingKick, kFallingKickSteps, 16);

#define NOTE(pitch) {1, {pitch}, 127, 1}

constexpr PatternStep kFallingBassSteps[] = {
    NOTE(Fd1),
    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,

    _NO_STEP,
    NOTE(Fd1),
    NOTE(Gd4),
    NOTE(Gd2),

    NOTE(Fd1),
    NOTE(Gd3),
    _NO_STEP,
    _NO_STEP,

    NOTE(Fd1),
    _NO_STEP,
    NOTE(Fd2),
    NOTE(Fd1),

    _NO_STEP,
    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,

    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,
    _NO_STEP,

    NOTE(Fd1),
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,

    NOTE(Fd1),
    _NO_STEP,
    NOTE(Fd2),
    NOTE(Fd1),

    _NO_STEP,
    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,

    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,
    _NO_STEP,

    NOTE(Fd1),
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,

    NOTE(Fd1),
    _NO_STEP,
    NOTE(Fd2),
    NOTE(Fd1),

    _NO_STEP,
    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,

    _NO_STEP,
    NOTE(Fd1),
    _NO_STEP,
    _NO_STEP,

    NOTE(Fd1),
    _NO_STEP,
    _NO_STEP,
    NOTE(Fd1),

    NOTE(Fd2),
    _NO_STEP,
    NOTE(A2), 
    _NO_STEP
};

MAKE_PATTERN(kFallingBass, kFallingBassSteps, 16);

} // namespace FallingPatterns

#undef KICK_STEP
