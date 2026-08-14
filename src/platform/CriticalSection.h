#pragma once

// RAII wrapper around mbed critical section (disables interrupts).
// Use to make shared data (ring buffers, counters) safe between ISR and
// thread context.

#include "platform/mbed_critical.h"

class CriticalSection {
public:
    CriticalSection() {
        core_util_critical_section_enter();
    }
    ~CriticalSection() {
        core_util_critical_section_exit();
    }
    CriticalSection(const CriticalSection&) = delete;
    CriticalSection& operator=(const CriticalSection&) = delete;
};
