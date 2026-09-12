#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"
#include "BibimbapSamples.h"

namespace BibimbapPatterns
{

constexpr PatternStep kBibimbapArpSteps[] = {
    {{Bibimbap::bbbArp}}, {}, {}, {}, {}, {}, {},
    {}, {}, {}, {}, {}, {}, {}
};

MAKE_PATTERN(kBibimbapArp, kBibimbapArpSteps, 4);


constexpr PatternStep kBibimbapKickHiSteps[] = {
    {{Bibimbap::bbbKickhi}},
};

MAKE_PATTERN(kBibimbapKickHi, kBibimbapKickHiSteps, 4);


constexpr PatternStep kBibimbapTomSteps[] = {
    {{Bibimbap::bbbTom1}}, _NO_STEP,
    {{Bibimbap::bbbTom1}}, _NO_STEP,
    {{Bibimbap::bbbTom1}}, _NO_STEP, _NO_STEP
};

MAKE_PATTERN(kBibimbapTom, kBibimbapTomSteps, 16);

constexpr PatternStep kBibimbapTomStepsB[] = {
    {{Bibimbap::bbbTom1, Bibimbap::bbbTom2}}, _NO_STEP,
    {{Bibimbap::bbbTom1, Bibimbap::bbbTom2}}, _NO_STEP,
    {{Bibimbap::bbbTom1, Bibimbap::bbbTom2}}, _NO_STEP, _NO_STEP
};

MAKE_PATTERN(kBibimbapTomB, kBibimbapTomStepsB, 16);

constexpr PatternStep kBibimbapShakerSteps[] = {
    _NO_STEP, _NO_STEP, {{Bibimbap::bbbShake}}, _NO_STEP,
    _NO_STEP, {{Bibimbap::bbbShake}, 90}, {{Bibimbap::bbbShake}}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Bibimbap::bbbShake}}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Bibimbap::bbbShake}}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Bibimbap::bbbShake}}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Bibimbap::bbbShake}}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Bibimbap::bbbShake}}, _NO_STEP,
};

MAKE_PATTERN(kBibimbapShaker, kBibimbapShakerSteps, 16);


constexpr PatternStep kBibimbapVocalsSteps[] = {
    {{Bibimbap::bbbFleeta}}, {}, {}, {}, {}, {}, {},
    {{Bibimbap::bbbFleeta}}, {}, {}, {}, {}, {}, {},
    {{Bibimbap::bbbFleeta}}, {}, {}, {}, {}, {}, {},
    {{Bibimbap::bbbFleeta}}, {}, {}, {}, {}, {}, {},

    {{Bibimbap::bbbFleetb}}, {}, {}, {}, {}, {}, {},
    {{Bibimbap::bbbFleetb}}, {}, {}, {}, {}, {}, {},
    {{Bibimbap::bbbFleetb}}, {}, {}, {}, {}, {}, {},
    {{Bibimbap::bbbFleetb}}, {}, {}, {}, {}, {}, {},
};

MAKE_PATTERN(kBibimbapVocals, kBibimbapVocalsSteps, 4);


constexpr PatternStep kBibimbapMarimbaVerbSteps[] = {
    {{Bibimbap::bbbMrvrb}}, {}, {}, {}, {}, {}, {},
};

MAKE_PATTERN(kBibimbapMarimbaVerb, kBibimbapMarimbaVerbSteps, 8);


constexpr PatternStep kBibimbapPercsSteps[] = {
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {{Bibimbap::bbbCl}}, {}, {{Bibimbap::bbbCl}}, 
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {Bibimbap::bbbGuiro}, {},

    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {{Bibimbap::bbbCl}}, {}, {{Bibimbap::bbbCl}}, 
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {},
};

MAKE_PATTERN(kBibimbapPercs, kBibimbapPercsSteps, 16);

constexpr PatternStep kBibimbapPercsStepsB[] = {
    {}, {}, {}, {},
    {}, {Bibimbap::bbbAt1}, {}, {},
    {}, {{Bibimbap::bbbCl}}, {}, {{Bibimbap::bbbCl}}, 
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {Bibimbap::bbbGuiro,Bibimbap::bbbAt2}, {Bibimbap::bbbAt2},

    {}, {}, {}, {},
    {}, {Bibimbap::bbbAt1}, {}, {},
    {}, {{Bibimbap::bbbCl}}, {}, {{Bibimbap::bbbCl}}, 
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {Bibimbap::bbbAt2}, {Bibimbap::bbbAt2},
};

MAKE_PATTERN(kBibimbapPercsB, kBibimbapPercsStepsB, 16);

#define BASS_(note) STEP(note), _NO_STEP, STEP(note), _NO_STEP, STEP(note), _NO_STEP, _NO_STEP
#define BASS(note) BASS_(note), BASS_(note), BASS_(note), BASS_(note)

constexpr PatternStep kBibimbapBassSteps[] = {
BASS(B1),
BASS(C2),
BASS(G1),
BASS(E1),
BASS(A1),
BASS(Fd1),
BASS(G1),
BASS(D2),
};

MAKE_PATTERN(kBibimbapBass, kBibimbapBassSteps, 16);

#undef BASS
#undef BASS_


constexpr PatternStep kBibimbapHatsSteps[] = {
    {{Bibimbap::bbbHatlp}, 127, 1},
};

MAKE_PATTERN(kBibimbapHats, kBibimbapHatsSteps, 4);


constexpr PatternStep kBibimbapOpenHatSteps[] = {
    {{Bibimbap::openh}, 127, 1},
};

MAKE_PATTERN(kBibimbapOpenHat, kBibimbapOpenHatSteps, 16);


constexpr PatternStep kBibimbapFreakSteps[] = {
    {{G2}}, {}, {{G2}}, {}, {}, {{G2}}, {}
};

MAKE_PATTERN(kBibimbapFreak, kBibimbapFreakSteps, 16);

} // namespace BibimbapPatterns
