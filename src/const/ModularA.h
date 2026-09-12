#pragma once

#include <cstdint>

namespace ModularA {
#define _MODULAR_A_CC(ccName, nbr) constexpr uint8_t  k##ccName##_cc = nbr

_MODULAR_A_CC(MuteClock, 60);
_MODULAR_A_CC(GlobalMute, 80);
}

