
#include "MyDisplay.h"

#ifdef __MBED__
#include "platform/mbed_critical.h"
#endif

MyDisplay::MyDisplay() : Adafruit_GFX(480, 800) { }

MyDisplay::~MyDisplay(void) {
  if (buffer) {
    free(buffer);
    }
}

#ifdef __MBED__
void MyDisplay::refresh_if_needed() {
  while (1) {
    rtos::ThisThread::flags_wait_any(0x1);

    int16_t y1 = 0, y2 = -1;
    bool doDraw = false;

    if (sweepActive) {
      // Continue an ongoing band sweep: one band per wake.
      y1 = sweepY;
      y2 = sweepY + bandHeight - 1;
      if (y2 > sweepYEnd) y2 = sweepYEnd;
      sweepY += bandHeight;
      if (sweepY > sweepYEnd) sweepActive = false;
      doDraw = true;
    } else if (dirty) {
      y1 = dirtyY1;
      y2 = dirtyY2;
      dirty = false;
      if (y1 < 0) y1 = 0;
      if (y2 >= HEIGHT) y2 = HEIGHT - 1;

      const int16_t h = y2 - y1 + 1;
      if (h <= singleBlitThreshold) {
        // Small update: blit the whole band in one go.
        doDraw = true;
      } else {
        // Large update: spread over multiple wakes, one band at a time.
        sweepActive = true;
        sweepY = y1 + bandHeight;
        sweepYEnd = y2;
        y2 = y1 + bandHeight - 1;
        if (y2 > sweepYEnd) y2 = sweepYEnd;
        doDraw = true;
      }
    }

    if (doDraw) {
      // Blit full-width horizontal bands: dsi_lcdDrawImage hardcodes
      // InputOffset = 0, which is only valid when xSize == lcd_x_size (480).
      // Partial-width blits would skew rows into diagonals.
      // Source is L8 (1 byte/pixel), DMA2D converts to RGB565 via the CLUT
      // configured in begin() before writing the RGB565 framebuffer.
      const uint32_t bh = y2 - y1 + 1;
      uint8_t*  src = buffer + y1 * WIDTH;
      uint16_t* dst = (uint16_t*)dsi_getActiveFrameBuffer() + y1 * WIDTH;
      dsi_lcdDrawImage(src, dst, WIDTH, bh, DMA2D_INPUT_L8);
    }
  }
}
#endif

void MyDisplay::begin() {
    display = new Arduino_Video(480, 800, GigaDisplayShield);
    display->begin();

    #ifdef __MBED__
      // L8 indexed buffer: 1 byte/pixel, half the RAM and half the DMA2D
      // read bandwidth of RGB565. CLUT[0]=black, CLUT[1]=white, rest=black.
      buffer = (uint8_t*)ea_malloc(WIDTH * HEIGHT);
      _refresh_thd = new rtos::Thread(osPriorityNormal);
      _refresh_thd->start(mbed::callback(this, &MyDisplay::refresh_if_needed));

      uint32_t clut[256];
      for (int i = 0; i < 256; ++i) clut[i] = 0xFF000000u; // opaque black
      clut[0] = 0xFF000000u;                                // black  -> RGB565 0x0000
      clut[1] = 0xFFFFFFFFu;                                // white  -> RGB565 0xFFFF
      dsi_configueCLUT(clut);
    #elif defined(__ZEPHYR__)
      #ifdef CONFIG_SHARED_MULTI_HEAP
        void* ptrFB = this->display->getFramebuffer();
        if (ptrFB == nullptr){
          while(1){}
        }
        // Cast the void pointer to an int pointer to use it
        buffer = static_cast<uint8_t*>(ptrFB);
      #else
        SDRAM.begin();
        buffer = (uint8_t*)SDRAM.malloc(this->width() * this-> height() * sizeof(uint16_t));
      #endif
      this->display->setFrameDesc(this->width(), this->height(), this->width(), (this->width() * this-> height() * sizeof(uint16_t)));
    #endif
}

void MyDisplay::endWrite() {
#ifdef __MBED__
    if (sweepActive || dirty) {
        _refresh_thd->flags_set(0x1);
    }
#elif defined(__ZEPHYR__)
     this->display->drawBuffer(0, 0, buffer);
#endif
}

void MyDisplay::markDirty(int16_t x, int16_t y) {
    if (!dirty) {
        dirtyX1 = dirtyX2 = x;
        dirtyY1 = dirtyY2 = y;
        dirty = true;
    } else {
        if (x < dirtyX1) dirtyX1 = x;
        if (x > dirtyX2) dirtyX2 = x;
        if (y < dirtyY1) dirtyY1 = y;
        if (y > dirtyY2) dirtyY2 = y;
    }
}

void MyDisplay::markDirtyRect(int16_t x, int16_t y, int16_t w, int16_t h) {
    if (w <= 0 || h <= 0) return;
    const int16_t x2 = x + w - 1;
    const int16_t y2 = y + h - 1;
    if (!dirty) {
        dirtyX1 = x;  dirtyY1 = y;
        dirtyX2 = x2; dirtyY2 = y2;
        dirty = true;
    } else {
        if (x  < dirtyX1) dirtyX1 = x;
        if (y  < dirtyY1) dirtyY1 = y;
        if (x2 > dirtyX2) dirtyX2 = x2;
        if (y2 > dirtyY2) dirtyY2 = y2;
    }
}

void MyDisplay::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
        return;

    // Rotation 1: logical (x,y) -> raw (WIDTH-1-y, x)
    int16_t t = x;
    x = WIDTH - 1 - y;
    y = t;

    buffer[x + y * WIDTH] = (uint8_t)color;
    markDirty(x, y);
}

uint16_t MyDisplay::getPixel(int16_t x, int16_t y) {
    // Rotation 1: logical (x,y) -> raw (WIDTH-1-y, x)
    int16_t t = x;
    x = WIDTH - 1 - y;
    y = t;
    return getRawPixel(x, y);
}

uint16_t MyDisplay::getRawPixel(int16_t x, int16_t y) {
  if ((x < 0) || (y < 0) || (x >= WIDTH) || (y >= HEIGHT)) {
    return 0;
    }
  // L8 index -> RGB565 (API stays RGB565 for Adafruit_GFX compatibility).
  return buffer[x + y * WIDTH] ? 0xFFFF : 0x0000;
}

void MyDisplay::fillScreen(uint16_t color) {
    memset(buffer, (uint8_t)color, WIDTH * HEIGHT);
    markDirtyRect(0, 0, WIDTH, HEIGHT);
}

void MyDisplay::byteSwap(void) {
    // No-op in L8: 1 byte/pixel has no endianness to swap. Kept for API compat.
    markDirtyRect(0, 0, WIDTH, HEIGHT);
}

void MyDisplay::drawFastVLine(int16_t x, int16_t y, int16_t h,
                                    uint16_t color) {
  if (h < 0) { // Convert negative heights to positive equivalent
    h *= -1;
    y -= h - 1;
    if (y < 0) {
      h += y;
      y = 0;
    }
  }

  // Edge rejection (no-draw if totally off canvas)
  if ((x < 0) || (x >= width()) || (y >= height()) || ((y + h - 1) < 0)) {
    return;
  }

  if (y < 0) { // Clip top
    h += y;
    y = 0;
  }
  if (y + h > height()) { // Clip bottom
    h = height() - y;
  }

  // Rotation 1: logical VLine -> raw HLine
  int16_t t = x;
  x = WIDTH - 1 - y;
  y = t;
  x -= h - 1;
  drawFastRawHLine(x, y, h, color);
}

void MyDisplay::drawFastHLine(int16_t x, int16_t y, int16_t w,
                                    uint16_t color) {
  if (w < 0) { // Convert negative widths to positive equivalent
    w *= -1;
    x -= w - 1;
    if (x < 0) {
      w += x;
      x = 0;
    }
  }

  // Edge rejection (no-draw if totally off canvas)
  if ((y < 0) || (y >= height()) || (x >= width()) || ((x + w - 1) < 0)) {
    return;
  }

  if (x < 0) { // Clip left
    w += x;
    x = 0;
  }
  if (x + w >= width()) { // Clip right
    w = width() - x;
  }

  // Rotation 1: logical HLine -> raw VLine
  int16_t t = x;
  x = WIDTH - 1 - y;
  y = t;
  drawFastRawVLine(x, y, w, color);
}

void MyDisplay::drawFastRawVLine(int16_t x, int16_t y, int16_t h,
                                       uint16_t color) {

  // x & y already in raw (rotation 0) coordinates, no need to transform.
  uint8_t idx = (uint8_t)color;
  uint8_t *buffer_ptr = buffer + y * WIDTH + x;
  for (int16_t i = 0; i < h; i++) {
    (*buffer_ptr) = idx;
    buffer_ptr += WIDTH;
  }
  markDirtyRect(x, y, 1, h);

}

void MyDisplay::drawFastRawHLine(int16_t x, int16_t y, int16_t w,
                                       uint16_t color) {
  // x & y already in raw (rotation 0) coordinates, no need to transform.
  memset(buffer + y * WIDTH + x, (uint8_t)color, w);
  markDirtyRect(x, y, w, 1);
}

void MyDisplay::fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
                                uint16_t color) {
  // Clip to logical viewport (rotation 1: _width=HEIGHT, _height=WIDTH).
  if (w <= 0 || h <= 0) return;
  if (x < 0) { w += x; x = 0; }
  if (y < 0) { h += y; y = 0; }
  if (x + w > _width)  { w = _width  - x; }
  if (y + h > _height) { h = _height - y; }
  if (w <= 0 || h <= 0) return;

  // Rotation 1: logical (x,y) -> raw (rx, ry) with rx = WIDTH-1-y, ry = x.
  // Logical rect (x,y,w,h) maps to raw rect (rx, ry, w=h, h=w) where
  // rx = WIDTH-1-(y+h-1), ry = x, rawW = h, rawH = w.
  int16_t rx = WIDTH - 1 - (y + h - 1);
  int16_t ry = x;
  int16_t rw = h;
  int16_t rh = w;

  uint8_t idx = (uint8_t)color;
  for (int16_t row = 0; row < rh; row++) {
    memset(buffer + (ry + row) * WIDTH + rx, idx, rw);
  }
  markDirtyRect(rx, ry, rw, rh);
}
