#pragma once

#include "ControlAutomation.h"
#include "ControlChange.h"
#include "MuteEvent.h"
#include "Note.h"
#include "ProgramChange.h"
#include "SequenceTrack.h"
#include "Tick.h"
#include "TickHelper.h"

#include <cstdint>
#include <vector>

using TrackBuilder = SequenceTrack (*)(tick_t lengthInTicks, tick_t startInTicks);

// Fluent description of a track to add to a sequence.
//
// Construct from a track builder (implicitly for the common case, or via the
// track() helper when chaining options), then chain modifiers:
//
//   track(WaterTrackFactory::waterHats).muted().withCC(7, 64).withPC(42)
//
// Each modifier returns *this so calls can be chained. buildSequence() reads
// the resulting spec to build and post-process the SequenceTrack.
class TrackSpec
{
public:
    // Non-explicit on purpose: lets bare builders participate in initializer
    // lists, e.g. {SequenceTrackFactory::kickFour, track(...).muted()}.
    TrackSpec(TrackBuilder builder) : builder_(builder) {}

    TrackSpec& muted() { startMuted_ = true; return *this; }
    TrackSpec& withProgramChange(uint8_t program, tick_t tick = 0);
    TrackSpec& withCC(uint8_t controller, uint8_t value, tick_t tick = 0);
    TrackSpec& withCCs(std::vector<ControlChange> controlChanges);
    TrackSpec& withAutomation(
        tick_t startTick,
        tick_t endTick,
        uint8_t controller,
        uint8_t startValue,
        uint8_t endValue);
    TrackSpec& withMuteEvent(tick_t tick, bool mute = true);
    TrackSpec& withNote(uint8_t pitch, uint8_t velocity, tick_t tick, tick_t duration = TickHelper::kStepLen);
    TrackSpec& asFill();
    TrackSpec& withLength(tick_t length);
    TrackSpec& withStart(tick_t start);
    TrackSpec& withPitchOffset(int offset);

    TrackBuilder builder() const noexcept { return builder_; }
    bool startMuted() const noexcept { return startMuted_; }
    const std::vector<ProgramChange>& programChanges() const noexcept { return programChanges_; }
    const std::vector<ControlChange>& controlChanges() const noexcept { return controlChanges_; }
    const std::vector<ControlAutomation>& controlAutomations() const noexcept { return controlAutomations_; }
    const std::vector<MuteEvent>& muteEvents() const noexcept { return muteEvents_; }
    const std::vector<ScheduledNote>& notes() const noexcept { return notes_; }
    bool isFill() const noexcept { return isFill_; }
    bool hasCustomLength() const noexcept { return hasCustomLength_; }
    tick_t customLength() const noexcept { return customLength_; }
    bool hasCustomStart() const noexcept { return hasCustomStart_; }
    tick_t startInTicks() const noexcept { return startInTicks_; }
    bool hasPitchOffset() const noexcept { return hasPitchOffset_; }
    int pitchOffset() const noexcept { return pitchOffset_; }

private:
    TrackBuilder builder_;
    bool startMuted_ = false;
    std::vector<ProgramChange> programChanges_;
    std::vector<ControlChange> controlChanges_;
    std::vector<ControlAutomation> controlAutomations_;
    std::vector<MuteEvent> muteEvents_;
    std::vector<ScheduledNote> notes_;
    bool isFill_ = false;

    bool hasCustomLength_ = false;
    tick_t customLength_ = 0;
    bool hasCustomStart_ = false;
    tick_t startInTicks_ = 0;
    bool hasPitchOffset_ = false;
    int pitchOffset_ = 0;
};

// Ergonomic helper to start a fluent TrackSpec from a builder.
// Use it whenever you need to chain options; bare builders still convert
// implicitly to TrackSpec when no option is needed.
inline TrackSpec track(TrackBuilder builder) { return TrackSpec{builder}; }
