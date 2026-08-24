#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace UandiPatterns
{

constexpr PatternStep kUandiArpSteps[] = {
    {{C3}, 127, 1},
};

MAKE_PATTERN(kUandiArp, kUandiArpSteps, 16);


constexpr PatternStep kUandiBassASteps[] = {
    _NO_STEP, _NO_STEP, STEP(Cd4), STEP(Cd4),
    STEP(Cd3), STEP(D1), STEP(Cd3), _NO_STEP,
    STEP(D3), STEP(D3), STEP(D1), STEP(Fd2), 
    _NO_STEP, STEP(D1), _NO_STEP, STEP(A2), 
    
    _NO_STEP, _NO_STEP, STEP(Cd3), _NO_STEP, 
    STEP(Cd3), _NO_STEP, _NO_STEP, _NO_STEP, 
    _NO_STEP, STEP(A2), STEP(Cd2), STEP(D2),
    STEP(Fd2), STEP(Cd3), STEP(D5), STEP(Cd5),

    _NO_STEP, _NO_STEP, STEP(D1), _NO_STEP,
    _NO_STEP, STEP(D1), _NO_STEP, _NO_STEP,
    STEP(Fd2), _NO_STEP, _NO_STEP, STEP(A2),
    _NO_STEP, _NO_STEP, STEP(A2), _NO_STEP,

    _NO_STEP, STEP(D1), _NO_STEP, _NO_STEP,
    STEP(D1), _NO_STEP, _NO_STEP, STEP(D1),
    _NO_STEP, STEP(Cd3), STEP(D1), STEP(Fd2),
    STEP(A2), _NO_STEP, STEP(Cd2), _NO_STEP
};

MAKE_PATTERN(kUandiBassA, kUandiBassASteps, 16);


constexpr PatternStep kUandiBassbSteps[] = {
    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP,     
    STEP(Dd3), STEP(Gd2), STEP(E2), STEP(E4),

    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP, 
    STEP(Dd3), STEP(Gd2), _NO_STEP, STEP(E2),

    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP,     
    STEP(Dd3), STEP(Gd2), STEP(E2), STEP(E4),

    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, 
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP, 
    STEP(Dd3), STEP(Gd2), _NO_STEP, _NO_STEP,
};

MAKE_PATTERN(kUandiBassb, kUandiBassbSteps, 16);


constexpr PatternStep kUandiFreakSteps[] = {
    STEP(D3),
    STEP(D4),
    STEP(D5),
    STEP(D6),
};

MAKE_PATTERN(kUandiFreak, kUandiFreakSteps, 16);

} // namespace UandiPatterns
