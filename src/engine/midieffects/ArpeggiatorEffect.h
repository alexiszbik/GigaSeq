#pragma once

#include "midieffects/MidiEffect.h"
#include "TickHelper.h"

#include <cstdint>

//TODO : Right now we only made Arppegiator for Together wih a specific setup

enum class ArpDirection : uint8_t
{
    DownUp,
};

class ArpeggiatorEffect : public MidiEffect
{
public:
    ArpeggiatorEffect(uint8_t octaves, uint8_t rate, ArpDirection direction);

    void reset() override;
    
    void onSourceNote(const Note& note, tick_t durationTicks, tick_t startTick) override;

    void processTick(
        tick_t tick,
        uint8_t channel,
        ActiveNotePool& activeNotes,
        MidiInOut& midi) override;

private:
    uint8_t pitchForStep();

    uint8_t octaves_ = 2;
    uint8_t rate_ = 16;
    ArpDirection direction_ = ArpDirection::DownUp;

    uint8_t rootPitch_ = 0;
    uint8_t velocity_ = 127;
    tick_t startTick_ = 0;
    tick_t durationTicks_ = 0;

    uint8_t currentOctave = 0;
    bool isGoingUp = false;
};

extern ArpeggiatorEffect kTogetherArpeggiator;
