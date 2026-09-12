#include "SequencerView.h"

#include "TextBox.h"
#include "../platform/CriticalSection.h"

#include <cstring>

#define CHAR_PLAY 16
#define CHAR_STOP 253

namespace GigaSeq
{
    namespace
    {
        constexpr uint8_t kBlack = 0;
        constexpr uint8_t kWhite = 1;

        char* appendUInt(char *p, uint32_t value)
        {
            if (value == 0)
            {
                *p++ = '0';
                return p;
            }
            char tmp[10];
            int i = 0;
            while (value > 0)
            {
                tmp[i++] = '0' + (value % 10);
                value /= 10;
            }
            while (i > 0)
            {
                *p++ = tmp[--i];
            }
            return p;
        }
    }

    void SequencerView::begin(MyDisplay &display)
    {
        display_ = &display;
        display_->fillScreen(kBlack);
        display_->setTextColor(kWhite, kBlack);
    }

    void SequencerView::copyActionText(char *dest, const char *src)
    {
        if (!src)
        {
            dest[0] = '\0';
            return;
        }
        std::strncpy(dest, src, sizeof(ViewAction::text) - 1);
        dest[sizeof(ViewAction::text) - 1] = '\0';
    }

    void SequencerView::enqueueAction(const ViewAction &action)
    {
        // Producer: can be called from the clock ISR (updatePosition) or from
        // the main loop (mute, sequence switch). Guard against processOne().
        CriticalSection cs;
        if (queueCount_ >= kQueueCapacity)
        {
            // Queue full: drop the oldest action to make room for the newest.
            ++queueTail_;
            if (queueTail_ >= kQueueCapacity) queueTail_ = 0;
            --queueCount_;
        }
        queue_[queueHead_] = action;
        ++queueHead_;
        if (queueHead_ >= kQueueCapacity) queueHead_ = 0;
        ++queueCount_;
    }

    void SequencerView::updateSequenceName(const char *name)
    {
        ViewAction action;
        action.type = ViewActionType::UpdateSequenceName;
        copyActionText(action.text, name);
        enqueueAction(action);
    }

    void SequencerView::updateSequenceInfos(uint16_t bar)
    {
        ViewAction action;
        action.type = ViewActionType::UpdateSequenceInfos;
        action.value1 = bar;
        enqueueAction(action);
    }

    void SequencerView::updateSongName(const char *name)
    {
        ViewAction action;
        action.type = ViewActionType::UpdateSongName;
        copyActionText(action.text, name);
        enqueueAction(action);
    }

    void SequencerView::updatePosition(uint16_t bar, uint8_t beat)
    {
        ViewAction action;
        action.type = ViewActionType::UpdatePosition;
        action.value1 = bar;
        action.value2 = beat;
        enqueueAction(action);
    }

    void SequencerView::updateTransportState(bool isPlaying)
    {
        ViewAction action;
        action.type = ViewActionType::UpdateTransportState;
        action.state = isPlaying;
        enqueueAction(action);
    }

    void SequencerView::updatePending(PendingSwitch sw)
    {
        ViewAction action;
        action.type = ViewActionType::UpdatePending;
        copyActionText(action.text, "");
        if (sw == PendingSwitch::Next) {
            copyActionText(action.text, "NEXT");
        } else if (sw == PendingSwitch::Previous) {
            copyActionText(action.text, "PREV");
        } else if (sw == PendingSwitch::JumpToSong) {
            copyActionText(action.text, "SONG");
        }
        enqueueAction(action);
    }

    void SequencerView::updateBpm(uint8_t bpm) {
        ViewAction action;
        action.type = ViewActionType::UpdateBpm;
        action.value2 = bpm;
        enqueueAction(action);
    }

    void SequencerView::drawTrack(uint8_t trackIndex, const char *text, bool state)
    {
        if (trackIndex >= kTrackCount)
        {
            return;
        }
        ViewAction action;
        action.type = ViewActionType::DrawTrack;
        action.trackIndex = trackIndex;
        action.state = state;
        copyActionText(action.text, text);
        enqueueAction(action);
    }

    void SequencerView::showTemporaryMessage(const char *text, uint32_t durationMs, unsigned long nowMs)
    {
        if (!display_ || !text || durationMs == 0)
        {
            return;
        }

        overlayUntilMs_ = nowMs + durationMs;
        overlayActive_ = true;
        drawOverlay(text);
    }

    bool SequencerView::updateOverlay(unsigned long nowMs)
    {
        if (!overlayActive_)
        {
            return false;
        }

        if (nowMs < overlayUntilMs_)
        {
            return false;
        }

        overlayActive_ = false;
        overlayUntilMs_ = 0;
        return true;
    }

    void SequencerView::drawOverlay(const char *text)
    {
        if (!display_ || !text)
        {
            return;
        }

        static constexpr int kOverlayWidth = 520;
        static constexpr int kOverlayHeight = 100;
        static constexpr uint8_t kOverlayTextSize = 3;
        static constexpr uint8_t kOverlayCharsPerLine = 24;

        const int boxX = (kWidth - kOverlayWidth) / 2;
        const int boxY = kHeaderHeight + (kTracksHeight - kOverlayHeight) / 2;

        display_->fillRect(boxX, boxY, kOverlayWidth, kOverlayHeight, kWhite);
        display_->drawRect(boxX, boxY, kOverlayWidth, kOverlayHeight, kBlack);
        display_->setTextColor(kBlack, kWhite);
        printTextInRect(*display_, boxX, boxY, kOverlayWidth, kOverlayHeight, text, kOverlayTextSize, kOverlayCharsPerLine);
    }

    bool SequencerView::processOne()
    {
        ViewAction action;
        {
            // Consumer: runs in the main loop. Guard against ISR enqueueAction().
            CriticalSection cs;
            if (queueCount_ == 0)
            {
                return false;
            }
            action = queue_[queueTail_];
            ++queueTail_;
            if (queueTail_ >= kQueueCapacity) queueTail_ = 0;
            --queueCount_;
            // Lock released here: execute* below must not run IRQ-disabled.
        }

        switch (action.type)
        {
            case ViewActionType::UpdateSongName:
                executeUpdateSongName(action.text);
                break;
            case ViewActionType::UpdateSequenceName:
                executeUpdateSequenceName(action.text);
                break;
            case ViewActionType::UpdatePosition:
                executeUpdatePosition(action.value1, action.value2);
                break;
            case ViewActionType::DrawTrack:
                executeDrawTrack(action.trackIndex, action.text, action.state);
                break;
            case ViewActionType::UpdateSequenceInfos:
                executeUpdateSequenceInfos(action.value1);
                break;
            case ViewActionType::UpdateTransportState:
                executeUpdateTransportState(action.state);
                break;
            case ViewActionType::UpdatePending:
                executePendingSwitch(action.text);
                break;
            case ViewActionType::UpdateBpm:
                executeUpdateBpm(action.value2);
                break;
            default:
                break;
        }

        return true;
    }

    void SequencerView::prepareHeaderArea(int x, int y, int width, bool inverted)
    {
        display_->fillRect(x, y, width, kHeaderHeight, inverted ? kWhite : kBlack);
        display_->setTextSize(kHeaderTextSize);
        display_->setTextColor(inverted ? kBlack : kWhite, inverted ? kWhite : kBlack);
        display_->setCursor(x, y);
    }

    void SequencerView::drawHeaderText(int x, int y, int width, const char *text, bool inverted)
    {
        prepareHeaderArea(x, y, width, inverted);
        if (text)
        {
            display_->print(text);
        }
    }

    void SequencerView::drawHeaderChar(int x, int y, int width, uint8_t ch)
    {
        prepareHeaderArea(x, y, width);
        display_->write(ch);
    }

    void SequencerView::executeUpdateSequenceName(const char *name)
    {
        if (!display_ || disable)
        {
            return;
        }

        drawHeaderText(0, kSequencePosY, kSequenceNameWidth, name);
    }

    void SequencerView::executeUpdateSequenceInfos(const uint16_t bar)
    {
        if (!display_ || disable)
        {
            return;
        }

        // ':' + up to 3 digits (barCount <= 255) + NUL
        char barText[8];
        char *p = barText;
        *p++ = ':';
        p = appendUInt(p, bar);
        *p = '\0';

        drawHeaderText(kBarX, 0, kBarWidth, barText);
    }

    void SequencerView::executeUpdateTransportState(bool isPlaying)
    {
        if (!display_ || disable)
        {
            return;
        }

        drawHeaderChar(kTransportIconX, 0, kTransportIconWidth,
                       isPlaying ? CHAR_PLAY : CHAR_STOP);
    }

    void SequencerView::executeUpdateSongName(const char *name)
    {
        if (!display_ || disable)
        {
            return;
        }

        drawHeaderText(0, 0, kSequenceNameWidth, name);
    }

    void SequencerView::executePendingSwitch(const char *name)
    {
        if (!display_ || disable)
        {
            return;
        }

        drawHeaderText(kTransportIconX, kSequencePosY, kPendingSwitchWidth, name, name[0] != '\0');
    }

    void SequencerView::executeUpdateBpm(uint8_t bpm) {
        if (!display_ || disable)
        {
            return;
        }

        // ':' + up to 3 digits (barCount <= 255) + NUL
        char tempoText[8];
        char *p = tempoText;
        p = appendUInt(tempoText, bpm);
        *p = '\0';

        drawHeaderText(kBarX, kSequencePosY, kBarWidth, tempoText);
    }

    void SequencerView::executeUpdatePosition(uint16_t bar, uint8_t beat)
    {
        if (!display_ || disable)
        {
            return;
        }

        char positionText[16];
        char *p = positionText;
        p = appendUInt(p, bar);
        *p++ = '.';
        p = appendUInt(p, beat);
        *p = '\0';

        drawHeaderText(kPositionX, 0, kPositionWidth, positionText);
    }

    void SequencerView::executeDrawTrack(uint8_t trackIndex, const char *text, bool state)
    {
        if (!display_ || trackIndex >= kTrackCount || disable)
        {
            return;
        }

        // Text color follows the cell background: black on white when active,
        // white on black when inactive. Explicit bg avoids Adafruit_GFX's
        // default textbgcolor (0xFFFF -> L8 index 255 -> wrong CLUT entry).
        display_->setTextColor(state ? kBlack : kWhite,
                               state ? kWhite : kBlack);

        const int tracksY = kHeight - kTracksHeight;
        const int trackW = kWidth / kColCount;
        const int trackH = kTracksHeight / kColCount;

        const uint8_t col = trackIndex % kColCount;
        const uint8_t row = kColCount - 1 - (trackIndex / kColCount);
        const int x = col * trackW;
        const int y = tracksY + row * trackH;

        if (state)
        {
            display_->fillRect(x, y, trackW, trackH, kWhite);
        }
        else
        {
            display_->fillRect(x, y, trackW, trackH, kBlack);
            display_->drawRect(x, y, trackW, trackH, kWhite);
        }

        const char *label = text;
        if (label && label[0] != '\0')
        {
            printTextInRect(*display_, x, y, trackW, trackH, label, kTrackTextSize, kCharsPerLine);
        }
    }

} // namespace GigaSeq
