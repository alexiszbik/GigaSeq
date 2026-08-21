#pragma once

#include "Note.h"
#include "Tick.h"

#include <cstdint>

static constexpr tick_t kPatternTicksPerQuarterNote = 96;
static constexpr tick_t kPatternTicksPerBar = kPatternTicksPerQuarterNote * 4;

static constexpr uint8_t kMaxNotesPerPatternStep = 4;

struct PatternStep
{
    uint8_t noteCount = 0;
    Note notes[kMaxNotesPerPatternStep] = {};
    uint8_t durationMul = 1;
};

#define _NO_STEP {0, {}, 1}

#define MAKE_PATTERN(NAME, STEPS_ARRAY, RATE) \
constexpr TrackPattern NAME = { \
    STEPS_ARRAY, \
    sizeof(STEPS_ARRAY) / sizeof(STEPS_ARRAY[0]), \
    RATE \
};

struct TrackPattern
{
    const PatternStep* steps = nullptr;
    uint16_t stepCount = 0;
    uint8_t rate = 4;
};

inline tick_t patternStepDuration(const TrackPattern& pattern)
{
    if (pattern.rate == 0) {
        return 0;
    }
    return kPatternTicksPerBar / pattern.rate;
}
