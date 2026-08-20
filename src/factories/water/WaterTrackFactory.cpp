#include "WaterTrackFactory.h"

#include "factories/SequenceTrackFactory.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "factories/MidiNotes.h"

namespace
{
constexpr tick_t oneBarTick = 384;
}

SequenceTrack WaterTrackFactory::waterArp(tick_t lengthInTicks) {
    SequenceTrack track("Marimba", MidiChannel::kDrums);

    SequenceDesc desc;
    //TODO : might be a better way to do it
    desc.notes = {{55}};
    desc.rate = 0.25;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}

SequenceTrack WaterTrackFactory::waterHats(tick_t lengthInTicks) {
    SequenceTrack track("Hats", MidiChannel::kDrums);

    SequenceDesc desc;
    //TODO : might be a better way to do it
    desc.notes = {{}, {40}, {40}, {40}};
    desc.velocities = {55, 127, 55};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}
