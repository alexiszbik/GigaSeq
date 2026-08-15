#include <Arduino_GigaDisplay_GFX.h>

#include "clock/Clock.h"
#include "SequencePool.h"
#include "hid/Mux.h"
#include "hid/Switch.h"
#include "midi/EngineMidiBridge.h"
#include "midi/GigaMidiInOut.h"
#include "platform/ArduinoLogger.h"
#include "task/TimedTask.h"
#include "view/SequencerView.h"

using namespace GigaSeq;

unsigned long currentTime = 0;

#define PUSH_PEDAL 2

#define PUSH_PLAY 43
#define PUSH_NEXT 45
#define PUSH_PREV 47
#define PUSH_SONG 49
#define PUSH_MODE 51
#define TOGGLE_SCENE 53

Switch pushPedal(PUSH_PEDAL);
Switch pushPlay(PUSH_PLAY);
Switch pushNext(PUSH_NEXT);
Switch pushPrev(PUSH_PREV);
Switch pushSong(PUSH_SONG);
Switch pushMode(PUSH_MODE);

Mux mux(41, 33, 35, 37, 39);

MyDisplay display;
TransportClock transportClock;
GigaMidiInOut gigaMidi;
EngineMidiBridge midiBridge(gigaMidi);
ArduinoLogger logger;
SequencePool sequencePool = SequencePool::createDefault(midiBridge, logger);
SequencerView sequencerView;

uint8_t midiClockCounter = 0;
uint8_t beatTickCounter = 0;

void resetTickCounters() {
    midiClockCounter = 0;
    beatTickCounter = 0;
}

void refreshViewFromPool() {
    Sequence& sequence = sequencePool.current();
    sequencerView.updateSequenceName(sequence.name());
    sequencerView.updateSequenceInfos(sequence.barCount());

    sequencerView.updateSongName(sequencePool.currentSong().name());
    sequencerView.updateTransportState(transportClock.isPlaying());

    for (uint8_t trackIndex = 0; trackIndex < 16; ++trackIndex) {
        if (trackIndex < sequence.trackCount()) {
            const SequenceTrack& track = sequence.track(trackIndex);
            sequencerView.drawTrack(trackIndex, track.name(), track.isMuted());
        } else {
            sequencerView.drawTrack(trackIndex, "", false);
        }
    }

}

void onSequenceChanged(void* /*context*/) {
    refreshViewFromPool();
}

void onTrackMuteChanged(uint8_t trackIndex, bool muted, void* /*context*/) {
    if (trackIndex >= 16) {
        return;
    }

    const SequenceTrack& track = sequencePool.current().track(trackIndex);
    sequencerView.drawTrack(trackIndex, track.name(), muted);
}

void startTransport() {
    sequencePool.resetCurrent();
    resetTickCounters();
    transportClock.start();
    midiBridge.sendStart();
}

void stopTransport() {
    transportClock.stop();
    midiBridge.sendStop();
    sequencePool.allNotesOff();
}

void inputCheckCallback() {
    bool isPlaying = transportClock.isPlaying();
    if (pushPlay.isPushed()) {
        if (isPlaying) {
            stopTransport();
            sequencerView.updateTransportState(false);
        } else {
            startTransport();
            sequencerView.updateTransportState(true);
            sequencerView.updatePosition(1, 1);
        }
    }

    if (pushNext.isPushed()) {
        sequencePool.requestNext(!isPlaying);
    }

    if (pushPrev.isPushed()) {
        sequencePool.requestPrevious(!isPlaying);
    }
}

void muxCallback() {
    mux.readNext();

    Sequence& sequence = sequencePool.current();
    uint16_t pressed = mux.getChangedStates() & mux.getStates();

    for (uint8_t i = 0; pressed; ++i, pressed >>= 1) {
        if ((pressed & 1) && i < sequence.trackCount()) {
            SequenceTrack& track = sequence.track(i);
            track.setMuted(!track.isMuted());
        }
    }

    mux.clearChangedStates();
}

void displayCallback() {
    sequencerView.processOne();
}

TimedTask inputCheck(20, inputCheckCallback);
TimedTask muxCheck(3, muxCallback);
TimedTask displayCheck(10, displayCallback);

void onClockTick(void* context) {
    (void)context;

    sequencePool.processTick();

    if (midiClockCounter == 0) {
        midiBridge.sendClock();
    }
    midiClockCounter++;
    if (midiClockCounter >= 4) {
        midiClockCounter = 0;
    }

    if (beatTickCounter == 0) {
        Sequence& current = sequencePool.current();
        sequencerView.updatePosition(current.currentBar() + 1, current.currentBeat() + 1);
    }

    beatTickCounter++;
    if (beatTickCounter >= TransportClock::kPpqn) {
        beatTickCounter = 0;
    }
}

void setup() {
    Serial.begin(9600);

    delay(100);

    display.begin();
    display.setRotation(1);

    mux.begin();

    sequencerView.begin(display);
    refreshViewFromPool();

    gigaMidi.begin();
    transportClock.begin(166);
    transportClock.setOnTick(onClockTick);
    sequencePool.setOnSequenceChanged(onSequenceChanged);
    sequencePool.setOnTrackMuteChanged(onTrackMuteChanged);
}

void loop() {

    gigaMidi.read();
    if (gigaMidi.flush()) return;

    currentTime = millis();

    if (inputCheck.update(currentTime)) return;
    if (muxCheck.update(currentTime)) return;
    if (displayCheck.update(currentTime)) return;

    display.endWrite();


}
