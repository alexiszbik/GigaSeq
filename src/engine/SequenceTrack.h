#pragma once

#include "ControlChange.h"
#include "StringHelper.h"
#include "MidiInOut.h"
#include "Note.h"
#include "MuteEvent.h"
#include "ProgramChange.h"
#include "TimedEventList.h"
#include "Tick.h"

#include <cstdint>

using MuteChangedCallback = void (*)(uint8_t trackIndex, bool muted, void* context);

class SequenceTrack
{
public:
    static constexpr uint8_t kNameMaxLength = 30;

    SequenceTrack(const char* name = "", uint8_t channel = 0);

    const char* name() const noexcept { return name_; }
    uint8_t channel() const noexcept { return channel_; }

    void attachMidi(MidiInOut& midi);

    bool isMuted() const noexcept { return muted_; }
    void setMuted(bool muted);

    void setTrackIndex(uint8_t index);
    void setOnMuteChanged(MuteChangedCallback callback, void* context = nullptr);

    void setStartMuted() { startMuted_ = true; }

    void addNote(
        tick_t startTick,
        tick_t durationTicks,
        uint8_t note,
        uint8_t velocity);

    void addControlChange(
        tick_t tick,
        uint8_t controller,
        uint8_t value);

    void addProgramChange(
        tick_t tick,
        uint8_t program);

    void addMuteEvent(
        tick_t tick);

    void reset();
    void processTick(tick_t position, bool loopWrap);
    void releaseActiveNotes();

private:
    struct ActiveNote
    {
        uint8_t note = 0;
        tick_t remainingTicks = 0;
    };

    void startNote(const Note& note);
    void tickActiveNotes();
    void notifyMuteChanged();

    char name_[kNameMaxLength + 1] = {};
    uint8_t channel_ = 0;
    uint8_t trackIndex_ = 0;

    bool muted_ = false;
    bool startMuted_ = false;

    MidiInOut* midi_ = nullptr;
    MuteChangedCallback onMuteChanged_ = nullptr;
    void* onMuteChangedContext_ = nullptr;

    // Fixed-capacity active note pool: no heap allocation, so it is safe to
    // mutate from the clock ISR (startNote/tickActiveNotes run in ISR).
    static constexpr uint8_t kMaxActiveNotes = 32;
    ActiveNote activeNotes_[kMaxActiveNotes];
    uint8_t activeNoteCount_ = 0;

    TimedEventList<Note> notes_;
    TimedEventList<ControlChange> controlChanges_;
    TimedEventList<ProgramChange> programChanges_;
    TimedEventList<MuteEvent> muteEvents_;
};
