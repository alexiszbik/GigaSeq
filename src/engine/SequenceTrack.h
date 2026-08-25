#pragma once

#include "ControlAutomation.h"
#include "ControlChange.h"
#include "MidiInOut.h"
#include "Note.h"
#include "MuteEvent.h"
#include "ProgramChange.h"
#include "TimedEventList.h"
#include "Tick.h"
#include "TrackPattern.h"

#include <cstdint>
#include <vector>

using MuteChangedCallback = void (*)(uint8_t trackIndex, bool muted);

class SequenceTrack
{
public:
    SequenceTrack(const char* name = "", uint8_t channel = 0);

    const char* name() const noexcept { return name_; }
    uint8_t channel() const noexcept { return channel_; }

    void attachMidi(MidiInOut& midi);

    bool isMuted() const noexcept { return muted_; }
    void setMuted(bool muted);

    void setTrackIndex(uint8_t index);
    void setOnMuteChanged(MuteChangedCallback callback);

    void setStartMuted() { startMuted_ = true; }
    void setFill();

    bool getFill() { return isFill_; }

    void addNote(
        tick_t startTick,
        tick_t durationTicks,
        uint8_t note,
        uint8_t velocity);

    void addControlChange(
        tick_t tick,
        uint8_t controller,
        uint8_t value);

    void addControlAutomation(
        tick_t startTick,
        tick_t endTick,
        uint8_t controller,
        uint8_t startValue,
        uint8_t endValue);

    void addProgramChange(
        tick_t tick,
        uint8_t program);

    void addMuteEvent(
        tick_t tick, bool state = true);

    void setPattern(const TrackPattern& pattern, tick_t lengthInTicks, tick_t startInTicks);
    bool hasPattern() const noexcept { return pattern_ != nullptr; }

    void setPitchOffset(int offset) noexcept { pitchOffset_ = offset; }
    int pitchOffset() const noexcept { return pitchOffset_; }

    void removeNotes(
        tick_t tick,
        tick_t durationTicks,
        const std::vector<uint8_t>& pitches = {});

    void reset();
    void processTick(tick_t position, bool loopWrap);
    void releaseActiveNotes();

private:
    struct ActiveNote
    {
        uint8_t note = 0;
        tick_t remainingTicks = 0;
    };

    void startNote(const ScheduledNote& scheduledNote);
    void processPatternTick(tick_t position);
    void processControlAutomations(tick_t position, bool loopWrap);
    void tickActiveNotes();
    void notifyMuteChanged();

    const char* name_ = "";
    uint8_t channel_ = 0;
    uint8_t trackIndex_ = 0;

    bool muted_ = false;
    bool startMuted_ = false;
    bool isFill_ = false;

    MidiInOut* midi_ = nullptr;
    MuteChangedCallback onMuteChanged_ = nullptr;

    // Fixed-capacity active note pool: no heap allocation, so it is safe to
    // mutate from the clock ISR (startNote/tickActiveNotes run in ISR).
    static constexpr uint8_t kMaxActiveNotes = 32;
    ActiveNote activeNotes_[kMaxActiveNotes];
    uint8_t activeNoteCount_ = 0;

    const TrackPattern* pattern_ = nullptr;
    tick_t patternStart_ = 0;
    tick_t patternLength_ = 0;
    int pitchOffset_ = 0;

    TimedEventList<ScheduledNote> notes_;
    TimedEventList<ControlChange> controlChanges_;
    std::vector<ControlAutomation> controlAutomations_;
    std::vector<uint8_t> automationLastSent_;
    TimedEventList<ProgramChange> programChanges_;
    TimedEventList<MuteEvent> muteEvents_;
};
