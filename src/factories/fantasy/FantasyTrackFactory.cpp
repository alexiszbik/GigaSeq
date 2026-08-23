#include "FantasyTrackFactory.h"

#include "factories/fantasy/FantasyPatterns.h"
#include "MidiChannel.h"

SequenceTrack FantasyTrackFactory::fantasyArp(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);
    track.setPattern(FantasyPatterns::kFantasyArp, lengthInTicks, startInTicks);
    return track;
}
