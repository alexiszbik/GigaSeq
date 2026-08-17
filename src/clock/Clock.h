#pragma once

#include <Arduino.h>
#include <cstdint>

#include "drivers/Ticker.h"
#include "platform/Callback.h"

namespace GigaSeq {

using TickCallback = void (*)(void* context);

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

private:
    void onTicker();
    static uint32_t intervalFor(uint16_t bpm);

    static TransportClock* instance_;

    TickCallback tickCallback_ = nullptr;
    void* tickContext_ = nullptr;
    uint32_t intervalUs_ = 0;
    volatile uint32_t pendingIntervalUs_ = 0;
    uint16_t bpm_ = 120;
    volatile bool playing_ = false;
    volatile bool intervalDirty_ = false;

    mbed::Ticker ticker_;
};

}  // namespace GigaSeq
