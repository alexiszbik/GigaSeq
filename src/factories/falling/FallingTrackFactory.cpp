#include "FallingTrackFactory.h"

#include "factories/falling/FallingPatterns.h"

#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "factories/MidiNotes.h"


namespace
{
constexpr tick_t oneBarTick = 384;

constexpr uint8_t riz = 52;

}

SequenceTrack FallingTrackFactory::fallingHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kDrums);
    track.setPattern(FallingPatterns::kFallingHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingPads(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Pads", MidiChannel::kSampler);
    track.setPattern(FallingPatterns::kFallingPads, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingKick(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Kick", MidiChannel::kSampler);
    track.setPattern(FallingPatterns::kFallingKick, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack FallingTrackFactory::fallingRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);

    track.addNote(startInTicks + 6*oneBarTick, 24, riz, 127);

    return track;
}

SequenceTrack FallingTrackFactory::fallingBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    track.setPattern(FallingPatterns::kFallingBass, lengthInTicks, startInTicks);
    return track;
}
