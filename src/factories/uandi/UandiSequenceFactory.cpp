#include "UandiSequenceFactory.h"

#include "factories/SequenceBuilder.h"
#include "factories/SequenceTrackFactory.h"
#include "factories/uandi/UandiTrackFactory.h"
#include "MidiChannel.h"

namespace {
constexpr uint8_t songTempo = 140;
}

Sequence UandiSequenceFactory::uandiIntro()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Intro", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            UandiTrackFactory::uandiWavetableA,
            track(UandiTrackFactory::uandiHatLoop).muted(),
            track(UandiTrackFactory::uandiWant).withMuteEvent(0),
            track(UandiTrackFactory::uandiBassA).muted(),
            track(UandiTrackFactory::uandiFreak).muted(),
        });
    return seq;
}

Sequence UandiSequenceFactory::uandiIntroB()
{
    Sequence seq = buildSequence(
        4, 4, 0, "IntroB", songTempo, true,
        {
            SequenceTrackFactory::kickFour,
            UandiTrackFactory::uandiWavetableB,
            UandiTrackFactory::uandiBassB,
            UandiTrackFactory::uandiFreak,
        });
    return seq;
}
