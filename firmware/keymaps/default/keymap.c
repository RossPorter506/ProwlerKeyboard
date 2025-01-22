// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* Logical switch numbers
* ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
* │ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │                   │ 6 │ 7 │ 8 │ 9 │10 │11 │
* ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
* │12 │13 │14 │15 │16 │17 │                   │18 │19 │20 │21 │22 │23 │
* ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
* │24 │25 │26 │27 │28 │29 │                   │30 │31 │32 │33 │34 │35 │
* └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
*             │36 │37 │   │   │44 │   │45 │   │   │38 │39 │            
*             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
*             │40 │41 │42 │43 │           │46 │47 │48 │49 │            
*             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
*
* Matrix positions
* 8x5 half => physical 16x5 kb => 8x10 in QMK
* ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
* │0,0│0,1│0,2│0,3│0,4│0,5│                   │5,5│5,4│5,3│5,2│5,1│5,0│
* ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
* │1,0│1,1│1,2│1,3│1,4│1,5│                   │6,5│6,4│6,3│6,2│6,1│6,0│
* ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
* │2,0│2,1│2,2│2,3│2,4│2,5│                   │7,5│7,4│7,3│7,2│7,1│7,0│
* └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
*             │3,3│3,4│   │   │4,7│   │9,7│   │   │8,4│8,3│            
*             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
*             │4,3│4,4│4,5│4,6│           │9,6│9,5│9,4│9,3│            
*             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
*/

enum kb_layers {
    _BASE = 0,
    _MOD = 1,
    _FN = 2,
};

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * LAYER 0 - Base
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │                   │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │' "│ A │ S │ D │ F │ G │                   │ H │ J │ K │ L │, .│; :│
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │_ -│                   │( )│ B │ N │ M │? !│Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │PUp│Tab│   │   │ Fn│   │Mod│   │   │Del│   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │PDn│Alt│Etr│Spc│           │Sft│Bsp│Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RM_ON,  
        KC_QUOT,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,                                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_COMM, KC_SCLN,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_UNDS,                                               KC_LPRN, KC_B,    KC_N,    KC_M,    KC_QUES, KC_RCTL,
                                      KC_PGUP,  KC_TAB,                                                         KC_DEL,  XXXXXXX,                                    
                                      KC_PGDN,  KC_LALT, KC_ENT,  KC_SPC,   TT(_FN),        TT(_MOD),  KC_RSFT, KC_BSPC, KC_RALT, KC_RGUI                            
    ),
    /* LAYER 1 - Mod
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ # │ & │ | │   │                   │   │ 7 │ 8 │ 9 │ $ │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │` ~│< >│[ ]│( )│{ }│ = │                   │ 0 │4 ←│5 ↑│6 →│, .│   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ ^ │/ \│ * │ - │ + │                   │   │ 1 │2 ↓│ 3 │ % │Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │Hom│   │   │   │ Fn│   │*Md│   │   │Del│   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │End│Alt│   │Sft│           │Sft│Bsp│Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
    [_MOD] = LAYOUT(
        XXXXXXX,  XXXXXXX,  KC_HASH,  KC_AMPR,  KC_PIPE, XXXXXXX,                                               XXXXXXX,   KC_P7,   KC_P8,   KC_P9,   KC_DLR,  XXXXXXX,
        KC_GRV,   KC_LABK,  KC_LBRC,  KC_LPRN,  KC_LCBR, KC_EQL,                                                KC_P0,     KC_P4,   KC_P5,   KC_P6,   KC_COMM, XXXXXXX,
        KC_LCTL,  KC_CIRC,  KC_SLSH,  KC_ASTR,  KC_MINS, KC_PLUS,                                               XXXXXXX,   KC_P1,   KC_P2,   KC_P3,   KC_PERC, KC_RCTL,
                                      KC_HOME,  XXXXXXX,                                                        KC_DEL,    XXXXXXX,                                    
                                      KC_END,   KC_LALT, XXXXXXX, KC_LSFT,  TT(_FN),        TT(_MOD), KC_RSFT,  KC_BSPC,   KC_RALT, KC_RGUI                            
    ),
    /* LAYER 2 - Fn
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │F5 │F6 │                   │F7 │F8 │F9 │F10│F11│F12│
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │LNx│                   │   │ ← │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│   │   │   │   │LTg│                   │   │   │ ↓ │   │   │Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │LUp│   │   │   │*Fn│   │Mod│   │   │Del│   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │LDn│Alt│   │Sft│           │Sft│Bsp│Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
    [_FN] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,                                                 KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, RM_NEXT,                                               XXXXXXX, KC_LEFT, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, RM_TOGG,                                               XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, XXXXXXX, KC_RCTL,
                                      RM_VALU,  XXXXXXX,                                                        KC_DEL,  XXXXXXX,                                    
                                      RM_VALD,  KC_LALT, XXXXXXX, KC_LSFT,  TT(_FN),        TT(_MOD), KC_RSFT,  KC_BSPC, KC_RALT, KC_RGUI                            
    ),
};

// Key overrides
const key_override_t shift_underscore_is_minus  = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINUS);
const key_override_t shift_lparen_is_rparen     = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t shift_comma_is_dot         = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_DOT);
const key_override_t shift_qmark_is_exmark      = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t shift_labrkt_is_rabrkt     = ko_make_basic(MOD_MASK_SHIFT, KC_LABK, KC_RABK);
const key_override_t shift_lsqbrkt_is_rsqbrkt   = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t shift_lcurbrkt_is_rcurbrkt = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t shift_equals_is_equals     = ko_make_basic(MOD_MASK_SHIFT, KC_EQL,  KC_EQL);
const key_override_t shift_minus_is_minus       = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);
const key_override_t shift_slash_is_backslash   = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);

const key_override_t shift_5_is_up              = ko_make_basic(MOD_MASK_SHIFT, KC_P5, KC_UP);
const key_override_t shift_0_is_0               = ko_make_basic(MOD_MASK_SHIFT, KC_P0, KC_P0);
const key_override_t shift_1_is_1               = ko_make_basic(MOD_MASK_SHIFT, KC_P1, KC_P1);
const key_override_t shift_3_is_3               = ko_make_basic(MOD_MASK_SHIFT, KC_P3, KC_P3);
const key_override_t shift_7_is_7               = ko_make_basic(MOD_MASK_SHIFT, KC_P7, KC_P7);
const key_override_t shift_8_is_8               = ko_make_basic(MOD_MASK_SHIFT, KC_P8, KC_P8);
const key_override_t shift_9_is_9               = ko_make_basic(MOD_MASK_SHIFT, KC_P9, KC_P9);


const key_override_t *key_overrides[] = {
	&shift_underscore_is_minus,
	&shift_lparen_is_rparen,
    &shift_comma_is_dot,
    &shift_qmark_is_exmark,
    &shift_labrkt_is_rabrkt,
    &shift_lsqbrkt_is_rsqbrkt,
    &shift_lcurbrkt_is_rcurbrkt,
    &shift_equals_is_equals,
    &shift_minus_is_minus,
    &shift_slash_is_backslash,
    &shift_5_is_up,
    &shift_0_is_0,
    &shift_1_is_1,
    &shift_3_is_3,
    &shift_7_is_7,
    &shift_8_is_8,
    &shift_9_is_9,
};

// TODO: Remove
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
