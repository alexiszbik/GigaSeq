#pragma once

#include <Arduino.h>

namespace GigaSeq {

using TickCallback = void (*)(uint32_t tick, void* context);

class TransportClock {
public:
    static constexpr uint8_t kPpqn = 24;
    static constexpr uint8_t kBeatsPerBar = 4;

    void begin(uint16_t bpm = 120);
    void run();
    void start();
    void stop();
    void toggleStartStop();
    void setTempo(uint16_t bpm);
    void setOnTick(TickCallback callback, void* context = nullptr);

    uint16_t getBar() const;
    uint8_t getBeat() const;
    uint8_t getTick() const;

private:
    static void onOutputPPQN(uint32_t tick);

    TickCallback tickCallback_ = nullptr;
    void* tickContext_ = nullptr;
    uint32_t currentTick_ = 0;
    static TransportClock* instance_;

    bool isPlaying = false;
};

}  // namespace GigaSeq
