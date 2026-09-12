#pragma once

#include <cstdint>

namespace DrumMachine {

#define _DM_CC(ccName, nbr) constexpr uint8_t  k##ccName##_cc = nbr

_DM_CC(MuteAll, 80);
_DM_CC(ClearAll, 82);
_DM_CC(PerformMode, 10);
_DM_CC(RepeatMode, 11);

#undef _DM_CC

}