#ifndef KEYMAP_C
#define KEYMAP_C

#include "key_definitions.h"
#include "keyboard_config.h"
#include "keymap.h"
#include "plugins.h"

// A bit different from QMK, default returns you to the first layer, LOWER and raise increase/lower layer by order.
#define DEFAULT 0x100
#define LOWER 0x101
#define RAISE 0x102

// Keymaps are designed to be relatively interchangeable with QMK
enum custom_keycodes {
	QWERTY
};

//Set these for each layer and use when layers are needed in a hold-to use layer
enum layer_holds {
	QWERTY_H = LAYER_HOLD_BASE_VAL, NUM_H,FUNCS_H
};

// array to hold names of layouts for oled
char default_layout_names[LAYERS][MAX_LAYOUT_NAME_LENGTH] = { "QWERTY"
		};

/* select a keycode for your macro
 * important - first macro must be initialized as MACRO_BASE_VAL
 * */

#define MACROS_NUM 2
enum custom_macros {
	KC_CTRL_ALT_DELETE = MACRO_BASE_VAL, KC_ALT_F4,
};

/*define what the macros do
 * important- make sure you you put the macros in the same order as the their enumeration
 */
uint16_t macros[MACROS_NUM][MACRO_LEN] = {
		// CTRL+ALT+DEL
		{ KC_LCTRL, KC_LALT, KC_DEL },
		//ALT +F4
		{ KC_RALT, KC_LALT, KC_NO } };

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//NOTE: For this keymap due to wiring constraints the the two last rows on the left are wired unconventionally
// Each keymap is represented by an array, with an array that points to all the keymaps  by order
	 uint16_t _QWERTY[MATRIX_ROWS][KEYMAP_COLS]={
			  {KC_LCTL, KC_LGUI,    KC_LALT,    KC_F1,  KC_SPC, KC_SPC, KC_F6,  KC_SPC, KC_ENT, KC_NONE,    KC_RALT,    KC_RGUI,	KC_APP,		KC_RCTL,    KC_LEFT,    KC_DOWN,	KC_RGHT },
			  {KC_LSFT,	KC_LSFT,    KC_Z,		KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT,		KC_SLSH,	KC_RSFT,    KC_RSFT,    KC_MPRV,    KC_UP,		KC_MNXT },
			  {KC_CAPS, KC_A,		KC_S,		KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,		KC_SCLN,	KC_QUOT,	KC_BSLS,    KC_ENT,		KC_MSTP,    KC_MPLY,	KC_MSEL },
			  {KC_TAB,  KC_Q,		KC_W,		KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,		KC_P,		KC_LBRC,	KC_RBRC,    KC_BSLS,    KC_DEL,		KC_END,		KC_PGDN },
			  {KC_1,	KC_2,		KC_3,		KC_4,   KC_5,   KC_6,	KC_7,   KC_8,   KC_9,   KC_0,		KC_MINS,    KC_EQUAL,	KC_BSPC,    KC_BSPC,    KC_INS,		KC_HOME,	KC_PGUP },
			  {KC_ESC,	KC_GRV,		KC_F2,		KC_F3,	KC_F4,	KC_F5,	KC_F7,	KC_F8,	KC_F9,	KC_F10,		KC_F11,		KC_F12,		KC_VOLD,	KC_VOLU,	KC_PSCR,	KC_LSCR,	KC_BRK }
	};

 //Create an array that points to the various keymaps
uint16_t (*default_layouts[])[MATRIX_ROWS][KEYMAP_COLS] = { &_QWERTY
		};

uint8_t current_layout = 0;

#endif

