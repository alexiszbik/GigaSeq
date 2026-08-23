#pragma once

#include "SequenceTrack.h"
#include "Tick.h"

#include <cstdint>
#include <vector>

struct SequenceDesc
{
    std::vector<std::vector<uint8_t>> notes;
    std::vector<uint8_t> velocities;
    std::vector<uint8_t> durations;
    double rate = 4;
    uint8_t groove = 0;
};

void makeSequenceTrack(
    SequenceTrack& track,
    const SequenceDesc& desc,
    tick_t lengthInTicks,
    tick_t startTick = 0);
