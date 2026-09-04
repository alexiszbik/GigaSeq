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

 void addSingleNote(
    SequenceTrack& track,
    uint8_t note,
    tick_t startTick = 0);

void makeRiser(
    SequenceTrack& track,
    uint8_t note,
    tick_t lengthInTicks,
    tick_t riserLength);

void makeRoll(
    SequenceTrack& track,
    uint8_t note,
    tick_t lengthInTicks,
    tick_t startTick,
    uint8_t startVelocity,
    uint8_t endVelocity,
    std::vector<double> velocityPattern = {1},
    uint8_t stepRatio = 16);
