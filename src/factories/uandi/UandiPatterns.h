#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace UandiPatterns
{

constexpr PatternStep kUandiArpSteps[] = {
    {{C3}, 127, 1},
};

MAKE_PATTERN(kUandiArp, kUandiArpSteps, 16);

#define UANDI_BASS_A \
\
    _NO_STEP, _NO_STEP, STEP(Cd4), STEP(Cd4), \
    STEP(Cd3), STEP(D1), STEP(Cd3), _NO_STEP, \
    STEP(D3), STEP(D3), STEP(D1), STEP(Fd2), \
    _NO_STEP, STEP(D1), _NO_STEP, STEP(A2), \
\
    _NO_STEP, _NO_STEP, STEP(Cd3), _NO_STEP, \
    STEP(Cd3), _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, STEP(A2), STEP(Cd2), STEP(D2), \
    STEP(Fd2), STEP(Cd3), STEP(D5), STEP(Cd5), \
\
    _NO_STEP, _NO_STEP, STEP(D1), _NO_STEP, \
    _NO_STEP, STEP(D1), _NO_STEP, _NO_STEP, \
    STEP(Fd2), _NO_STEP, _NO_STEP, STEP(A2), \
    _NO_STEP, _NO_STEP, STEP(A2), _NO_STEP, \
\
    _NO_STEP, STEP(D1), _NO_STEP, _NO_STEP, \
    STEP(D1), _NO_STEP, _NO_STEP, STEP(D1), \
    _NO_STEP, STEP(Cd3), STEP(D1), STEP(Fd2), \
    STEP(A2), _NO_STEP, STEP(Cd2), _NO_STEP 

constexpr PatternStep kUandiBassASteps[] = {
    UANDI_BASS_A
};

MAKE_PATTERN(kUandiBassA, kUandiBassASteps, 16);

#define UANDI_BASS_B \
\
    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP, \
    STEP(Dd3), STEP(Gd2), STEP(E2), STEP(E4), \
\
    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP, \
    STEP(Dd3), STEP(Gd2), _NO_STEP, STEP(E2), \
\
    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP, \
    STEP(Dd3), STEP(Gd2), STEP(E2), STEP(E4), \
\
    _NO_STEP, _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E1), _NO_STEP, \
    STEP(E1), _NO_STEP, STEP(E3), _NO_STEP, \
    STEP(Dd3), STEP(Gd2), _NO_STEP, _NO_STEP 

constexpr PatternStep kUandiBassbSteps[] = {
    UANDI_BASS_B
};

MAKE_PATTERN(kUandiBassb, kUandiBassbSteps, 16);


constexpr PatternStep kUandiFreakSteps[] = {
    STEP(D3),
    STEP(D4),
    STEP(D5),
    STEP(D6),
};

MAKE_PATTERN(kUandiFreak, kUandiFreakSteps, 16);


constexpr PatternStep kUandiDiscoABSteps[] = {
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),

    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),
    STEP(Uandi::uaiVo2), STEP(Uandi::uaiVo2),

    STEP(Uandi::uaiVo1), STEP(Uandi::uaiVo1),
    STEP(Uandi::uaiVo1), STEP(Uandi::uaiVo1),
    STEP(Uandi::uaiVo1), STEP(Uandi::uaiVo1),
    STEP(Uandi::uaiVo1), STEP(Uandi::uaiVo1),
};

MAKE_PATTERN(kUandiDiscoAB, kUandiDiscoABSteps, 2);


constexpr PatternStep kUandiDiscoBSteps[] = {
    {{Uandi::uaiVo1}, 127, 1},
};

MAKE_PATTERN(kUandiDiscoB, kUandiDiscoBSteps, 2);


constexpr PatternStep kUandiBassABSteps[] = {
    UANDI_BASS_A, UANDI_BASS_A, UANDI_BASS_B
};

MAKE_PATTERN(kUandiBassAB, kUandiBassABSteps, 16);

#undef UANDI_BASS_A
#undef UANDI_BASS_B


constexpr PatternStep kUandiOpenHatSteps[] = {
    STEP(Uandi::uaiOh)
};

MAKE_PATTERN(kUandiOpenHat, kUandiOpenHatSteps, 4);


constexpr PatternStep kUandiShakerSteps[] = {
    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,
    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,
    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,
    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,

    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,
    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,
    _NO_STEP, STEP(Uandi::uaiShk), STEP(Uandi::uaiShk), _NO_STEP,
    _NO_STEP, _NO_STEP, STEP(Uandi::uaiShk), _NO_STEP,
};

MAKE_PATTERN(kUandiShaker, kUandiShakerSteps, 16);


constexpr PatternStep kUandiRimFillSteps[] = {
    {{Uandi::sst}, 127, 1},
};

MAKE_PATTERN(kUandiRimFill, kUandiRimFillSteps, 16);

} // namespace UandiPatterns
