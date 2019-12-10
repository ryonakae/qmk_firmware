/* Copyright 2019 Ryo Nakae
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_FN    MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
    //|-----------------------------------------.            ,----------------------------------------------------------.
          ESC,     1,     2,     3,     4,     5,                  6,     7,     8,     9,     0,  MINS,   EQL,     BSPC,\
    //|------+------+------+------+------+------|            |------+------+------+------+------+------+------+---------|
             TAB,     Q,     W,     E,     R,     T,                  Y,     U,     I,     O,     P,  LBRC,  RBRC,   ENT,\
    //|---------+------+------+------+------+------|            |------+------+------+------+------+------+------+      |
             LCTRL,     A,     S,     D,     F,     G,                  H,     J,     K,     L,  SCLN,  QUOT,            \
    //|-----------+------+------+------+------+------|            |------+------+------+------+------+------+-----------|
                 LSFT,     Z,     X,     C,     V,     B,                  N,     M,  COMM,   DOT,  SLSH,             FN,\
    //|--------------+------+------+------+------+------|--------.   |------+------+------+------+------+---------------|
         LCAP,  LALT,      LGUI,                              SPC,               RGUI,  BSLS,  LEFT,  DOWN,    UP,  RGHT \
    //|------+------+----------+---------------------------------'            `------+------+------+------+------+------.
  ),
  [_FN] = LAYOUT_kc(
    //|-----------------------------------------.            ,----------------------------------------------------------.
        _____,    F1,    F2,    F3,    F4,    F5,                 F6,    F7,    F8,    F9,   F10,   F11,   F12,      DEL,\
    //|------+------+------+------+------+------|            |------+------+------+------+------+------+------+---------|
           _____, _____, _____, _____, _____, _____,              _____, _____, _____, _____, _____, _____, _____,  PENT,\
    //|---------+------+------+------+------+------|            |------+------+------+------+------+------+------+      |
             _____,  VOLD,  VOLU,  MUTE,  EJCT, _____,              _____, _____, _____, _____, _____, _____,            \
    //|-----------+------+------+------+------+------|            |------+------+------+------+------+------+-----------|
                _____, _____, _____, _____, _____, _____,              _____, _____, _____, _____, _____,          _____,\
    //|--------------+------+------+------+------+------|--------.   |------+------+------+------+------+---------------|
        _____, _____,     _____,                            _____,                GRV, _____, _____, _____, _____, _____ \
    //|------+------+----------+---------------------------------'            `------+------+------+------+------+------.
  ),
};
