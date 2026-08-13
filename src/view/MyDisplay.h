#pragma once

#if defined(ARDUINO_ARCH_ZEPHYR)
#include "Arduino_Video.h"
#else
#include "Arduino_H7_Video.h"
using Arduino_Video = Arduino_H7_Video;
#endif
#include "Adafruit_GFX.h"

#if __MBED__
#include "Adafruit_SPITFT.h"
#include "dsi.h"
#include "SDRAM.h"
#endif

class MyDisplay : public Adafruit_GFX {
  public:
    MyDisplay();
    ~MyDisplay(void);
    void begin();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void fillScreen(uint16_t color);
    void byteSwap(void);
    void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
    void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
    uint16_t getPixel(int16_t x, int16_t y);

    void endWrite();

    uint16_t color565(uint8_t red, uint8_t green, uint8_t blue) {
      return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
    }

  protected:
    uint16_t getRawPixel(int16_t x, int16_t y);
    void drawFastRawVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
    void drawFastRawHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
    uint16_t *buffer = nullptr; ///< Raster data: no longer private, allow subclass access

  private:
    void markDirty(int16_t x, int16_t y);
    void markDirtyRect(int16_t x, int16_t y, int16_t w, int16_t h);

    Arduino_Video* display;
#ifdef __MBED__
    rtos::Thread* _refresh_thd;
    void refresh_if_needed();
#endif
    bool buffering = false;
    uint32_t last_refresh = 0;

    // Dirty region in raw buffer coordinates (inclusive bounds)
    bool dirty = false;
    int16_t dirtyX1 = 0;
    int16_t dirtyY1 = 0;
    int16_t dirtyX2 = 0;
    int16_t dirtyY2 = 0;

    // Progressive band sweep for large updates
    static constexpr uint16_t bandHeight = 8;
    static constexpr uint16_t singleBlitThreshold = 128;
    bool sweepActive = false;
    int16_t sweepY = 0;
    int16_t sweepYEnd = 0;
};
