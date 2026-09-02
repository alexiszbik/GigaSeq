#pragma once

#include <cstdint>

namespace HXStomp {
#define _HX_PRESET(preset, nbr, letter) constexpr uint8_t k##preset = ((nbr - 1) * 3 + letter)
#define _HX_CC(preset, ccName, nbr) constexpr uint8_t  k##preset##_cc##ccName = nbr

#define A 0
#define B 1
#define C 2

_HX_PRESET(BiBimBapSolo, 2, B);
_HX_CC(BiBimBapSolo, Drive, 10);
_HX_CC(BiBimBapSolo, Gain, 11);
_HX_CC(BiBimBapSolo, Pitch, 12);

_HX_PRESET(BiBimBapIntro, 2, C);

_HX_PRESET(Water, 4, B);

_HX_PRESET(UandI, 5, C);
_HX_CC(UandI, Drive, 19);
_HX_CC(UandI, Shifter, 12);
_HX_CC(UandI, Reverb, 10);


_HX_PRESET(TiredDelay, 6, A);
_HX_PRESET(TiredSlicer, 6, B);
_HX_PRESET(TiredEndA, 6, C);
_HX_PRESET(TiredEndB, 7, A);

_HX_PRESET(Falling, 9, B);

_HX_PRESET(FantasySolo, 10, A);

_HX_PRESET(Bass, 11, B);

_HX_PRESET(CloserBassDisto, 12, C);

_HX_PRESET(TogetherChorus, 13, C);
_HX_CC(TogetherChorus, Drive, 15);
_HX_CC(TogetherChorus, Volume, 21);

_HX_PRESET(TogetherEnd, 14, A);

_HX_PRESET(Friendship, 14, B);


#undef A 
#undef B 
#undef C 
}

