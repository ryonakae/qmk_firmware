/*
Copyright 2018 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
};


extern keymap_config_t keymap_config;

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _CTRL
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(\
    LT(_CTRL, KC_ESC), KC_Q,  KC_W,    KC_E,    KC_R,       KC_T,   KC_MINS,     KC_EQL,  KC_Y,           KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,\
    LCTL_T(KC_TAB),    KC_A,  KC_S,    KC_D,    KC_F,       KC_G,   KC_LBRC,     KC_RBRC, KC_H,           KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
    KC_LSFT,           KC_Z,  KC_X,    KC_C,    KC_V,       KC_B,   XXXXXXX,     XXXXXXX, KC_N,           KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,\
    KC_LALT,           KC_LT, KC_LPRN, KC_LGUI, MO(_LOWER), KC_SPC, XXXXXXX,     XXXXXXX, LSFT_T(KC_ENT), MO(_RAISE), KC_RGUI, KC_RPRN, KC_GT,   KC_GRV\
  ),

  [_LOWER] = LAYOUT(\
    _______,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_UNDS,     KC_PLUS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
    LCTL(KC_TAB), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,     KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
    _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______,\
    _______,      _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, _______, _______, _______, _______, _______, _______\
  ),

  [_RAISE] = LAYOUT(\
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_UNDS,     KC_PLUS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR,     KC_RCBR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_F12,\
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,     XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,\
    _______, _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, _______, _______, _______, _______, _______, _______\
  ),

  [_CTRL] = LAYOUT(\
    _______, AD_WO_L, ENT_SLP, BATT_LV, XXXXXXX, USB_EN,  BLE_EN,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4, USB_DIS, BLE_DIS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    ENT_DFU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
;
