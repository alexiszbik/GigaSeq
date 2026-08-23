#pragma once

#include "Tick.h"

class TickHelper {
public:
    static constexpr tick_t kTicksPerQuarterNote = 96;
    static constexpr tick_t kOneBarTick4_4 = kTicksPerQuarterNote * 4;
    static constexpr tick_t kStepLen = kTicksPerQuarterNote / 4;
    static constexpr tick_t kTicksPerEighthNote = kTicksPerQuarterNote / 2;

    static constexpr tick_t bars(uint8_t count) noexcept
    {
        return count * kOneBarTick4_4;
    }

    static constexpr tick_t quarters(uint8_t count) noexcept
    {
        return count * kTicksPerQuarterNote;
    }

    static constexpr tick_t tickTime(uint8_t bar, uint8_t quarter = 0, uint8_t step = 0) noexcept
    {
        return bar * kOneBarTick4_4 + quarter * kTicksPerQuarterNote + step * kStepLen;
    }
};

#define TICK(...) TickHelper::tickTime(__VA_ARGS__)
