
#include "MIDI.h"

#include <uClock.h>

#define MIDI_MIN 36
#define MIDI_CHANNEL 4

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

bool state = false;

//Just for testing
void onOutputPPQNCallback(uint32_t tick) {
  //    onTick(tick);
  if (tick % 96 == 0) {
    state = !state;
    if (state) {
      MIDI.sendNoteOn(60, 127, 4);
      Serial.print("note on");
    } else {
      MIDI.sendNoteOff(60, 127, 4);
      Serial.print("note offf");
    }
  }
}

class MidiInOut {
private:

public:
  MidiInOut() {
  }

  void begin() {
    Serial1.begin(31250);
    Serial.begin(9600);

    MIDI.begin(MIDI_CHANNEL_OMNI);

    uClock.init();
    uClock.setTempo(120);
    uClock.setOutputPPQN(uClock.PPQN_24);
    uClock.setOnOutputPPQN(onOutputPPQNCallback);

    Serial.print("begin");

    uClock.start();
  }

  void loop() {
    uClock.run();

    //midiOut.sendOutput(currentTime);
    //MIDI.read();
  }
};