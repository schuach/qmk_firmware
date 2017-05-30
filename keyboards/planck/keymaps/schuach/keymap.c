// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "keymap.h"
#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _XOY 0   // AdNWzjßf
#define _QW 1  // qwertz-layer (neo2 softcoded)
#define _N3 2  // neo2 Ebene 3 hardcoded
#define _N4 3  // neo2 Ebene 4 hardcoded
#define _KI 4  // KOY inverted
#define _SP 5  // space-toggled layer
#define _SYS 6 // system keys

// macros
#define N2_CARET M(1)
#define N2_BTCK M(2)

// KC-Defs für Neo 2 softcoded
#define N2_MOD3 KC_CAPS
#define N2_MOD4 KC_NUBS
#define N2_RMD4 KC_RALT // right Mod4 for locking the layer
#define KC_SZ   KC_LBRC

// Standard layer
#define N2_MINS KC_SLSH   // -
#define N2_GRAV S(KC_EQL) // è dead
#define N2_AKUT KC_EQL    // é dead
#define N2_SZ	KC_MINS   // ß
#define N2_Y	KC_Z      // y
#define N2_Z	KC_Y      // z
#define N2_UE   KC_LBRC   // ü
#define N2_OE	KC_SCLN   // ö
#define N2_AE	KC_QUOT   // ä

// Shift-layer
#define N2_RING S(KC_GRV)       // °
#define N2_PARG KC_HASH         // §
#define N2_FLDQ RALT(KC_Z)      // »
#define N2_FRDQ RALT(KC_X)      // »
#define N2_EURO RALT(KC_E)      // €
#define N2_GLDQ RALT(KC_V)      // „
#define N2_GRDQ RALT(KC_B)      // “
#define N2_ERDQ RALT(KC_N)      // ”
#define N2_CEDI RALT(KC_EQL)    // ¸
#define N2_CSZ  RALT(S(KC_S))   // ẞ großes ß
#define N2_DASH RALT(KC_SLSH)   // – Halbgeviertstrich
#define N2_TILD RALT(KC_RBRC)   // ~ non-dead
#define N2_MDOT RALT(KC_COMM)   // · Malpunkt

// Mod3
#define N2_SPS1 RALT(KC_1)
#define N2_SPS2 RALT(KC_2)
#define N2_SPS3 RALT(KC_3)
#define N2_FLSQ RALT(S(KC_Z))
#define N2_FRSQ RALT(S(KC_X))
#define N2_CENT RALT(KC_C)
#define N2_YEN  RALT(S(KC_Y))
#define N2_GLSQ RALT(S(KC_V))
#define N2_GRSQ RALT(S(KC_B))
#define N2_ERSQ RALT(S(KC_N))
#define N2_UL   S(KC_SLSH)
/*
#define
#define
#define
#define
#define
*/
#define N2_COLN S(KC_DOT)
#define N2_AT   RALT(KC_Q)
#define N2_BSLS RALT(KC_MINS)
#define N2_SLSH KC_AMPR
#define N2_MINS KC_SLSH
#define N2_HASH KC_BSLS

// Klammern 1
#define N2_LPRN KC_ASTR
#define N2_RPRN KC_LPRN
#define N2_LCBR RALT(KC_7)
#define N2_RCBR RALT(KC_0)
#define N2_LBRC RALT(KC_8)
#define N2_RBRC RALT(KC_9)
#define N2_GT   KC_NUBS    // <
#define N2_LT   S(KC_NUBS) // >

// Symbole
#define N2_EQL  S(KC_0)
#define N2_AMP  S(KC_6)
#define N2_AST  S(KC_RBRC)
#define N2_QM   S(KC_MINS)
#define N2_PIPE RALT(KC_NUBS)
#define N2_DQ   S(KC_2)
#define N2_SQ   S(KC_BSLS)
#define N2_SCLN S(KC_COMM)
#define N2_CLN  S(KC_DOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_XOY] = { /* XOY */
  {LT(_SYS,KC_TAB), KC_X,    KC_DOT,    KC_O,    KC_COMM,  N2_Y,          KC_V,           KC_G,           KC_C,    KC_L,    KC_J,  N2_SZ         },
  {CTL_T(KC_ESC),   KC_H,    KC_A,      KC_E,    KC_I,     KC_U,          KC_D,           KC_T,           KC_R,    KC_N,    KC_S,  KC_F          },
  {KC_LEAD,         KC_K,    KC_Q,      N2_AE,   N2_UE,    N2_OE,         KC_B,           KC_P,           KC_W,    KC_M,    N2_Z,  SFT_T(KC_ENT) },
  {KC_HOME,         KC_END,  KC_LGUI,   KC_LALT, TT(_N4),  SFT_T(KC_DEL), LT(_N3,KC_BSPC),LT(_SP,KC_SPC), LT(_KI,KC_LEFT), KC_DOWN, KC_UP, KC_RGHT       }
},
[_QW] = { /* Qwertz/Software-Neo2 */
  {LT(_SYS,KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,           KC_I,    KC_O,    KC_P,    KC_SZ        },
  {CTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,           KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,           KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT)},
  {KC_HOME,         KC_END,  KC_LGUI, KC_LALT, N2_MOD4, N2_MOD3, KC_BSPC, LT(_SP,KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,}
},
[_N3] = { /* Neo Ebene 3 hardcoded */
  {KC_TRNS, KC_NO,   N2_UL,   N2_LBRC, N2_RBRC, N2_CARET,KC_EXLM, N2_GT,   N2_LT,   N2_EQL,  N2_AMP,  KC_TRNS},
  {KC_TRNS, N2_BSLS, N2_SLSH, N2_LCBR, N2_RCBR, N2_AST,  N2_QM,   N2_LPRN, N2_RPRN, N2_MINS, N2_COLN, N2_AT},
  {KC_TRNS, N2_HASH, KC_DLR,  N2_PIPE, N2_TILD, N2_BTCK, N2_EURO, KC_PERC, N2_DQ,   N2_SQ,   N2_SCLN, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_N4] = { /* WIP Neo Ebene 4 hardcoded */
  {KC_TRNS, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, N2_MINS},
  {KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_COMM, KC_DOT},
  {KC_TRNS, KC_ESC,  KC_TAB,  KC_INS,  KC_PENT, KC_UNDO, N2_CLN,  KC_P1,   KC_P2,   KC_P3,   N2_SCLN, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_SPC,  KC_VOLD, KC_VOLU, KC_MUTE},
},
[_KI] = { /* KOY inverted plus Sonderzeichen */
  {KC_TRNS,  N2_GRAV,   KC_NO,   KC_NO,   N2_PARG,   KC_NO,    N2_Y,    KC_COMM, KC_O,    KC_DOT,  KC_K,    KC_TAB       },
  {KC_TRNS,  N2_AKUT,   KC_NO,   KC_NO,   N2_EURO,   KC_NO,    KC_U,    KC_I,    KC_E,    KC_A,    KC_H,    CTL_T(KC_ESC)},
  {KC_TRNS,  KC_NO,     KC_NO,   KC_NO,   KC_NO,     KC_NO,    N2_OE,   N2_UE,   N2_AE,   KC_Q,    KC_X,    SFT_T(KC_ENT)},
  {KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_END,  KC_HOME}
},
[_SP] = { /* spacebar-layer */
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_BSPC, KC_PGDN, KC_PGUP, KC_DEL,  KC_NO},
  {KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END},
  {KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_D, KC_WH_U, KC_BTN2},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R}
},

[_SYS] = { /* system keys */
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET},
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO},  
  {M(0),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DF(_QW), DF(_XOY),KC_NO,   KC_NO,   KC_NO},
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   LALT(LCTL(KC_DEL)) }
},
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(_N4)

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
          backlight_step();
        } else {
          unregister_code(KC_RSFT);
        }
      break;
      case 1:
        // if-statement notwendig, weil sonst auch bei key-up das Makro aufgerufen wird.
        if (record->event.pressed) {
          return MACRO( T(GRV), T(SPC), END);
        }
        break;
      case 2:
        if (record->event.pressed) {
          return MACRO(D(LSFT), T(EQL), U(LSFT), T(SPC), END);
        }
        break;
    } 
    return MACRO_NONE;

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_P) {
      // paste
      register_code(KC_LCTL);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(N2_Y) {
      // copy
      register_code(KC_LCTL);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LCTL);
    }

    SEQ_TWO_KEYS(KC_D, KC_D) {
      // cut whole line
      register_code(KC_HOME);
      unregister_code(KC_HOME);
      register_code(KC_LSFT);
      register_code(KC_END);
      unregister_code(KC_END);
      unregister_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LCTL);
    }
    SEQ_TWO_KEYS(KC_Y, KC_Y) {
      // copy whole line
      register_code(KC_HOME);
      unregister_code(KC_HOME);
      register_code(KC_LSFT);
      register_code(KC_END);
      unregister_code(KC_END);
      unregister_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LCTL);
    }

    SEQ_THREE_KEYS(KC_A, KC_S, KC_D) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
