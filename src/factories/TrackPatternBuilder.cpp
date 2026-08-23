#include "TrackPatternBuilder.h"

#include "TickHelper.h"

void makeSequenceTrack(
    SequenceTrack& track,
    const SequenceDesc& desc,
    tick_t lengthInTicks,
    tick_t startTick)
{
    const int barDuration = TickHelper::kOneBarTick4_4;
    const int stepDuration = barDuration / desc.rate;

    const int seqSize = static_cast<int>(desc.notes.size());
    int seqIdx = 0;

    const int velSize = static_cast<int>(desc.velocities.size());
    int velIdx = 0;

    const int durationSize = static_cast<int>(desc.durations.size());
    int durIdx = 0;

    for (tick_t tick = startTick; tick < (startTick + lengthInTicks); tick = static_cast<tick_t>(tick + stepDuration))
    {
        int noteDuration = stepDuration;
        const std::vector<uint8_t>& stepNotes = desc.notes[seqIdx];

        uint8_t velocity = 127;
        if (velIdx < velSize) {
            velocity = desc.velocities[velIdx];
        }

        if (durIdx < durationSize) {
            noteDuration *= desc.durations[durIdx];
        }

        bool noteExists = false;

        for (uint8_t note : stepNotes) {
            track.addNote(tick, noteDuration, note, velocity);
            noteExists = true;
        }

        seqIdx = (seqIdx + 1) % seqSize;

        if (noteExists) {
            if (velSize > 0) {
                velIdx = (velIdx + 1) % velSize;
            }

            if (durationSize > 0) {
                durIdx = (durIdx + 1) % durationSize;
            }
        }
    }
}

void makeAutomationTrack(
    SequenceTrack& track,
    tick_t startInTicks,
    tick_t endInTicks,
    uint8_t controller,
    uint8_t startValue,
    uint8_t endValue)
{
    if (startInTicks > endInTicks) {
        return;
    }

    if (startInTicks == endInTicks) {
        track.addControlChange(startInTicks, controller, endValue);
        return;
    }

    const tick_t duration = endInTicks - startInTicks;
    uint8_t lastSentValue = startValue;

    track.addControlChange(startInTicks, controller, startValue);

    for (tick_t tick = startInTicks + 1; tick < endInTicks; ++tick) {
        const tick_t delta = tick - startInTicks;
        const int range = static_cast<int>(endValue) - startValue;

        const uint8_t value = static_cast<uint8_t>(
            startValue + range * static_cast<int>(delta) / static_cast<int>(duration));

        if (value != lastSentValue) {
            track.addControlChange(tick, controller, value);
            lastSentValue = value;
        }
    }

    track.addControlChange(endInTicks, controller, endValue);
}
