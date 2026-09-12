#include "DummyTrackFactory.h"

#include "factories/dummy/DummyPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiConst.h"

SequenceTrack DummyTrackFactory::dummyArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    track.setPattern(DummyPatterns::kDummyArp, lengthInTicks, startInTicks);
    return track;
}
