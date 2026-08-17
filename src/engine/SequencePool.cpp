#include "SequencePool.h"

#include "factories/SequenceFactory.h"

#include <cstdio>
#include <utility>

SequencePool::SequencePool(MidiInOut& midi, Logger& logger)
    : midi_(midi)
    , logger_(logger)
{
}

void SequencePool::add(Song song)
{
    song.attachMidi(midi_);
    songs_.push_back(std::move(song));
    wireTrackMuteCallbacks();
    wireTempoCallbacks();
}

std::size_t SequencePool::sequenceCount() const noexcept
{
    std::size_t count = 0;
    for (const Song& song : songs_) {
        count += song.size();
    }
    return count;
}

Song& SequencePool::currentSong()
{
    return songs_.at(currentSongIndex_);
}

const Song& SequencePool::currentSong() const
{
    return songs_.at(currentSongIndex_);
}

Sequence& SequencePool::current()
{
    return currentSong().sequence(currentSequenceIndex_);
}

const Sequence& SequencePool::current() const
{
    return currentSong().sequence(currentSequenceIndex_);
}

void SequencePool::resetCurrent()
{
    setPending(PendingSwitch::None);
    current().reset();
}

bool SequencePool::canAdvanceNext() const
{
    if (songs_.empty()) {
        return false;
    }

    if (currentSequenceIndex_ + 1 < currentSong().size()) {
        return true;
    }

    return currentSongIndex_ + 1 < songs_.size()
        && songs_[currentSongIndex_ + 1].size() > 0;
}

bool SequencePool::canAdvancePrevious() const
{
    if (songs_.empty()) {
        return false;
    }

    if (currentSequenceIndex_ > 0) {
        return true;
    }

    return currentSongIndex_ > 0
        && songs_[currentSongIndex_ - 1].size() > 0;
}

void SequencePool::queueSwitch(PendingSwitch direction)
{
    if (songs_.empty()) {
        return;
    }

    if (pendingSwitch_ == PendingSwitch::Next && direction == PendingSwitch::Previous) {
        logger_.info("Cancel next sequence.\n");
        setPending(PendingSwitch::None);
        return;
    }

    if (pendingSwitch_ == PendingSwitch::Previous && direction == PendingSwitch::Next) {
        logger_.info("Cancel previous sequence.\n");
        setPending(PendingSwitch::None);
        return;
    }

    if (pendingSwitch_ != PendingSwitch::None) {
        logger_.info("Already waiting to switch sequence.\n");
        return;
    }

    if (direction == PendingSwitch::Next && !canAdvanceNext()) {
        logger_.info("Already on last sequence.\n");
        return;
    }

    if (direction == PendingSwitch::Previous && !canAdvancePrevious()) {
        logger_.info("Already on first sequence.\n");
        return;
    }

    setPending(direction);

    if (direction == PendingSwitch::Next) {
        logger_.info("Next sequence queued — finishing current sequence...\n");
    } else {
        logger_.info("Previous sequence queued — finishing current sequence...\n");
    }
}

void SequencePool::setPending(PendingSwitch sw) {
    pendingSwitch_ = sw;
    if (onPendingChanged_) {
        onPendingChanged_(sw);
    }
}

void SequencePool::requestNext(bool now)
{
    if (now) {
        advanceToNext();
    } else {
        queueSwitch(PendingSwitch::Next);
    }
}

void SequencePool::requestPrevious(bool now)
{
    if (now) {
        advanceToPrevious();
    } else {
        queueSwitch(PendingSwitch::Previous);
    }
}

void SequencePool::processTick()
{
    if (songs_.empty()) {
        return;
    }

    Sequence& sequence = current();
    const bool wrapAtEnd = pendingSwitch_ == PendingSwitch::None;
    sequence.processTick(wrapAtEnd);

    if (pendingSwitch_ != PendingSwitch::None && sequence.position() >= sequence.lengthInTicks()) {
        if (pendingSwitch_ == PendingSwitch::Next) {
            advanceToNext();
        } else {
            advanceToPrevious();
        }
    }
}

void SequencePool::allNotesOff()
{
    for (Song& song : songs_) {
        song.allNotesOff();
    }
}

void SequencePool::setOnSequenceChanged(SequenceChangedCallback callback)
{
    onSequenceChanged_ = callback;
}

void SequencePool::setOnTrackMuteChanged(MuteChangedCallback callback)
{
    onTrackMuteChanged_ = callback;
    wireTrackMuteCallbacks();
}

void SequencePool::setOnTempoChanged(TempoChangedCallback callback)
{
    onTempoChanged_ = callback;
    wireTempoCallbacks();
}

void SequencePool::setOnPendingChanged(PendingChangedCallback callback) 
{
    onPendingChanged_ = callback;
}

void SequencePool::wireTrackMuteCallbacks()
{
    if (!onTrackMuteChanged_) {
        return;
    }

    for (Song& song : songs_) {
        for (std::size_t i = 0; i < song.size(); ++i) {
            song.sequence(i).setOnTrackMuteChanged(onTrackMuteChanged_);
        }
    }
}

void SequencePool::wireTempoCallbacks()
{
    if (!onTempoChanged_) {
        return;
    }

    for (Song& song : songs_) {
        for (std::size_t i = 0; i < song.size(); ++i) {
            song.sequence(i).setOnTempoChanged(onTempoChanged_);
        }
    }
}

void SequencePool::notifySequenceChanged()
{
#ifdef GIGASEQ_LOCAL
    logCurrentSequenceSwitch();
#endif
    if (onSequenceChanged_) {
        onSequenceChanged_();
    }
}

void SequencePool::logCurrentSequenceSwitch()
{
    char buffer[192];
    std::snprintf(
        buffer,
        sizeof(buffer),
        "Switched to song %zu / %zu — sequence %zu / %zu — %s (%zu tracks, %u BPM)\n",
        currentSongIndex_ + 1,
        songs_.size(),
        currentSequenceIndex_ + 1,
        currentSong().size(),
        current().name(),
        current().trackCount(),
        current().getTempo());

    logger_.info(buffer);
}

void SequencePool::advanceToNext()
{
    if (!canAdvanceNext()) {
        logger_.info("Already on last sequence.\n");
        return;
    }

    current().allNotesOff();

    setPending(PendingSwitch::None);

    if (currentSequenceIndex_ + 1 < currentSong().size()) {
        ++currentSequenceIndex_;
    } else {
        ++currentSongIndex_;
        currentSequenceIndex_ = 0;
    }

    current().reset();
    notifySequenceChanged();
}

void SequencePool::advanceToPrevious()
{
    if (!canAdvancePrevious()) {
        logger_.info("Already on first sequence.\n");
        return;
    }

    current().allNotesOff();

    setPending(PendingSwitch::None);

    if (currentSequenceIndex_ > 0) {
        --currentSequenceIndex_;
    } else {
        --currentSongIndex_;
        currentSequenceIndex_ = currentSong().size() - 1;
    }

    current().reset();
    notifySequenceChanged();
}

SequencePool SequencePool::createDefault(MidiInOut& midi, Logger& logger)
{
    SequencePool pool(midi, logger);

    using Builder = Sequence (*)();
    auto addSong = [&pool](const char* name, std::vector<Builder> builders) {
        Song song(name);
        for (auto& b : builders) {
            song.add(b());
        }
        pool.add(std::move(song));
    };

    addSong("Together", {
        SequenceFactory::togetherIntro,
        SequenceFactory::togetherDrum,
    });

    addSong("Intro", {
        SequenceFactory::createSequenceOne,
        SequenceFactory::createSequenceTwo,
    });
    addSong("Main", {
        SequenceFactory::createSequenceThree,
        SequenceFactory::createSequenceFour,
        SequenceFactory::createSequenceFive,
    });
    addSong("Outro", {
        SequenceFactory::createSequenceSix,
        SequenceFactory::createSequenceSeven,
    });

    addSong("Intro 2", {
        SequenceFactory::createSequenceOne,
        SequenceFactory::createSequenceTwo,
    });
    addSong("Main 2", {
        SequenceFactory::createSequenceThree,
        SequenceFactory::createSequenceFour,
        SequenceFactory::createSequenceFive,
    });
    addSong("Outro 2", {
        SequenceFactory::createSequenceSix,
        SequenceFactory::createSequenceSeven,
    });

    addSong("Intro 3", {
        SequenceFactory::createSequenceOne,
        SequenceFactory::createSequenceTwo,
    });
    addSong("Main 3", {
        SequenceFactory::createSequenceThree,
        SequenceFactory::createSequenceFour,
        SequenceFactory::createSequenceFive,
    });
    addSong("Outro 3", {
        SequenceFactory::createSequenceSix,
        SequenceFactory::createSequenceSeven,
    });

    addSong("Intro 4", {
        SequenceFactory::createSequenceOne,
        SequenceFactory::createSequenceTwo,
    });
    addSong("Main 4", {
        SequenceFactory::createSequenceThree,
        SequenceFactory::createSequenceFour,
        SequenceFactory::createSequenceFive,
    });
    addSong("Outro 4", {
        SequenceFactory::createSequenceSix,
        SequenceFactory::createSequenceSeven,
    });

    addSong("Intro 5", {
        SequenceFactory::createSequenceOne,
        SequenceFactory::createSequenceTwo,
    });
    addSong("Main 5", {
        SequenceFactory::createSequenceThree,
        SequenceFactory::createSequenceFour,
        SequenceFactory::createSequenceFive,
    });
    addSong("Outro 5", {
        SequenceFactory::createSequenceSix,
        SequenceFactory::createSequenceSeven,
    });

    return pool;
}
