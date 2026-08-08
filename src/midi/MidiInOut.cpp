#include "MidiInOut.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

namespace GigaSeq {

void MidiInOut::begin(uint8_t channel) {
    Serial1.begin(31250);
    Serial.begin(9600);
    MIDI.begin(channel);
}

void MidiInOut::read() {
    MIDI.read();
}

void MidiInOut::sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) {
    MIDI.sendNoteOn(note, velocity, channel);
}

void MidiInOut::sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) {
    MIDI.sendNoteOff(note, velocity, channel);
}

}  // namespace GigaSeq
