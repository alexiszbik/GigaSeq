#pragma once

#include "MidiInOut.h"
#include "Sequence.h"
#include "StringHelper.h"

#include <cstddef>
#include <vector>

class Song
{
public:
    static constexpr std::size_t kNameMaxLength = 12;

    explicit Song(const char* name);

    const char* name() const noexcept { return name_; }

    void add(Sequence sequence);
    std::size_t size() const noexcept { return sequences_.size(); }

    Sequence& sequence(std::size_t index);
    const Sequence& sequence(std::size_t index) const;

    void attachMidi(MidiInOut& midi);
    void allNotesOff();

private:
    char name_[kNameMaxLength + 1] = {};
    std::vector<Sequence> sequences_;
};
