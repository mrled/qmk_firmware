#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  BL_RED,
  BL_GREEN,
  BL_CYAN,
  BL_VIOLET,
  BL_BLUE,
  BL_YELLOW,
  BL_INDIGO,
  BL_ORANGE,
  BL_PINK,
};

/* List of my tap dances */
enum {
 DANCE_COLON = 0,
 DANCE_QUOTE,
 DANCE_UNDERSCORE,
 DANCE_PLUS,
 DANCE_CTRLX,
 DANCE_LGUICURLY,
 DANCE_RGUICURLY,
 DANCE_CTRLALT,
};

/* Used in the cur_dance function to hold state */
typedef struct {
  bool is_press_action;
  int state;
} dancestep;

/* List of all the types of taps/holds we know about as dance steps */
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
};

/* List all my layers by name */
enum {
    LAYER_BASE = 0,
    LAYER_ARROW,
    LAYER_FUNC,
    LAYER_COLOR,
    LAYER_TEST,
    LAYER_MOUSE,
};

/* Layer Layout
 * Take special care to only allow entering non-base layers from the base layer
 * Take care to allow certain keys via KC_TRANSPARENT on the function layer -
 * e.g. modifiers for alt-f4, tab might be helpful here, etc.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_LEAD,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TAB,                                         MO(LAYER_MOUSE),KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    KC_LBRACKET,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LGUI,                                        KC_RGUI,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RBRACKET,
    MO(LAYER_FUNC), KC_NO,          KC_NO,          MO(LAYER_ARROW),KC_LALT,                                                                                                        KC_LALT,        MO(LAYER_ARROW),KC_VOLD,        KC_VOLU,        KC_MUTE,
                                                                                                    KC_DELETE	,     KC_HOME,        KC_PGUP,        KC_APPLICATION,
                                                                                                                    KC_END,         KC_PGDOWN,
                                                                                    KC_LSHIFT,      KC_BSPACE,      KC_LCTRL,       KC_LCTRL,       KC_ENTER,       KC_SPACE
  ),
  [LAYER_ARROW] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 TO(LAYER_BASE), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_UP,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_UP,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,                                                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LAYER_FUNC] = LAYOUT_ergodox_pretty(
    KC_PWR,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 TO(LAYER_BASE), KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_INSERT,
    KC_NO,          KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,         KC_TRANSPARENT,                                 KC_NO,          KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_PAUSE,
    //TT(LAYER_TEST), LCTL(LALT(LSFT(KC_F1))), LCTL(LALT(LSFT(KC_F2))), LCTL(LALT(LSFT(KC_F3))), LCTL(LALT(LSFT(KC_F4))), KC_NO,                                      KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_NO,          KC_PSCREEN,
    TT(LAYER_TEST), KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,                                                                          KC_KP_6,      KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_PSCREEN,
    TT(LAYER_COLOR),KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, TG(LAYER_FUNC), KC_MPLY,        KC_MPRV,        KC_MNXT,                                                                                                        KC_BRIU,        KC_BRID,        KC_NO,          KC_NO,          KC_MEDIA_EJECT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LAYER_COLOR] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          TO(LAYER_BASE), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          BL_RED,         KC_NO,          KC_NO,                                          KC_NO,          BL_YELLOW,      KC_NO,          BL_INDIGO,      BL_ORANGE,      BL_PINK,        KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          BL_GREEN,                                                                       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          BL_CYAN,        BL_VIOLET,      BL_BLUE,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          RGB_HUD,        RGB_HUI,                                                                                                        RGB_VAI,        RGB_VAD,        KC_NO,          KC_NO,          KC_NO,
                                                                                                    RGB_MOD,        KC_NO,          RGB_TOG,        RGB_SLD,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),
  [LAYER_TEST] = LAYOUT_ergodox_pretty(
    TD(DANCE_PLUS), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TO(LAYER_BASE), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_UNDERSCORE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_COLON),TD(DANCE_QUOTE),
    KC_NO,          KC_TRANSPARENT, TD(DANCE_CTRLX),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_LGUICURLY),                       TD(DANCE_RGUICURLY), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_CTRLALT), TD(DANCE_CTRLALT), KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LAYER_MOUSE] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 TO(LAYER_BASE), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_NO,          KC_MS_BTN3,                                     KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,                                                                          KC_MS_LEFT,     KC_MS_UP,       KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          TG(LAYER_MOUSE),KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_RIGHT,                                                                                                 KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2
  ),
  /*
  // A gergoplex-like layout, for experimentation
  // See the default gergoplex layout here:
  // https://github.com/germ/qmk_firmware/blob/gboards-update/keyboards/gergoplex/keymaps/default/keymap.c
  [LAYER_THREEROW] = LAYOUT_ergodox_pretty(
    // Skip first column - 1.5u keys
    // Skip last column - 1.5u keys
    // Skip first row - numbers etc
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          TO(LAYER_BASE), KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TAB,                                         TT(LAYER_MOUSE),KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           TD(DANCE_COLON),KC_NO,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LGUI,                                        KC_RGUI,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    // Skip last row - ergodox arrow keys etc
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    // In thumb clusters, only use bottom row
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),
  */
  /*
  [LAYER_TRANSPARENT_TEMPLATE] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
   [LAYER_NO_TEMPLATE] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),
  */
};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

void rgblight_sethsv_wrap(uint8_t hue, uint8_t sat, uint8_t index) {
  #ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    rgblight_mode(1);
    rgblight_sethsv(hue, sat, index);
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case BL_RED:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(0,255,255);
      }
      return false;
    case BL_GREEN:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(86,255,128);
      }
      return false;
    case BL_CYAN:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(125,255,255);
      }
      return false;
    case BL_VIOLET:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(215,115,238);
      }
      return false;
    case BL_BLUE:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(172,255,255);
      }
      return false;
    case BL_YELLOW:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(43,255,255);
      }
      return false;
    case BL_INDIGO:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(196,255,130);
      }
      return false;
    case BL_ORANGE:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(27,255,255);
      }
      return false;
    case BL_PINK:
      if (record->event.pressed) {
        rgblight_sethsv_wrap(229,102,255);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    switch (layer) {
      case LAYER_BASE:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(194,255,255);
        }
        break;
      case LAYER_FUNC:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,255,255);
        }
        break;
      case LAYER_ARROW:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(HSV_BLUE);
        }
        break;
      case LAYER_MOUSE:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(79,255,255);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}


/* The colon dance
 * Tap the semicolon key for a semicolon (;), but double tap it for a colon (:)
 */
void dance_colon_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_SCLN);
  } else {
    register_code(KC_RSFT);
    register_code(KC_SCLN);
    unregister_code(KC_RSFT);
  }
}
void dance_colon_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_SCLN);
  } else {
    unregister_code(KC_SCLN);
    unregister_code(KC_RSFT);
  }
}

/* The quote dance
 * Tap the single quote key for a single quote ('), but double tap it for a double quote (")
 */
void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_QUOTE);
  } else {
    register_code(KC_RSFT);
    register_code(KC_QUOTE);
    unregister_code(KC_RSFT);
  }
}
void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_QUOTE);
  } else {
    unregister_code(KC_RSFT);
    unregister_code(KC_QUOTE);
  }
}

/* The underscore dance
 * Tap the dash key for a dash (-), but double tap it for an underscore (_)
 */
void dance_underscore_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_MINUS);
  } else {
    register_code(KC_RSFT);
    register_code(KC_MINUS);
    unregister_code(KC_RSFT);
  }
}
void dance_underscore_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_MINUS);
  } else {
    unregister_code(KC_RSFT);
    unregister_code(KC_MINUS);
  }
}

/* The plus dance
 * Tap the equals key for an equals sign (=), but double tap it for a plus (+)
 */
void dance_plus_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_EQUAL);
  } else {
    register_code(KC_RSFT);
    register_code(KC_EQUAL);
    unregister_code(KC_RSFT);
  }
}
void dance_plus_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_EQUAL);
  } else {
    unregister_code(KC_RSFT);
    unregister_code(KC_EQUAL);
  }
}


/* Enable multi function tap dance
 * See also <https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39>
 */
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int current_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

/* Similar to the previous one, but designed just for space cadet keys
 * This supports either a tap or a hold; double taps, tap-holds etc are not interpretted specially
 */
int spacecadet_dance(qk_tap_dance_state_t *state) {
  if (state->interrupted) return SINGLE_HOLD;
  else if (!state->pressed) return SINGLE_TAP;
  else return SINGLE_HOLD;
}


// dancestep objects for each of the tap dances that require them
static dancestep dance_lguicurly = { .is_press_action=true, .state=0 };
static dancestep dance_rguicurly = { .is_press_action=true, .state=0 };
static dancestep dance_ctrlx = { .is_press_action=true, .state=0 };
static dancestep dance_ctrlalt = { .is_press_action=true, .state=0 };

/* The ctrl-x dance
 * See also https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39
 * Allow one key to have 4 (or more) functions, in this case:
 *   Tap = Send x
 *   Hold = Send Control
 *   Double Tap = Send Escape
 *   Double Tap and Hold = Send Alt
 */
void dance_ctrlx_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_ctrlx.state = current_dance(state);
  switch (dance_ctrlx.state) {
  case SINGLE_TAP: register_code(KC_X); break;
  case SINGLE_HOLD: register_code(KC_LCTRL); break;
  case DOUBLE_TAP: register_code(KC_ESC); break;
  case DOUBLE_HOLD: register_code(KC_LALT); break;
  case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X); break;
  //Last case is for fast typing. Assuming your key is `f`:
  //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
  //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}
void dance_ctrlx_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_ctrlx.state) {
  case SINGLE_TAP: unregister_code(KC_X); break;
  case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
  case DOUBLE_TAP: unregister_code(KC_ESC); break;
  case DOUBLE_HOLD: unregister_code(KC_LALT); break;
  case DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
  }
  dance_ctrlx.state = 0;
}


/* The ctrl-alt dance
 * ctrl if tapped/held; alt if double-tapped/double-held
 */
void dance_ctrlalt_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_ctrlalt.state = current_dance(state);
  switch (dance_ctrlalt.state) {
  case SINGLE_TAP: register_code(KC_LCTRL); break;
  case SINGLE_HOLD: register_code(KC_LCTRL); break;
  case DOUBLE_TAP: register_code(KC_LALT); break;
  case DOUBLE_HOLD: register_code(KC_LALT); break;
  }
}
void dance_ctrlalt_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_ctrlalt.state) {
  case SINGLE_TAP: unregister_code(KC_LCTRL); break;
  case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
  case DOUBLE_TAP: unregister_code(KC_LALT); break;
  case DOUBLE_HOLD: unregister_code(KC_LALT); break;
  }
  dance_ctrlalt.state = 0;
}


/* The lguicurly dance
 * Tap the LGUI key for an open curly brace ({); hold it for LGUI
 */
void dance_lguicurly_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_lguicurly.state = current_dance(state);
  switch (dance_lguicurly.state) {
  case SINGLE_TAP: register_code16(S(KC_LBRACKET)); break;
  case SINGLE_HOLD: register_mods(MOD_BIT(KC_LGUI)); break;
  case DOUBLE_TAP: tap_code16(S(KC_LBRACKET)); register_code16(S(KC_LBRACKET)); break;
  }
}
void dance_lguicurly_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_lguicurly.state) {
  case SINGLE_TAP: unregister_code16(S(KC_LBRACKET)); break;
  case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LGUI)); break;
  case DOUBLE_TAP: unregister_code16(S(KC_LBRACKET)); break;
  }
}

/* The rguicurly dance
 * Tap the LGUI key for an open curly brace ({); hold it for LGUI
 */
void dance_rguicurly_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_rguicurly.state = current_dance(state);
  switch (dance_rguicurly.state) {
  case SINGLE_TAP: register_code(KC_RSFT); register_code(KC_RBRACKET); break;
  case SINGLE_HOLD: register_code(KC_RGUI); break;
  }
}
void dance_rguicurly_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_rguicurly.state) {
  case SINGLE_TAP: unregister_code(KC_RSFT); unregister_code(KC_RBRACKET); break;
  case SINGLE_HOLD: unregister_code(KC_RGUI); break;
  }
}


//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_COLON] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_colon_finished, dance_colon_reset),
    [DANCE_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quote_finished, dance_quote_reset),
    [DANCE_UNDERSCORE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_underscore_finished, dance_underscore_reset),
    [DANCE_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_plus_finished, dance_plus_reset),
    [DANCE_CTRLX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ctrlx_finished, dance_ctrlx_reset),
    [DANCE_LGUICURLY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lguicurly_finished, dance_lguicurly_reset),
    [DANCE_RGUICURLY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rguicurly_finished, dance_rguicurly_reset),
    [DANCE_CTRLALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ctrlalt_finished, dance_ctrlalt_reset),
};


void matrix_init_user (void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

/* Set keyboard LEDs like the caps/scroll/num lock LEDs
 */
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}

/* The LEADER key for macros
 * This key works like emacs C-x prefix - you hit this key, and it supports key sequences you type next
 */

bool leader_did_succeed;

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leader_did_succeed = false;
    leading = false;
    leader_end();

    // C X: Enable capslock
    SEQ_TWO_KEYS(KC_C, KC_X) {
      tap_code(KC_CAPSLOCK);
      leader_did_succeed = true;
    }

    // S X: Enable shift lock (symbols too)
    // Disabled by just pressing the same shift again
    // Hmm. Doesn't seem to actually work though.
    SEQ_TWO_KEYS(KC_S, KC_X) {
      tap_code16(KC_LOCK);
      //unregister_code16(KC_LOCK);
      tap_code16(KC_LSHIFT);
      leader_did_succeed = true;
    }

    // C A D: Ctrl-Alt-Delete
    SEQ_THREE_KEYS(KC_C, KC_A, KC_D) {
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_DEL);
      unregister_code(KC_DEL);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTRL);
      leader_did_succeed = true;
    }

    // C A E: Ctrl-Alt-End (used in remote desktop at times)
    SEQ_THREE_KEYS(KC_C, KC_A, KC_E) {
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_END);
      unregister_code(KC_END);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTRL);
      leader_did_succeed = true;
    }

    // C O E: Command-Option-Escape
    SEQ_THREE_KEYS(KC_C, KC_O, KC_E) {
      register_code(KC_LGUI);
      register_code(KC_LALT);
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      leader_did_succeed = true;
    }

  }
}

void leader_start(void) {
    ergodox_right_led_3_on();
}
void leader_end(void) {
    ergodox_right_led_3_off();
    _delay_ms(100);
    if (leader_did_succeed) {
        ergodox_right_led_3_on();
        _delay_ms(100);
        ergodox_right_led_3_off();
        _delay_ms(100);
        ergodox_right_led_3_on();
        _delay_ms(100);
        ergodox_right_led_3_off();
        _delay_ms(100);
        ergodox_right_led_3_off();
    } else {
        ergodox_right_led_2_on();
        _delay_ms(100);
        ergodox_right_led_2_off();
        _delay_ms(100);
         ergodox_right_led_2_off();
        _delay_ms(100);
        ergodox_right_led_2_on();
        _delay_ms(100);
        ergodox_right_led_2_off();
    }
}

