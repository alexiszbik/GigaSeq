#include "BibimbapTrackFactory.h"

#include "factories/bibimbap/BibimbapPatterns.h"
#include "factories/TrackPatternBuilder.h"
#include "MidiConst.h"

SequenceTrack BibimbapTrackFactory::bibimbapArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kSampler);
    track.setPattern(BibimbapPatterns::kBibimbapArp, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapKickHi(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("KickHi", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapKickHi, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapTom(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tom", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapTom, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapTomB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Tom", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapTomB, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapShaker(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Shaker", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapShaker, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapVocals(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Vocals", MidiChannel::kSampler);
    track.setPattern(BibimbapPatterns::kBibimbapVocals, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapMarimbaVerb(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("MarimbaVerb", MidiChannel::kSampler);
    track.setPattern(BibimbapPatterns::kBibimbapMarimbaVerb, lengthInTicks, startInTicks);
    return track;
}

#define EMPTY_BAR \
{}, {}, {}, {}, \
{}, {}, {}, {}, \
{}, {}, {}, {}, \
{}, {}, {}, {}, \
{}, {}, {}, {}, \
{}, {}, {}, {}, \
{}, {}, {}, {}

SequenceTrack BibimbapTrackFactory::bibimbapRim(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Rim", MidiChannel::kDrums);

    SequenceDesc desc;
    desc.notes = {
        EMPTY_BAR,

    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {}, 
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {},
    {}, {}, {}, {Bibimbap::bbbRim}};

    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapPercs(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Percs", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapPercs, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapPercsB(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Percs", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapPercsB, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapDizee(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Dizee", MidiChannel::kDrums);

    uint8_t d = Bibimbap::bbbDz;

    SequenceDesc desc;
    desc.notes = {
        EMPTY_BAR,
        EMPTY_BAR,
        EMPTY_BAR,
        EMPTY_BAR,

        EMPTY_BAR,
        EMPTY_BAR,
        EMPTY_BAR,

        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {d}, {d}, {d}, {}
    };
    desc.rate = 16;
    desc.velocities = {90,115,127};
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapDizee4bars(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Dizee", MidiChannel::kDrums);

    uint8_t d = Bibimbap::bbbDz;

    SequenceDesc desc;
    desc.notes = {
        EMPTY_BAR,
        EMPTY_BAR,
        EMPTY_BAR,

        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {}, {}, {}, {}, 
        {d}, {d}, {d}, {}
    };
    desc.rate = 16;
    desc.velocities = {90,115,127};
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

#undef EMPTY_BAR

SequenceTrack BibimbapTrackFactory::bibimbapXyloLoop(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("XyloLoop", MidiChannel::kSampler);

    SequenceDesc desc;
    desc.notes = {
        {Bibimbap::marimbaloop}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},

        {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},
        {}, {}, {}, {}, {}, {}, {},
    };
    desc.rate = 4;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapBass(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Bass", MidiChannel::kBass);
    track.setPattern(BibimbapPatterns::kBibimbapBass, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapHats(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Hats", MidiChannel::kDrums);
    track.setPattern(BibimbapPatterns::kBibimbapHats, lengthInTicks, startInTicks);
    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapRiser(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Riser", MidiChannel::kSampler);

    makeRiser(track, Bibimbap::bbbRiz, lengthInTicks, TICK(0,7));

    return track;
}

SequenceTrack BibimbapTrackFactory::bibimbapSnareRoll(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("SnareRoll", MidiChannel::kDrums);

    makeRoll(track, Bibimbap::sd1050, lengthInTicks, startInTicks, 20, 127);

    return track;
}
