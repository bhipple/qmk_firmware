// See https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
// Turning this on would prevent a quick `'s` from resulting in `S` if the right quote key was a shift mod tap key.
// However, it means I need to properly hold shift and the key to be shifted for longer than
// the tapping term, which is worse. So this is disabled for now.
// #define IGNORE_MOD_TAP_INTERRUPT
// See explanation in `get_ignore_mod_tap_interrupt` of `keymap.c`
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// Tapping term is used for many things, e.g.
// - how fast I need to double tap the number keys to get an F key
// - for mod-shifts, how long they need to be held to be considered a hold rather than a tap.
#define TAPPING_TERM 200
