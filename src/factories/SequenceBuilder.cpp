#include "SequenceBuilder.h"

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<TrackSpec> tracks)
{
    Sequence sequence(name, tempo, barCount, beatsPerBar, barLoop, isLooping);
    const tick_t length = sequence.lengthInTicks();

    for (const TrackSpec& spec : tracks) {
        tick_t trackLength = length;
        if (spec.hasCustomLength()) {
            trackLength = spec.customLength();
        }

        sequence.addTrack(spec.builder()(trackLength));

        SequenceTrack& t = sequence.lastTrack();

        if (spec.startMuted()) {
            t.setStartMuted();
        }
        if (spec.hasProgramChange()) {
            t.addProgramChange(0, spec.programChange());
        }
        for (const CCPair& cc : spec.controlChanges()) {
            t.addControlChange(0, cc.control, cc.value);
        }
        for (tick_t tick : spec.muteEvents()) {
            t.addMuteEvent(tick);
        }
        if (spec.isFill()) {
            t.setFill();
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
