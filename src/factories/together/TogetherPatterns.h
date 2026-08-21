#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace TogetherPatterns
{

#define ARP_GD_STEP \
    {1, {{Gd4, 127}}, 1}, {1, {{Gd3, 127}}, 1}, {1, {{Gd2, 127}}, 1}, {1, {{Gd3, 127}}, 1}

#define ARP_GD_BAR \
    ARP_GD_STEP, ARP_GD_STEP, ARP_GD_STEP, ARP_GD_STEP

#define ARP_GD_PHRASE \
    ARP_GD_BAR, ARP_GD_BAR, ARP_GD_BAR, ARP_GD_BAR

#define ARP_C_STEP \
    {1, {{C4, 127}}, 1}, {1, {{C3, 127}}, 1}, {1, {{C2, 127}}, 1}, {1, {{C3, 127}}, 1}

#define ARP_C_BAR \
    ARP_C_STEP, ARP_C_STEP, ARP_C_STEP, ARP_C_STEP

#define ARP_C_PHRASE \
    ARP_C_BAR, ARP_C_BAR, ARP_C_BAR, ARP_C_BAR

constexpr PatternStep kTogetherArpSteps[] = {
    ARP_GD_PHRASE,
    ARP_C_PHRASE,
};

MAKE_PATTERN(kTogetherArp, kTogetherArpSteps, 16);

#define DX7_BB2_STEP {1, {{Bb2, 127}}, 1}

#define DX7_BB2_BAR \
    DX7_BB2_STEP, DX7_BB2_STEP, DX7_BB2_STEP, DX7_BB2_STEP, \
    DX7_BB2_STEP, DX7_BB2_STEP, DX7_BB2_STEP, DX7_BB2_STEP

#define DX7_BB2_PHRASE \
    DX7_BB2_BAR, DX7_BB2_BAR, DX7_BB2_BAR, DX7_BB2_BAR, \
    DX7_BB2_BAR, DX7_BB2_BAR, DX7_BB2_BAR, DX7_BB2_BAR

#define DX7_B2_STEP {1, {{B2, 127}}, 1}

#define DX7_B2_BAR \
    DX7_B2_STEP, DX7_B2_STEP, DX7_B2_STEP, DX7_B2_STEP, \
    DX7_B2_STEP, DX7_B2_STEP, DX7_B2_STEP, DX7_B2_STEP

#define DX7_B2_PHRASE \
    DX7_B2_BAR, DX7_B2_BAR, DX7_B2_BAR, DX7_B2_BAR, \
    DX7_B2_BAR, DX7_B2_BAR, DX7_B2_BAR, DX7_B2_BAR

constexpr PatternStep kTogetherDX7Steps[] = {
    DX7_BB2_PHRASE,
    DX7_B2_PHRASE,
};

MAKE_PATTERN(kTogetherDX7, kTogetherDX7Steps, 8);

constexpr PatternStep kTogetherHiDrumSteps[] = {
    {3, {{56, 127}, {37, 127}, {40, 127}}, 1},
    {2, {{38, 127}, {40, 56}}, 1},
    {2, {{37, 127}, {40, 127}}, 1},
    {2, {{38, 127}, {40, 56}}, 1},
    {3, {{56, 127}, {37, 127}, {40, 127}}, 1},
    {2, {{38, 127}, {40, 56}}, 1},
    {2, {{37, 127}, {40, 127}}, 1},
    {2, {{38, 127}, {40, 56}}, 1},
};
MAKE_PATTERN(kTogetherHiDrum, kTogetherHiDrumSteps, 8);

constexpr PatternStep kTogetherSampleSteps[] = {
    {1, {{52, 127}}, 2},
    _NO_STEP,
    {1, {{52, 127}}, 2},
    _NO_STEP,
    {1, {{53, 127}}, 2},
    _NO_STEP,
    {1, {{53, 127}}, 2},
    _NO_STEP,
};
MAKE_PATTERN(kTogetherSample, kTogetherSampleSteps, 1);

#define _PAD12 \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP

#define SYNTH_ROW(n1, n2, n3, n4, n5, n6, n7, n8) \
    {4, {{n1, 127}, {n2, 127}, {n3, 127}, {n4, 127}}, 2}, _NO_STEP, _NO_STEP, \
    {4, {{n5, 127}, {n6, 127}, {n7, 127}, {n8, 127}}, 9}, _PAD12

constexpr PatternStep kTogetherPartBSynthSteps[] = {
    SYNTH_ROW(Ab2, C4, Eb4, Bb4, Ab2, C4, Eb4, Ab4),
    SYNTH_ROW(G2, B3, D4, Bb4, G2, B3, D4, G4),
    SYNTH_ROW(Bb2, Bb3, D4, F4, Bb2, Bb3, D4, G4),
    SYNTH_ROW(C3, C4, Eb4, Ab4, C3, C4, Eb4, G4),
};
MAKE_PATTERN(kTogetherPartBSynth, kTogetherPartBSynthSteps, 8);

#undef SYNTH_ROW
#undef _PAD12

constexpr PatternStep kTogetherPartBAhSteps[] = {
    {1, {{39, 127}}, 1},
};
MAKE_PATTERN(kTogetherPartBAh, kTogetherPartBAhSteps, 4);

constexpr PatternStep kTogetherPartBDaDaDaSteps[] = {
    {1, {{41, 127}}, 1},
    {1, {{42, 127}}, 1},
    {1, {{43, 127}}, 1},
    {1, {{42, 127}}, 1},
    {1, {{41, 127}}, 1},
    {1, {{42, 127}}, 1},
    {1, {{43, 127}}, 1},
    {1, {{43, 127}}, 1},
};
MAKE_PATTERN(kTogetherPartBDaDaDa, kTogetherPartBDaDaDaSteps, 8);

constexpr PatternStep kTogetherHatsOnlySteps[] = {
    {1, {{40, 127}}, 1},
    {1, {{40, 56}}, 1},
};
MAKE_PATTERN(kTogetherHatsOnly, kTogetherHatsOnlySteps, 8);

constexpr PatternStep kTogetherPartBTambourinSteps[] = {
    {2, {{48, 127}, {50, 127}}, 1},
};
MAKE_PATTERN(kTogetherPartBTambourin, kTogetherPartBTambourinSteps, 4);

constexpr PatternStep kTogetherPartBCymbalSteps[] = {
    {1, {{51, 127}}, 1},
    {1, {{51, 56}}, 1},
};
MAKE_PATTERN(kTogetherPartBCymbal, kTogetherPartBCymbalSteps, 8);

#undef ARP_GD_STEP
#undef ARP_GD_BAR
#undef ARP_GD_PHRASE
#undef ARP_C_STEP
#undef ARP_C_BAR
#undef ARP_C_PHRASE
#undef DX7_BB2_STEP
#undef DX7_BB2_BAR
#undef DX7_BB2_PHRASE
#undef DX7_B2_STEP
#undef DX7_B2_BAR
#undef DX7_B2_PHRASE

} // namespace TogetherPatterns
