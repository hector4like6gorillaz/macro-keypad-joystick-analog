/* Copyright 2021 Hector_Balan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <analog.h>


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE = 0,
    _ONE = 1,
    _TWO = 2,
    _THREE = 3,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BASE] = LAYOUT(
        KC_A,    KC_1,   KC_2,
        KC_4,  KC_5, TO(1),  MO(3)
    ),
    [_ONE] = LAYOUT(
        KC_Q,    KC_W,   KC_E,
        KC_R,  KC_T, TO(2),  MO(_FN)
    ),
    [_TWO] = LAYOUT(
        KC_BTN1,    KC_MS_U,   TO(3),
        KC_MS_L,  KC_MS_D, KC_MS_R, KC_BTN2
    ),
    [_THREE] = LAYOUT(
        KC_BTN1,    KC_WH_U,   TO(0),
        KC_WH_L,  KC_WH_D, KC_WH_R, KC_BTN2
    ),
    [_FN] = LAYOUT(
        QMKBEST, QMKURL,  _______,
        RESET,   KC_A,    KC_1, _______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("do:a margara francisca");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
