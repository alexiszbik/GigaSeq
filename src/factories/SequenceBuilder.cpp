#include "SequenceBuilder.h"

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<SequenceBuilderData> buildersData)
{
    Sequence sequence(name, tempo, barCount, beatsPerBar, barLoop, isLooping);
    const tick_t length = sequence.lengthInTicks();

    for (const auto& b : buildersData) {
        sequence.addTrack(b.builder(length));

        SequenceTrack& t = sequence.lastTrack();

        if (b.startAsMuted) {
            t.setStartMuted();
        }
        if (b.hasProgramChange) {
            t.addProgramChange(0, b.programChange);
        }
        for (const CCPair& cc : b.controlChanges) {
            t.addControlChange(0, cc.control, cc.value);
        }
    }

    return sequence;
}

void addProgramChangeTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    uint8_t value)
{
    SequenceTrack track(name, channel);
    track.addProgramChange(0, value);
    sequence.addTrack(track);
}

void addControlChangesTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    std::vector<CCPair> controlChanges)
{
    SequenceTrack track(name, channel);
    for (const CCPair& cc : controlChanges) {
        track.addControlChange(0, cc.control, cc.value);
    }
    sequence.addTrack(track);
}
