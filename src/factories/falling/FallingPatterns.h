#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace FallingPatterns
{
constexpr uint8_t hatC = 40;
constexpr uint8_t hatO = 42;

constexpr uint8_t pads = 66;
constexpr uint8_t kick = 36;

constexpr uint8_t handTamb = 54;

//constexpr uint8_t riz = 52;
//constexpr uint8_t bigClap = 39;

constexpr uint8_t tamb = 43;
constexpr uint8_t ride = 51;

constexpr PatternStep kFallingHatsSteps[] = {
    _NO_STEP,
    {{hatC}, 127, 1},
    {{hatC, hatO}, 127, 1},
    {{hatC}, 127, 1},

    {{hatC}, 90, 1},
    _NO_STEP,
    {{hatO}, 127, 1},
    _NO_STEP,

    _NO_STEP,
    {{hatC}, 127, 1},
    {{hatC, hatO}, 127, 1},
    {{hatC}, 127, 1},

    _NO_STEP,
    _NO_STEP,
    {{hatO}, 127, 1},
    _NO_STEP,
};

MAKE_PATTERN(kFallingHats, kFallingHatsSteps, 16);


constexpr PatternStep kFallingPadsSteps[] = {
    {{pads}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kFallingPads, kFallingPadsSteps, 1);


#define KICK_STEP {{kick}, 127, 1}

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

#define NOTE(pitch) {{pitch}, 127, 1}

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

constexpr PatternStep kFallingHarpSteps[] = {
    NOTE(Fd2),
    NOTE(A2 ),
    NOTE(Cd3), 
    NOTE(A2 ),
    NOTE(Cd3), 
    NOTE(E3 ),
    NOTE(Cd3), 
    NOTE(E3 ),
    NOTE(Fd3), 
    NOTE(E3 ),
    NOTE(Fd3), 
    NOTE(A3 ),
    NOTE(Fd3), 
    NOTE(A3 ),
    NOTE(Cd4), 
    NOTE(A3 ),
    NOTE(Cd4), 
    NOTE(E4 ),
    NOTE(Cd4), 
    NOTE(E4 ),
    NOTE(Fd4), 
    NOTE(E4 ),
    NOTE(Fd4), 
    NOTE(A4 ),
    NOTE(Fd4), 
    NOTE(A4 ),
    NOTE(Cd5), 
    NOTE(A4 ),
    NOTE(Cd5), 
    NOTE(E5 ),
    NOTE(Cd5), 
    NOTE(E5 ),
    NOTE(Fd5), 
    NOTE(Fd4), 
    NOTE(Fd5), 
    NOTE(A5 ),
    NOTE(Fd5), 
    NOTE(A5 ),
    NOTE(Cd6), 
    NOTE(A5 ),
    NOTE(Cd6), 
    NOTE(E6 ),
    NOTE(Cd6), 
    NOTE(A5 ),
    NOTE(Cd6), 
    NOTE(A5 ),
    NOTE(Fd5), 
    NOTE(A5 ),
    NOTE(Fd5), 
    NOTE(E5 ),
    NOTE(Fd5), 
    NOTE(E5 ),
    NOTE(Cd5), 
    NOTE(E5 ),
    NOTE(Cd5), 
    NOTE(A4 ),
    NOTE(Cd5), 
    NOTE(A4 ),
    NOTE(Fd4), 
    NOTE(A4 ),
    NOTE(Fd4), 
    NOTE(E4 ),
    NOTE(Fd4), 
    NOTE(E4 )
};

MAKE_PATTERN(kFallingHarp, kFallingHarpSteps, 16);

#define TAMB_STEP {{tamb}, 127, 1}

constexpr PatternStep kFallingTambourinSteps[] = {
    _NO_STEP,
    TAMB_STEP,
    TAMB_STEP,
    _NO_STEP,

    TAMB_STEP,
    _NO_STEP,
    TAMB_STEP,
    _NO_STEP,

    TAMB_STEP,
    _NO_STEP,
    TAMB_STEP,
    _NO_STEP,

    TAMB_STEP,
    TAMB_STEP,
    _NO_STEP,
    TAMB_STEP
};

MAKE_PATTERN(kFallingTambourin, kFallingTambourinSteps, 16);


constexpr PatternStep kFallingHandTambSteps[] = {
    {{handTamb}, 127, 1},
};

MAKE_PATTERN(kFallingHandTamb, kFallingHandTambSteps, 1);

#undef KICK_STEP
#undef NOTE

} // namespace FallingPatterns
