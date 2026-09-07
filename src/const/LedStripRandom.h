#pragma once

#include <cstdint>

class LedStripRandom
{
public:
    constexpr LedStripRandom(const uint8_t* notes, uint8_t count)
        : notes_(notes), count_(count) {}

    uint8_t nextRandom() const;

private:
    const uint8_t* notes_;
    uint8_t count_;
};
