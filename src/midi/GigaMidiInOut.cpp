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
    //while (queue_.peek(e)) {
    if (queue_.peek(e)) {
        const uint8_t statusChannel = e.channel > 0 ? (e.channel - 1) : 0;

        bool sent = false;
        switch (e.type) {
            case MidiEventType::NoteOn:
                sent = write3(0x90 | statusChannel, e.data1, e.data2);
                break;
            case MidiEventType::NoteOff:
                sent = write3(0x80 | statusChannel, e.data1, e.data2);
                break;
            case MidiEventType::ControlChange:
                sent = write3(0xB0 | statusChannel, e.data1, e.data2);
                break;
            case MidiEventType::ProgramChange:
                sent = write2(0xC0 | statusChannel, e.data1);
                break;
            case MidiEventType::Clock:
                sent = write1(0xF8);
                break;
            case MidiEventType::Start:
                sent = write1(0xFA);
                break;
            case MidiEventType::Stop:
                sent = write1(0xFC);
                break;
        }

        queue_.pop();
        return true;
    }
    return false;
    //}
}

}  // namespace GigaSeq
