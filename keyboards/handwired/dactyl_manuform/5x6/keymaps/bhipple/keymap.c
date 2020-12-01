/* The bhipple layout for the Dactyl Manuform 5x6 Keyboard */
// clang-format: off

#include QMK_KEYBOARD_H

#define Colemak 0
#define NumPad 1
#define Macros 2
#define LeftIdx 3
#define RightIdx 4
#define Emacs 5
#define Tmux 6
#define Qwerty 7

#define RAISE MO(_COLEMAK)
#define LOWER MO(_COLEMAK)

enum my_keycodes {
    LYR_CLR = SAFE_RANGE,  // Clear Layer
    FOO,
};

// See here for keycodes:
// https://docs.qmk.fm/#/keycodes
#include "generated.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FOO:
            if (record->event.pressed) {
                // Do something when pressed
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}
