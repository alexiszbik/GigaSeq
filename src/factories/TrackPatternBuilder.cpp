#include "TrackPatternBuilder.h"

#include "TickHelper.h"
#include "TrackPattern.h"

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

    const uint8_t groove = patternEffectiveGroove(static_cast<uint8_t>(desc.rate), desc.groove);

    bool isOddBeat = false;

    for (tick_t tick = startTick; tick < (startTick + lengthInTicks); tick = static_cast<tick_t>(tick + stepDuration))
    {
        int noteDuration = stepDuration;
        const std::vector<uint8_t>& stepNotes = desc.notes[seqIdx];

        tick_t noteTick = tick;
        if (groove > 0 && isOddBeat) {
            noteTick += patternStepGrooveOffset(stepDuration, groove);
        }

        uint8_t velocity = 127;
        if (velIdx < velSize) {
            velocity = desc.velocities[velIdx];
        }

        if (durIdx < durationSize) {
            noteDuration *= desc.durations[durIdx];
        }

        bool noteExists = false;

        for (uint8_t note : stepNotes) {
            track.addNote(noteTick, noteDuration, note, velocity);
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

        isOddBeat = !isOddBeat;
    }
}


void addSingleNote(
    SequenceTrack& track,
    uint8_t note,
    tick_t startTick)
{
    track.addNote(startTick, TickHelper::kStepLen, note, 127);

}

void makeRiser(
    SequenceTrack& track,
    uint8_t note,
    tick_t lengthInTicks,
    tick_t riserLength) 
{
    track.addNote(lengthInTicks - riserLength, riserLength, note, 127);

}

void makeRoll(
    SequenceTrack& track,
    uint8_t note,
    tick_t lengthInTicks,
    tick_t startTick,
    uint8_t startVelocity,
    uint8_t endVelocity,
    std::vector<double> velocityPattern,
    uint8_t stepRatio) 
{
    const tick_t stepDuration = TickHelper::kOneBarTick4_4 / stepRatio;

    if (lengthInTicks < stepDuration) {
        return;
    }

    int velocityIdx = 0;
    size_t velocityCount = velocityPattern.size();
    
    const int stepCount = static_cast<int>(lengthInTicks / stepDuration);

    const int velocityDelta = static_cast<int>(endVelocity) - static_cast<int>(startVelocity);
    
    for (int step = 0; step < stepCount; ++step) {

        double velocityRatio = velocityPattern.at(velocityIdx);

        const tick_t tick = startTick + step * stepDuration;

        const int velocity = startVelocity + (velocityDelta * step) / (stepCount - 1);

        track.addNote(tick, stepDuration, note, static_cast<uint8_t>(velocity * velocityRatio));

        velocityIdx++;
        if (velocityIdx >= velocityCount) {
            velocityIdx = 0;
        }
    }

}