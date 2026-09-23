#include "MidiClock.h"
#include "SequencerConsoleUI.h"
#include "TerminalLogger.h"
#include "UiTerminalLogger.h"
#include "VirtualMidiSender.h"
#include "SequencePool.h"

#include <curses.h>
#include <csignal>
#include <cstdio>

namespace
{
volatile std::sig_atomic_t gKeepRunning = 1;

SequencePool* gPool = nullptr;
SequencerConsoleUI* gUi = nullptr;
Logger* gLogger = nullptr;
MidiClock* gClock = nullptr;

void handleSignal(int)
{
    gKeepRunning = 0;
}

void onSequenceChanged()
{
    if (gUi != nullptr) {
        gUi->resetTrackSelection();
        gUi->requestRedraw();
    }

    if (gPool != nullptr && gClock != nullptr) {
        try {
            gClock->setBpm(static_cast<double>(gPool->current().getTempo()));
        } catch (const std::exception& error) {
            if (gLogger != nullptr) {
                char buffer[128];
                std::snprintf(buffer, sizeof(buffer), "%s", error.what());
                gLogger->info(buffer);
            }
        }
    }
}

void onTrackMuteChanged(uint8_t, bool)
{
    if (gUi != nullptr) {
        gUi->requestRedraw();
    }
}

void onTempoChanged(uint8_t bpm)
{
    if (gClock == nullptr) {
        return;
    }

    try {
        gClock->setBpm(static_cast<double>(bpm));
    } catch (const std::exception& error) {
        if (gLogger != nullptr) {
            char buffer[128];
            std::snprintf(buffer, sizeof(buffer), "%s", error.what());
            gLogger->info(buffer);
        }
    }

    if (gUi != nullptr) {
        gUi->requestRedraw();
    }
}

void onPlaybackStop()
{
    if (gClock != nullptr && gClock->isPlaying()) {
        gClock->stop();
    }

    if (gUi != nullptr) {
        gUi->requestRedraw();
    }
}

void handleAction(ConsoleAction action, SequencePool& pool, MidiClock& clock)
{
    switch (action) {
    case ConsoleAction::TogglePlay:
        if (clock.isPlaying()) {
            clock.stop();
        } else {
            clock.play();
        }
        break;
    case ConsoleAction::Next:
        pool.requestNext(!clock.isPlaying());
        break;
    case ConsoleAction::Back:
        pool.requestPrevious(!clock.isPlaying());
        break;
    case ConsoleAction::Quit:
        gKeepRunning = 0;
        break;
    case ConsoleAction::None:
        break;
    }
}
} // namespace

int main()
{
    std::signal(SIGINT, handleSignal);

    constexpr auto kPortName = "GigaSeq Virtual";

    try {
        SequencerConsoleUI ui;
        if (!ui.init()) {
            return 1;
        }

        UiTerminalLogger logger(ui);
        VirtualMidiSender sender(kPortName, logger);
        MidiClock clock(sender, logger);
        SequencePool pool = SequencePool::createDefault(sender, logger);

        ui.setPool(&pool);
        ui.setClock(&clock);

        gPool = &pool;
        gUi = &ui;
        gLogger = &logger;
        gClock = &clock;

        pool.setOnSequenceChanged(onSequenceChanged);
        pool.setOnTrackMuteChanged(onTrackMuteChanged);
        pool.setOnTempoChanged(onTempoChanged);
        pool.setOnPlaybackStop(onPlaybackStop);

        clock.setBpm(static_cast<double>(pool.current().getTempo()));

        clock.setOnPlay([&pool]() {
            pool.resetCurrent();
        });

        clock.setOnTick([&pool, &ui](int) {
            pool.processTick();
            ui.requestRedraw();
        });

        clock.setOnStop([&pool, &ui]() {
            pool.allNotesOff();
            ui.requestRedraw();
        });

        char buffer[64];
        std::snprintf(
            buffer,
            sizeof(buffer),
            "Loaded %zu songs (%zu sequences)",
            pool.songCount(),
            pool.sequenceCount());
        logger.info(buffer);
        logger.info("Ready - p play/stop, s song, n/b seq, tracks: Up/Down Enter mute.");

        pool.sendProgramChange();

        while (gKeepRunning) {
            ConsoleAction action = ConsoleAction::None;
            if (ui.pollAndDraw(50, action)) {
                handleAction(action, pool, clock);
            }
        }

        clock.stop();
        ui.shutdown();
    } catch (const std::exception& error) {
        endwin();
        char buffer[256];
        std::snprintf(buffer, sizeof(buffer), "Error: %s\n", error.what());
        TerminalLogger fallback;
        fallback.error(buffer);
        return 1;
    }

    return 0;
}
