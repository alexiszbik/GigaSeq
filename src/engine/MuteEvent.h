#pragma once

#include "Tick.h"

#include <cstdint>

struct MuteEvent
{
    tick_t tick = 0;
    bool mute = true;
};
