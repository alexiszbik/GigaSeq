#pragma once

#include "Tick.h"

class TickHelper {
public:
    static constexpr tick_t kTicksPerQuarterNote = 96;
    static constexpr tick_t kOneBarTick4_4 = kTicksPerQuarterNote * 4;
    static constexpr tick_t kStepLen = kTicksPerQuarterNote/4;

    static tick_t tickTime(uint8_t bar, uint8_t quarter = 0, uint8_t step = 0) {
        return bar*kOneBarTick4_4 + quarter*kTicksPerQuarterNote + step*kStepLen;
    }

};

#define TICK(var...) tickTime(var)