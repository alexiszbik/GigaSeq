#pragma once

#include "Tick.h"

#include <cstdint>

struct ControlAutomation
{
    tick_t startTick = 0;
    tick_t endTick = 0;
    uint8_t controller = 0;
    uint8_t startValue = 0;
    uint8_t endValue = 0;
};

constexpr uint8_t kAutomationNotSent = 255;

inline uint8_t automationValueAt(const ControlAutomation& automation, tick_t position) noexcept
{
    if (automation.startTick >= automation.endTick) {
        return automation.endValue;
    }

    const tick_t duration = automation.endTick - automation.startTick;
    const tick_t delta = position - automation.startTick;
    const int range = static_cast<int>(automation.endValue) - automation.startValue;

    return static_cast<uint8_t>(
        automation.startValue + range * static_cast<int>(delta) / static_cast<int>(duration));
}
