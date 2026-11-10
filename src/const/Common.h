#pragma once

#include <cstdint>

namespace Common {

#define _COMMON_CC(ccName, nbr) constexpr uint8_t  k##ccName##_cc = nbr

_COMMON_CC(Tempo, 10);

#undef _COMMON_CC

}