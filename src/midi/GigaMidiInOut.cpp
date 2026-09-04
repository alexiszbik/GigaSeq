#include "GigaMidiInOut.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

namespace GigaSeq {

GigaMidiInOut* GigaMidiInOut::instance_ = nullptr;

void GigaMidiInOut::onNoteOn(byte channel, byte note, byte velocity) {
    if (instance_ != nullptr) {
        instance_->sendNoteOn(note, velocity, channel - 1);
    }
}

void GigaMidiInOut::onNoteOff(byte channel, byte note, byte velocity) {
    if (instance_ != nullptr) {
        instance_->sendNoteOff(note, velocity, channel - 1);
    }
}

void GigaMidiInOut::onControlChange(byte channel, byte control, byte value) {
    if (instance_ != nullptr && channel != 1 /* dont use control change from keyboard */) {
        instance_->sendControlChange(channel - 1, control, value);
    }
}

void GigaMidiInOut::begin(uint8_t channel) {
    instance_ = this;

    Serial1.begin(31250);

    MIDI.setHandleNoteOn(onNoteOn);
    MIDI.setHandleNoteOff(onNoteOff);
    MIDI.setHandleControlChange(onControlChange);

    MIDI.begin(channel);
    MIDI.turnThruOff();
}

void GigaMidiInOut::read() {
    MIDI.read();
}

void GigaMidiInOut::sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) {
    MidiEvent e;
    e.type = MidiEventType::NoteOn;
    e.channel = channel;
    e.data1 = note;
    e.data2 = velocity;
    queue_.push(e);
}

void GigaMidiInOut::sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) {
    MidiEvent e;
    e.type = MidiEventType::NoteOff;
    e.channel = channel;
    e.data1 = note;
    e.data2 = velocity;
    queue_.push(e);
}

void GigaMidiInOut::sendControlChange(uint8_t channel, uint8_t controller, uint8_t value) {
    MidiEvent e;
    e.type = MidiEventType::ControlChange;
    e.channel = channel;
    e.data1 = controller;
    e.data2 = value;
    queue_.push(e);
}

void GigaMidiInOut::sendProgramChange(uint8_t channel, uint8_t program) {
    MidiEvent e;
    e.type = MidiEventType::ProgramChange;
    e.channel = channel;
    e.data1 = program;
    queue_.push(e);
}

void GigaMidiInOut::sendClock() {
    MidiEvent e;
    e.type = MidiEventType::Clock;
    queue_.push(e);
}

void GigaMidiInOut::sendStart() {
    MidiEvent e;
    e.type = MidiEventType::Start;
    queue_.push(e);
}

void GigaMidiInOut::sendStop() {
    MidiEvent e;
    e.type = MidiEventType::Stop;
    queue_.push(e);
}

void GigaMidiInOut::write1(uint8_t b) {
    Serial1.write(b);
}

void GigaMidiInOut::write2(uint8_t b1, uint8_t b2) {
    Serial1.write(b1);
    Serial1.write(b2);
}

void GigaMidiInOut::write3(uint8_t b1, uint8_t b2, uint8_t b3) {
    Serial1.write(b1);
    Serial1.write(b2);
    Serial1.write(b3);
}

bool GigaMidiInOut::flush() {
    MidiEvent e;
    if (queue_.peek(e)) {
        const uint8_t statusChannel = e.channel;

        switch (e.type) {
            case MidiEventType::NoteOn:
                write3(0x90 | statusChannel, e.data1, e.data2);
                break;
            case MidiEventType::NoteOff:
                write3(0x80 | statusChannel, e.data1, e.data2);
                break;
            case MidiEventType::ControlChange:
                write3(0xB0 | statusChannel, e.data1, e.data2);
                break;
            case MidiEventType::ProgramChange:
                write2(0xC0 | statusChannel, e.data1);
                break;
            case MidiEventType::Clock:
                write1(0xF8);
                break;
            case MidiEventType::Start:
                write1(0xFA);
                break;
            case MidiEventType::Stop:
                write1(0xFC);
                break;
        }

        queue_.pop();
        return true;
    }
    return false;
}

}  // namespace GigaSeq
