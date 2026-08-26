#pragma once

#include <cstdint>

namespace PolySynth {
#define _POLY_PRESET(preset, nbr) constexpr uint8_t k##preset = nbr - 1

_POLY_PRESET(TogetherChords, 2);
_POLY_PRESET(WaterSqr, 3);
_POLY_PRESET(SlowStr, 4);
_POLY_PRESET(FilterStr, 5);
_POLY_PRESET(BigLead, 6);
_POLY_PRESET(FallingEnd, 9);

}

