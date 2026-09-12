#pragma once

#include <Arduino.h>
#include <cstdint>

#include "TempoInterval.h"
#include "TickHelper.h"
#include "drivers/Ticker.h"
#include "platform/Callback.h"

namespace GigaSeq {

using TickCallback = void (*)(void* context);

// Hardware-backed transport clock using mbed::Ticker (STM32H7 us_ticker).
// The tick callback runs in ISR context: anything it calls must be IRQ-safe.
class TransportClock {
public:
    static constexpr uint16_t kPpqn = TickHelper::kTicksPerQuarterNote;
    static constexpr uint8_t kBeatsPerBar = 4;

    TransportClock();

    void begin(uint16_t bpm = 120);
    void start();
    void stop();
    void toggleStartStop();
    void setTempo(uint16_t bpm);
    void setOnTick(TickCallback callback, void* context = nullptr);

    bool isPlaying() const;

private:
    // Overrides Ticker rescheduling so each period is last_deadline + N/N+1 µs
    // (absolute), never now() + interval. Re-attaching from the ISR was adding
    // callback latency and pulling the tempo down.
    class Scheduler : public mbed::Ticker {
    public:
        explicit Scheduler(TransportClock& owner);

    protected:
        void handler() override;

    private:
        TransportClock& owner_;
    };

    void invokeTick();

    TickCallback tickCallback_ = nullptr;
    void* tickContext_ = nullptr;
    TempoInterval interval_;
    uint16_t bpm_ = 120;
    volatile uint16_t pendingBpm_ = 120;
    volatile bool playing_ = false;
    volatile bool intervalDirty_ = false;
    Scheduler scheduler_;
};

}  // namespace GigaSeq
