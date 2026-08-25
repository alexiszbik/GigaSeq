#pragma once

#include "TrackPattern.h"
#include "TiredSamples.h"
#include "factories/MidiNotes.h"

namespace TiredPatterns
{


constexpr PatternStep kTiredIntroSteps[] = {
    {{Tired::tiredIntro}, 127, 1},
    _NO_STEP
};

MAKE_PATTERN(kTiredIntro, kTiredIntroSteps, 1);


constexpr PatternStep kTiredHatSoloSteps[] = {
    {{Tired::tiredSolohat}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,

    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP
};

MAKE_PATTERN(kTiredHatSolo, kTiredHatSoloSteps, 1);


constexpr PatternStep kTiredCongasSteps[] = {
    {{Tired::tiredConga}, 127, 1},
};

MAKE_PATTERN(kTiredCongas, kTiredCongasSteps, 1);


constexpr PatternStep kTiredRobotoSteps[] = {
    {{Tired::tiredPsysynth}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,

    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
    _NO_STEP
};

MAKE_PATTERN(kTiredRoboto, kTiredRobotoSteps, 1);


constexpr PatternStep kTiredHatsSteps[] = {
    {{Tired::tiredHat}, 66, 1},
    {{Tired::tiredHat}, 91, 1},
    {{Tired::tiredHat}, 127, 1},
    {{Tired::tiredHat}, 91, 1},

};

MAKE_PATTERN(kTiredHats, kTiredHatsSteps, 16);


constexpr PatternStep kTiredSyncSteps[] = {
    {{Tired::tiredSync}, 127, 1},
};

MAKE_PATTERN(kTiredSync, kTiredSyncSteps, 1);


constexpr PatternStep kTiredPhazeHatSteps[] = {
    {{Tired::tiredPhzhat}, 127, 1},
    _NO_STEP,
    _NO_STEP,
    _NO_STEP,
};

MAKE_PATTERN(kTiredPhazeHat, kTiredPhazeHatSteps, 1);


constexpr PatternStep kTiredFreakSteps[] = {
    STEP(G1), _NO_STEP, STEP(G1), _NO_STEP,
    _NO_STEP, STEP(G1), _NO_STEP, _NO_STEP
};

MAKE_PATTERN(kTiredFreak, kTiredFreakSteps, 16);


constexpr PatternStep kTiredFreakArpSteps[] = {
    STEP(D3),STEP(F3),STEP(A3),STEP(D4),STEP(F4),STEP(A4),
    STEP(D5),STEP(F5),STEP(A5),STEP(D6),STEP(F6),STEP(A6),
    STEP(F6),STEP(D6),STEP(A5),STEP(F5),STEP(D5),STEP(A4),
    STEP(F4),STEP(D4),STEP(A3),STEP(F3),STEP(D3),STEP(F3),

    STEP(Ad2),STEP(D3),STEP(F3),STEP(Ad3),STEP(D4),STEP(F4),
    STEP(Ad4),STEP(D5),STEP(F5),STEP(Ad5),STEP(D6),STEP(F6),
    STEP(D6),STEP(Ad5),STEP(F5),STEP(D5),STEP(Ad4),STEP(F4),
    STEP(D4),STEP(Ad3),STEP(F3),STEP(D3),STEP(Ad2),STEP(D3),

    STEP(G2),STEP(Ad2),STEP(D3),STEP(G3),STEP(Ad3),STEP(D4),
    STEP(G4),STEP(Ad4),STEP(D5),STEP(G5),STEP(Ad5),STEP(D6),
    STEP(Ad5),STEP(G5),STEP(D5),STEP(Ad4),STEP(G4),STEP(D4),
    STEP(Ad3),STEP(G3),STEP(D3),STEP(Ad2),STEP(G2),STEP(Ad2),

    STEP(D3),STEP(Fd3),STEP(A3),STEP(D4),STEP(Fd4),STEP(A4),
    STEP(D5),STEP(Fd5),STEP(A5),STEP(D6),STEP(Fd6),STEP(A6),
    STEP(Fd6),STEP(D6),STEP(A5),STEP(Fd5),STEP(D5),STEP(A4),
    STEP(Fd4),STEP(D4),STEP(A3),STEP(Fd3),STEP(D3),STEP(Fd3),
};

MAKE_PATTERN(kTiredFreakArp, kTiredFreakArpSteps, 24);

#define CHORD(note) {{ note, note + 7, note - 12}, 127, 1}

#define CHORD_PATTERN(note) \
CHORD(note), _NO_STEP, _NO_STEP, CHORD(note), \
_NO_STEP, _NO_STEP, CHORD(note), _NO_STEP, \
_NO_STEP, CHORD(note), _NO_STEP, _NO_STEP, \
CHORD(note), _NO_STEP, CHORD(note), _NO_STEP

constexpr PatternStep kTiredStabsSteps[] = {
    CHORD_PATTERN(D3), CHORD_PATTERN(Ad2), CHORD_PATTERN(G2),
    CHORD(D3), _NO_STEP, _NO_STEP, CHORD(D3),
    _NO_STEP, _NO_STEP, CHORD(D3), _NO_STEP,
    _NO_STEP, CHORD(D2), _NO_STEP, _NO_STEP,
    CHORD(D2), _NO_STEP, CHORD(D2), _NO_STEP
};

MAKE_PATTERN(kTiredStabs, kTiredStabsSteps, 16);

#undef CHORD
#undef CHORD_PATTERN

#define NOTE_PATTERN(note) \
STEP(note), _NO_STEP, _NO_STEP, STEP(note), \
_NO_STEP, _NO_STEP, STEP(note), _NO_STEP, \
_NO_STEP, STEP(note), _NO_STEP, _NO_STEP, \
STEP(note), _NO_STEP, STEP(note), _NO_STEP

constexpr PatternStep kTiredBassSteps[] = {
    NOTE_PATTERN(D2), NOTE_PATTERN(Ad1), NOTE_PATTERN(G1),
    STEP(D2), _NO_STEP, _NO_STEP, STEP(D3),
    _NO_STEP, _NO_STEP, STEP(D3), _NO_STEP,
    _NO_STEP, STEP(D1), _NO_STEP, _NO_STEP,
    STEP(D1), _NO_STEP, STEP(D1), _NO_STEP
};

MAKE_PATTERN(kTiredBass, kTiredBassSteps, 16);

#undef NOTE_PATTERN

constexpr PatternStep kTiredTechHatsSteps[] = {
    _NO_STEP, _NO_STEP, {{Tired::hhod4}, 127, 1}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Tired::hhod4}, 127, 1}, _NO_STEP,
    _NO_STEP, _NO_STEP, {{Tired::hhod4}, 127, 1}, {{Tired::hhod42}, 127, 1},
    _NO_STEP, _NO_STEP, {{Tired::hhod4}, 127, 1}, _NO_STEP,
};

MAKE_PATTERN(kTiredTechHats, kTiredTechHatsSteps, 16);

#define IMPACT {{Tired::techsnare, Tired::handclp1}, 127, 1}

constexpr PatternStep kTiredImpactsSteps[] = {
    _NO_STEP, IMPACT, IMPACT, IMPACT,
    IMPACT, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    IMPACT, _NO_STEP, IMPACT, _NO_STEP,
    IMPACT, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, IMPACT, IMPACT,
};

#undef IMPACT

MAKE_PATTERN(kTiredImpacts, kTiredImpactsSteps, 16);

#define IMPACT {{Tired::techkicklong}, 127, 1}

constexpr PatternStep kTiredKickImpactsSteps[] = {
    _NO_STEP, IMPACT, IMPACT, IMPACT,
    IMPACT, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    IMPACT, _NO_STEP, IMPACT, _NO_STEP,
    IMPACT, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    _NO_STEP, _NO_STEP, IMPACT, IMPACT,
};

#undef IMPACT

MAKE_PATTERN(kTiredKickImpacts, kTiredKickImpactsSteps, 16);

#define KICK_STEP {{Tired::techkickshort}, 127, 1}

constexpr PatternStep kTiredTechKickSteps[] = {
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, KICK_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,

    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, _NO_STEP,
    KICK_STEP, _NO_STEP, _NO_STEP, KICK_STEP,
    KICK_STEP, _NO_STEP, KICK_STEP, _NO_STEP,
};

MAKE_PATTERN(kTiredTechKick, kTiredTechKickSteps, 16);

#define IMPACT {{Tired::techkickshort, Tired::techsnare, Tired::handclp1, Tired::hhod4}, 127, 1}

constexpr PatternStep kTiredBigDrumsSteps[] = {
    IMPACT, _NO_STEP, _NO_STEP, IMPACT,
    _NO_STEP, _NO_STEP, IMPACT, _NO_STEP,
    _NO_STEP, IMPACT, _NO_STEP, _NO_STEP,
    IMPACT, _NO_STEP, IMPACT, _NO_STEP,

    IMPACT, _NO_STEP, _NO_STEP, IMPACT,
    _NO_STEP, _NO_STEP, IMPACT, _NO_STEP,
    _NO_STEP, IMPACT, _NO_STEP, _NO_STEP,
    IMPACT, _NO_STEP, IMPACT, _NO_STEP,

    IMPACT, _NO_STEP, _NO_STEP, IMPACT,
    _NO_STEP, _NO_STEP, IMPACT, _NO_STEP,
    _NO_STEP, IMPACT, _NO_STEP, _NO_STEP,
    IMPACT, _NO_STEP, IMPACT, _NO_STEP,

    IMPACT, _NO_STEP, _NO_STEP, IMPACT,
    _NO_STEP, _NO_STEP, IMPACT, _NO_STEP,
    _NO_STEP, IMPACT, IMPACT, _NO_STEP,
    IMPACT, _NO_STEP, IMPACT, _NO_STEP
};

#undef IMPACT

MAKE_PATTERN(kTiredBigDrums, kTiredBigDrumsSteps, 16);

constexpr PatternStep kTiredClapRollSteps[] = {
    {{Tired::clap}, 127, 1},
};

MAKE_PATTERN(kTiredClapRoll, kTiredClapRollSteps, 16);

constexpr PatternStep kTiredShakeSteps[] = {
    _NO_STEP, {{Tired::tiredShake}, 127, 1}
};

MAKE_PATTERN(kTiredShake, kTiredShakeSteps, 8);

#define CLAVE {{Tired::clave, Tired::tiredHat}, 127, 1}

constexpr PatternStep kTiredClaveSteps[] = {
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,

    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,

    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,

    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP, CLAVE, _NO_STEP,
    CLAVE, CLAVE, CLAVE, CLAVE, CLAVE, CLAVE, CLAVE, CLAVE,
};

MAKE_PATTERN(kTiredClave, kTiredClaveSteps, 32);


constexpr PatternStep kTiredRideSteps[] = {
    _NO_STEP,
    {{Tired::cy0000}, 127, 1},
};

MAKE_PATTERN(kTiredRide, kTiredRideSteps, 8);

} // namespace TiredPatterns
