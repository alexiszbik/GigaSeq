#include "Arduino_GigaDisplay_GFX.h"
#include "TextBox.h"

#include "MidiInOut.h"

GigaDisplay_GFX display;  // create the object

#define BLACK 0x0000
#define WHITE 0xffff

constexpr int width = 800;
constexpr int height = 480;

constexpr int tracksHeight = 380;

constexpr int colCount = 4;
constexpr int trackCount = 16;
constexpr uint8_t trackTextSize = 3;
constexpr uint8_t charsPerLine = 9;

MidiInOut midiInOut;

void setup() {
  delay(100);

  display.begin();
  display.setRotation(1);  // landscape: 800x480
  display.fillScreen(BLACK);

  display.setTextColor(WHITE);
  display.setTextSize(5);
  display.setCursor(0, 0);
  display.print("Sequence 01");

  display.setCursor(width / 2, 0);
  display.print("1.1.00");

  const char* text = "Hello World of Darkness!";

  const int tracksY = height - tracksHeight;
  const int trackW = width / colCount;
  const int trackH = tracksHeight / colCount;

  for (int t = 0; t < trackCount; t++) {
    const byte col = t % colCount;
    const byte row = t / colCount;

    const int x = col * trackW;
    const int y = tracksY + row * trackH;

    display.drawRect(x, y, trackW, trackH, WHITE);
    printTextInRect(display, x, y, trackW, trackH, text, trackTextSize, charsPerLine);
  }

  midiInOut.begin();
}

void loop() {
  midiInOut.loop();
}
