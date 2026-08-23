#include "FantasySequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/fantasy/FantasyTrackFactory.h"
#include "MidiChannel.h"

namespace {
constexpr uint8_t songTempo = 130;
}


Sequence FantasySequenceFactory::fantasyIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            FantasyTrackFactory::fantasyArp,
        });
    return seq;
}
