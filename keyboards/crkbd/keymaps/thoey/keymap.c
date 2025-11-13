/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

const uint16_t PROGMEM pageup[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM pagedn[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM alt[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM alt1[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM alt2[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM layer5L[] = {LT(3,KC_A), MO(2), COMBO_END};
const uint16_t PROGMEM layer5R[] = {LT(3,KC_SCLN), KC_SPC, COMBO_END};
const uint16_t PROGMEM rctl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM f2[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM ESC[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM gamei[] = {KC_LALT, KC_G, COMBO_END};
const uint16_t PROGMEM gamef2[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM gamectl[] = {KC_X, KC_LALT, COMBO_END};
const uint16_t PROGMEM gameb[] = {KC_LALT, KC_E, COMBO_END};
const uint16_t PROGMEM gameo[] = {KC_ESC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM gameq[] = {KC_X, KC_3, COMBO_END};
const uint16_t PROGMEM gametog1[] = {KC_ESC, KC_LSFT, KC_W, KC_C, COMBO_END};
const uint16_t PROGMEM tog1[] = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM thai[] = {KC_Q, MO(2), COMBO_END};



combo_t key_combos[] = {
    COMBO(pageup, KC_PGUP),
    COMBO(pagedn, KC_PGDN), 
    COMBO(alt, OSM(MOD_LALT)),
    COMBO(alt1, A(KC_1)),
    COMBO(alt2, A(KC_2)),
    COMBO(layer5L, OSL(5)),
    COMBO(layer5R, OSL(5)),
    COMBO(rctl, OSM(MOD_RCTL)),
    COMBO(f2, KC_F2),
    COMBO(ESC, KC_ESC),
    COMBO(gamei, KC_I),
    COMBO(gamef2, KC_F2),
    COMBO(gamectl, KC_LCTL),
    COMBO(gameb, KC_B),
    COMBO(gameo, KC_O),
    COMBO(gameq, KC_Q),
    COMBO(gametog1, TG(1)),
    COMBO(tog1, TG(1)),
    COMBO(thai, A(KC_LSFT)),
};


// Tap Dance declarations
enum {
    TD_PLUS_MULT,
    TD_MIN_DIV,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    
    [TD_PLUS_MULT] = ACTION_TAP_DANCE_DOUBLE(KC_KP_PLUS, KC_PAST),
    [TD_MIN_DIV] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_PSLS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(

      XXXXXXX,    KC_Q,        KC_W,    KC_E,    KC_R,         KC_T,                                  KC_Y,    KC_U,   	      KC_I,    KC_O,   KC_P,    	XXXXXXX,
      XXXXXXX,    LT(3,KC_A),  KC_S,    KC_D,    LSFT_T(KC_F), KC_G,                                  KC_H,    LSFT_T(KC_J),  KC_K,    KC_L,   LT(3,KC_SCLN),   XXXXXXX,
      XXXXXXX,    LT(4,KC_Z),  KC_X,    KC_C,    KC_V,         KC_B,                         	      KC_N,    KC_M, 	      KC_COMM, KC_DOT, LT(4,KC_SLSH), 	XXXXXXX,
                                                 KC_BSPC,      LCTL_T(KC_TAB),  MO(2),       KC_SPC,  MO(1), KC_ENT                                   
  ),

    [1] = LAYOUT_split_3x6_3(

       XXXXXXX, KC_ESC,  KC_LSFT, KC_W,    KC_C,    KC_R,                           KC_MINS,    KC_7,    KC_8,    KC_9, KC_0,       XXXXXXX,
       XXXXXXX, KC_E,    KC_A,    KC_S,    KC_D,    KC_G,                           KC_KP_PLUS, KC_4,    KC_5,    KC_6, KC_PAST,    XXXXXXX,
       XXXXXXX, KC_X,    KC_3,    KC_F2,   KC_F,    KC_S,                           KC_0,       KC_1,    KC_2,    KC_3, KC_PSLS,    XXXXXXX,
                                            KC_Z,   KC_LALT,  KC_SPC,      TG(1),   MO(3),      KC_ENT
  ),

    [2] = LAYOUT_split_3x6_3(
 
      XXXXXXX, KC_EXLM,   KC_AT,    KC_4,    KC_5,    KC_6,                         KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, XXXXXXX,
      XXXXXXX, KC_RBRC,   KC_LEFT,  KC_UP,   KC_RGHT, KC_HOME,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
      XXXXXXX, KC_ENT,    KC_WBAK,  KC_DOWN, KC_WFWD, KC_END,                       KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,
                                             KC_LGUI, MO(3),  KC_SPC,       KC_ENT, _______, KC_RALT
  ),

    [3] = LAYOUT_split_3x6_3(
  
      XXXXXXX, QK_BOOT, KC_7,    KC_8,    KC_9,    CW_TOGG,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(A(KC_DEL)), XXXXXXX,
      XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    TD(TD_PLUS_MULT),                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,
      XXXXXXX, QK_BOOT, KC_1,    KC_2,    KC_3,    TD(TD_MIN_DIV),	                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(A(KC_DEL)), XXXXXXX,
                                          KC_LGUI, XXXXXXX,          KC_SPC,       KC_ENT, _______, KC_RALT
  ),

    [4] = LAYOUT_split_3x6_3(
 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, MS_BTN2, MS_UP,   MS_BTN1, MS_WHLU,                      MS_WHLU, MS_BTN1, MS_UP,   MS_BTN2, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                      MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,
                                          KC_LGUI, MS_BTN2,  MS_BTN1,   MS_BTN1, MS_BTN2, KC_RGUI
                           
  ),

    [5] = LAYOUT_split_3x6_3(
 
      XXXXXXX, KC_P,  KC_O,  KC_I, KC_U,    KC_Y,                        KC_T,    KC_R, KC_E, KC_W, KC_Q, XXXXXXX,
      XXXXXXX, KC_NO, KC_L,  KC_K, KC_J,    KC_H,                        KC_G,    KC_F, KC_D, KC_S, KC_A, XXXXXXX,
      XXXXXXX, KC_NO, KC_NO, KC_P, KC_M,    KC_N,                        KC_B,    KC_V, KC_C, KC_X, KC_Z, XXXXXXX,
                                   KC_LGUI, KC_BSPC, KC_SPC,     KC_SPC, KC_BSPC, KC_RGUI
                           
  )

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif


