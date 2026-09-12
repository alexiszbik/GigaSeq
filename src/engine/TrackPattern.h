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

#define MAKE_PATTERN_GROOVE(NAME, STEPS_ARRAY, GROOVE) \
constexpr TrackPattern NAME = { \
    STEPS_ARRAY, \
    sizeof(STEPS_ARRAY) / sizeof(STEPS_ARRAY[0]), \
    kPatternGrooveRate, \
    GROOVE \
};

static constexpr uint8_t kPatternGrooveStraight = 0;
static constexpr uint8_t kPatternGrooveMax = 25;
static constexpr uint8_t kPatternGrooveRate = 16;

struct TrackPattern
{
    const PatternStep* steps = nullptr;
    uint16_t stepCount = 0;
    uint8_t rate = 4;
    uint8_t groove = kPatternGrooveStraight;
};

inline uint8_t patternEffectiveGroove(uint8_t rate, uint8_t groove) noexcept
{
    return rate == kPatternGrooveRate ? groove : kPatternGrooveStraight;
}

inline tick_t patternStepGrooveOffset(
    tick_t stepDuration,
    uint8_t groove) noexcept
{
    return static_cast<tick_t>(
        (static_cast<uint32_t>(groove) * stepDuration + 25) / 50);
}

inline tick_t patternStepDuration(const TrackPattern& pattern)
{
    return TickHelper::kOneBarTick4_4 / pattern.rate;
}
