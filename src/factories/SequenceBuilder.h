#pragma once

#include "Sequence.h"
#include "SequenceTrack.h"

#include <cstdint>
#include <vector>

using TrackBuilder = SequenceTrack (*)(tick_t lengthInTicks);

struct CCPair
{
    uint8_t control;
    uint8_t value;
};

struct SequenceBuilderData {
    TrackBuilder builder;
    bool startAsMuted = false;

    bool hasProgramChange = false;
    uint8_t programChange;
    std::vector<CCPair> controlChanges;

    SequenceBuilderData(TrackBuilder builder, bool startAsMuted = false, std::vector<CCPair> controlChanges = {}) 
    : builder(builder), startAsMuted(startAsMuted), controlChanges(controlChanges) {};

    SequenceBuilderData(TrackBuilder builder, bool startAsMuted, std::vector<CCPair> controlChanges, uint8_t programChange) 
    : builder(builder), startAsMuted(startAsMuted), controlChanges(controlChanges), programChange(programChange) {
        hasProgramChange = true;
    };
};

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<SequenceBuilderData> buildersData);

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
