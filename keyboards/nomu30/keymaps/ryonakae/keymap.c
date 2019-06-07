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

#define _BASE 0
#define _NUMS 1
#define _SYMS 2
#define _FUNC 3

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_RST   RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
          //|--------------------------------------------------------------------------.
                Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,  BSPC,\
    //|----------+------+------+------+------+------+------+------+------+------+------|
         LCTL,     A,     S,     D,     F,     G,     H,     J,     K,     L,       ENT,\
    //|------+------+------+------+------+------+------+------+------+------+----------|
             LSFT,     Z,     X,     C,     V,     B,     N,     M,        SPC \
    //|----------+------+------+------+------+------+------+------+-----------+--------|
  ),
  [_NUMS] = LAYOUT_kc(
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, GRV,
    _____, LBRC, RBRC, SLSH, BSLS, _____, MINS, EQL, SCLN, QUOT, _____,
    _____, _____, _____, _____, _____, _____, _____, COMM, DOT
  ),
  [_SYMS] = LAYOUT_kc(
    EXLM, AT, HASH, DLR, PERC, CIRC, AMPR, ASTR, LPRN, RPRN, TILD,
    _____, LCBR, RCBR, QUES, PIPE, _____, UNDS, PLUS, COLN, DQUO, _____,
    _____, LABK, RABK, _____, _____, _____, _____, _____, _____
  ),
  [_FUNC] = LAYOUT_kc(
    ESC, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
    TAB, VOLU, VOLD, MUTE, _____, _____, LEFT, DOWN, UP, RGHT, RST,
    _____, LALT, LGUI, _____, _____, _____, _____, _____, _____
  )
};
