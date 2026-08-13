#include "GigaMidiInOut.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

namespace GigaSeq {

void GigaMidiInOut::begin(uint8_t channel) {
    Serial1.begin(31250);
    MIDI.begin(channel);
}

void GigaMidiInOut::read() {
    MIDI.read();
}

void GigaMidiInOut::sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) {
    MIDI.sendNoteOn(note, velocity, channel);
}

void GigaMidiInOut::sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) {
    MIDI.sendNoteOff(note, velocity, channel);
}

void GigaMidiInOut::sendControlChange(uint8_t channel, uint8_t controller, uint8_t value) {
    MIDI.sendControlChange(controller, value, channel);
}

void GigaMidiInOut::sendProgramChange(uint8_t channel, uint8_t program) {
    MIDI.sendProgramChange(program, channel);
}

void GigaMidiInOut::sendClock() {
    MIDI.sendClock();
}

void GigaMidiInOut::sendStart() {
    MIDI.sendStart();
}

void GigaMidiInOut::sendStop() {
    MIDI.sendStop();
}

}  // namespace GigaSeq
