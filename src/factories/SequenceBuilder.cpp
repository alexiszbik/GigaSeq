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

        tick_t startInTicks = 0;
        if (spec.hasCustomStart()) {
            startInTicks = spec.startInTicks();
        }

        sequence.addTrack(spec.builder()(trackLength, startInTicks));

        SequenceTrack& t = sequence.lastTrack();

        if (spec.startMuted()) {
            t.setStartMuted();
        }
        for (const ProgramChange& change : spec.programChanges()) {
            t.addProgramChange(change);
        }
        for (const ControlChange& change : spec.controlChanges()) {
            t.addControlChange(change);
        }
        for (const ControlAutomation& automation : spec.controlAutomations()) {
            t.addControlAutomation(
                automation.startTick,
                automation.endTick,
                automation.controller,
                automation.startValue,
                automation.endValue);
        }
        for (const MuteEvent& event : spec.muteEvents()) {
            t.addMuteEvent(event);
        }
        for (const ScheduledNote& note : spec.notes()) {
            t.addNote(note.tick, note.durationTicks, note.note.note, note.note.velocity);
        }
        if (spec.isFill()) {
            t.setFill();
        }
        if (spec.hasPitchOffset()) {
            t.setPitchOffset(spec.pitchOffset());
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
    track.addProgramChange({ 0, value });
    sequence.addTrack(track);
}

void addControlChangesTrack(
    Sequence& sequence,
    const char* name,
    uint8_t channel,
    std::vector<ControlChange> controlChanges)
{
    SequenceTrack track(name, channel);
    for (const ControlChange& change : controlChanges) {
        track.addControlChange(change);
    }
    sequence.addTrack(track);
}
