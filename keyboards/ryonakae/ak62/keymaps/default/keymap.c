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

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FUNC 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_FNC   FUNC


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
    //|--------------------------------------------------------------------------------.
          ESC,     1,     2,     3,     4,     5,     6,     7,     8,     9,     0,  MINS,   EQL,     BSPC,\
    //|------+------+------+------+------+------+------+------+------+------+------+------+------+---------|
             TAB,     Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,  LBRC,  RBRC,   ENT,\
    //|---------+------+------+------+------+------+------+------+------+------+------+------+------+      |
             LCTRL,     A,     S,     D,     F,     G,     H,     J,     K,     L,  SCLN,  QUOT,            \
    //|-----------+------+------+------+------+------+------+------+------+------+------+------+-----------|
                 LSFT,     Z,     X,     C,     V,     B,     N,     M,  COMM,   DOT,  SLSH,            FNC,\
    //|--------------+------+------+------+------+------+------+------+------+------+------+---------------|
         LCAP,  LALT,      LGUI, LANG2,                              SPC, LANG1,  LEFT,  DOWN,    UP,  RGHT \
    //|------+------+----------+------+---------------------------------+------+------+------+------+------|
  ),
  [_FUNC] = LAYOUT_kc(
    //|--------------------------------------------------------------------------------.
        _____,    F1,    F2,    F3,    F4,    F5,    F6,    F7,    F8,    F9,   F10,   F11,   F12,      DEL,\
    //|------+------+------+------+------+------+------+------+------+------+------+------+------+---------|
           _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,RETURN,\
    //|---------+------+------+------+------+------+------+------+------+------+------+------+------+      |
             _____,  VOLD,  VOLU,  MUTE, _____, _____, _____, _____, _____, _____, _____, _____,            \
    //|-----------+------+------+------+------+------+------+------+------+------+------+------+-----------|
                _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,          _____,\
    //|--------------+------+------+------+------+------+------+------+------+------+------+---------------|
        _____, _____,     _____,   GRV,                            _____,  BSLS, _____, _____, _____, _____ \
    //|------+------+----------+------+---------------------------------+------+------+------+------+------|
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    default:
      break;
  }
  return true;
}
