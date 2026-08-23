#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"
#include "CloserSamples.h"

namespace CloserPatterns
{
constexpr uint8_t hat = Closer::triH909;
constexpr uint8_t loopHat = Closer::triHat;
constexpr uint8_t tambA = Closer::triTamb1;
constexpr uint8_t tambB = Closer::triTamb2;

constexpr uint8_t clap = Closer::triClp;
constexpr uint8_t but = Closer::triBut;
constexpr uint8_t distom = Closer::triTomdist;
constexpr uint8_t voice = Closer::triVoi;
constexpr uint8_t tom808 = Closer::tri808tom;

constexpr uint8_t songGroove = 5;

constexpr PatternStep kCloserHatSteps[] = {
    {{hat}, 50, 1},
    {{hat}, 92, 1},
    {{hat}, 127, 1},
    {{hat}, 92, 1},
};

MAKE_PATTERN_GROOVE(kCloserHat, kCloserHatSteps, songGroove);


constexpr PatternStep kCloserLoopHatSteps[] = {
    {{loopHat}, 127, 1},
};

MAKE_PATTERN(kCloserLoopHat, kCloserLoopHatSteps, 1);


constexpr PatternStep kCloserTambourinSteps[] = {
    {{tambA}, 127, 1},
    {{tambA}, 127, 1},
    {{tambB}, 127, 1},
    {{tambA}, 127, 1},
};

MAKE_PATTERN(kCloserTambourin, kCloserTambourinSteps, 4);


constexpr PatternStep kCloserClapTomSteps[] = {
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, STEP(but),

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, STEP(distom), _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, STEP(but),

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, STEP(voice), _NO_STEP,
    STEP(clap), _NO_STEP, _NO_STEP, STEP(tom808),
};

MAKE_PATTERN_GROOVE(kCloserClapTom, kCloserClapTomSteps, songGroove);

} // namespace CloserPatterns
