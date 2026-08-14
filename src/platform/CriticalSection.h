#pragma once

// RAII wrapper around mbed critical section (disables interrupts).
// Use to make shared data (ring buffers, counters) safe between ISR and
// thread context. No-op on non-mbed builds.

#if defined(__MBED__)
#include "platform/mbed_critical.h"
#endif

class CriticalSection {
public:
    CriticalSection() {
#if defined(__MBED__)
        core_util_critical_section_enter();
#endif
    }
    ~CriticalSection() {
#if defined(__MBED__)
        core_util_critical_section_exit();
#endif
    }
    CriticalSection(const CriticalSection&) = delete;
    CriticalSection& operator=(const CriticalSection&) = delete;
};
