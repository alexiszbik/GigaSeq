#include "SequenceFactory.h"

#include "SequenceTrackFactory.h"

namespace
{
using TrackBuilder = SequenceTrack (*)(tick_t lengthInTicks);

Sequence buildSequence(
    int barCount,
    int beatsPerBar,
    int barLoop,
    const char* name,
    uint8_t tempo,
    bool isLooping,
    std::vector<TrackBuilder> builders)
{
    Sequence sequence(name, tempo, barCount, beatsPerBar, barLoop, isLooping);
    const tick_t length = sequence.lengthInTicks();

    for (auto& tb : builders) {
        sequence.addTrack(tb(length));
    }
    
    return sequence;
}
} // namespace

Sequence SequenceFactory::togetherIntro()
{
    return buildSequence(
        8, 4, 0, "Intro", 130, true,
        {
            SequenceTrackFactory::togetherArp
        });
}

Sequence SequenceFactory::togetherSample()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Sample", 130, true,
        {
            SequenceTrackFactory::togetherArp,
            SequenceTrackFactory::togetherHiDrum,
            SequenceTrackFactory::togetherSample,
            SequenceTrackFactory::togetherDX7
        });

    seq.track(2).setStartMuted();
    seq.track(3).setStartMuted();

    return seq;
}

Sequence SequenceFactory::togetherKick()
{
    return buildSequence(
        8, 4, 0, "Kick", 130, true,
        {
            SequenceTrackFactory::togetherArp,
            SequenceTrackFactory::togetherHiDrum,
            SequenceTrackFactory::togetherSample,
            SequenceTrackFactory::togetherDX7,
            SequenceTrackFactory::kickFour
        });
}

Sequence SequenceFactory::togetherVocoder()
{
    return buildSequence(
        36, 4, 36, "Vocoder", 130, false,
        {
            SequenceTrackFactory::togetherVocoderPartArp,
            SequenceTrackFactory::togetherVocoderPartHiDrum,
            SequenceTrackFactory::togetherVocoderPartSample,
            SequenceTrackFactory::togetherVocoderPartDX7,
            SequenceTrackFactory::togetherVocoderPartKick,
            SequenceTrackFactory::togetherVocoder,
            SequenceTrackFactory::togetherVocoderPartExtraBass,
            SequenceTrackFactory::togetherEndRiser
        });
}

Sequence SequenceFactory::togetherPartB()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Part B", 130, true,
        {
            SequenceTrackFactory::togetherPartBSampleCut,
            SequenceTrackFactory::togetherPartBSynth,
            SequenceTrackFactory::togetherPartBAh,
            SequenceTrackFactory::togetherPartBDaDaDa,
        });

    seq.track(2).setStartMuted();
    seq.track(3).setStartMuted();

    return seq;
}

Sequence SequenceFactory::togetherPartBWithHats()
{
    return buildSequence(
        16, 4, 0, "Part B Hats", 130, false,
        {
            SequenceTrackFactory::togetherPartBSampleCut,
            SequenceTrackFactory::togetherPartBSynth,
            SequenceTrackFactory::togetherPartBAh,
            SequenceTrackFactory::togetherPartBDaDaDa,
            SequenceTrackFactory::togetherPartBHat
        });
}

Sequence SequenceFactory::togetherPartBDrums()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Part B Drums", 130, true,
        {
            SequenceTrackFactory::togetherPartBSynth,
            SequenceTrackFactory::togetherPartBAh,
            SequenceTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::togetherPartBJC,
            SequenceTrackFactory::togetherPartBTambourin
        });

    seq.track(4).setStartMuted();
    seq.track(5).setStartMuted();

    return seq;
}

Sequence SequenceFactory::togetherPartBClimax()
{
    Sequence seq = buildSequence(
        8, 4, 0, "Part B Climax", 130, true,
        {
            SequenceTrackFactory::togetherPartBSynth,
            SequenceTrackFactory::togetherPartBAh,
            SequenceTrackFactory::togetherHiDrum,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::togetherPartBJC,
            SequenceTrackFactory::togetherPartBTambourin,
            SequenceTrackFactory::togetherPartBCymbal,
            SequenceTrackFactory::togetherEndRiser
        });

    seq.track(7).addMuteEvent(0);
    return seq;
}

Sequence SequenceFactory::createSequenceOne()
{
    return buildSequence(
        2, 7, 1, "Kick/Hat12345", 120, true,
        { 
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createPluck,
            SequenceTrackFactory::createLead,
        });
}

Sequence SequenceFactory::createSequenceTwo()
{
    return buildSequence(
        4, 4, 2, "F on Flour", 140, true,
        {
            SequenceTrackFactory::createCMaj7Arpeggio,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createRimshot,
            SequenceTrackFactory::createCowbell,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createArpFast,
        });
}

Sequence SequenceFactory::createSequenceThree()
{
    Sequence sequence = buildSequence(
        4, 4, 0, "Am7Hi-Hat", 165, true,
        {
            SequenceTrackFactory::createAm7Arpeggio,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createClave,
            SequenceTrackFactory::createTomFill,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createLead,
        });

    const tick_t bar2Tick = static_cast<tick_t>(1 * 4 * Sequence::kTicksPerQuarterNote);
    const tick_t bar4Tick = static_cast<tick_t>(3 * 4 * Sequence::kTicksPerQuarterNote);
    sequence.addTempoEvent(bar2Tick, 140);
    sequence.addTempoEvent(bar4Tick, 165);

    return sequence;
}

Sequence SequenceFactory::createSequenceFour()
{
    return buildSequence(
        4, 4, 0, "Pads", 90, true,
        {
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createFxBleep,
        });
}

Sequence SequenceFactory::createSequenceFive()
{
    return buildSequence(
        4, 4, 1, "Melodic", 104, true,
        {
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createRimshot,
            SequenceTrackFactory::createClave,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createLead,
            SequenceTrackFactory::createPluck,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createArpFast,
        });
}

Sequence SequenceFactory::createSequenceSix()
{
    return buildSequence(
        4, 4, 2, "Stabs", 115, true,
        {
            SequenceTrackFactory::createSynthStabs,
            SequenceTrackFactory::createKickSnareWithHats,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createSnareBackbeat,
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createCowbell,
            SequenceTrackFactory::createBassLine,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createChordStab,
            SequenceTrackFactory::createLead,
            SequenceTrackFactory::createGtrChug,
        });
}

Sequence SequenceFactory::createSequenceSeven()
{
    return buildSequence(
        2, 4, 0, "Clap", 155, true,
        {
            SequenceTrackFactory::createClapBackbeat,
            SequenceTrackFactory::createMelodicBass,
            SequenceTrackFactory::kickFour,
            SequenceTrackFactory::createKickSnare,
            SequenceTrackFactory::createHiHatPattern,
            SequenceTrackFactory::createOpenHat,
            SequenceTrackFactory::createCymbalRide,
            SequenceTrackFactory::createRimshot,
            SequenceTrackFactory::createTambourine,
            SequenceTrackFactory::createShaker,
            SequenceTrackFactory::createClave,
            SequenceTrackFactory::createTomFill,
            SequenceTrackFactory::createSubBass,
            SequenceTrackFactory::createPadChords,
            SequenceTrackFactory::createPadSwells,
            SequenceTrackFactory::createFxBleep,
        });
}
