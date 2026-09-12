#!/usr/bin/env bash

if [ -z "${BASH_VERSION:-}" ]; then
    exec bash "$0" "$@"
fi

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
CMAKE_FILE="${SCRIPT_DIR}/CMakeLists.txt"

SONG_NAME="${1:-}"
RULES_NAME="${2:-}"

add_to_cmake() {
    local cmake_entry="src/factories/${SONG_NAME}/${CLASS_NAME}.cpp"

    if grep -qF "$cmake_entry" "$CMAKE_FILE"; then
        echo "CMakeLists.txt already contains ${cmake_entry}."
        return
    fi

    local anchor="src/factories/${SONG_NAME}/${UPPERCASE_SONG}TrackFactory.cpp"
    local anchor_line
    anchor_line="$(grep -nF "$anchor" "$CMAKE_FILE" | head -1 | cut -d: -f1)"

    if [[ -z "$anchor_line" ]]; then
        anchor="src/factories/${SONG_NAME}/${UPPERCASE_SONG}Song.cpp"
        anchor_line="$(grep -nF "$anchor" "$CMAKE_FILE" | head -1 | cut -d: -f1)"
    fi

    if [[ -z "$anchor_line" ]]; then
        echo "Could not find song sources in ${CMAKE_FILE}" >&2
        exit 1
    fi

    if [[ "$(uname)" == "Darwin" ]]; then
        sed -i '' "${anchor_line}a\\
    ${cmake_entry}
" "$CMAKE_FILE"
    else
        sed -i "${anchor_line}a\\    ${cmake_entry}" "$CMAKE_FILE"
    fi
}

if [[ -z "$SONG_NAME" ]]; then
    read -r -p "Which song? : " SONG_NAME
fi

if [[ -z "$RULES_NAME" ]]; then
    read -r -p "Rules name (e.g. Led) : " RULES_NAME
fi

if [[ -z "$SONG_NAME" || -z "$RULES_NAME" ]]; then
    echo "Usage: $0 <song> <name>" >&2
    exit 1
fi

SONG_NAME="$(printf '%s' "$SONG_NAME" | tr '[:upper:]' '[:lower:]')"
UPPERCASE_SONG="$(printf '%s' "${SONG_NAME:0:1}" | tr '[:lower:]' '[:upper:]')${SONG_NAME:1}"
UPPERCASE_NAME="$(printf '%s' "${RULES_NAME:0:1}" | tr '[:lower:]' '[:upper:]')${RULES_NAME:1}"

CLASS_NAME="${UPPERCASE_SONG}${UPPERCASE_NAME}Rules"
SINGLETON_NAME="k${UPPERCASE_SONG}${UPPERCASE_NAME}Rules"
FACTORY_DIR="src/factories/${SONG_NAME}"
RULES_H="${FACTORY_DIR}/${CLASS_NAME}.h"
RULES_CPP="${FACTORY_DIR}/${CLASS_NAME}.cpp"

if [[ ! -d "$FACTORY_DIR" ]]; then
    echo "Song folder not found: ${FACTORY_DIR}" >&2
    echo "Run make_song.sh first to create the song." >&2
    exit 1
fi

if [[ -f "$RULES_H" || -f "$RULES_CPP" ]]; then
    echo "OutMidiRules files already exist: ${RULES_H} / ${RULES_CPP}" >&2
    exit 1
fi

if [[ ! -f "$CMAKE_FILE" ]]; then
    echo "CMakeLists.txt not found: ${CMAKE_FILE}" >&2
    exit 1
fi

cat > "$RULES_H" <<EOF
#pragma once

#include "OutMidiRules.h"

class ${CLASS_NAME} : public OutMidiRules
{
public:
    void processNoteOn(const Note& note, uint8_t channel, tick_t durationTicks, MidiInOut& midi) override;
};

extern ${CLASS_NAME} ${SINGLETON_NAME};
EOF

cat > "$RULES_CPP" <<EOF
#include "${CLASS_NAME}.h"

#include "MidiChannel.h"
#include "MidiConst.h"

${CLASS_NAME} ${SINGLETON_NAME};

void ${CLASS_NAME}::processNoteOn(
    const Note& note,
    uint8_t channel,
    tick_t durationTicks,
    MidiInOut& midi)
{
}
EOF

add_to_cmake

echo "Created OutMidiRules for '${SONG_NAME}'"
echo "  class    : ${CLASS_NAME}"
echo "  singleton: ${SINGLETON_NAME}"
echo "  - ${RULES_H}"
echo "  - ${RULES_CPP}"
echo "  - ${CMAKE_FILE}"
