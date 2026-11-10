#pragma once

#include <cstdint>

namespace Sampler {

#define _SAMPLER_CC(ccName, nbr) constexpr uint8_t k##ccName##_cc = nbr

_SAMPLER_CC(SamplerRepeatState, 8);
_SAMPLER_CC(DrumsRepeatState, 9);
_SAMPLER_CC(SamplerRepeatRate, 10);
_SAMPLER_CC(SamplerBitCrushRate, 11);
_SAMPLER_CC(SamplerHiPass, 12);
_SAMPLER_CC(SamplerLowPass, 13);
_SAMPLER_CC(SamplerFlangerSpeed, 14);
_SAMPLER_CC(SamplerFlangerLevel, 15);
_SAMPLER_CC(HatsFlangerLevel, 16);
_SAMPLER_CC(HatsFlangerSpeed, 17);
_SAMPLER_CC(DrumsLowPass, 18);
_SAMPLER_CC(DrumsHiPass, 19);
_SAMPLER_CC(DrumsBitCrushRate, 20);
_SAMPLER_CC(DrumsRepeatRate, 21);
_SAMPLER_CC(HatsReverbSend, 30);
_SAMPLER_CC(TomsDelayLevel, 31);
_SAMPLER_CC(TomsDelayTime, 32);
_SAMPLER_CC(TomsDelayFeedback, 33);
_SAMPLER_CC(HatsVolume, 34);
_SAMPLER_CC(TomsVolume, 35);
_SAMPLER_CC(SnareVolume, 36);
_SAMPLER_CC(KickVolume, 37);
_SAMPLER_CC(SamplerVolume, 38);
_SAMPLER_CC(SamplerDelayFeedback, 39);
_SAMPLER_CC(SamplerDelayTime, 40);
_SAMPLER_CC(SamplerDelayLevel, 41);
_SAMPLER_CC(SnareReverbSend, 42);
_SAMPLER_CC(TomsDelaySync, 50);
_SAMPLER_CC(SamplerDelaySync, 51);
_SAMPLER_CC(SamplerMute, 52);
_SAMPLER_CC(KickMute, 53);
_SAMPLER_CC(SnareMute, 54);
_SAMPLER_CC(TomsMute, 55);
_SAMPLER_CC(HatsMute, 56);

_SAMPLER_CC(PanLfoAmount, 80);

#undef _SAMPLER_CC

} // namespace Sampler
