#pragma once

#include "TrackPattern.h"
#include "FantasySamples.h"
#include "factories/MidiNotes.h"

namespace FantasyPatterns
{

constexpr uint8_t snr = Fantasy::fant909;
constexpr uint8_t sample = Fantasy::ftsySample;

constexpr uint8_t kk = Fantasy::ftsyKick;
constexpr uint8_t clp = Fantasy::ftsyClp;
constexpr uint8_t hh = Fantasy::ftsyHat;
constexpr uint8_t shk = Fantasy::ftsyShake;

constexpr uint8_t v1 = Fantasy::fantVoc1;
constexpr uint8_t v2 = Fantasy::fantVoc2;
constexpr uint8_t v3 = Fantasy::fantVoc3;
constexpr uint8_t v4 = Fantasy::fantVoc4;
constexpr uint8_t v5 = Fantasy::fantVoc5;

constexpr uint8_t bgClp = Fantasy::fantBigclp;

constexpr PatternStep kFantasyArpSteps[] = {
    STEP(C2), STEP(E2), STEP(C3), STEP(B2), STEP(G2), STEP(C3), STEP(E2), STEP(G2),
    STEP(E3), STEP(C3), STEP(B2), STEP(E3), STEP(G2), STEP(B2), STEP(Fd3), STEP(D3),
    STEP(G3), STEP(B2), STEP(D3), STEP(B3), STEP(G3), STEP(Fd3), STEP(B3), STEP(D3),
    STEP(Fd3), STEP(D3), STEP(B3), STEP(Fd3), STEP(G3), STEP(B3), STEP(B2), STEP(A3),
    STEP(C3), STEP(E3), STEP(A3), STEP(B2), STEP(A2), STEP(E3), STEP(B2), STEP(C3),
    STEP(E3), STEP(A2), STEP(E2), STEP(C3), STEP(A2), STEP(B2), STEP(E2), STEP(D2),
    STEP(E2), STEP(D3), STEP(B2), STEP(G2), STEP(D3), STEP(E2), STEP(G2), STEP(E3),
    STEP(D3), STEP(B2), STEP(E3), STEP(G2), STEP(B2), STEP(G3), STEP(E3), STEP(G3),
    STEP(B2), STEP(C3), STEP(B3), STEP(G3), STEP(E3), STEP(B3), STEP(C3), STEP(E3),
    STEP(C3), STEP(B3), STEP(E3), STEP(G3), STEP(B3), STEP(C3), STEP(B2), STEP(D3),
    STEP(Fd3), STEP(G3), STEP(B2), STEP(G2), STEP(Fd3), STEP(B2), STEP(D3), STEP(Fd3),
    STEP(G2), STEP(Fd2), STEP(D3), STEP(G2), STEP(B2), STEP(D3), STEP(C2), STEP(E2),
    STEP(C3), STEP(B2), STEP(A2), STEP(C3), STEP(E2), STEP(A2), STEP(E3), STEP(C3),
    STEP(B2), STEP(E3), STEP(A2), STEP(B2), STEP(A3), STEP(E3), STEP(C3), STEP(B2),
    STEP(D3), STEP(B3), STEP(G3), STEP(E3), STEP(B3), STEP(D3), STEP(E3), STEP(D3),
    STEP(B3), STEP(E3), STEP(G3), STEP(B3), STEP(D3), STEP(B2), STEP(G3), STEP(E3),
    STEP(G3), STEP(B2), STEP(G2), STEP(E3), STEP(B2), STEP(C3), STEP(E3), STEP(G2),
    STEP(E2), STEP(C3), STEP(G2), STEP(B2), STEP(C3), STEP(E2), STEP(C2), STEP(D3),
    STEP(B2), STEP(G2), STEP(D3), STEP(Fd2), STEP(G2), STEP(Fd3), STEP(D3), STEP(B2),
    STEP(Fd3), STEP(G2), STEP(B2), STEP(G3), STEP(Fd3), STEP(D3), STEP(B2), STEP(C3),
    STEP(B3), STEP(A3), STEP(E3), STEP(B3), STEP(C3), STEP(E3), STEP(C3), STEP(B3),
    STEP(E3), STEP(A3), STEP(B3), STEP(C3), STEP(B2), STEP(A3), STEP(C3), STEP(G3),
    STEP(B2), STEP(G2), STEP(E3), STEP(B2), STEP(D3), STEP(E3), STEP(G2), STEP(E2),
    STEP(D3), STEP(G2), STEP(B2), STEP(D3), STEP(E2), STEP(D2), STEP(E2), STEP(B2),
};

MAKE_PATTERN(kFantasyArp, kFantasyArpSteps, 16);


constexpr PatternStep kFantasySnare909Steps[] = {
    {{snr}, 127, 1},
};

MAKE_PATTERN(kFantasySnare909, kFantasySnare909Steps, 16);

constexpr PatternStep kFantasySampleSteps[] = {
    {{sample}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kFantasySample, kFantasySampleSteps, 1);


constexpr PatternStep kFantasyDrumsSteps[] = {
    STEP(kk), STEP(hh),
    STEP(kk, clp), STEP(hh),
};

MAKE_PATTERN(kFantasyDrums, kFantasyDrumsSteps, 8);


constexpr PatternStep kFantasyShakeSteps[] = {
    {{shk}, 127, 1},
    {{shk}, 80, 1},
};

MAKE_PATTERN(kFantasyShake, kFantasyShakeSteps, 8);

#define _NO_STEPx6 \
_NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP  

#define _NO_STEPx7 \
_NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP    

#define _NO_STEPx8 \
_NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP     

constexpr PatternStep kFantasyChordsSteps[] = {
    {{G3, B3, E3, C3}, 127, 7}, _NO_STEPx6,
    {{A3, B3, Fd3, D3}, 127, 8}, _NO_STEPx7,
    {{A3, B3, E3, C3}, 127, 8}, _NO_STEPx7,
    {{G3, B3, E3, D3}, 127, 9}, _NO_STEPx8
    
};

MAKE_PATTERN(kFantasyChords, kFantasyChordsSteps, 8);

#define FREAK_STEP {{D3, G3, A3}, 127, 1}

constexpr PatternStep kFantasyFreakSteps[] = {
    _NO_STEP, _NO_STEP, FREAK_STEP, _NO_STEP, 
    FREAK_STEP, FREAK_STEP
};

MAKE_PATTERN(kFantasyFreak, kFantasyFreakSteps, 16);

#undef FREAK_STEP
#undef _NO_STEPx6
#undef _NO_STEPx7
#undef _NO_STEPx8


constexpr PatternStep kFantasyVocalsSteps[] = {
    STEP(v1), _NO_STEP,
    _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP,
    STEP(v2), _NO_STEP,

    _NO_STEP, _NO_STEP,
    STEP(v3), _NO_STEP,
    _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP,

    STEP(v5), _NO_STEP,
    _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP,
    STEP(v2), _NO_STEP,

    _NO_STEP, _NO_STEP,
    STEP(v3), _NO_STEP,
    _NO_STEP, STEP(v4),
    _NO_STEP, _NO_STEP,
};

MAKE_PATTERN(kFantasyVocals, kFantasyVocalsSteps, 8);


constexpr PatternStep kFantasyBigClapSteps[] = {
    _NO_STEP,
    {{bgClp}, 127, 1},
};

MAKE_PATTERN(kFantasyBigClap, kFantasyBigClapSteps, 4);


constexpr PatternStep kFantasyShakeEndSteps[] = {
    _NO_STEP,
    {{Fantasy::fminishake}, 127, 1},
};

MAKE_PATTERN(kFantasyShakeEnd, kFantasyShakeEndSteps, 8);

} // namespace FantasyPatterns
