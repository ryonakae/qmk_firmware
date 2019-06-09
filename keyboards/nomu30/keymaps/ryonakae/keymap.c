/* Copyright 2019 Naoto Takai
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
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER_V,
  RAISE_N,
  ADJUST,
};

#define KC______  KC_TRNS
#define KC_XXXXX  KC_NO
#define KC_RST    RESET
#define KC_LOWV   LOWER_V
#define KC_RAIN   RAISE_N
#define KC_CTLTB  CTL_T(KC_TAB)
#define KC_CTL_TB LCTL(KC_TAB)
#define KC_SFTESC SFT_T(KC_ESC)
#define KC_ALTZ   ALT_T(KC_Z)
#define KC_LGUIX  LGUI_T(KC_X)
#define KC_RGUIM  RGUI_T(KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
                Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,  BSPC,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
        CTLTB,     A,     S,     D,     F,     G,     H,     J,     K,     L,       ENT,\
    //|------+------+------+------+------+------+------+------+------+------+          |
           SFTESC,  ALTZ, LGUIX,     C,  LOWV,     B,  RAIN, RGUIM,        SPC          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_LOWER] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
                1,     2,     3,     4,     5,     6,     7,     8,     9,     0,   GRV,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
       CTL_TB,  LBRC,  RBRC, _____, _____, _____,  MINS,   EQL,  SCLN,  QUOT,     _____,\
    //|------+------+------+------+------+------+------+------+------+------+          |
             MINS,   EQL,  BSLS, _____, _____, _____, _____,  COMM,        DOT          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_RAISE] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
             EXLM,    AT,  HASH,   DLR,  PERC,  CIRC,  AMPR,  ASTR,  LPRN,  RPRN,   DEL,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
        _____, _____, _____, _____, _____, _____,  LEFT,  DOWN,    UP,  RGHT,     _____,\
    //|------+------+------+------+------+------+------+------+------+------+          |
            _____, _____, _____, _____, _____, _____, _____, _____,      _____          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_ADJUST] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
               F1,    F2,    F3,    F4,    F5,    F6,    F7,    F8,    F9,   F10,   RST,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
        _____,  VOLU,  VOLD,  MUTE, _____, _____, _____, _____, _____, _____,     _____,\
    //|------+------+------+------+------+------+------+------+------+------+          |
            _____, _____, _____, _____, _____, _____, _____, _____,      _____          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER_V:
      if (record->event.pressed) {
        lower_pressed = true;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed) {
          register_code(KC_V);
          unregister_code(KC_V);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE_N:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed) {
          register_code(KC_N);
          unregister_code(KC_N);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return true;
}
