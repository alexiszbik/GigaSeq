
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
      const uint32_t bh = y2 - y1 + 1;
      uint16_t* src = buffer + y1 * WIDTH;
      void* dst = (uint16_t*)dsi_getActiveFrameBuffer() + y1 * WIDTH;
      dsi_lcdDrawImage(src, dst, WIDTH, bh, DMA2D_INPUT_RGB565);
    }
  }
}
#endif

void MyDisplay::begin() {
    display = new Arduino_Video(480, 800, GigaDisplayShield);
    display->begin();

    #ifdef __MBED__
      buffer = (uint16_t*)ea_malloc(this->width() * this-> height() * 2);
      _refresh_thd = new rtos::Thread(osPriorityNormal);
      _refresh_thd->start(mbed::callback(this, &MyDisplay::refresh_if_needed));
    #elif defined(__ZEPHYR__)
      #ifdef CONFIG_SHARED_MULTI_HEAP
        void* ptrFB = this->display->getFramebuffer();
        if (ptrFB == nullptr){
          while(1){}
        }
        // Cast the void pointer to an int pointer to use it
        buffer = static_cast<uint16_t*>(ptrFB);
      #else
        SDRAM.begin();
        buffer = (uint16_t*)SDRAM.malloc(this->width() * this-> height() * sizeof(uint16_t));
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

    int16_t t;
    switch (rotation) {
        case 1:
        t = x;
        x = WIDTH - 1 - y;
        y = t;
        break;
        case 2:
        x = WIDTH - 1 - x;
        y = HEIGHT - 1 - y;
        break;
        case 3:
        t = x;
        x = y;
        y = HEIGHT - 1 - t;
        break;
    }

    buffer[x + y * WIDTH] = color;
    markDirty(x, y);
}

uint16_t MyDisplay::getPixel(int16_t x, int16_t y) {
  int16_t t;
  switch (rotation) {
    case 1:
      t = x;
      x = WIDTH - 1 - y;
      y = t;
      break;
    case 2:
      x = WIDTH - 1 - x;
      y = HEIGHT - 1 - y;
      break;
    case 3:
      t = x;
      x = y;
      y = HEIGHT - 1 - t;
      break;
  }
  return getRawPixel(x, y);
}

uint16_t MyDisplay::getRawPixel(int16_t x, int16_t y) {
  if ((x < 0) || (y < 0) || (x >= WIDTH) || (y >= HEIGHT)) {
    return 0;
    } else   return buffer[x + y * WIDTH];

}

void MyDisplay::fillScreen(uint16_t color) {
    uint8_t hi = color >> 8, lo = color & 0xFF;
    if (hi == lo) {
      memset(buffer, lo, WIDTH * HEIGHT * 2);
    } else {
      uint32_t i, pixels = WIDTH * HEIGHT;
      for (i = 0; i < pixels; i++) {
        buffer[i] = color;
        }
    }
    markDirtyRect(0, 0, WIDTH, HEIGHT);

}

void MyDisplay::byteSwap(void) {

    uint32_t i, pixels = WIDTH * HEIGHT;
    for (i = 0; i < pixels; i++) {
      buffer[i] = __builtin_bswap16(buffer[i]);
      }
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

  if (getRotation() == 0) {
    drawFastRawVLine(x, y, h, color);
  } else if (getRotation() == 1) {
    int16_t t = x;
    x = WIDTH - 1 - y;
    y = t;
    x -= h - 1;
    drawFastRawHLine(x, y, h, color);
  } else if (getRotation() == 2) {
    x = WIDTH - 1 - x;
    y = HEIGHT - 1 - y;

    y -= h - 1;
    drawFastRawVLine(x, y, h, color);
  } else if (getRotation() == 3) {
    int16_t t = x;
    x = y;
    y = HEIGHT - 1 - t;
    drawFastRawHLine(x, y, h, color);
  }
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

  if (getRotation() == 0) {
    drawFastRawHLine(x, y, w, color);
  } else if (getRotation() == 1) {
    int16_t t = x;
    x = WIDTH - 1 - y;
    y = t;
    drawFastRawVLine(x, y, w, color);
  } else if (getRotation() == 2) {
    x = WIDTH - 1 - x;
    y = HEIGHT - 1 - y;

    x -= w - 1;
    drawFastRawHLine(x, y, w, color);
  } else if (getRotation() == 3) {
    int16_t t = x;
    x = y;
    y = HEIGHT - 1 - t;
    y -= w - 1;
    drawFastRawVLine(x, y, w, color);
  }
}

void MyDisplay::drawFastRawVLine(int16_t x, int16_t y, int16_t h,
                                       uint16_t color) {

  // x & y already in raw (rotation 0) coordinates, no need to transform.
  uint16_t *buffer_ptr = buffer + y * WIDTH + x;
  for (int16_t i = 0; i < h; i++) {
    (*buffer_ptr) = color;
    buffer_ptr += WIDTH;
  }
  markDirtyRect(x, y, 1, h);

}

void MyDisplay::drawFastRawHLine(int16_t x, int16_t y, int16_t w,
                                       uint16_t color) {
  // x & y already in raw (rotation 0) coordinates, no need to transform.
  uint32_t buffer_index = y * WIDTH + x;
  for (uint32_t i = buffer_index; i < buffer_index + w; i++) {
    buffer[i] = color;
  }
  markDirtyRect(x, y, w, 1);
}
