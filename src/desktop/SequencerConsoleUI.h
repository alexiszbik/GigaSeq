#pragma once

#include "MidiClock.h"
#include "SequencePool.h"

#include <cstddef>
#include <deque>
#include <mutex>
#include <string>

enum class ConsoleAction
{
    None,
    TogglePlay,
    Quit,
    Next,
    Back,
};

enum class ListPanel
{
    Tracks,
    Songs,
    Sequences,
};

class SequencerConsoleUI
{
public:
    SequencerConsoleUI() = default;
    ~SequencerConsoleUI();

    SequencerConsoleUI(const SequencerConsoleUI&) = delete;
    SequencerConsoleUI& operator=(const SequencerConsoleUI&) = delete;

    bool init();
    void shutdown();

    //Todo, remove setPool & setClock as they can be passed by the ctor
    void setPool(SequencePool* pool) noexcept { pool_ = pool; }
    void setClock(MidiClock* clock) noexcept { clock_ = clock; }

    void appendLog(const std::string& line);
    void requestRedraw() noexcept { dirty_ = true; }
    void redrawNow();
    void resetTrackSelection() noexcept
    {
        selectedTrackIndex_ = 0;
        listPanel_ = ListPanel::Tracks;
    }

    bool pollAndDraw(int timeoutMs, ConsoleAction& action);

private:
    void drawFrame();

    void clampSelectedTrack();
    void clampSelectedSong();
    void clampSelectedSequence();

    void enterSongSelectMode();
    void enterSequenceSelectMode();

    void confirmSongSelection();
    void confirmSequenceSelection();
    void toggleSelectedTrackMute();


    static std::string trimTrailingNewlines(const std::string& text);
    static std::string sanitizeForDisplay(const std::string& text);

    SequencePool* pool_ = nullptr;
    MidiClock* clock_ = nullptr;

    std::mutex logMutex_;
    std::deque<std::string> logLines_;

    std::size_t selectedTrackIndex_ = 0;
    std::size_t selectedSequenceIndex_ = 0;
    std::size_t selectedSongIndex_ = 0;

    ListPanel listPanel_ = ListPanel::Tracks;
    bool active_ = false;
    bool dirty_ = true;
};
