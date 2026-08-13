#include "EngineMidiBridge.h"

EngineMidiBridge::EngineMidiBridge(GigaSeq::GigaMidiInOut& midi) : midi_(midi) {}

void EngineMidiBridge::sendClock() {
    midi_.sendClock();
}

void EngineMidiBridge::sendStart() {
    midi_.sendStart();
}

void EngineMidiBridge::sendStop() {
    midi_.sendStop();
}

void EngineMidiBridge::sendNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    midi_.sendNoteOn(note, velocity, channel);
}

void EngineMidiBridge::sendNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
    midi_.sendNoteOff(note, velocity, channel);
}

void EngineMidiBridge::sendControlChange(uint8_t channel, uint8_t controller, uint8_t value) {
    midi_.sendControlChange(channel, controller, value);
}

void EngineMidiBridge::sendProgramChange(uint8_t channel, uint8_t program) {
    midi_.sendProgramChange(channel, program);
}
