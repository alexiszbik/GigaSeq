#pragma once

#include <cstdint>

namespace Vocoder {

#define _VOCODER_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr


_VOCODER_CC(PlayMode, 10); // 0
_VOCODER_CC(Glide, 11);
_VOCODER_CC(Release, 12);
_VOCODER_CC(OscMix, 13); //89
_VOCODER_CC(OscAWaveform, 14); //127
_VOCODER_CC(OscBWaveform, 15); //0
_VOCODER_CC(OscAPwm, 16); //64
_VOCODER_CC(OscBPwm, 17); //64
/*
CC	10	Play Mode: 0 = Mono, 127 = Poly
CC	11	Glide (0–127 → parameter 0–1, squared in seconds)
CC	12	Release (0–127 → parameter 0–1, pow³ curve mapped to 0.005–8 s)
CC	13	Osc mix: balance osc A / osc B (0 = osc B, 127 = osc A, sqrt dry/wet)
CC	14	Osc A waveform: 0–63 = saw, 64–127 = square
CC	15	Osc B waveform: 0–63 = saw, 64–127 = square
CC	16	Osc A pulse width: duty cycle in square mode (0–127 → 0–1, 64 = 50 %)
CC	17	Osc B pulse width: duty cycle in square mode (0–127 → 0–1, 64 = 50 %)
    */
/*
dafault values

setParameterValue(PlayMode, 1.f); 0
setParameterValue(OscMix, 0.7f); 89
setParameterValue(OscAWaveform, 1.f); 127
setParameterValue(OscBWaveform, 0.f); 0
setParameterValue(OscAPulseWidth, 0.5f); 64
setParameterValue(OscBPulseWidth, 0.5f); 64

.withCC(Vocoder::kPlayMode, 0)
.withCC(Vocoder::kGlide, 0)
.withCC(Vocoder::kRelease, 0)
.withCC(Vocoder::kOscMix, 89)
.withCC(Vocoder::kOscAWaveform, 127)
.withCC(Vocoder::kOscBWaveform, 0)
.withCC(Vocoder::kOscAPwm, 64)
.withCC(Vocoder::kOscBPwm, 64)



with



*/   
}