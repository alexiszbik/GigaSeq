#pragma once

#include <cstdint>

namespace MidiLoop
{
#define _MIDI_LOOP_CC(name, nbr) constexpr uint8_t k##name##_cc = nbr

#define _MIDI_LOOP_NOTE(name, nbr) constexpr uint8_t k##name = nbr

_MIDI_LOOP_CC(BarCount, 10);
_MIDI_LOOP_CC(ArpMode, 20);
_MIDI_LOOP_CC(Record, 40);

_MIDI_LOOP_NOTE(SelectPoly, 50);
_MIDI_LOOP_NOTE(SelectBass, 51);
_MIDI_LOOP_NOTE(SelectVocoder, 52);
_MIDI_LOOP_NOTE(SelectMicrofreak, 53);

_MIDI_LOOP_NOTE(MuteMomentaryPoly, 60);
_MIDI_LOOP_NOTE(MuteMomentaryBass, 61);
_MIDI_LOOP_NOTE(MuteMomentaryVocoder, 62);
_MIDI_LOOP_NOTE(MuteMomentaryMicrofreak, 63);

_MIDI_LOOP_CC(MutePoly, 60);
_MIDI_LOOP_CC(MuteBass, 61);
_MIDI_LOOP_CC(MuteVocoder, 62);
_MIDI_LOOP_CC(MuteMicrofreak, 63);

_MIDI_LOOP_NOTE(EraseAll, 70);


} // namespace MidiChannel