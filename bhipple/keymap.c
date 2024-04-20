#include QMK_KEYBOARD_H

#define Colemak 0
#define NumPad 1
#define Macros 2
#define LeftIdx 3
#define RightIdx 4
#define Editor 5
#define Tmux 6
#define Qwerty 7

// Define Aliases
#define D_BLUETOOTH_CON KC_WWW_SEARCH
#define D_BLUETOOTH_DISC KC_MAIL
#define D_PROGRAM LALT(KC_P)
#define D_TERMINAL LALT(KC_ENTER)

#include "generated.h"

const uint16_t PROGMEM combo1[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_E, KC_S, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_F, KC_U, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo1, KC_SPACE),
    COMBO(combo2, KC_SPACE),
    COMBO(combo3, KC_SPACE),
    COMBO(combo4, KC_ENTER),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only do things on key presses, not lift ups
    if (!record->event.pressed) {
        return true;
    }

    // All of the standard ones that are just mapping KEY -> STRING
    return generated_keycode_process(keycode);
}
