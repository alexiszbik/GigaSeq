#include "midieffects/ArpeggiatorEffect.h"
#include <algorithm>

ArpeggiatorEffect::ArpeggiatorEffect(uint8_t octaves, uint8_t rate, ArpDirection direction)
    : octaves_(octaves),
      rate_(rate),
      direction_(direction)
{
}

void ArpeggiatorEffect::reset()
{
    rootPitch_ = 0;
    velocity_ = 127;
    startTick_ = 0;
    durationTicks_ = 0;
}

void ArpeggiatorEffect::onSourceNote(const Note& note, tick_t durationTicks, tick_t startTick)
{
    currentOctave = octaves_;
    isGoingUp = false;

    rootPitch_ = note.note;
    velocity_ = note.velocity;
    startTick_ = startTick;
    durationTicks_ = durationTicks;
}

uint8_t ArpeggiatorEffect::pitchForStep()
{
    uint8_t note = static_cast<uint8_t>(static_cast<int>(rootPitch_) + currentOctave*12);

    if (direction_ == ArpDirection::DownUp && octaves_ > 0) {
        if (isGoingUp) {
            currentOctave++;
        } else {
            currentOctave--;
        }

        if (currentOctave <= 0) {
            isGoingUp = true;
        } else if (currentOctave >= octaves_) {
            isGoingUp = false;
        }
    }

    return note;
}

void ArpeggiatorEffect::processTick(
    tick_t tick,
    uint8_t channel,
    ActiveNotePool& activeNotes,
    MidiInOut& midi)
{
    if (rootPitch_ == 0) {
        return;
    }

    if (tick < startTick_ || tick - startTick_ > durationTicks_) { //verify bounds
        return;
    }

    const tick_t stepDuration = TickHelper::kOneBarTick4_4 / rate_;
    if (stepDuration == 0 || tick % stepDuration != 0) {
        return;
    }

    const uint8_t pitch = pitchForStep();
    const tick_t noteDuration = stepDuration - 1;

    activeNotes.startNote(channel, pitch, velocity_, (noteDuration / 2), midi); //with gate 50% now

}
