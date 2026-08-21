#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"

namespace WaterPatterns
{

constexpr PatternStep kWaterHatsSteps[] = {
    _NO_STEP,
    {1, {{40, 55}}, 1},
    {1, {{40, 127}}, 1},
    {1, {{40, 55}}, 1},
};

MAKE_PATTERN(kWaterHats, kWaterHatsSteps, 16);

constexpr PatternStep kWaterFreakSteps[] = {
    _NO_STEP,
    {1, {{Eb1, 127}}, 1},
    _NO_STEP,
    {1, {{Eb1, 127}}, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kWaterFreak, kWaterFreakSteps, 16);

constexpr PatternStep kWaterBassSteps[] = {
    _NO_STEP,
    _NO_STEP,
    {1, {{Eb2, 127}}, 1},
    {1, {{Eb2, 127}}, 1},
};

MAKE_PATTERN(kWaterBass, kWaterBassSteps, 16);

constexpr PatternStep kWaterXmasSteps[] = {
    _NO_STEP,
    _NO_STEP,
    {1, {{A2, 127}}, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    {1, {{A2, 127}}, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    {1, {{A2, 127}}, 1},
    _NO_STEP,
    _NO_STEP,
    {1, {{A2, 60}}, 1},
    {1, {{A2, 127}}, 1},
    _NO_STEP,
};

MAKE_PATTERN(kWaterXmas, kWaterXmasSteps, 16);

constexpr PatternStep kWaterCongasSteps[] = {
    _NO_STEP,
    {1, {{43, 55}}, 1},
    {1, {{44, 127}}, 1},
    {1, {{44, 112}}, 1},
    {1, {{44, 45}}, 1},
    {1, {{44, 30}}, 1},
    {1, {{43, 112}}, 1},
    {1, {{43, 28}}, 1},
};

MAKE_PATTERN(kWaterCongas, kWaterCongasSteps, 16);

constexpr PatternStep kWaterBalafonSteps[] = {
    {1, {{D3, 127}}, 1},
    {1, {{Dd3, 127}}, 1},
    {1, {{E3, 127}}, 1},
};

MAKE_PATTERN(kWaterBalafon, kWaterBalafonSteps, 16);

constexpr PatternStep kWaterShakesSteps[] = {
    _NO_STEP,
    {1, {{F1, 55}}, 1},
    {1, {{F1, 127}}, 1},
    {1, {{F1, 55}}, 1},
};

MAKE_PATTERN(kWaterShakes, kWaterShakesSteps, 16);

constexpr PatternStep kWaterMarimbaSteps[] = {
    {1, {{G2, 127}}, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kWaterMarimba, kWaterMarimbaSteps, 1);

constexpr PatternStep kWaterClavesSteps[] = {
    _NO_STEP,
    {1, {{46, 127}}, 1},
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
    _NO_STEP, _NO_STEP, {1, {{Gd2, 127}}, 1}, {1, {{Gd2, 127}}, 1}, \
    {1, {{Ad2, 127}}, 1}, {1, {{Ad2, 127}}, 1}, {1, {{Cd3, 127}}, 1}, {1, {{Cd3, 127}}, 1}

#define FMBASS_MOTIF_CD \
    _NO_STEP, _NO_STEP, {1, {{Cd3, 127}}, 1}, {1, {{Cd3, 127}}, 1}, \
    {1, {{Ad2, 127}}, 1}, {1, {{Ad2, 127}}, 1}, {1, {{Cd3, 127}}, 1}, {1, {{Cd3, 127}}, 1}

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

#undef FMBASS_MOTIF_GD
#undef FMBASS_MOTIF_CD
#undef FMBASS_24_EMPTY
#undef FMBASS_HALF_GD
#undef FMBASS_HALF_CD

} // namespace WaterPatterns
