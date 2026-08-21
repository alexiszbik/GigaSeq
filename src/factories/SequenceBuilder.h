#pragma once

#include "Sequence.h"
#include "SequenceTrack.h"
#include "TrackSpec.h"

#include <vector>

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<TrackSpec> tracks);

void addProgramChangeTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    uint8_t value);

void addControlChangesTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    std::vector<CCPair> controlChanges);
