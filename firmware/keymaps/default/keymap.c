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

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * LAYER 0 - Base
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │                   │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │' "│ A │ S │ D │ F │ G │                   │ H │ J │ K │ L │, .│; :│
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │_ -│                   │( )│B  │ N │ M │? !│Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │PUp│Tab│   │   │ Fn│   │Mod│   │   │Del│   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │PDn│Alt│Etr│Spc│           │Sft│Bsp│Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
     // Keys labelled YYY need special attention (key overrides etc).
    [0] = LAYOUT(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        KC_QUOT,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,                                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_COMM, KC_SCLN,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_UNDS,                                               KC_LPRN, KC_B,    KC_N,    KC_M,    KC_QUES, KC_RCTL,
                                      KC_PGUP,  KC_TAB,                                                         KC_DEL,  XXXXXXX,                                    
                                      KC_PGDN,  KC_LALT, KC_ENT,  KC_SPC,   TT(2),          TT(1),    KC_RSFT,  KC_BSPC, KC_RALT, KC_RGUI                           
    ),
    /* LAYER 1 - Mod
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ # │ & │ | │   │                   │   │ 7 │ 8 │ 9 │ $ │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │` ~│< >│[ ]│( )│{ }│ = │                   │   │ 4 │ 5 │ 6 │ 0 │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ ^ │/ \│ * │ - │ + │                   │   │ 1 │ 2 │ 3 │ % │Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │Hom│   │   │   │ Fn│   │Mod│   │   │   │   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │End│Alt│   │Sft│           │Sft│   │Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
    [1] = LAYOUT(
        XXXXXXX,  XXXXXXX,  KC_HASH,  KC_AMPR,  KC_PIPE, XXXXXXX,                                               XXXXXXX,   KC_P7,   KC_P8,   KC_P9,   KC_DLR,  XXXXXXX,
        KC_GRV,   KC_LABK,  KC_LBRC,  KC_LPRN,  KC_LCBR, KC_EQL,                                                XXXXXXX,   KC_P4,   KC_P5,   KC_P6,   KC_P0,   XXXXXXX,
        KC_LCTL,  KC_CIRC,  KC_SLSH,  KC_ASTR,  KC_MINS, KC_PLUS,                                               XXXXXXX,   KC_P1,   KC_P2,   KC_P3,   KC_PERC, KC_RCTL,
                                      KC_HOME,  XXXXXXX,                                                        XXXXXXX,   XXXXXXX,                                    
                                      KC_END,   KC_LALT, XXXXXXX, KC_LSFT,  TT(2),          TT(1),    KC_RSFT,  XXXXXXX,   KC_RALT, KC_RGUI                           
    ),
    /* LAYER 2 - Fn
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │F5 │F6 │                   │F7 │F8 │F9 │F10│F11│F12│
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │                   │   │ ← │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│   │   │   │   │   │                   │   │   │ ↓ │   │   │Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │   │   │   │   │ Fn│   │Mod│   │   │   │   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │   │Alt│   │Sft│           │Sft│   │Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
    [2] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,                                                 KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                                               XXXXXXX, KC_LEFT, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                                               XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, XXXXXXX, KC_RCTL,
                                      XXXXXXX,  XXXXXXX,                                                        XXXXXXX, XXXXXXX,                                    
                                      XXXXXXX,  KC_LALT, XXXXXXX, KC_LSFT,  TT(2),          TT(1),    KC_RSFT,  XXXXXXX, KC_RALT, KC_RGUI                           
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
const key_override_t shift_equals_is_equals     = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);
const key_override_t shift_minus_is_minus       = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);
const key_override_t shift_slash_is_backslash   = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);

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
};
