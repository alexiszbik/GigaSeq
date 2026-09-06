#include "TransposeInMidiRules.h"

TransposeInMidiRules kTransposeInMidiRules;

void TransposeInMidiRules::processNoteOn(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity,
    const InMidiRulesConfig& config,
    MidiInOut& midi)
{
    midi.sendNoteOn(channel, transposeMidiNote(note, config.transposeSemitones), velocity);
}

void TransposeInMidiRules::processNoteOff(
    uint8_t channel,
    uint8_t note,
    uint8_t velocity,
    const InMidiRulesConfig& config,
    MidiInOut& midi)
{
    midi.sendNoteOff(channel, transposeMidiNote(note, config.transposeSemitones), velocity);
}
