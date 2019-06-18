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
#define _FUNC 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC_ENT
};

#define KC______  KC_TRNS
#define KC_XXXXX  KC_NO
#define KC_RST    RESET
#define KC_LOWV   LT(_LOWER, KC_V)
#define KC_RAIN   LT(_RAISE, KC_N)
#define KC_FNCENT FUNC_ENT
#define KC_CTLTB  CTL_T(KC_TAB)
#define KC_CTL_TB LCTL(KC_TAB)
#define KC_SFTESC SFT_T(KC_ESC)
#define KC_ALTZ   ALT_T(KC_Z)
#define KC_LGUIC  LGUI_T(KC_C)
#define KC_RGUIM  RGUI_T(KC_M)
#define KC_COPY   LGUI(KC_C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
                Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,  BSPC,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
        CTLTB,     A,     S,     D,     F,     G,     H,     J,     K,     L,    FNCENT,\
    //|------+------+------+------+------+------+------+------+------+------+          |
           SFTESC,  ALTZ,     X, LGUIC,  LOWV,     B,  RAIN, RGUIM,        SPC          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_LOWER] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
                1,     2,     3,     4,     5,     6,     7,     8,     9,     0, _____,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
       CTL_TB,    F1,    F2,    F3,    F4,    F5,    F6,    F7,    F8,    F9,     _____,\
    //|------+------+------+------+------+------+------+------+------+------+          |
            _____, _____, _____,  COPY, _____, _____, _____, _____,      _____          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_RAISE] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
             EXLM,    AT,  HASH,   DLR,  PERC,  CIRC,  AMPR,  ASTR,  LPRN,  RPRN, _____,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
        _____,  LBRC,  RBRC,  SLSH,  BSLS,   GRV,  MINS,   EQL,  SCLN,  QUOT,     _____,\
    //|------+------+------+------+------+------+------+------+------+------+          |
            _____, _____, _____, _____, _____, _____, _____,  COMM,        DOT          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_FUNC] = LAYOUT_kc(
        //|----------------------------------------------------------------------------.
              RST, _____, _____, _____, _____, _____, _____,    UP, _____, _____,   DEL,\
    //|---+------+------+------+------+------+------+------+------+------+------+------|
        _____,  VOLD,  VOLU,  MUTE, _____, _____, _____,  LEFT,  RGHT, _____,     _____,\
    //|------+------+------+------+------+------+------+------+------+------+          |
            _____, _____, _____, _____, _____, _____, _____,  DOWN,      _____          \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool func_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case FUNC_ENT:
      if (record->event.pressed) {
        func_pressed = true;
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
        if (func_pressed) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        }
        func_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        func_pressed = false;
      }
      break;
  }
  return true;
}
