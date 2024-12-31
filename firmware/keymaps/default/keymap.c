// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// @@@@@@@ used for physically present but unassigned keys.
// XXXXXXX for physically missing keys.
#define @@@@@@@ XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
      * 
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
     // @@@@@@@ used for physically present but unassigned keys.
     // XXXXXXX for physically missing keys.
     // Keys labelled YYY need special attention (key overrides etc).
    [0] = LAYOUT(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    @@@@@@@,
        KC_QUOT,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  KC_H,    KC_J,    KC_K,    KC_L,    YYY,     KC_SCLN,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,    YYY,     XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  YYY,     KC_B,    KC_N,    KC_M,    YYY,     KC_RCTL,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_TAB,  XXXXXXX, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  KC_DEL,  @@@@@@@, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGDN,  KC_LALT, KC_ENT,  KC_SPC,   YYY,            YYY,      KC_RSFT,  KC_BSPC, KC_RALT, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* LAYER 1 - Mod
      * ┌───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ # │ & │ | │   │                   │   │ 7 │ 8 │ 9 │ $ │   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │` ~│< >│[ ]│( )│{ }│ = │                   │   │ 4 │ 5 │ 6 │, .│   │
      * ├───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ ^ │/ \│ * │ - │ + │                   │   │ 1 │ 2 │ 3 │ 0 │Ctl│
      * └───┴───┴───┼───┼───┼───┼───┬───┐   ┌───┬───┼───┼───┼───┼───┴───┴───┘
      *             │Hom│   │   │   │ Fn│   │Mod│   │   │   │   │            
      *             ├───┼───┤   │   ├───┘   └───│   │   ├───┼───┤            
      *             │End│Alt│   │Sft│           │Sft│   │Alt│Mta│            
      *             └───┴───┴───┴───┘           └───┴───┴───┴───┘            
      *                                                                      
      */
    [1] = LAYOUT(
        @@@@@@@,  @@@@@@@,  KC_HASH,  KC_AMPR,  KC_PIPE, @@@@@@@, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@,   YYY,     YYY,     YYY,     KC_DLR,  @@@@@@@,
        KC_GRV,   YYY,      YYY,      YYY,      YYY,     YYY,     XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@,   YYY,     YYY,     YYY,     YYY,     @@@@@@@,
        KC_LCTL,  KC_CIRC,  YYY,      KC_ASTR,  YYY,     KC_PLUS, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@,   YYY,     YYY,     YYY,     KC_PERC, KC_RCTL,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  @@@@@@@, XXXXXXX, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@,   @@@@@@@, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_END,   KC_LALT, @@@@@@@, KC_LSFT,  YYY,            YYY,      KC_RSFT,  @@@@@@@,   KC_RALT, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
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
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        @@@@@@@,  @@@@@@@,  @@@@@@@,  @@@@@@@,  @@@@@@@, @@@@@@@, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@, KC_LEFT, KC_UP,   KC_RGHT, @@@@@@@, @@@@@@@,
        KC_LCTL,  @@@@@@@,  @@@@@@@,  @@@@@@@,  @@@@@@@, @@@@@@@, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@, @@@@@@@, KC_DOWN, @@@@@@@, @@@@@@@, KC_RCTL,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  @@@@@@@,  @@@@@@@, XXXXXXX, XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  @@@@@@@, @@@@@@@, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        XXXXXXX,  XXXXXXX,  XXXXXXX,  @@@@@@@,  KC_LALT, @@@@@@@, KC_LSFT,  YYY,            YYY,      KC_RSFT,  @@@@@@@, KC_RALT, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
