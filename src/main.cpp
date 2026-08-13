#include <Arduino_GigaDisplay_GFX.h>

#include "clock/Clock.h"
#include "midi/MidiInOut.h"
#include "view/SequencerView.h"
#include "hid/Switch.h"
#include "task/TimedTask.h"
#include "hid/Mux.h"

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

Mux mux(41,33,35,37,39);

GigaDisplay_GFX display;
TransportClock transportClock;
MidiInOut midiInOut;
SequencerView sequencerView;

void inputCheckCallback() {
    if (pushPlay.debounce()) {
        if (pushPlay.getState()) {
            transportClock.toggleStartStop();
        }
        Serial.write(pushPlay.getState());
    }
}

void muxCallback() {
    mux.readNext();

    for (byte i = 0; i < 16; i++) {
        if (mux.hasChanged(i)) {
            bool state = mux.getValue(i);
            if (state) {
                Serial.println(i);
            }
        }
    }
}

TimedTask inputCheck(200, inputCheckCallback);
TimedTask muxCheck(1, muxCallback);

void onClockTick(uint32_t tick, void *context)
{
    (void)context;

    static bool state = false;
    if (tick % 96 == 0)
    {
        state = !state;
        if (state)
        {
            midiInOut.sendNoteOn(60, 127, 4);
        }
        else
        {
            midiInOut.sendNoteOff(60, 127, 4);
        }
    }

    sequencerView.updatePosition(
            transportClock.getBar(),
            transportClock.getBeat(),
            transportClock.getTick());

}

void setup()
{   
    Serial.begin(9600);

    delay(100);

    display.begin();
    display.setRotation(1);

    mux.begin();

    sequencerView.begin(display);
    sequencerView.drawStaticLayout();
    
    for (uint8_t trackIndex = 0; trackIndex < 16; trackIndex++)
    {
        sequencerView.setTrackLabel(trackIndex, "Hello World of Darkness!");
    }
    
    midiInOut.begin();
    transportClock.begin(120);
    transportClock.setOnTick(onClockTick);
    transportClock.start();

    Serial.write("hello world");
}

void loop()
{
    currentTime = millis();

    inputCheck.update(currentTime);
    muxCheck.update(currentTime);

    transportClock.run();
    midiInOut.read();
}
