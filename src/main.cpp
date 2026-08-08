#include <Arduino_GigaDisplay_GFX.h>

#include "clock/Clock.h"
#include "midi/MidiInOut.h"
#include "view/SequencerView.h"

using namespace GigaSeq;

GigaDisplay_GFX display;
TransportClock transportClock;
MidiInOut midiInOut;
SequencerView sequencerView;

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
            Serial.println("note on");
        }
        else
        {
            midiInOut.sendNoteOff(60, 127, 4);
            Serial.println("note off");
        }
    }

    sequencerView.updatePosition(
            transportClock.getBar(),
            transportClock.getBeat(),
            transportClock.getTick());
}

void setup()
{
    delay(100);

    display.begin();
    display.setRotation(1);

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
}

void loop()
{
    transportClock.run();
    midiInOut.read();
}
