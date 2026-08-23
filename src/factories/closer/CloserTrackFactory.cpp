#include "CloserTrackFactory.h"

#include "factories/closer/CloserPatterns.h"
#include "MidiChannel.h"

SequenceTrack CloserTrackFactory::closerHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerLoopHat(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("LoopHat", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserLoopHat, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerTambourin(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tambourin", MidiChannel::kSampler);
    track.setPattern(CloserPatterns::kCloserTambourin, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerClapTom(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("ClapTom", MidiChannel::kDrums);
    track.setPattern(CloserPatterns::kCloserClapTom, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack CloserTrackFactory::closerRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);
/*
    SequenceDesc desc;
    desc.notes = {{C3}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks 2 , startInTicks);
*/
    return track;
}
