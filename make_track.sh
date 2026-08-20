#!/bin/bash

set -euo pipefail

SONG_NAME="${1:-}"
TRACK_NAME="${2:-}"

if [[ -z "$SONG_NAME" ]]; then
    read -r -p "Which song? : " SONG_NAME
fi

if [[ -z "$TRACK_NAME" ]]; then
    read -r -p "Track name (e.g. bass, hiDrum) : " TRACK_NAME
fi

if [[ -z "$SONG_NAME" || -z "$TRACK_NAME" ]]; then
    echo "Usage: $0 <song> <track>" >&2
    exit 1
fi

SONG_NAME="$(tr '[:upper:]' '[:lower:]' <<< "$SONG_NAME")"
UPPERCASE_SONG="$(tr '[:lower:]' '[:upper:]' <<< "${SONG_NAME:0:1}")${SONG_NAME:1}"
UPPERCASE_TRACK="$(tr '[:lower:]' '[:upper:]' <<< "${TRACK_NAME:0:1}")${TRACK_NAME:1}"

FUNCTION_NAME="${SONG_NAME}${UPPERCASE_TRACK}"
CLASS_NAME="${UPPERCASE_SONG}TrackFactory"
FACTORY_DIR="src/factories/${SONG_NAME}"
TRACK_H="${FACTORY_DIR}/${CLASS_NAME}.h"
TRACK_CPP="${FACTORY_DIR}/${CLASS_NAME}.cpp"

if [[ ! -d "$FACTORY_DIR" ]]; then
    echo "Song folder not found: ${FACTORY_DIR}" >&2
    echo "Run make_song.sh first to create the song." >&2
    exit 1
fi

if [[ ! -f "$TRACK_H" || ! -f "$TRACK_CPP" ]]; then
    echo "Track factory not found: ${TRACK_H} / ${TRACK_CPP}" >&2
    exit 1
fi

if grep -q "${FUNCTION_NAME}(tick_t" "$TRACK_H"; then
    echo "Track function '${FUNCTION_NAME}' already exists." >&2
    exit 1
fi

if [[ "$(uname)" == "Darwin" ]]; then
    sed -i '' "/^};/i\\
    static SequenceTrack ${FUNCTION_NAME}(tick_t lengthInTicks);
" "$TRACK_H"
else
    sed -i "/^};/i\\    static SequenceTrack ${FUNCTION_NAME}(tick_t lengthInTicks);" "$TRACK_H"
fi

cat >> "$TRACK_CPP" <<EOF

SequenceTrack ${CLASS_NAME}::${FUNCTION_NAME}(tick_t lengthInTicks) {
    SequenceTrack track("Modular", MidiChannel::kModularA);

    SequenceDesc desc;
    desc.notes = {{C3}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks);

    return track;
}
EOF

echo "Added ${CLASS_NAME}::${FUNCTION_NAME}"
echo "  - ${TRACK_H}"
echo "  - ${TRACK_CPP}"
