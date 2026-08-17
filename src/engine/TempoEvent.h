#pragma once

#include "Tick.h"

#include <cstdint>

struct TempoEvent
{
    tick_t tick = 0;
    uint8_t bpm = 120;
};
