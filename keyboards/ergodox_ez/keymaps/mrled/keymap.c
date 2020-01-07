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
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_125_255_255,
  HSV_215_115_238,
  HSV_172_255_255,
  HSV_43_255_255,
  HSV_196_255_130,
  HSV_27_255_255,
  HSV_229_102_255,
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
    LAYER_TESTING = 4,
    LAYER_MOUSE = 5,
    LAYER_THREEROW = 3,
    LAYER_MEDIACOLOR = 8,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_LEAD,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_PGUP,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TAB,                                         TT(LAYER_MOUSE),KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_PGDOWN,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    KC_LBRACKET,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LGUI,                                        KC_RGUI,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RBRACKET,
    KC_GRAVE,       KC_NO,          TT(LAYER_MEDIACOLOR),KC_LEFT,   KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    TT(LAYER_TESTING),
                                                                                                    KC_LSPO,        KC_HYPR,        KC_MEH,         KC_RSPC,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    KC_LSHIFT,      KC_BSPACE,      KC_LCTRL,       KC_LALT,        KC_ENTER,       KC_SPACE
  ),
  [LAYER_MOUSE] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_MS_BTN3,                                     KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_MS_LEFT,     KC_MS_UP,       KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_F13,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F14,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT,                                                                                                 KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_PGUP,        KC_PGDOWN,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_HOME,        KC_END,         KC_MS_BTN1,     KC_MS_BTN2
  ),
  [LAYER_MEDIACOLOR] = LAYOUT_ergodox_pretty(
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_43_255_255, KC_TRANSPARENT, HSV_196_255_130,HSV_27_255_255, HSV_229_102_255,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_86_255_128,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_125_255_255,HSV_215_115_238,HSV_172_255_255,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, RGB_HUD,        RGB_HUI,                                                                                                        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    RGB_MOD,        KC_TRANSPARENT, RGB_TOG,        RGB_SLD,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LAYER_TESTING] = LAYOUT_ergodox_pretty(
    TD(DANCE_PLUS), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_UNDERSCORE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_COLON),TD(DANCE_QUOTE),
    KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_CTRLX),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_LGUICURLY),                       TD(DANCE_RGUICURLY), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_CTRLALT), TD(DANCE_CTRLALT), KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /*
  // A gergoplex-like layout, for experimentation
  // See the default gergoplex layout here:
  // https://github.com/germ/qmk_firmware/blob/gboards-update/keyboards/gergoplex/keymaps/default/keymap.c
  [LAYER_THREEROW] = LAYOUT_ergodox_pretty(
    // Skip first column - 1.5u keys
    // Skip last column - 1.5u keys
    // Skip first row - numbers etc
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
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
    case HSV_0_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
        #endif
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(86,255,128);
        #endif
      }
      return false;
    case HSV_125_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(125,255,255);
        #endif
      }
      return false;
    case HSV_215_115_238:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(215,115,238);
        #endif
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(172,255,255);
        #endif
      }
      return false;
    case HSV_43_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(43,255,255);
        #endif
      }
      return false;
    case HSV_196_255_130:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(196,255,130);
        #endif
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(27,255,255);
        #endif
      }
      return false;
    case HSV_229_102_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(229,102,255);
        #endif
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case LAYER_MOUSE:
        ergodox_right_led_1_on();
        break;
      case LAYER_MEDIACOLOR:
        ergodox_right_led_2_on();
        break;
      case LAYER_TESTING:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case LAYER_BASE:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(194,255,255);
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



/* The LEADER key for macros
 * This key works like emacs C-x prefix - you hit this key, and it supports key sequences you type next
 */
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(KC_C, KC_X) {
      tap_code(KC_CAPSLOCK);
    }

    /* LEADER examples:

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTRL("a") SS_LCTRL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
    */

  }
}
