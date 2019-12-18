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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                                      KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_PGUP,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TAB,                                         TT(1),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_PGDOWN,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           LT(1,KC_SCOLON),KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LGUI,                                        KC_RGUI,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_GRAVE,       KC_QUOTE,       TT(2),          KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
                                                                                                    KC_LSPO,        KC_HYPR,        KC_MEH,         KC_RSPC,
                                                                                                                    KC_LALT,        KC_LALT,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_LCTRL,       KC_RCTRL,       KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_HOME,                                        KC_END,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_PGUP,        KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_MS_BTN3,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    KC_PGDOWN,      KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_MS_WH_LEFT,  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_F13,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F14,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT,                                                                                                 KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_PGUP,        KC_PGDOWN,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_HOME,        KC_END,         KC_MS_BTN1,     KC_MS_BTN2
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, HSV_43_255_255, KC_TRANSPARENT, HSV_196_255_130,HSV_27_255_255, HSV_229_102_255,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_86_255_128,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_125_255_255,HSV_215_115_238,HSV_172_255_255,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, RGB_HUD,        RGB_HUI,                                                                                                        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    RGB_MOD,        KC_TRANSPARENT, RGB_TOG,        RGB_SLD,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
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
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(194,255,255);
        }
        break;
      case 1:
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
