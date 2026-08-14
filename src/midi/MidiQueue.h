#pragma once

#include <cstdint>

enum class MidiEventType : uint8_t
{
    NoteOn,
    NoteOff,
    ControlChange,
    ProgramChange,
    Clock,
    Start,
    Stop
};

struct MidiEvent
{
    MidiEventType type;
    uint8_t channel = 0;
    uint8_t data1 = 0;
    uint8_t data2 = 0;
};

class MidiQueue
{
public:
    static constexpr uint8_t kCapacity = 128;

    bool push(const MidiEvent &event);
    bool peek(MidiEvent &out) const;
    bool pop();
    bool empty() const { return count_ == 0; }
    bool full() const { return count_ >= kCapacity; }
    uint8_t size() const { return count_; }

private:
    MidiEvent buffer_[kCapacity];
    uint8_t head_ = 0;
    uint8_t tail_ = 0;
    uint8_t count_ = 0;
};
