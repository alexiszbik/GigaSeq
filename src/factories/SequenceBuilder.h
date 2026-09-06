#pragma once

#include "Sequence.h"
#include "SequenceTrack.h"
#include "TrackSpec.h"

#include "OutMidiRules.h"

#include <vector>

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<TrackSpec> tracks,
    OutMidiRules* outMidiRules = nullptr);

void addProgramChangeTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    uint8_t value);

void addControlChangesTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    std::vector<ControlChange> controlChanges);
