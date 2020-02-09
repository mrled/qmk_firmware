#include QMK_KEYBOARD_H

enum {
    LAY_BASE,
    LAY_FUNC,
};

enum mrl_custom_keycodes {
    CKC_NICECAPS = SAFE_RANGE,
    CKC_MATRIX,
    CKC_TYPESELF,
};

// Custom keys
#define MACLOCK LGUI(LCTL(KC_Q))
#define FQUIT LGUI(LALT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAY_BASE] = LAYOUT(
        KC_F,        KC_S,
        KC_V,        KC_H,
        KC_C,        KC_X,
        KC_K,        LT(LAY_FUNC, KC_T)
    ),
    [LAY_FUNC] = LAYOUT(
        KC_VOLD,      KC_VOLU,
        MACLOCK,      FQUIT,
        CKC_NICECAPS, CKC_MATRIX,
        CKC_TYPESELF, KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_NICECAPS:
            if (record->event.pressed) SEND_STRING("Nice keycaps, wanna fvck?");
            return false;
        case CKC_MATRIX:
            if (record->event.pressed) {
                _delay_ms(500);
                register_code(KC_LGUI);
                tap_code(KC_SPACE);
                unregister_code(KC_LGUI);
                _delay_ms(500);
                SEND_STRING("terminal");
                tap_code(KC_ENTER);
                _delay_ms(1500);
                SEND_STRING("curl http://bruxy.regnet.cz/linux/matrix/matrix.sh | bash");
                tap_code(KC_ENTER);
            }
            return false;
        case CKC_TYPSELF:
            if (record->event.pressed) {
                SEND_STRING("$___keymap");
                tap_code(KC_ENTER);
                SEND_STRING("$___typeself");
                tap_code(KC_ENTER);
            }
            return false;
        default:
            return true; // Process all other keycodes normally
  }
}
