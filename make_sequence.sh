#!/bin/bash

set -euo pipefail

SONG_NAME="${1:-}"
SEQUENCE_NAME="${2:-}"

if [[ -z "$SONG_NAME" ]]; then
    read -r -p "Which song? : " SONG_NAME
fi

if [[ -z "$SEQUENCE_NAME" ]]; then
    read -r -p "Sequence name (e.g. intro, partB, climax) : " SEQUENCE_NAME
fi

if [[ -z "$SONG_NAME" || -z "$SEQUENCE_NAME" ]]; then
    echo "Usage: $0 <song> <sequence>" >&2
    exit 1
fi

SONG_NAME="$(tr '[:upper:]' '[:lower:]' <<< "$SONG_NAME")"
UPPERCASE_SONG="$(tr '[:lower:]' '[:upper:]' <<< "${SONG_NAME:0:1}")${SONG_NAME:1}"
UPPERCASE_SEQUENCE="$(tr '[:lower:]' '[:upper:]' <<< "${SEQUENCE_NAME:0:1}")${SEQUENCE_NAME:1}"

FUNCTION_NAME="${SONG_NAME}${UPPERCASE_SEQUENCE}"
SEQUENCE_LABEL="${UPPERCASE_SEQUENCE}"
CLASS_NAME="${UPPERCASE_SONG}SequenceFactory"
TRACK_CLASS="${UPPERCASE_SONG}TrackFactory"
FACTORY_DIR="src/factories/${SONG_NAME}"
SEQUENCE_H="${FACTORY_DIR}/${CLASS_NAME}.h"
SEQUENCE_CPP="${FACTORY_DIR}/${CLASS_NAME}.cpp"
SONG_CPP="${FACTORY_DIR}/${UPPERCASE_SONG}Song.cpp"
TRACK_H="${FACTORY_DIR}/${UPPERCASE_SONG}TrackFactory.h"

if [[ ! -d "$FACTORY_DIR" ]]; then
    echo "Song folder not found: ${FACTORY_DIR}" >&2
    echo "Run make_song.sh first to create the song." >&2
    exit 1
fi

if [[ ! -f "$SEQUENCE_H" || ! -f "$SEQUENCE_CPP" ]]; then
    echo "Sequence factory not found: ${SEQUENCE_H} / ${SEQUENCE_CPP}" >&2
    exit 1
fi

if [[ ! -f "$SONG_CPP" ]]; then
    echo "Song file not found: ${SONG_CPP}" >&2
    exit 1
fi

if grep -q "${FUNCTION_NAME}()" "$SEQUENCE_H"; then
    echo "Sequence function '${FUNCTION_NAME}' already exists." >&2
    exit 1
fi

FIRST_TRACK=""
if [[ -f "$TRACK_H" ]]; then
    FIRST_TRACK="$(grep -oE "static SequenceTrack ${SONG_NAME}[A-Za-z0-9_]+\(tick_t" "$TRACK_H" | head -1 | sed -E 's/static SequenceTrack ([^(]+).*/\1/' || true)"
fi

if [[ "$(uname)" == "Darwin" ]]; then
    sed -i '' "/^};/i\\
    static Sequence ${FUNCTION_NAME}();
" "$SEQUENCE_H"
else
    sed -i "/^};/i\\    static Sequence ${FUNCTION_NAME}();" "$SEQUENCE_H"
fi

cat >> "$SEQUENCE_CPP" <<EOF

Sequence ${CLASS_NAME}::${FUNCTION_NAME}()
{
    Sequence seq = buildSequence(
        8, 4, 0, "${SEQUENCE_LABEL}", 130, true,
        {
${TRACK_ENTRIES}
        });
    return seq;
}
EOF

ARRAY_CLOSE_LINE="$(grep -n '^    };$' "$SONG_CPP" | head -1 | cut -d: -f1)"
if [[ -z "$ARRAY_CLOSE_LINE" ]]; then
    echo "Could not find sequences array in ${SONG_CPP}" >&2
    exit 1
fi

if [[ "$(uname)" == "Darwin" ]]; then
    sed -i '' "${ARRAY_CLOSE_LINE}i\\
        ${CLASS_NAME}::${FUNCTION_NAME},
" "$SONG_CPP"
else
    sed -i "${ARRAY_CLOSE_LINE}i\\        ${CLASS_NAME}::${FUNCTION_NAME}," "$SONG_CPP"
fi

echo "Added ${CLASS_NAME}::${FUNCTION_NAME}"
echo "  - ${SEQUENCE_H}"
echo "  - ${SEQUENCE_CPP}"
echo "  - ${SONG_CPP}"
