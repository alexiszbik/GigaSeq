#include "FallingTrackFactory.h"

#include "factories/falling/FallingPatterns.h"
#include "MidiChannel.h"

SequenceTrack FallingTrackFactory::fallingHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kSampler);
    track.setPattern(FallingPatterns::kFallingHats, lengthInTicks, startInTicks);
    return track;
}
