#include "CloserTrackFactory.h"

#include "factories/closer/CloserPatterns.h"
#include "MidiChannel.h"

SequenceTrack CloserTrackFactory::closerArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    track.setPattern(CloserPatterns::kCloserArp, lengthInTicks, startInTicks);
    return track;
}
