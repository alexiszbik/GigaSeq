#pragma once

#include "TrackPattern.h"
#include "factories/MidiNotes.h"
#include "WaterSamples.h"
#include "MidiConst.h"

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

#define SEQ_EMPTY \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP, \
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP

#define FMBASS_HALF_GD \
    SEQ_EMPTY, FMBASS_MOTIF_GD

#define FMBASS_HALF_CD \
    SEQ_EMPTY, FMBASS_MOTIF_CD

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

#undef FMBASS_HALF_GD
#undef FMBASS_HALF_CD

//TODO : something more random here !
//We could use an arp for that

constexpr PatternStep kWaterMatrixSteps[] = {
    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedMatrix::kWater_osc_squareA_note}}, {{LedMatrix::kWater_osc_squareD_note}}, 
    {{LedMatrix::kWater_osc_squareB_note}}, {{LedMatrix::kWater_osc_squareC_note}}, 
    {{LedMatrix::kWater_osc_squareA_note}}, {{LedMatrix::kWater_osc_squareB_note}}, 

    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedMatrix::kWater_osc_squareB_note}}, {{LedMatrix::kWater_osc_squareA_note}}, 
    {{LedMatrix::kWater_osc_squareD_note}}, {{LedMatrix::kWater_osc_squareA_note}}, 
    {{LedMatrix::kWater_osc_squareC_note}}, {{LedMatrix::kWater_osc_squareB_note}}, 

    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedMatrix::kWater_osc_squareD_note}}, {{LedMatrix::kWater_osc_squareA_note}}, 
    {{LedMatrix::kWater_osc_squareC_note}}, {{LedMatrix::kWater_osc_squareD_note}}, 
    {{LedMatrix::kWater_osc_squareB_note}}, {{LedMatrix::kWater_osc_squareA_note}}, 

    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedMatrix::kWater_osc_squareB_note}}, {{LedMatrix::kWater_osc_squareC_note}}, 
    {{LedMatrix::kWater_osc_squareB_note}}, {{LedMatrix::kWater_osc_squareA_note}}, 
    {{LedMatrix::kWater_osc_squareD_note}}, {{LedMatrix::kWater_osc_squareC_note}}, 
};

MAKE_PATTERN(kWaterMatrix, kWaterMatrixSteps, 16);


constexpr PatternStep kWaterLedPatternSteps[] = {
    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedStrips::kWhite_A}}, {{LedStrips::kWhite_B}}, 
    {{LedStrips::kWhite_D}}, {{LedStrips::kWhite_A}}, 
    {{LedStrips::kWhite_D}}, {{LedStrips::kWhite_C}}, 

    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedStrips::kWhite_A}}, {{LedStrips::kWhite_C}}, 
    {{LedStrips::kWhite_B}}, {{LedStrips::kWhite_A}}, 
    {{LedStrips::kWhite_C}}, {{LedStrips::kWhite_D}}, 

    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedStrips::kWhite_C}}, {{LedStrips::kWhite_D}}, 
    {{LedStrips::kWhite_A}}, {{LedStrips::kWhite_C}}, 
    {{LedStrips::kWhite_B}}, {{LedStrips::kWhite_D}}, 

    SEQ_EMPTY, _NO_STEP, _NO_STEP,
    {{LedStrips::kWhite_B}}, {{LedStrips::kWhite_A}}, 
    {{LedStrips::kWhite_D}}, {{LedStrips::kWhite_B}}, 
    {{LedStrips::kWhite_A}}, {{LedStrips::kWhite_C}}, 
};

MAKE_PATTERN(kWaterLedPattern, kWaterLedPatternSteps, 16);



constexpr PatternStep kWaterCyanBlinkSteps[] = {
    _NO_STEP,
    {{LedStrips::kBlue_C, LedStrips::kGreen_C}, 127, 1},
    _NO_STEP,
    {{LedStrips::kBlue_C, LedStrips::kGreen_C}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kWaterCyanBlink, kWaterCyanBlinkSteps, 16);

} // namespace WaterPatterns

#undef SEQ_EMPTY