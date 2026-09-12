#pragma once

#include "Tick.h"

#include <cstdint>

struct Note
{
    uint8_t note = 0;
    uint8_t velocity = 0;
};

struct ScheduledNote
{
    tick_t tick = 0;
    tick_t durationTicks = 0;
    Note note;
};
