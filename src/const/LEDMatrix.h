#pragma once

#include <cstdint>

namespace LedMatrix {

#define _MATRIX_PRESET(song, preset, nbr) constexpr uint8_t k##song##_##preset = nbr
#define _MATRIX_PRESET_NOTE(song, preset, command, nbr) constexpr uint8_t k##song##_##preset##_##command##_note = nbr

constexpr uint8_t kKill = 16; //Maybe prepare a specific program for this ?

// === Together ===
//TO do ...
_MATRIX_PRESET(Together, vuIntro, 43); //?
_MATRIX_PRESET(Together, circles, 44); //?
_MATRIX_PRESET(Together, vuRainbow, 45); //?

// === Water ===
_MATRIX_PRESET(Water, oscBlue, 24);
_MATRIX_PRESET(Water, turnstile, 25);
_MATRIX_PRESET(Water, oscBlueWhite, 26);

_MATRIX_PRESET_NOTE(Water, osc, squareA, 48);
_MATRIX_PRESET_NOTE(Water, osc, squareB, 49);
_MATRIX_PRESET_NOTE(Water, osc, squareC, 50);
_MATRIX_PRESET_NOTE(Water, osc, squareD, 51);

_MATRIX_PRESET_NOTE(Water, osc, squareOff, 60);

// === Falling ===
//TO do ...
_MATRIX_PRESET(Falling, turnstile, 25);
_MATRIX_PRESET(Falling, drops, 6);
_MATRIX_PRESET(Falling, rain, 22);

// === Closer ===
_MATRIX_PRESET(Closer, lasers, 8);
_MATRIX_PRESET(Closer, plasma, 7);
_MATRIX_PRESET(Closer, smileys, 9);

// === Fantasy ===
_MATRIX_PRESET(Fantasy, signA, 30);
_MATRIX_PRESET(Fantasy, signB, 31);
_MATRIX_PRESET(Fantasy, signC, 32);

// === Bibimbap ===
_MATRIX_PRESET(Bibimbap, vu, 35);
_MATRIX_PRESET_NOTE(Bibimbap, vu, noteA, 36);
_MATRIX_PRESET_NOTE(Bibimbap, vu, noteB, 37);
_MATRIX_PRESET(Bibimbap, vortex, 36);

// === U & I ===
_MATRIX_PRESET(UandI, noise, 19);
_MATRIX_PRESET(UandI, wash, 20);
_MATRIX_PRESET(UandI, explode, 59);

// === Friendship ===
_MATRIX_PRESET(Friendship, vuIntro, 43); //?
_MATRIX_PRESET(Friendship, circles, 44); //?
_MATRIX_PRESET(Friendship, vuRainbow, 45); //?
_MATRIX_PRESET(Friendship, kaomjis, 18); //?
_MATRIX_PRESET(Friendship, sign, 46);
_MATRIX_PRESET(Friendship, rainbowSign, 47);

// === Tir3d ===
_MATRIX_PRESET(Tired, sticks, 15); //?
_MATRIX_PRESET(Tired, starTour, 42); //?

#undef _MATRIX_PRESET
#undef _MATRIX_PRESET_NOTE

}
/*
     //Brighter Beat
      case 2:
        scene = new BigVu(new VuPalette(), 60, 4, BigVu::vertical);
        break;

      case 4:
        scene = new Spiral();
        break;

      //Say : Brighter
      case 5:
        scene = new FlashingSign(new Palette(COLOR(0, 0, 7), COLOR(0, 7, 7), COLOR(7, 7, 7)), FlashingSign::brighter, 3);
        break;



      //End Brighter // Expect the Unexpected
      case 6:
        scene = new SquareDrops(bluePalette(), SquareDrops::randDrops);
        break;

      //Plasma
      case 7:
        scene = new Plasma();
        break;

      //Lasers
      case 8:
        scene = new Lasers();
        break;
      //Smileys
      case 9:
        scene = new Gfx(new Palette(COLOR(7, 4, 0)), GfxEnum::gfx_smiley, Gfx::EGfxMode::gfxMode_normal, Gfx::EYmove::noMove, false, true);
        break;

      //Expect the Unexpected, + drums
      case 10:
        scene = new RandomYMNK(new RainbowPalette());
        break;


      //Pers intro
      case 15:
        scene = new Sticks(redPalette());  //Weird but okay!
        break;

      //Pers Kick
      case 16:
        scene = new BigVu(new Palette(COLOR(7, 0, 0)), 36, 1, BigVu::Mode::horizontal, true);
        break;

      //Pers Drop
      case 17:
        scene = new RectangleGroup(bluePalette(4));
        break;

        //Pers End
      case 18:
        scene = new Kaomojis(new RainbowPalette());
        break;

      case 19:
        scene = new PixNoise();
        break;
      case 20:
        scene = new SquareDrops(new Palette(7, 7, 0, 7), SquareDrops::wash);
        break;


      //Hopes
      //intro
      case 22:
        scene = new RainDrops(bluePalette());
        break;
      //toms
      case 23:
        scene = new BigVu(new Palette(COLOR(0, 0, 7)), 48, 4, BigVu::Mode::vertical, true);
        break;


        //Water

      case 24:
        scene = new Osc(new Palette(COLOR(0, 7, 7)));
        break;

      case 25:
        scene = new Turnstile();
        break;

      case 26:
        scene = new Osc(new Palette(COLOR(0, 0, 7), COLOR(0, 7, 7), COLOR(7, 7, 7)));
        break;



      //Animaux intro
      case 27:
        scene = new SquareDrops(redPalette(), SquareDrops::trail);
        break;
      //Animaux kick
      case 28:
        scene = new Arrows();
        break;
      //Animaux end
      case 29:
        scene = new BigYMNK(new RainbowPalette());
        break;

      //FANTASY
      case 30:
        scene = new MovingSign(new Palette(COLOR(0, 0, 7)), MovingSign::fantasy);
        break;

      case 31:
        scene = new MovingSign(new RainbowPalette(), MovingSign::fantasy);
        break;

      case 32:
        scene = new MovingSign(new RainbowPalette(), MovingSign::fantasy, true, true);
        break;



      // BiBimBap
      case 35:
        scene = new BigVu(new Palette(COLOR(0, 7, 0)), 36, 2, BigVu::Mode::horizontal, true);
        break;
      case 36:
        scene = new Vortex();
        break;

      //Raindrops Rainbow
      case 40:
        scene = new RainDrops(new RainbowPalette());
        break;


      //Tir3d of Technology
      case 42:
        scene = new StarTour();
        break;

        //Friendship & Bravery
      case 43:
        scene = new AutoVu(new Palette(COLOR(0, 0, 7)));
        break;

      case 44:
        scene = new Circles(bluePalette());
        break;

      case 45:
        scene = new AutoVu(new VuPalette2());
        break;

      case 46:
        scene = new FlashingSign(new Palette(COLOR(7, 7, 7)), FlashingSign::friendship, 1);
        break;

      case 47:
        scene = new FlashingSign(new RainbowPalette(), FlashingSign::friendship, 1);
        break;


      //test hearth
      case 50:
        scene = new Gfx(new Palette(COLOR(7, 0, 0)), GfxEnum::gfx_hearth);
        break;

      case 51:
      //Gfx(Palette* palette, GfxEnum gfxEnum, EGfxMode mode = gfxMode_normal, EYmove yMove = noMove, bool colorMove = false, bool isMidiSynced = false)
        scene = new Gfx(new RainbowPalette(), GfxEnum::gfx_hearth, Gfx::EGfxMode::gfxMode_plainWithContour,  Gfx::EYmove::noMove, true);
        break;


      case 52:
        scene = new Intro();
        break;

        //Fill outside
      case 53:
        scene = new BigYMNK(new RainbowPalette(), true);
        break;

      case 54:
        scene = new FlashingSign(new Palette(COLOR(7, 7, 7)), FlashingSign::version, 0);
        break;

      case 59:
        scene = new Explode();
        break;

      case 64:
        scene = new BigVu(new VuPalette(), 36, 4, BigVu::vertical);
        break;

      case 65:
        scene = new Sticks(new RainbowPalette(), 2, 3, 1);
        break;

        //L'amour
      case 67:
        scene = new SquareDrops(new RainbowPalette(), SquareDrops::wash);
        break;
      case 68:
        scene = new Gfx(new RainbowPalette(), GfxEnum::gfx_star, Gfx::EGfxMode::gfxMode_normal,  Gfx::EYmove::bipolar, true, true);
        break;


      case 70:
        scene = new Gfx(new Palette(COLOR(7, 0, 0)), GfxEnum::gfx_tear, Gfx::EGfxMode::gfxMode_plain,  Gfx::EYmove::diagonalFall);
        break;
      case 71:
        scene = new Gfx(new Palette(COLOR(7, 0, 0)), GfxEnum::gfx_tear, Gfx::EGfxMode::gfxMode_plain,  Gfx::EYmove::falling);
        break;

*/