#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"
#include "WaterSamples.h"

namespace WaterPatterns
{

constexpr PatternStep kWaterHatsSteps[] = {
    _NO_STEP,
    {{Water::wtrHat}, 55, 1},
    {{Water::wtrHat}, 127, 1},
    {{Water::wtrHat}, 55, 1},
};

MAKE_PATTERN(kWaterHats, kWaterHatsSteps, 16);

constexpr PatternStep kWaterFreakSteps[] = {
    _NO_STEP,
    {{Eb1}, 127, 1},
    _NO_STEP,
    {{Eb1}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kWaterFreak, kWaterFreakSteps, 16);

constexpr PatternStep kWaterBassSteps[] = {
    _NO_STEP,
    _NO_STEP,
    {{Eb2}, 127, 1},
    {{Eb2}, 127, 1},
};

MAKE_PATTERN(kWaterBass, kWaterBassSteps, 16);

constexpr PatternStep kWaterXmasSteps[] = {
    _NO_STEP,
    _NO_STEP,
    {{Water::wtrXmas}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    {{Water::wtrXmas}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    {{Water::wtrXmas}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    {{Water::wtrXmas}, 60, 1},
    {{Water::wtrXmas}, 127, 1},
    _NO_STEP,
};

MAKE_PATTERN(kWaterXmas, kWaterXmasSteps, 16);

constexpr PatternStep kWaterCongasSteps[] = {
    _NO_STEP,
    {{Water::wtrCg1}, 55, 1},
    {{Water::wtrCg2}, 127, 1},
    {{Water::wtrCg2}, 112, 1},
    {{Water::wtrCg2}, 45, 1},
    {{Water::wtrCg2}, 30, 1},
    {{Water::wtrCg1}, 112, 1},
    {{Water::wtrCg1}, 28, 1},
};

MAKE_PATTERN(kWaterCongas, kWaterCongasSteps, 16);

constexpr PatternStep kWaterBalafonSteps[] = {
    {{Water::wtrBlf1}, 127, 1},
    {{Water::wtrBlf2}, 127, 1},
    {{Water::wtrBlf3}, 127, 1},
};

MAKE_PATTERN(kWaterBalafon, kWaterBalafonSteps, 16);

constexpr PatternStep kWaterShakesSteps[] = {
    _NO_STEP,
    {{Water::wtrShk}, 55, 1},
    {{Water::wtrShk}, 127, 1},
    {{Water::wtrShk}, 55, 1},
};

MAKE_PATTERN(kWaterShakes, kWaterShakesSteps, 16);

constexpr PatternStep kWaterMarimbaSteps[] = {
    {{Water::wtrMarimba}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kWaterMarimba, kWaterMarimbaSteps, 1);

constexpr PatternStep kWaterClavesSteps[] = {
    _NO_STEP,
    {{Water::wtrClverb}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kWaterClaves, kWaterClavesSteps, 4);

#define FMBASS_MOTIF_GD \
    _NO_STEP, _NO_STEP, {{Water::fmbassgd}, 127, 1}, {{Water::fmbassgd}, 127, 1}, \
    {{Water::fmbassad}, 127, 1}, {{Water::fmbassad}, 127, 1}, {{Water::fmbasscd}, 127, 1}, {{Water::fmbasscd}, 127, 1}

#define FMBASS_MOTIF_CD \
    _NO_STEP, _NO_STEP, {{Water::fmbasscd}, 127, 1}, {{Water::fmbasscd}, 127, 1}, \
    {{Water::fmbassad}, 127, 1}, {{Water::fmbassad}, 127, 1}, {{Water::fmbasscd}, 127, 1}, {{Water::fmbasscd}, 127, 1}

#define FMBASS_24_EMPTY \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP

#define FMBASS_HALF_GD \
    FMBASS_24_EMPTY, FMBASS_MOTIF_GD

#define FMBASS_HALF_CD \
    FMBASS_24_EMPTY, FMBASS_MOTIF_CD

constexpr PatternStep kWaterFmbassSteps[] = {
    FMBASS_HALF_GD,
    FMBASS_HALF_GD,
    FMBASS_HALF_CD,
    FMBASS_HALF_GD,
};

MAKE_PATTERN(kWaterFmbass, kWaterFmbassSteps, 16);

constexpr PatternStep kWaterChorusBFreakSteps[] = {
    STEP(Gd2), STEP(Dd3), STEP(F3)
};

MAKE_PATTERN(kWaterChorusBFreak, kWaterChorusBFreakSteps, 16);

#undef FMBASS_MOTIF_GD
#undef FMBASS_MOTIF_CD
#undef FMBASS_24_EMPTY
#undef FMBASS_HALF_GD
#undef FMBASS_HALF_CD


} // namespace WaterPatterns
