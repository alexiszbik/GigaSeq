#pragma once

#include <cstdint>

namespace PolySynth {
#define _POLY_PRESET(preset, nbr) constexpr uint8_t k##preset = nbr - 1
#define _POLY_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr

_POLY_PRESET(TogetherChords, 2);
_POLY_PRESET(WaterSqr, 3);
_POLY_PRESET(SlowStr, 4);
_POLY_PRESET(FilterStr, 5);
_POLY_PRESET(BigLead, 6);
_POLY_PRESET(Rave, 7);
_POLY_PRESET(TiredEnd, 8);
_POLY_PRESET(FallingEnd, 9);
_POLY_PRESET(Closer, 12);
_POLY_PRESET(FantasyChords, 16);


// Synth part
_POLY_CC(PlayMode, 10);
_POLY_CC(Glide, 11);
_POLY_CC(Volume, 12);
_POLY_CC(OscWaveformA, 13);
_POLY_CC(OscOctaveA, 14);
_POLY_CC(OscWaveformB, 15);
_POLY_CC(OscTuneB, 16);
_POLY_CC(OscNoise, 17);
_POLY_CC(OscMix, 18);
_POLY_CC(FilterCutoff, 19);
_POLY_CC(FilterRes, 20);
_POLY_CC(FilterEnv, 21);
_POLY_CC(Attack, 22);
_POLY_CC(Decay, 23);
_POLY_CC(Sustain, 24);
_POLY_CC(HighPass, 25);
_POLY_CC(LfoTypeA, 26);
_POLY_CC(LfoDestinationA, 27);
_POLY_CC(LfoRateA, 28);
_POLY_CC(LfoAmountA, 29);
_POLY_CC(LfoTypeB, 30);
_POLY_CC(LfoDestinationB, 31);
_POLY_CC(LfoRateB, 32);
_POLY_CC(LfoAmountB, 33);
_POLY_CC(GlobalOctave, 34);

// FX part
_POLY_CC(GlobalMute, 80);



}

