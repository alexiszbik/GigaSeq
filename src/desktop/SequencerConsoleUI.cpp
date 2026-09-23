#include "SequencerConsoleUI.h"

#include "TickHelper.h"
#include "TransportPosition.h"

#include <algorithm>
#include <curses.h>
#include <cstdio>

namespace {
constexpr int kLogLineLimit = 80;
constexpr int kHeaderRows = 6;
constexpr int kTrackListStartRow = kHeaderRows;

bool isEscapeKey(int key)
{
    return key == 27
#ifdef KEY_ESC
        || key == KEY_ESC
#endif
        ;
}

// After ESC, discard bytes from an incomplete function-key sequence.
void drainPendingInput()
{
    timeout(0);
    while (getch() != ERR) {
    }
}
}

SequencerConsoleUI::~SequencerConsoleUI()
{
    shutdown();
}

bool SequencerConsoleUI::init()
{
    if (active_) {
        return true;
    }

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    set_escdelay(25);
    timeout(0);
    curs_set(0);

    if (has_colors()) {
        start_color();
        use_default_colors();
        init_pair(1, COLOR_GREEN, -1);
        init_pair(2, COLOR_YELLOW, -1);
        init_pair(3, COLOR_RED, -1);
        init_pair(4, COLOR_CYAN, -1);
        init_pair(5, COLOR_MAGENTA, -1);
    }

    active_ = true;
    dirty_ = true;
    drawFrame();
    return true;
}

void SequencerConsoleUI::shutdown()
{
    if (!active_) {
        return;
    }

    endwin();
    active_ = false;
}

void SequencerConsoleUI::appendLog(const std::string& line)
{
    const std::string trimmed = sanitizeForDisplay(trimTrailingNewlines(line));
    if (trimmed.empty()) {
        return;
    }

    std::lock_guard<std::mutex> lock(logMutex_);
    logLines_.push_back(trimmed);
    while (logLines_.size() > static_cast<std::size_t>(kLogLineLimit)) {
        logLines_.pop_front();
    }
    dirty_ = true;
}

void SequencerConsoleUI::redrawNow()
{
    if (active_) {
        drawFrame();
    }
}

void SequencerConsoleUI::clampSelectedTrack()
{
    if (pool_ == nullptr) {
        selectedTrackIndex_ = 0;
        return;
    }

    const std::size_t trackCount = pool_->current().trackCount();
    if (trackCount == 0) {
        selectedTrackIndex_ = 0;
        return;
    }

    if (selectedTrackIndex_ >= trackCount) {
        selectedTrackIndex_ = trackCount - 1;
    }
}

void SequencerConsoleUI::toggleSelectedTrackMute()
{
    if (pool_ == nullptr) {
        return;
    }

    Sequence& sequence = pool_->current();
    clampSelectedTrack();

    if (sequence.trackCount() == 0) {
        return;
    }

    SequenceTrack& track = sequence.track(selectedTrackIndex_);
    sequence.setTrackMuted(selectedTrackIndex_, !track.isMuted());
}

void SequencerConsoleUI::clampSelectedSong()
{
    if (pool_ == nullptr) {
        selectedSongIndex_ = 0;
        return;
    }

    const std::size_t songCount = pool_->songCount();
    if (songCount == 0) {
        selectedSongIndex_ = 0;
        return;
    }

    if (selectedSongIndex_ >= songCount) {
        selectedSongIndex_ = songCount - 1;
    }
}

void SequencerConsoleUI::clampSelectedSequence()
{
    if (pool_ == nullptr) {
        selectedSequenceIndex_ = 0;
        return;
    }

    const std::size_t seqCount = pool_->currentSong().size();
    if (seqCount == 0) {
        selectedSequenceIndex_ = 0;
        return;
    }

    if (selectedSequenceIndex_ >= seqCount) {
        selectedSequenceIndex_ = seqCount - 1;
    }
}

void SequencerConsoleUI::enterSongSelectMode()
{
    if (pool_ == nullptr || pool_->songCount() == 0) {
        return;
    }

    listPanel_ = ListPanel::Songs;
    selectedSongIndex_ = pool_->currentSongIndex();
    clampSelectedSong();
}

void SequencerConsoleUI::enterSequenceSelectMode()
{
    if (pool_ == nullptr || pool_->currentSong().size() == 0) {
        return;
    }

    listPanel_ = ListPanel::Sequences;
    selectedSequenceIndex_ = pool_->currentSequenceIndex();
    clampSelectedSong();
}

void SequencerConsoleUI::confirmSongSelection()
{
    if (pool_ == nullptr) {
        return;
    }

    clampSelectedSong();
    const bool switchNow = clock_ == nullptr || !clock_->isPlaying();
    pool_->requestSong(selectedSongIndex_, switchNow);
    listPanel_ = ListPanel::Tracks;
}

void SequencerConsoleUI::confirmSequenceSelection()
{
    if (pool_ == nullptr) {
        return;
    }

    clampSelectedSequence();
    const bool switchNow = clock_ == nullptr || !clock_->isPlaying();
    pool_->requestSequence(selectedSequenceIndex_, switchNow);
    listPanel_ = ListPanel::Tracks;
}

bool SequencerConsoleUI::pollAndDraw(int timeoutMs, ConsoleAction& action)
{
    if (!active_) {
        action = ConsoleAction::None;
        return false;
    }

    timeout(timeoutMs);
    const int key = getch();
    action = ConsoleAction::None;

    if (key != ERR) {
        dirty_ = true;

        if (key == 'q' || key == 'Q') {
            action = ConsoleAction::Quit;
        } else if (isEscapeKey(key)) {
            drainPendingInput();
            if (listPanel_ != ListPanel::Tracks) {
                listPanel_ = ListPanel::Tracks;
            }
        } else if (key == 'p' || key == 'P') {
            action = ConsoleAction::TogglePlay;
        } else if (key == 's' || key == 'S') {
            if (listPanel_ != ListPanel::Songs) {
                enterSongSelectMode();
            }
        } 
        else if (key == 'z' || key == 'Z') {
            if (listPanel_ != ListPanel::Sequences) {
                enterSequenceSelectMode();
            }
        } else if (key == 'n' || key == 'N') {
            action = ConsoleAction::Next;
        } else if (key == 'b' || key == 'B') {
            action = ConsoleAction::Back;
        } else if (key == '\n' || key == KEY_ENTER) {
            if (listPanel_ == ListPanel::Songs) {
                confirmSongSelection();
            } else if (listPanel_ == ListPanel::Sequences) {
                confirmSequenceSelection();
            } 
        } else if (key == 'm' || key == 'M') {
            if (listPanel_ == ListPanel::Tracks) {
                toggleSelectedTrackMute();
            }
        } else if (key == KEY_UP) {
            if (listPanel_ == ListPanel::Songs) {
                if (selectedSongIndex_ > 0) {
                    --selectedSongIndex_;
                }
            } else if (listPanel_ == ListPanel::Sequences) {
                if (selectedSequenceIndex_ > 0) {
                    --selectedSequenceIndex_;
                }
            } else if (selectedTrackIndex_ > 0) {
                --selectedTrackIndex_;
            }
        } else if (key == KEY_DOWN) {
            if (listPanel_ == ListPanel::Songs) {
                if (pool_ != nullptr && selectedSongIndex_ + 1 < pool_->songCount()) {
                    ++selectedSongIndex_;
                }
            } else if (listPanel_ == ListPanel::Sequences) {
                if (pool_ != nullptr && selectedSequenceIndex_ + 1 < pool_->currentSong().size()) {
                    ++selectedSequenceIndex_;
                }
            } else if (pool_ != nullptr) {
                const std::size_t last = pool_->current().trackCount();
                if (last > 0 && selectedTrackIndex_ + 1 < last) {
                    ++selectedTrackIndex_;
                }
            }
        }
    }

    drawFrame();
    return action != ConsoleAction::None;
}

void SequencerConsoleUI::drawFrame()
{
    dirty_ = false;

    int maxRows = 0;
    int maxCols = 0;
    getmaxyx(stdscr, maxRows, maxCols);

    erase();

    if (pool_ == nullptr) {
        mvprintw(0, 0, "GigaSeq - no sequence pool");
        refresh();
        return;
    }

    clampSelectedTrack();
    clampSelectedSong();

    const Sequence& sequence = pool_->current();
    const Song& song = pool_->currentSong();

    const tick_t tickIndex = sequence.position() == 0 ? 0 : sequence.position() - 1;
    const TransportPosition transport = TransportPosition::fromTickIndex(
        tickIndex,
        sequence.beatsPerBar(),
        sequence.lengthInTicks());

    const int ticksPerBar = sequence.beatsPerBar() * TickHelper::kTicksPerQuarterNote;
    const int loopBar = static_cast<int>(sequence.loopInPoint() / ticksPerBar) + 1;


    attron(A_REVERSE);
    attron(A_BOLD);
    mvprintw(
        0,
        0,
        "Song: %s (%zu/%zu)  Sequence: %s (%zu/%zu)",
        song.name(),
        pool_->currentSongIndex() + 1,
        pool_->songCount(),
        sequence.name(),
        pool_->currentSequenceIndex() + 1,
        song.size());
    attroff(A_BOLD);
    attroff(A_REVERSE);

    mvprintw(
        1,
        0,
        "Bars: %d  Loop bar: %d  Loop: %s  Tempo: %u BPM",
        sequence.barCount(),
        loopBar,
        sequence.isLooping() ? "yes" : "no",
        sequence.getTempo());

    const char* transportState = "stopped";
    if (clock_ != nullptr && clock_->isPlaying()) {
        transportState = "playing";
    }

    mvprintw(
        2,
        0,
        "Transport: %s  Position: bar %d / %d  (%s)",
        transportState,
        transport.bar,
        sequence.barCount(),
        transport.toString().c_str());

    int listRow = kTrackListStartRow + 1;

    if (listPanel_ == ListPanel::Songs) {
        mvprintw(kTrackListStartRow, 0, "Songs (Up/Down, Enter=select, Esc=cancel):");
        for (std::size_t i = 0; i < pool_->songCount(); ++i) {
            if (listRow >= maxRows - 3) {
                break;
            }

            const Song& listSong = pool_->song(i);
            const bool selected = i == selectedSongIndex_;
            const bool current = i == pool_->currentSongIndex();

            if (selected) {
                attron(A_REVERSE);
            }

            if (has_colors() && current) {
                attron(COLOR_PAIR(2));
            }

            mvprintw(
                listRow,
                2,
                "[%zu] %-20s (%zu sequences)%s",
                i + 1,
                listSong.name(),
                listSong.size(),
                current ? " *" : "");

            if (has_colors() && current) {
                attroff(COLOR_PAIR(2));
            }

            if (selected) {
                attroff(A_REVERSE);
            }

            ++listRow;
        }
    } else if (listPanel_ == ListPanel::Sequences) {
        mvprintw(kTrackListStartRow, 0, "Sequences (Up/Down, Enter=select, Esc=cancel):");
        Song& song = pool_->currentSong();
        for (std::size_t i = 0; i < song.size(); ++i) {
            if (listRow >= maxRows - 3) {
                break;
            }

            const Sequence& seq = song.sequence(i);
            const bool selected = i == selectedSequenceIndex_;
            const bool current = i == pool_->currentSequenceIndex();

            if (selected) {
                attron(A_REVERSE);
            }

            if (has_colors() && current) {
                attron(COLOR_PAIR(2));
            }

            mvprintw(
                listRow,
                2,
                "[%zu] %-20s %s",
                i + 1,
                seq.name(),
                current ? " *" : "");

            if (has_colors() && current) {
                attroff(COLOR_PAIR(2));
            }

            if (selected) {
                attroff(A_REVERSE);
            }

            ++listRow;
        }
    } else {
        mvprintw(kTrackListStartRow, 0, "Tracks (Up/Down, Enter=mute):");
        for (std::size_t i = 0; i < sequence.trackCount(); ++i) {
            if (listRow >= maxRows - 3) {
                break;
            }

            const SequenceTrack& track = sequence.track(i);
            const char* muteLabel = track.isMuted() ? "muted" : "unmuted";
            const bool selected = i == selectedTrackIndex_;

            if (selected) {
                attron(A_REVERSE);
            }

            if (has_colors()) {
                attron(COLOR_PAIR(track.isMuted() ? 3 : 1));
            }

            mvprintw(
                listRow,
                2,
                "[%zu] %-24s %s",
                i,
                track.name(),
                muteLabel);

            if (has_colors()) {
                attroff(COLOR_PAIR(track.isMuted() ? 3 : 1));
            }

            if (selected) {
                attroff(A_REVERSE);
            }

            ++listRow;
        }
    }

    const int logHeaderRow = listRow + 1;
    if (logHeaderRow < maxRows - 2) {
        mvprintw(logHeaderRow, 0, "Log");
    }

    int logRow = logHeaderRow + 1;
    {
        std::lock_guard<std::mutex> lock(logMutex_);
        const int availableRows = std::max(0, maxRows - logHeaderRow - 2);
        const int startIndex = std::max(0, static_cast<int>(logLines_.size()) - availableRows);

        for (int i = startIndex; i < static_cast<int>(logLines_.size()); ++i) {
            if (logRow >= maxRows - 1) {
                break;
            }

            const std::string& line = logLines_[static_cast<std::size_t>(i)];
            mvprintw(logRow, 2, "%.*s", std::max(0, maxCols - 3), line.c_str());
            ++logRow;
        }
    }

    if (has_colors()) {
        attron(COLOR_PAIR(4));
    }
    mvprintw(
        maxRows - 1,
        0,
        "[p]lay/stop [s]ong [n]ext [b]ack [q]uit  |  tracks: Up/Down+Enter=mute  songs: Esc=cancel");
    if (has_colors()) {
        attroff(COLOR_PAIR(4));
    }

    refresh();
}

std::string SequencerConsoleUI::trimTrailingNewlines(const std::string& text)
{
    std::string trimmed = text;
    while (!trimmed.empty() && (trimmed.back() == '\n' || trimmed.back() == '\r')) {
        trimmed.pop_back();
    }
    return trimmed;
}

std::string SequencerConsoleUI::sanitizeForDisplay(const std::string& text)
{
    std::string out;
    out.reserve(text.size());

    for (std::size_t i = 0; i < text.size(); ++i) {
        const unsigned char byte = static_cast<unsigned char>(text[i]);

        if (byte < 0x80) {
            if (byte >= 32 || byte == '\t') {
                out.push_back(static_cast<char>(byte));
            }
            continue;
        }

        // UTF-8 en dash / em dash -> " - "
        if (byte == 0xE2 && i + 2 < text.size()) {
            const unsigned char b1 = static_cast<unsigned char>(text[i + 1]);
            const unsigned char b2 = static_cast<unsigned char>(text[i + 2]);
            if (b1 == 0x80 && (b2 == 0x93 || b2 == 0x94)) {
                out += " - ";
                i += 2;
                continue;
            }
        }

        // Skip other UTF-8 sequences.
        if ((byte & 0xE0) == 0xC0) {
            i += 1;
        } else if ((byte & 0xF0) == 0xE0) {
            i += 2;
        } else if ((byte & 0xF8) == 0xF0) {
            i += 3;
        }
    }

    return out;
}
