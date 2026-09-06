#include "ActiveNotePool.h"

void ActiveNotePool::startNote(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (durationTicks == 0) {
        return;
    }

    midi.sendNoteOn(channel, note, velocity);

    if (activeNoteCount_ < kMaxActiveNotes) {
        activeNotes_[activeNoteCount_++] = { channel, note, durationTicks };
    }
}

void ActiveNotePool::processTick(MidiInOut& midi)
{
    uint8_t write = 0;
    for (uint8_t read = 0; read < activeNoteCount_; ++read) {
        --activeNotes_[read].remainingTicks;

        if (activeNotes_[read].remainingTicks == 0) {
            midi.sendNoteOff(activeNotes_[read].channel, activeNotes_[read].note, 0);
        } else {
            activeNotes_[write++] = activeNotes_[read];
        }
    }
    activeNoteCount_ = write;
}

void ActiveNotePool::releaseAll(MidiInOut& midi)
{
    for (uint8_t i = 0; i < activeNoteCount_; ++i) {
        midi.sendNoteOff(activeNotes_[i].channel, activeNotes_[i].note, 0);
    }
    activeNoteCount_ = 0;
}

void ActiveNotePool::reset()
{
    activeNoteCount_ = 0;
}
