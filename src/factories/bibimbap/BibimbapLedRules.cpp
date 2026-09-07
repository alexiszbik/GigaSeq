#include "BibimbapLedRules.h"
#include "BibimbapSamples.h"

#include "MidiChannel.h"
#include "MidiConst.h"

BibimbapLedRules kBibimbapLedRules;

bool isKickNote(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbKickhi
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isTomNote(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbTom1
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isRim(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbRim
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isSnare(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbSnr
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isDizzee(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::bbbDz
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

bool isBass(uint8_t channel, uint8_t note)
{
    return channel == MidiChannel::kBass;
}

bool isDropSnare(uint8_t channel, uint8_t note)
{
    return note == Bibimbap::sd1050
        && (channel == MidiChannel::kDrums || channel == MidiChannel::kSampler);
}

void BibimbapLedRules::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
    if (isKickNote(channel, note.note)) {
        addNote(MidiChannel::kMatrix, LedMatrix::kBibimbap_vu_noteA_note, 127, durationTicks, midi);
        return;
    }

    if (isTomNote(channel, note.note)) {
        addNote(MidiChannel::kMatrix, LedMatrix::kBibimbap_vu_noteB_note, 127, durationTicks, midi);
    }

    if (isRim(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kWhite_ALL, 127, durationTicks, midi);
    }

    if (isSnare(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_A, 127, durationTicks, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_B, 127, durationTicks, midi);
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_C, 127, durationTicks, midi);
    }

    if (isDizzee(channel, note.note)) {
        const uint8_t ledNote = LedStrips::kGreenLedsRandom.nextRandom();
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
    }

    if (isBass(channel, note.note)) {
        addNote(MidiChannel::kLedStrips, LedStrips::kGreen_D, 127, durationTicks, midi);
    }

    if (isDropSnare(channel, note.note)) {
        const uint8_t ledNote = LedStrips::kWhiteLedsRandom.nextRandom();
        addNote(MidiChannel::kLedStrips, ledNote, note.velocity, durationTicks, midi);
    }
}
