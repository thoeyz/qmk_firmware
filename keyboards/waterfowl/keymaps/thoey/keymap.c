#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _GAMING,
    _NAVIGATION,
    _FUNC,
    _MOUSE,
    _ONEHANDED,
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),ENCODER_CCW_CW(C(KC_PGUP), C(KC_PGDN)),		ENCODER_CCW_CW(S(KC_MS_WH_DOWN), S(KC_MS_WH_UP)),ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),ENCODER_CCW_CW(KC_F2, KC_I),			                ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_2, KC_1),ENCODER_CCW_CW(C(KC_Z), C(KC_Y)),			                ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_5, KC_6),ENCODER_CCW_CW(KC_7, KC_8),				                    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [4] = { ENCODER_CCW_CW(KC_5, KC_6),ENCODER_CCW_CW(KC_7, KC_8),				                    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [5] = { ENCODER_CCW_CW(KC_5, KC_6),ENCODER_CCW_CW(KC_7, KC_8),				                    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

const uint16_t PROGMEM pageup[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM pagedn[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM alt[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM alt1[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM alt2[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM layer5[] = {KC_Q, KC_W, COMBO_END};
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


combo_t key_combos[] = {
    COMBO(pageup, KC_PGUP),
    COMBO(pagedn, KC_PGDN), 
    COMBO(alt, OSM(MOD_LALT)),
    COMBO(alt1, A(KC_1)),
    COMBO(alt2, A(KC_2)),
    COMBO(layer5, OSL(5)),
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


[_QWERTY] = LAYOUT(
	KC_Q,		KC_W,	   KC_E,		           KC_R,		           KC_T,				        KC_Y,	KC_U,		        KC_I,	   	   KC_O,	KC_P,
	LT(3,KC_A),	KC_S,	   KC_D,	  	           LSFT_T(KC_F),	       KC_G,				        KC_H,	LSFT_T(KC_J),       KC_K,	   	   KC_L,	LT(3,KC_SCLN),
	LT(4,KC_Z),	KC_X,	   KC_C,		           KC_V,		           KC_B,				        KC_N,	KC_M,		        KC_COMM,  	   KC_DOT,	LT(4,KC_SLSH),
			    TG(1),	   LALT_T(KC_TAB),         LCTL_T(KC_BSPC),        MO(2),  	 KC_LGUI, KC_NUM,	MO(2),	KC_SPC,		        LT(1,KC_ENT),  TG(1)
),


[_GAMING] = LAYOUT(
	KC_ESC,       KC_LSFT,    KC_W,	    	 KC_C,     KC_R,			          KC_MINS,	    KC_7,	KC_8,	KC_9,	KC_MINS,
	KC_E,		  KC_A,	 	  KC_S,	    	 KC_D,     KC_G,			          KC_KP_PLUS,	KC_4,	KC_5,	KC_6,	KC_PAST, 
	KC_X,		  KC_3,       KC_F2,         KC_F,     KC_5,			          KC_0,	        KC_1,	KC_2,	KC_3,	KC_PSLS,
			      KC_TRNS, 	  KC_Z,	    	 KC_SPC,   KC_LALT,  CM_TOGG, KC_NUM, TG(1),        KC_Y,	KC_ENT,	KC_TRNS
),


[_NAVIGATION] = LAYOUT(
	A(KC_LSFT),	TG(1),		KC_4,		KC_5,		KC_6,				            KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
	KC_RBRC,	KC_LEFT,	KC_UP,		KC_RGHT,	LCTL_T(KC_HOME),	    	    KC_MS_BTN3,	KC_MS_BTN1,	KC_MS_UP,	KC_MS_BTN2,	KC_QUOT,
	KC_ENT,		KC_WBAK,	KC_DOWN,	KC_WFWD,	KC_END,				            KC_NO,		KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,KC_MS_BTN1,
			    KC_1,		KC_ENT,		KC_Y,		KC_LCTL,   CM_TOGG,   KC_NUM,	KC_EQL,		KC_LBRC,	KC_RBRC,	KC_4
),


[_FUNC] =  LAYOUT(
	KC_NO,	 KC_7,	 KC_8,	    KC_9,	    CW_TOGG,			  	                KC_LPRN,       KC_RPRN,    KC_F8,		KC_F9,		C(A(KC_DEL)),
	KC_NO,	 KC_4,	 KC_5,	    KC_6,	    TD(TD_PLUS_MULT),		  	            KC_PGUP,       KC_LEFT,    KC_UP,		KC_RIGHT,	KC_F12,
	QK_BOOT, KC_1,	 KC_2,	    KC_3,	    TD(TD_MIN_DIV),		  	                KC_PGDN,   	   KC_WFWD,    KC_DOWN,		KC_WBAK,   	QK_BOOT,
		     TG(4),  KC_0,      C(KC_PGUP), C(KC_PGDN),  	   KC_CAPS,  KC_NUM,    LSG(KC_RIGHT), KC_BSPC,    LT(2,KC_ENT),KC_4
),

[_MOUSE] =  LAYOUT(
	KC_NO,	 KC_NO,	 	 KC_F2,	      KC_NO,	   KC_F2,		      	           KC_NO,    KC_F7,	     KC_F8,		    KC_F9,		KC_F11,
	TG(1),	 KC_MS_BTN2, KC_MS_UP,    KC_MS_BTN1,  KC_MS_BTN1,		      	       KC_NO,    KC_MS_BTN1, KC_MS_UP,	    KC_MS_BTN2,	KC_F12,
	KC_NO,   KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, KC_MS_BTN2,		      	       KC_F10,   KC_MS_LEFT, KC_MS_DOWN,	KC_MS_RIGHT,KC_F13,
		     TG(4),  	 XXXXXXX,     XXXXXXX, 	   XXXXXXX,  	KC_CAPS,  KC_NUM,  KC_ESC,   KC_BSPC,	 LT(2,KC_ENT),	KC_4
),

[_ONEHANDED] =  LAYOUT(
	KC_P,	 KC_O,	KC_I,	  KC_U,	  KC_Y,		      	          KC_NO,    KC_F7,	KC_F8,		    KC_F9,	KC_F11,
	KC_NO,	 KC_L,	KC_K,     KC_J,   KC_H,		      	          KC_NO,    KC_F4,	KC_F5,		    KC_F6,	KC_F12,
	KC_NO,   KC_NO,	KC_NO,    KC_M,   KC_N,		      	          KC_F10,   KC_F1,	KC_F2,		    KC_F3,	KC_F13,
		     TG(4), KC_ENT,   KC_SPC, KC_SPC,  KC_CAPS,  KC_NUM,  KC_ESC,   KC_BSPC,LT(2,KC_ENT),	KC_4
),


};
