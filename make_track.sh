#!/usr/bin/env bash

if [ -z "${BASH_VERSION:-}" ]; then
    exec bash "$0" "$@"
fi

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
MIDI_CHANNEL_FILE="${SCRIPT_DIR}/src/engine/MidiChannel.h"

SONG_NAME="${1:-}"
TRACK_NAME="${2:-}"
MIDI_CHANNEL="${3:-}"

read_midi_channels() {
    CHANNEL_NAMES=()

    while IFS= read -r line; do
        local rest="$line"
        while [[ "$rest" =~ constexpr\ uint8_t\ ([kK][A-Za-z]+)\ =\ ([0-9]+) ]]; do
            CHANNEL_NAMES+=("${BASH_REMATCH[1]}")
            rest="${rest#*"${BASH_REMATCH[0]}"}"
        done
    done <<EOF
$(grep 'constexpr uint8_t' "$MIDI_CHANNEL_FILE")
EOF
}

is_valid_midi_channel() {
    local input="$1"
    for name in "${CHANNEL_NAMES[@]}"; do
        if [[ "$input" == "$name" ]]; then
            SELECTED_CHANNEL="$name"
            return 0
        fi
    done
    return 1
}

prompt_midi_channel() {
    if [[ ${#CHANNEL_NAMES[@]} -eq 0 ]]; then
        echo "No MIDI channels found in ${MIDI_CHANNEL_FILE}" >&2
        exit 1
    fi

    echo "Available MIDI channels:"
    for name in "${CHANNEL_NAMES[@]}"; do
        echo "  ${name}"
    done

    while true; do
        read -r -p "MIDI channel (enum name, e.g. kDrums) : " choice
        if is_valid_midi_channel "$choice"; then
            return
        fi
        echo "Invalid channel. Use one of the enum names listed above." >&2
    done
}

if [[ -z "$SONG_NAME" ]]; then
    read -r -p "Which song? : " SONG_NAME
fi

if [[ -z "$TRACK_NAME" ]]; then
    read -r -p "Track name (e.g. bass, hiDrum) : " TRACK_NAME
fi

if [[ -z "$SONG_NAME" || -z "$TRACK_NAME" ]]; then
    echo "Usage: $0 <song> <track> [midiChannel]" >&2
    exit 1
fi

read_midi_channels

if [[ -n "$MIDI_CHANNEL" ]]; then
    if ! is_valid_midi_channel "$MIDI_CHANNEL"; then
        echo "Invalid MIDI channel: ${MIDI_CHANNEL}" >&2
        echo "Available: ${CHANNEL_NAMES[*]}" >&2
        exit 1
    fi
else
    prompt_midi_channel
fi

SONG_NAME="$(printf '%s' "$SONG_NAME" | tr '[:upper:]' '[:lower:]')"
UPPERCASE_SONG="$(printf '%s' "${SONG_NAME:0:1}" | tr '[:lower:]' '[:upper:]')${SONG_NAME:1}"
UPPERCASE_TRACK="$(printf '%s' "${TRACK_NAME:0:1}" | tr '[:lower:]' '[:upper:]')${TRACK_NAME:1}"

FUNCTION_NAME="${SONG_NAME}${UPPERCASE_TRACK}"
TRACK_LABEL="${UPPERCASE_TRACK}"
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
    static SequenceTrack ${FUNCTION_NAME}(tick_t lengthInTicks, tick_t startInTicks);
" "$TRACK_H"
else
    sed -i "/^};/i\\    static SequenceTrack ${FUNCTION_NAME}(tick_t lengthInTicks, tick_t startInTicks);" "$TRACK_H"
fi

cat >> "$TRACK_CPP" <<EOF

SequenceTrack ${CLASS_NAME}::${FUNCTION_NAME}(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("${TRACK_LABEL}", MidiChannel::${SELECTED_CHANNEL});

    SequenceDesc desc;
    desc.notes = {{C3}};
    desc.rate = 16;
    makeSequenceTrack(track, desc, lengthInTicks, startInTicks);

    return track;
}
EOF

echo "Added ${CLASS_NAME}::${FUNCTION_NAME}"
echo "  label   : ${TRACK_LABEL}"
echo "  channel : MidiChannel::${SELECTED_CHANNEL}"
echo "  - ${TRACK_H}"
echo "  - ${TRACK_CPP}"
