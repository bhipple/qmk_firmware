#define TAPPING_TERM 125

// Opposite-hands rule: a tap-hold key chorded with another key on the SAME
// hand always settles as tapped, so same-hand rolls can't misfire mods/layers.
// https://docs.qmk.fm/tap_hold#chordal-hold
#define CHORDAL_HOLD

// With same-hand rolls filtered by Chordal Hold, let an opposite-hand key that
// is pressed AND released while a tap-hold key is down settle it as held, even
// faster than TAPPING_TERM.
// https://docs.qmk.fm/tap_hold#permissive-hold
#define PERMISSIVE_HOLD

// While typing quickly (a tap-hold alpha pressed within this many ms of the
// previous alpha), settle as tapped immediately: no accidental holds mid-word
// and no tapping-term latency.
// https://docs.qmk.fm/tap_hold#flow-tap
#define FLOW_TAP_TERM 150
