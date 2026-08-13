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
#include <vector>

using MuteChangedCallback = void (*)(std::size_t trackIndex, bool muted, void* context);

class SequenceTrack
{
public:
    SequenceTrack(const char* name = "", uint8_t channel = 0);

    const char* name() const noexcept { return name_; }
    uint8_t channel() const noexcept { return channel_; }

    void attachMidi(MidiInOut& midi);

    bool isMuted() const noexcept { return muted_; }
    void setMuted(bool muted);

    void setTrackIndex(std::size_t index);
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

    StringHelper::NameBuffer name_ = {};
    uint8_t channel_ = 0;
    std::size_t trackIndex_ = 0;

    bool muted_ = false;
    bool startMuted_ = false;

    MidiInOut* midi_ = nullptr;
    MuteChangedCallback onMuteChanged_ = nullptr;
    void* onMuteChangedContext_ = nullptr;
    std::vector<ActiveNote> activeNotes_;

    TimedEventList<Note> notes_;
    TimedEventList<ControlChange> controlChanges_;
    TimedEventList<ProgramChange> programChanges_;
    TimedEventList<MuteEvent> muteEvents_;
};
