#pragma once

#include "Sequence.h"
#include "SequenceTrack.h"

#include <cstdint>
#include <vector>

using TrackBuilder = SequenceTrack (*)(tick_t lengthInTicks);

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<TrackBuilder> builders);

void addProgramChangeTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    uint8_t value);

struct CCPair
{
    uint8_t control;
    uint8_t value;
};

void addControlChangesTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    std::vector<CCPair> controlChanges);
