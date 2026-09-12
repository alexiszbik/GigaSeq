#pragma once

#include <cstdint>

namespace Bass {
#define _BASS_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr

// FX part
_BASS_CC(HpfCutoff, 10);
_BASS_CC(HpfResonance, 11);
_BASS_CC(BitCrusherRate, 12);
_BASS_CC(FreqShifterAmount, 13);
_BASS_CC(FreqShifterDryWet, 14);
_BASS_CC(StutterDepth, 15);
_BASS_CC(ReverbSend, 16);
_BASS_CC(GlobalMute, 80);

}

