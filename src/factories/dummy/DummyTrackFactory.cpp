#include "DummyTrackFactory.h"

#include "factories/SequenceTrackFactory.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiChannel.h"
#include "factories/MidiNotes.h"

namespace
{
constexpr tick_t oneBarTick = 384;

}

SequenceTrack DummyTrackFactory::dummyArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);

    SequenceDesc desc;
    //TODO : might be a better way to do it
    desc.notes = {{C3}
    };
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}
