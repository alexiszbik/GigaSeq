#include "SequenceTrack.h"

#include <algorithm>
#include <cstddef>
#include <stdexcept>

SequenceTrack::SequenceTrack(const char* name, uint8_t channel)
    : name_(name ? name : ""),
      channel_(channel)
{
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

    notes_.add({ startTick, durationTicks, { note, velocity } });
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

void SequenceTrack::setPattern(const TrackPattern& pattern, tick_t lengthInTicks, tick_t startInTicks)
{
    pattern_ = &pattern;
    patternStart_ = startInTicks;
    patternLength_ = lengthInTicks;
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

    notes_.removeInRangeIf(tick, durationTicks, [&pitches](const ScheduledNote& scheduledNote) {
        if (pitches.empty()) {
            return true;
        }
        return std::find(pitches.begin(), pitches.end(), scheduledNote.note.note) != pitches.end();
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

void SequenceTrack::setFill() {
    isFill_ = true; 
    setStartMuted();
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

void SequenceTrack::startNote(const ScheduledNote& scheduledNote)
{
    midi_->sendNoteOn(channel_, scheduledNote.note.note, scheduledNote.note.velocity);
    if (activeNoteCount_ < kMaxActiveNotes) {
        activeNotes_[activeNoteCount_++] = { scheduledNote.note.note, scheduledNote.durationTicks };
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

void SequenceTrack::processPatternTick(tick_t position)
{
    if (!pattern_ || muted_ || pattern_->stepCount == 0) {
        return;
    }

    const tick_t stepDuration = patternStepDuration(*pattern_);
    if (stepDuration == 0) {
        return;
    }

    const tick_t local = position - patternStart_;
    if (local < 0 || local >= patternLength_) {
        return;
    }

    if (local % stepDuration != 0) {
        return;
    }

    const uint16_t stepIndex = static_cast<uint16_t>(
        (local / stepDuration) % pattern_->stepCount);
    const PatternStep& step = pattern_->steps[stepIndex];

    if (step.noteCount == 0) {
        return;
    }

    const tick_t noteDuration = stepDuration * step.durationMul;
    for (uint8_t i = 0; i < step.noteCount; ++i) {
        startNote({ position, noteDuration, step.notes[i] });
    }
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

    notes_.process(position, loopWrap, [this](const ScheduledNote& scheduledNote) {
        if (!muted_) {
            startNote(scheduledNote);
        }
    });

    processPatternTick(position);

    tickActiveNotes();
}
