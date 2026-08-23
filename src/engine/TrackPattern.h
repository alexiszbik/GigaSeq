#pragma once

#include "Tick.h"
#include "TickHelper.h"

#include <cstdint>

static constexpr uint8_t kMaxNotesPerPatternStep = 4;

// notes[] is a zero-terminated pitch list (0 = end / empty step; MIDI note 0 is not used).
struct PatternStep
{
    uint8_t notes[kMaxNotesPerPatternStep] = {};
    uint8_t velocity = 127;
    uint8_t durationMul = 1;
};

#define _NO_STEP {{}, 127, 1}
#define STEP(notes...) {{ notes }, 127, 1}

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
    return TickHelper::kOneBarTick4_4 / pattern.rate;
}
