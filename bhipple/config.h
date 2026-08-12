#define TAPPING_TERM 150

// If I press and hold a key for longer than TAPPING_TERM but do not press another key, send the original key
// https://docs.qmk.fm/#/tap_hold?id=retro-tapping
#define RETRO_TAPPING

// When defined: if I hold a tap-hold modifier key, then press another key, then
// release the other key, send the tap hold even if faster than TAPPING_TERM.
// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
#undef PERMISSIVE_HOLD
#undef PERMISSIVE_HOLD_PER_KEY
