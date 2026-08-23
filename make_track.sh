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

prompt_yes_no() {
    local prompt="$1"
    local default="${2:-n}"
    local answer

    while true; do
        read -r -p "${prompt} [y/N] : " answer
        answer="${answer:-$default}"
        answer="$(printf '%s' "$answer" | tr '[:upper:]' '[:lower:]')"
        case "$answer" in
            y|yes) return 0 ;;
            n|no) return 1 ;;
            *) echo "Please answer y or n." >&2 ;;
        esac
    done
}

add_pattern() {
    local patterns_h="$1"
    local pattern_const="$2"
    local steps_const="$3"
    local namespace="$4"
    local pattern_rate="$5"

    if grep -q "${pattern_const}" "$patterns_h"; then
        echo "Pattern '${pattern_const}' already exists in ${patterns_h}." >&2
        exit 1
    fi

    local namespace_close_line
    namespace_close_line="$(grep -n "^} // namespace ${namespace}$" "$patterns_h" | head -1 | cut -d: -f1)"
    if [[ -z "$namespace_close_line" ]]; then
        echo "Could not find namespace closing brace in ${patterns_h}" >&2
        exit 1
    fi

    local tmpfile
    tmpfile="$(mktemp)"
    trap 'rm -f "$tmpfile"' RETURN

    {
        head -n $((namespace_close_line - 1)) "$patterns_h"
        cat <<EOF

constexpr PatternStep ${steps_const}[] = {
    {{C3}, 127, 1},
};

MAKE_PATTERN(${pattern_const}, ${steps_const}, ${pattern_rate});

EOF
        tail -n +"$namespace_close_line" "$patterns_h"
    } > "$tmpfile"

    mv "$tmpfile" "$patterns_h"
    trap - RETURN
}

ensure_patterns_include() {
    local track_cpp="$1"
    local include_line="$2"

    if grep -qF "$include_line" "$track_cpp"; then
        return
    fi

    if grep -q '#include "MidiChannel.h"' "$track_cpp"; then
        if [[ "$(uname)" == "Darwin" ]]; then
            sed -i '' "/#include \"MidiChannel.h\"/i\\
${include_line}
" "$track_cpp"
        else
            sed -i "/#include \"MidiChannel.h\"/i\\${include_line}" "$track_cpp"
        fi
        return
    fi

  cat >> "$track_cpp" <<EOF
${include_line}
EOF
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
PATTERNS_H="${FACTORY_DIR}/${UPPERCASE_SONG}Patterns.h"
PATTERNS_NAMESPACE="${UPPERCASE_SONG}Patterns"
PATTERNS_INCLUDE="#include \"factories/${SONG_NAME}/${UPPERCASE_SONG}Patterns.h\""

USE_PATTERN=0
PATTERN_NAME=""
PATTERN_RATE="16"

if prompt_yes_no "Add a pattern to this track?"; then
    USE_PATTERN=1
    read -r -p "Pattern name [${TRACK_NAME}] : " PATTERN_NAME
    PATTERN_NAME="${PATTERN_NAME:-$TRACK_NAME}"
    read -r -p "Pattern rate (steps per bar, default 16) : " PATTERN_RATE
    PATTERN_RATE="${PATTERN_RATE:-16}"
fi

if [[ ! -d "$FACTORY_DIR" ]]; then
    echo "Song folder not found: ${FACTORY_DIR}" >&2
    echo "Run make_song.sh first to create the song." >&2
    exit 1
fi

if [[ ! -f "$TRACK_H" || ! -f "$TRACK_CPP" ]]; then
    echo "Track factory not found: ${TRACK_H} / ${TRACK_CPP}" >&2
    exit 1
fi

if [[ "$USE_PATTERN" -eq 1 && ! -f "$PATTERNS_H" ]]; then
    echo "Patterns file not found: ${PATTERNS_H}" >&2
    echo "Run make_song.sh first to create the song." >&2
    exit 1
fi

if grep -q "${FUNCTION_NAME}(tick_t" "$TRACK_H"; then
    echo "Track function '${FUNCTION_NAME}' already exists." >&2
    exit 1
fi

if [[ "$USE_PATTERN" -eq 1 ]]; then
    UPPERCASE_PATTERN="$(printf '%s' "${PATTERN_NAME:0:1}" | tr '[:lower:]' '[:upper:]')${PATTERN_NAME:1}"
    PATTERN_CONST="k${UPPERCASE_SONG}${UPPERCASE_PATTERN}"
    STEPS_CONST="${PATTERN_CONST}Steps"
    add_pattern "$PATTERNS_H" "$PATTERN_CONST" "$STEPS_CONST" "$PATTERNS_NAMESPACE" "$PATTERN_RATE"
    ensure_patterns_include "$TRACK_CPP" "$PATTERNS_INCLUDE"
fi

if [[ "$(uname)" == "Darwin" ]]; then
    sed -i '' "/^};/i\\
    static SequenceTrack ${FUNCTION_NAME}(tick_t lengthInTicks, tick_t startInTicks);
" "$TRACK_H"
else
    sed -i "/^};/i\\    static SequenceTrack ${FUNCTION_NAME}(tick_t lengthInTicks, tick_t startInTicks);" "$TRACK_H"
fi

if [[ "$USE_PATTERN" -eq 1 ]]; then
    cat >> "$TRACK_CPP" <<EOF

SequenceTrack ${CLASS_NAME}::${FUNCTION_NAME}(tick_t lengthInTicks, tick_t startInTicks) {
    SequenceTrack track("${TRACK_LABEL}", MidiChannel::${SELECTED_CHANNEL});
    track.setPattern(${PATTERNS_NAMESPACE}::${PATTERN_CONST}, lengthInTicks, startInTicks);
    return track;
}
EOF
else
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
fi

echo "Added ${CLASS_NAME}::${FUNCTION_NAME}"
echo "  label   : ${TRACK_LABEL}"
echo "  channel : MidiChannel::${SELECTED_CHANNEL}"
if [[ "$USE_PATTERN" -eq 1 ]]; then
    echo "  pattern : ${PATTERNS_NAMESPACE}::${PATTERN_CONST} (rate ${PATTERN_RATE})"
    echo "  - ${PATTERNS_H}"
fi
echo "  - ${TRACK_H}"
echo "  - ${TRACK_CPP}"
