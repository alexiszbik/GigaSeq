#pragma once

#include <cstdint>

namespace Bass {
#define _BASS_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr

// FX part
_BASS_CC(GlobalMute, 80);



}

