#include QMK_KEYBOARD_H

#define Colemak 0
#define NumPad 1
#define Macros 2
#define Idx 3
#define Editor 4
#define Tmux 5
#define Qwerty 6

// Define Aliases
#define D_BLUETOOTH_CON KC_WWW_SEARCH
#define D_BLUETOOTH_DISC KC_MAIL
#define D_PROGRAM LALT(KC_P)
#define D_TERMINAL LALT(KC_ENTER)

#include "generated.h"

// Top row
// Home row
const uint16_t PROGMEM combo3[] = {MT(MOD_LGUI, KC_S), MT(MOD_RGUI, KC_E), COMBO_END};
const uint16_t PROGMEM combo4[] = {MT(MOD_LALT, KC_R), MT(MOD_RALT, KC_I), COMBO_END};
// Bottom row
const uint16_t PROGMEM combo5[] = {KC_D, KC_H, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo3, KC_SPACE),
    COMBO(combo4, KC_SPACE),
    COMBO(combo5, KC_SPACE),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only do things on key presses, not lift ups
    if (!record->event.pressed) {
        return true;
    }

    // All of the standard ones that are just mapping KEY -> STRING
    return generated_keycode_process(keycode);
}
