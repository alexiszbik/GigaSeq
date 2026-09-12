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

void addOutMidiRules(Sequence& sequence, OutMidiRules* rules);

void addInMidiRules(Sequence& sequence, InMidiRules* rules, int8_t transposeSemitones = 0);

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
