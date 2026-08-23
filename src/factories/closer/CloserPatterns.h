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

constexpr uint8_t sing = Closer::triSing;

constexpr uint8_t topA = Closer::tricotTop;
constexpr uint8_t topB = Closer::tricotTop2;

constexpr uint8_t dsnr = Closer::discoSnr;
constexpr uint8_t cymb = Closer::triBlast;
constexpr uint8_t openhat = Closer::avHat;

constexpr uint8_t tb = Closer::tri303;

constexpr uint8_t songGroove = 6;

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


constexpr PatternStep kCloserModularSteps[] = {
    _NO_STEP,
    _NO_STEP,
    STEP(E3),
    _NO_STEP,

    STEP(Dd3),
    _NO_STEP,
    STEP(Gd2), 
    STEP(B2),

    _NO_STEP,
    STEP(Cd3),
    _NO_STEP, 
    _NO_STEP,

    STEP(B2),
    _NO_STEP,
    STEP(Gd3),
    _NO_STEP,

    _NO_STEP,
    _NO_STEP,
    STEP(E3),
    _NO_STEP,

    STEP(Dd3),
    _NO_STEP,
    STEP(Gd2), 
    STEP(B2),

    _NO_STEP,
    STEP(Gd3),
    _NO_STEP,
    _NO_STEP,

    STEP(Cd3),
    _NO_STEP, 
    STEP(Dd3),
    _NO_STEP, 
};

MAKE_PATTERN(kCloserModular, kCloserModularSteps, 16);


constexpr PatternStep kCloserChordsSteps[] = {
    {{A3, Cd4, A2, E4 }, 127, 2},
    _NO_STEP, 

    {{Fd2, Cd4, E4, A3 }, 127, 2},
    _NO_STEP, 

    {{E2, B3, Gd3, E4  }, 127, 2},
    _NO_STEP, 

    {{Cd2, Cd4, E4, Gd3 }, 127, 2},
    _NO_STEP, 
};

MAKE_PATTERN(kCloserChords, kCloserChordsSteps, 1);


constexpr PatternStep kCloserSingSteps[] = {
    {{sing}, 127, 2},
    _NO_STEP, 
};

MAKE_PATTERN(kCloserSing, kCloserSingSteps, 1);


constexpr PatternStep kCloserTopSteps[] = {
    {{topA}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP, 

    {{dsnr}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP, 


    {{topA}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP, 

    {{dsnr}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP,

    {{topA}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP, 

    {{dsnr}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP,

    {{topB}, 127, 1},
    {{dsnr}, 127, 1}, 
    _NO_STEP, 
    _NO_STEP, 

    {{dsnr}, 127, 1},
    _NO_STEP, 
    _NO_STEP, 
    _NO_STEP,
};

MAKE_PATTERN(kCloserTop, kCloserTopSteps, 16);


constexpr PatternStep kCloserBlastCymbSteps[] = {
    {{cymb}, 127, 1},
    {{openhat}, 127, 1},
};

MAKE_PATTERN(kCloserBlastCymb, kCloserBlastCymbSteps, 8);


} // namespace CloserPatterns
