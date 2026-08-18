#include "SequenceTrack.h"

#include "StringHelper.h"

#include <algorithm>
#include <cstddef>
#include <stdexcept>

SequenceTrack::SequenceTrack(const char* name, uint8_t channel)
    : channel_(channel)
{
    StringHelper::copyName(name_, name, kNameMaxLength + 1);
}

void SequenceTrack::attachMidi(MidiInOut& midi)
{
    midi_ = &midi;
}

void SequenceTrack::addNote(
    tick_t startTick,
    tick_t durationTicks,
    uint8_t note,
    uint8_t velocity)
{
    if (durationTicks == 0) {
        return;
    }

    /*

    if (!fitsInTickRange(static_cast<uint32_t>(startTick) + durationTicks)) {
        throw std::invalid_argument("Note exceeds maximum tick range");
    }
    */

    notes_.add({ startTick, durationTicks, note, velocity });
}

void SequenceTrack::addControlChange(
    tick_t tick,
    uint8_t controller,
    uint8_t value)
{
    controlChanges_.add({ tick, controller, value });
}

void SequenceTrack::addProgramChange(
    tick_t tick,
    uint8_t program)
{
    programChanges_.add({ tick, program });
}

void SequenceTrack::addMuteEvent(
    tick_t tick)
{
    muteEvents_.add({ tick });
}

void SequenceTrack::removeEvents(tick_t tick, tick_t durationTicks)
{
    if (durationTicks == 0) {
        return;
    }

    notes_.removeInRange(tick, durationTicks);
    controlChanges_.removeInRange(tick, durationTicks);
    programChanges_.removeInRange(tick, durationTicks);
    muteEvents_.removeInRange(tick, durationTicks);
}

void SequenceTrack::removeNotes(
    tick_t tick,
    tick_t durationTicks,
    const std::vector<uint8_t>& pitches)
{
    if (durationTicks == 0) {
        return;
    }

    notes_.removeInRangeIf(tick, durationTicks, [&pitches](const Note& note) {
        if (pitches.empty()) {
            return true;
        }
        return std::find(pitches.begin(), pitches.end(), note.note) != pitches.end();
    });
}

void SequenceTrack::reset()
{
    notes_.reset();
    controlChanges_.reset();
    programChanges_.reset();
    muteEvents_.reset();
    activeNoteCount_ = 0;

    const bool wasMuted = muted_;
    muted_ = startMuted_;
    if (muted_ != wasMuted) {
        notifyMuteChanged();
    }
}

void SequenceTrack::setTrackIndex(uint8_t index)
{
    trackIndex_ = index;
}

void SequenceTrack::setOnMuteChanged(MuteChangedCallback callback)
{
    onMuteChanged_ = callback;
}

void SequenceTrack::notifyMuteChanged()
{
    if (onMuteChanged_) {
        onMuteChanged_(trackIndex_, muted_);
    }
}

void SequenceTrack::setMuted(bool muted)
{
    if (muted == muted_) {
        return;
    }

    muted_ = muted;

    if (muted) {
        releaseActiveNotes();
        notes_.reset();
        controlChanges_.reset();
        programChanges_.reset();
        muteEvents_.reset();
    }

    notifyMuteChanged();
}

void SequenceTrack::startNote(const Note& note)
{
    midi_->sendNoteOn(channel_, note.note, note.velocity);
    if (activeNoteCount_ < kMaxActiveNotes) {
        activeNotes_[activeNoteCount_++] = { note.note, note.durationTicks };
    }
    // Pool full: drop the note-on silently rather than allocating in ISR.
}

void SequenceTrack::tickActiveNotes()
{
    uint8_t write = 0;
    for (uint8_t read = 0; read < activeNoteCount_; ++read)
    {
        --activeNotes_[read].remainingTicks;

        if (activeNotes_[read].remainingTicks == 0) {
            midi_->sendNoteOff(channel_, activeNotes_[read].note, 0);
        } else {
            activeNotes_[write++] = activeNotes_[read];
        }
    }
    activeNoteCount_ = write;
}

void SequenceTrack::releaseActiveNotes()
{
    for (uint8_t i = 0; i < activeNoteCount_; ++i) {
        midi_->sendNoteOff(channel_, activeNotes_[i].note, 0);
    }

    activeNoteCount_ = 0;
}

void SequenceTrack::processTick(tick_t position, bool loopWrap)
{
    // we will just mute the notes, control changes & program changes will not be affected
    // is this really what we want ?

    programChanges_.process(position, loopWrap, [this](const ProgramChange& change) {
        midi_->sendProgramChange(channel_, change.program);
    });

    controlChanges_.process(position, loopWrap, [this](const ControlChange& change) {
        midi_->sendControlChange(channel_, change.controller, change.value);
    });

    muteEvents_.process(position, loopWrap, [this](const MuteEvent& e) {
        setMuted(true);
    });

    notes_.process(position, loopWrap, [this](const Note& note) {
        if (!muted_) {
            startNote(note);
        }
    });

    tickActiveNotes();
}
