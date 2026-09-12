#pragma once

#include "MidiInOut.h"
#include "Sequence.h"

#include <cstddef>
#include <vector>

class Song
{
public:
    explicit Song(const char* name, uint8_t programChange);

    const char* name() const noexcept { return name_; }

    uint8_t programChange() { return programChange_;  }

    void add(Sequence sequence);
    std::size_t size() const noexcept { return sequences_.size(); }

    Sequence& sequence(std::size_t index);
    const Sequence& sequence(std::size_t index) const;

    void attachMidi(MidiInOut& midi);
    void allNotesOff();

private:
    const char* name_ = "";
    std::vector<Sequence> sequences_;
    uint8_t programChange_;
};
