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

// See here for generic keycodes:
// https://docs.qmk.fm/#/keycodes
enum my_keycodes {
    // New definitions
    M_PASTE = SAFE_RANGE,
    M_EOL_SEMICOLON,
};

// Define Aliases
#define D_BLUETOOTH  KC_WWW_SEARCH
#define D_PROGRAM    LWIN(KC_P)
#define D_TERMINAL   LWIN(KC_ENTER)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only do things on key presses, not lift ups
    if(!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case M_PASTE:
            SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
            break;
        case M_EOL_SEMICOLON:
            SEND_STRING(SS_TAP(X_ESCAPE) "A;");
            break;
    }
    return true;
}

#include "generated.h"
