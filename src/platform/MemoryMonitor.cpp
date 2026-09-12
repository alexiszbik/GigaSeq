#include "MemoryMonitor.h"

#include <cstdio>

#ifdef ARDUINO
#include <mbed_stats.h>
#endif

bool getHeapStats(HeapStats& stats)
{
#ifdef ARDUINO
    mbed_stats_heap_t heapStats{};
    mbed_stats_heap_get(&heapStats);

    stats.used = heapStats.current_size;
    stats.reserved = heapStats.reserved_size;
    stats.free = (stats.reserved > stats.used) ? (stats.reserved - stats.used) : 0;
    stats.maxUsed = heapStats.max_size;
    stats.allocFails = heapStats.alloc_fail_cnt;
    return true;
#else
    (void)stats;
    return false;
#endif
}

void formatHeapStatsForDisplay(const HeapStats& stats, char* buffer, size_t size)
{
    std::snprintf(
        buffer,
        size,
        "RAM free: %lu KB\n%lu / %lu KB used",
        static_cast<unsigned long>(stats.free / 1024),
        static_cast<unsigned long>(stats.used / 1024),
        static_cast<unsigned long>(stats.reserved / 1024));
}
