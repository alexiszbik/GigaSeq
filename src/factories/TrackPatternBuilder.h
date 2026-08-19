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
};

void makeSequenceTrack(
    SequenceTrack& track,
    const SequenceDesc& desc,
    tick_t lengthInTicks,
    tick_t startTick = 0);

void makeAutomationTrack(
    SequenceTrack& track,
    tick_t startInTicks,
    tick_t endInTicks,
    uint8_t controller,
    uint8_t startValue,
    uint8_t endValue);
