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
        if (spec.hasProgramChange()) {
            t.addProgramChange(spec.programChange().tick, spec.programChange().program);
        }
        for (const CCPair& cc : spec.controlChanges()) {
            t.addControlChange(cc.tick, cc.control, cc.value);
        }
        for (const ControlAutomation& automation : spec.controlAutomations()) {
            t.addControlAutomation(
                automation.startTick,
                automation.endTick,
                automation.controller,
                automation.startValue,
                automation.endValue);
        }
        for (MuteEvent e : spec.muteEvents()) {
            t.addMuteEvent(e.tick, e.mute);
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
        track.addControlChange(cc.tick, cc.control, cc.value);
    }
    sequence.addTrack(track);
}
