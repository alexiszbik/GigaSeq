#pragma once

#include "SequenceTrack.h"
#include "Tick.h"

#include <cstdint>
#include <vector>

using TrackBuilder = SequenceTrack (*)(tick_t lengthInTicks, tick_t startInTicks);

struct CCPair
{
    uint8_t control;
    uint8_t value;
};

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
    TrackSpec& withProgramChange(uint8_t program) { hasProgramChange_ = true; programChange_ = program; return *this; }
    TrackSpec& withCC(uint8_t control, uint8_t value);
    TrackSpec& withCCs(std::vector<CCPair> controlChanges);
    TrackSpec& withMuteEvent(tick_t tick);
    TrackSpec& asFill();
    TrackSpec& withLength(tick_t length);
    TrackSpec& withStart(tick_t start);

    TrackBuilder builder() const noexcept { return builder_; }
    bool startMuted() const noexcept { return startMuted_; }
    bool hasProgramChange() const noexcept { return hasProgramChange_; }
    uint8_t programChange() const noexcept { return programChange_; }
    const std::vector<CCPair>& controlChanges() const noexcept { return controlChanges_; }
    const std::vector<tick_t>& muteEvents() const noexcept { return muteEvents_; }
    bool isFill() const noexcept { return isFill_; }
    bool hasCustomLength() const noexcept { return hasCustomLength_; }
    tick_t customLength() const noexcept { return customLength_; }
    bool hasCustomStart() const noexcept { return hasCustomStart_; }
    tick_t startInTicks() const noexcept { return startInTicks_; }

private:
    TrackBuilder builder_;
    bool startMuted_ = false;
    bool hasProgramChange_ = false;
    uint8_t programChange_ = 0;
    std::vector<CCPair> controlChanges_;
    std::vector<tick_t> muteEvents_;
    bool isFill_ = false;

    bool hasCustomLength_ = false;
    tick_t customLength_ = 0;
    bool hasCustomStart_ = false;
    tick_t startInTicks_ = 0;
};

// Ergonomic helper to start a fluent TrackSpec from a builder.
// Use it whenever you need to chain options; bare builders still convert
// implicitly to TrackSpec when no option is needed.
inline TrackSpec track(TrackBuilder builder) { return TrackSpec{builder}; }
