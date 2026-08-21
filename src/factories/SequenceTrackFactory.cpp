#include "SequenceTrackFactory.h"

#include "TrackPatternBuilder.h"

#include "MidiChannel.h"
#include "MidiNotes.h"

SequenceTrack SequenceTrackFactory::kickFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Kick", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{36}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack SequenceTrackFactory::snareFour(tick_t lengthInTicks, tick_t startInTicks)
{
    SequenceTrack track("Clap", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {{}, {38}, {}, {38}};
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}
