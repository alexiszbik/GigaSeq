#pragma once

#include <cstdint>

namespace BossRC
{
#define _BOSS_PRESET(preset, nbr) constexpr uint8_t k##preset = nbr - 1
#define _BOSS_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr

_BOSS_PRESET(Fantasy, 18);

_BOSS_PRESET(TogetherA, 19);
_BOSS_PRESET(TogetherB, 20);

_BOSS_PRESET(Closer, 23);

_BOSS_PRESET(Tired, 25);

_BOSS_PRESET(TiredEnd, 26);

_BOSS_PRESET(Friendship, 27);

_BOSS_PRESET(Water, 28);

_BOSS_PRESET(BiBimBap, 29);

_BOSS_CC(Volume, 82);
_BOSS_CC(Erase, 80);

} // namespace MidiChannel