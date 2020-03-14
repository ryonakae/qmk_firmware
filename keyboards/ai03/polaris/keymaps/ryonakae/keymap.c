/* Copyright 2019 Ryota Goto
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

enum layer_names {
    _BASE,
    _FN
};

#define KC_FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all( /* Base */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,
    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_FN,
    _______, KC_LALT, KC_LGUI,         _______,           KC_SPC,           _______,                   KC_RGUI, KC_RALT, _______, _______
  ),
  [_FN] = LAYOUT_all( /* FN */
    KC_PWR,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______,          KC_CLR,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,                   KC_PENT,
    _______, _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS,  KC_END, KC_PGDN, KC_DOWN,          _______, _______,
    _______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______, _______
  )
};

