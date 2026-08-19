#include "Sequence.h"

#include "StringHelper.h"

#include <stdexcept>
#include <utility>

Sequence::Sequence(
    const char* name,
    uint8_t tempo,
    uint8_t barCount,
    uint8_t beatsPerBar,
    uint8_t barLoop,
    bool loop)
    : tempo_(tempo),
      activeTempo_(tempo),
      barCount_(barCount),
      beatsPerBar_(beatsPerBar),
      loop_(loop)
{
    StringHelper::copyName(name_, name, kNameMaxLength + 1);

    const uint32_t length = static_cast<uint32_t>(barCount_) * beatsPerBar_ * kTicksPerQuarterNote;
    if (!fitsInTickRange(length)) {
        throw std::invalid_argument("Sequence length exceeds maximum tick range");
    }

    const uint32_t loopInPoint = static_cast<uint32_t>(barLoop) * beatsPerBar_ * kTicksPerQuarterNote;
    loopInPoint_ = static_cast<tick_t>(loopInPoint);
}

tick_t Sequence::lengthInTicks() const noexcept
{
    return static_cast<tick_t>(barCount_ * beatsPerBar_ * kTicksPerQuarterNote);
}

void Sequence::attachMidi(MidiInOut& midi)
{
    midi_ = &midi;

    for (SequenceTrack& track : tracks_) {
        track.attachMidi(midi);
    }
}

void Sequence::addTrack(SequenceTrack track)
{
    if (midi_) {
        track.attachMidi(*midi_);
    }

    tracks_.push_back(std::move(track));
    applyTrackMuteCallbacks();
}

void Sequence::setOnTrackMuteChanged(MuteChangedCallback callback)
{
    onTrackMuteChanged_ = callback;
    applyTrackMuteCallbacks();
}

void Sequence::setOnTempoChanged(TempoChangedCallback callback)
{
    onTempoChanged_ = callback;
}

void Sequence::addTempoEvent(tick_t tick, uint8_t bpm)
{
    tempoEvents_.add({ tick, bpm });
}

void Sequence::applyTrackMuteCallbacks()
{
    for (std::size_t i = 0; i < tracks_.size(); ++i) {
        tracks_[i].setTrackIndex(i);
        tracks_[i].setOnMuteChanged(onTrackMuteChanged_);
    }
}

void Sequence::clearTracks()
{
    tracks_.clear();
}

void Sequence::unMuteFills() {
    for (auto& t : tracks_) {
        if (t.getFill()) {
            t.setMuted(false);
        }
    }
}

SequenceTrack& Sequence::track(std::size_t index)
{
    return tracks_.at(index);
}

const SequenceTrack& Sequence::track(std::size_t index) const
{
    return tracks_.at(index);
}

SequenceTrack& Sequence::lastTrack()
{
    return track(tracks_.size() - 1);
}

const SequenceTrack& Sequence::lastTrack() const
{
    return track(tracks_.size() - 1);
}

void Sequence::setTrackMuted(std::size_t index, bool muted)
{
    tracks_.at(index).setMuted(muted);
}

void Sequence::notifyTempoChanged()
{
    if (onTempoChanged_) {
        onTempoChanged_(activeTempo_);
    }
}

void Sequence::reset()
{
    position_ = 0;
    loopStartAfterWrap_ = false;
    tempoEvents_.reset();

    for (SequenceTrack& track : tracks_) {
        track.reset();
    }

    activeTempo_ = tempo_;
    notifyTempoChanged();
}

void Sequence::processTick(bool wrapAtEnd)
{
    const tick_t length = lengthInTicks();
    if (length == 0) {
        return;
    }

    if (!wrapAtEnd && position_ >= length) {
        return;
    }

    const bool loopWrap = wrapAtEnd && loopStartAfterWrap_;
    loopStartAfterWrap_ = false;

    tempoEvents_.process(position_, loopWrap, [this](const TempoEvent& event) {
        if (event.bpm != activeTempo_) {
            activeTempo_ = event.bpm;
            notifyTempoChanged();
        }
    });

    for (SequenceTrack& track : tracks_) {
        track.processTick(position_, loopWrap);
    }

    ++position_;
    if (position_ >= length) {
        if (wrapAtEnd) {
            position_ = loopInPoint_;
            loopStartAfterWrap_ = true;
        }
    }
}

void Sequence::allNotesOff()
{
    for (SequenceTrack& track : tracks_) {
        track.releaseActiveNotes();
    }
}
