#pragma once

#include <cstdint>

namespace Microfreak {
#define _MF_PRESET(preset, nbr) constexpr uint8_t k##preset = nbr - 1


_MF_PRESET(FriendshipArp, 1);
_MF_PRESET(TiredArp, 3);

_MF_PRESET(FantasyStabs, 12);
_MF_PRESET(FallingHarp, 13);

_MF_PRESET(FriendshipChords, 33);
_MF_PRESET(UandI, 34);
_MF_PRESET(UandIDust, 41);

_MF_PRESET(WaterArp, 36);

_MF_PRESET(TiredBass, 37);

_MF_PRESET(WaterBass, 44);
_MF_PRESET(Wind, 45);

_MF_PRESET(BiBimBap, 47);

_MF_PRESET(TogetherLead, 52);

_MF_PRESET(FriendshipTrance, 67);

_MF_PRESET(Rizup, 72);

_MF_PRESET(CloserHouse, 95);
_MF_PRESET(CloserChords, 104);

}

