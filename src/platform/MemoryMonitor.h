#pragma once

#include <cstddef>
#include <cstdint>

struct HeapStats
{
    uint32_t used = 0;
    uint32_t free = 0;
    uint32_t reserved = 0;
    uint32_t maxUsed = 0;
    uint32_t allocFails = 0;
};

// Fill heap stats on Arduino Giga (mbed). Returns false on desktop builds.
bool getHeapStats(HeapStats& stats);

// Short 2-line text for on-screen display.
void formatHeapStatsForDisplay(const HeapStats& stats, char* buffer, size_t size);
