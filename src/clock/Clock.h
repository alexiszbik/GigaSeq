#pragma once

#include <Arduino.h>
#include <cstdint>

#if defined(__MBED__)
#include "drivers/Ticker.h"
#include "platform/Callback.h"
#endif

namespace GigaSeq {

using TickCallback = void (*)(uint32_t tick, void* context);

// Hardware-backed transport clock using mbed::Ticker (STM32H7 us_ticker).
// The tick callback runs in ISR context: anything it calls must be IRQ-safe.
class TransportClock {
public:
    static constexpr uint16_t kPpqn = 96;
    static constexpr uint8_t kBeatsPerBar = 4;

    void begin(uint16_t bpm = 120);
    void start();
    void stop();
    void toggleStartStop();
    void setTempo(uint16_t bpm);
    void setOnTick(TickCallback callback, void* context = nullptr);

    bool isPlaying() const;
    uint32_t getRawTick() const;
    uint16_t getBar() const;
    uint8_t getBeat() const;
    uint8_t getTick() const;

private:
    void onTicker();
    static uint32_t intervalFor(uint16_t bpm);

    static TransportClock* instance_;

    TickCallback tickCallback_ = nullptr;
    void* tickContext_ = nullptr;
    volatile uint32_t currentTick_ = 0;
    uint32_t intervalUs_ = 0;
    uint16_t bpm_ = 120;
    volatile bool playing_ = false;

#if defined(__MBED__)
    mbed::Ticker ticker_;
#endif
};

}  // namespace GigaSeq
