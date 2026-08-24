#include "SequenceTrackFactory.h"

#include "DrumPatterns.h"
#include "TrackPatternBuilder.h"

#include "MidiConst.h"
#include "MidiNotes.h"

SequenceTrack SequenceTrackFactory::kickFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Kick", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kKickFour, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::clapFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Clap", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kSnareFour, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::snareFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Snare", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kSnareFour, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::rideOff(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Ride", MidiChannel::kDrums);
    track.setPattern(DrumPatterns::kRideOff, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack SequenceTrackFactory::gtrPedal(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("HXStomp", MidiChannel::kGtrPedal);
    return track;
}