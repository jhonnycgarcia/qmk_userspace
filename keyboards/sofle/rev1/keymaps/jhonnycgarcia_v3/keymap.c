/** Copyright 2021 Dane Evans
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

// Define the keycodes for the Spanish Latin America layout
// #include "keymap_spanish_latin_america.h"

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s, Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv, Override)

// Light combinations
#define SET_LAYER_ID(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36 + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}

enum sofle_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

/**
 * Define un tipo enumerado para identificar las diferentes capas del teclado.
 * El uso de un enum permite:
 * - Asignar nombres significativos a cada capa en lugar de usar números mágicos
 * - Garantizar que los valores sean únicos y secuenciales
 * - Facilitar el mantenimiento del código al centralizar la definición de capas
 * - Mejorar la legibilidad al usar nombres descriptivos en el resto del código
 * - Permitir al compilador detectar errores de digitación en nombres de capas
 */
enum custom_keycodes {
    KC_LOWER = SAFE_RANGE, // Definicion de tecla para la capa inferior
    KC_RAISE, // Definicion de tecla para la capa superior
    KC_ADJUST, // Definicion de tecla para la capa de ajuste
    KC_ALT_TAB, // Definicion de tecla para cambiar de ventana
    KC_ALT_SHIFT_TAB, // Definicion de tecla para cambiar de ventana con shift
    KC_NTIL, // Definicion de tecla para la letra ñ
};


// Definición de la macro para el Mod-Tap de Caps Lock
// Funciona como Shift cuando se mantiene presionado
// Funciona como Caps Lock cuando se presiona y suelta rápidamente
// Útil para tener ambas funcionalidades en una sola tecla
#define KC_CAPS_MT MT(MOD_LSFT, KC_CAPS)

/**
 * Definiciones para las teclas de modificación
 * - KC_CTRL_F: Control + F
 * - KC_CTRL_T: Control + T
 * - KC_CTRL_N: Control + N
 * - KC_LCTRL_UP: Left Control + Up
 * - KC_LCTRL_DOWN: Left Control + Down
 * - KC_LCTRL_RGHT: Left Control + Right
 * - KC_LCTRL_LEFT: Left Control + Left
 * - KC_LCTRL_G: Left Control + G
 * - KC_LCTRL_S: Left Control + S
 * - KC_CTRL_0: Control + 0
 * - KC_EMOJ: Control + Command + Space
 * - BSPC_NUM: fast Backspace / hold Numb Mod
 * - KC_REDO(Redo): Control + Shift + Z
 * - KC_UNDO(Undo): Control + Z
 * - KC_PASTE(Paste): Control + V
 * - KC_COPY(Copy): Control + C
 * - KC_CUT(Cut): Control + X
 */
#define KC_CTRL_F G(KC_F)
#define KC_CTRL_T G(KC_T)
#define KC_CTRL_N G(KC_N)
#define KC_LCTRL_UP LCTL(KC_UP)
#define KC_LCTRL_DOWN LCTL(KC_DOWN)
#define KC_LCTRL_RGHT LCTL(KC_RGHT)
#define KC_LCTRL_LEFT LCTL(KC_LEFT)
#define KC_CTRL_G G(KC_G)
#define KC_CTRL_S G(KC_S)
#define KC_CTRL_0 G(KC_0)
#define KC_EMOJ LCTL(LGUI(KC_SPC))
#define BSPC_NUM LT(KC_NUMPAD, KC_BSPC)
#define KC_REDO LGUI(S(KC_Z))
#define KC_UNDO LGUI(KC_Z)
#define KC_PASTE LGUI(KC_V)
#define KC_COPY LGUI(KC_C)
#define KC_CUT LGUI(KC_X)


/**
 * Definiciones para las capas
 * - KC_SWITCH: Cambia a la capa SWITCH mientras se mantiene presionada
 * - KC_ADJUST: Cambia a la capa ADJUST mientras se mantiene presionada
 * - KC_NUMPAD: Cambia a la capa NUMPAD mientras se mantiene presionada
 */
#define KC_SWITCH MO(_SWITCH)
#define KC_ADJUST MO(_ADJUST)
#define KC_NUMPAD MO(_NUMPAD)

/**
 * \brief QWERTY layout base para Sofle (6 rows, 12 columns).
 *
 * Layout base sin mod-taps que contiene la distribución QWERTY estándar.
 * Este layout se puede transformar usando macros para convertir la fila home
 * en mod-taps GACS (Gui, Alt, Ctrl, Shift) sin modificar directamente
 * cada tecla individual.
 *
 * Estructura del layout:
 * ,-------------------------------------------.                  ,-----------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |--------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |                  |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |--------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |Cps-lsft|   A  |   S  |   D  |   F  |   G  |-------.  ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+--------|Click  |  |CMD(F)|------+------+------+------+------+------|
 * |   CTRL |   Z  |   X  |   C  |   V  |   B  |-------|  |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/        /    \      \`-----------------------------------------/'
 *            |LAlt | CMD  |SWITCH| LOWER| / Space  /       \Enter \ |NUMPAD| RAISE| CMD | RAlt |
 *            |     |      |      |      |/       /          \      \|      |      |      |      |
 *            `----------------------------------'             '------''---------------------------'
 *
 * Uso: LAYOUT_QWERTY_BASE se puede pasar como parámetro a macros
 * transformadoras como HOME_ROW_MOD_GACS().
 */
#define LAYOUT_QWERTY_BASE                                                                     \
/*,------------------------------------------------.                    ,---------------------------------------------------.*/ \
KC_ESC,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,   KC_BSPC, \
/*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
KC_TAB,     KC_Q,   KC_W,   KC_E,     KC_R,   KC_T,                       KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,   KC_GRV, \
/*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
KC_CAPS_MT, KC_A,   KC_S,    KC_D,   KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT, \
/*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
KC_LCTL,    KC_Z,    KC_X,   KC_C,    KC_V,    KC_B, MS_BTN1,   KC_CTRL_F, KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, KC_MINS, \
/*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
               KC_LOPT, KC_LGUI, KC_SWITCH, KC_LOWER, KC_SPC,   KC_ENT, BSPC_NUM, KC_RAISE, KC_RGUI, KC_ROPT
/*            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------*/

/**
 * \brief Macro transformadora para Home Row Mods GACS.
 *
 * Esta macro convierte automáticamente las teclas de la fila home en mod-taps
 * siguiendo la distribución GACS (Gui, Option, Control, Shift) optimizada para macOS.
 * Transforma el layout base sin modificar directamente cada tecla individual.
 *
 * DISTRIBUCIÓN GACS IMPLEMENTADA:
 * ,-------------------------------------------.                  ,-----------------------------------------.
 * |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |                  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  | ⛛   |
 * |--------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |                  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |  ⛛   |
 * |--------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |  ⛛   |⛛+⌘   |⛛+⌥  |⛛+⌃  |⛛+⇧    |   ⛛   |-------.  ,-------|   ⛛   |⛛+⇧   |⛛+⌃   |⛛+⌥   |⛛+⌘   |  ⛛    |
 * |------+------+------+------+------+--------|   ⛛   |  |   ⛛   |------+------+------+------+------+------|
 * |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |-------|  |-------|   ⛛  |   ⛛  |   ⛛  |   ⛛  |   ⛛  |  ⛛   |
 * `-----------------------------------------/        /    \      \`-----------------------------------------/'
 *            |⛛   |  ⛛   |  ⛛   |  ⛛   | /   ⛛    /       \  ⛛   \ |  ⛛   |  ⛛   |  ⛛   |  ⛛   |
 *            |     |      |      |      |/       /          \      \|      |      |      |      |
 *            `----------------------------------'             '------''---------------------------'
 *
 * LEYENDA DE TRANSFORMACIONES:
 * ┌─────────────────────────────────────────────────────────────────────────────┐
 * │  ⛛: Símbolo que indica que la tecla se transformará en mod-tap GACS       │
 * │  ⛛+⌘: Tecla que se convierte en Command (⌘) cuando se mantiene presionada │
 * │  ⛛+⌥: Tecla que se convierte en Option (⌥) cuando se mantiene presionada  │
 * │  ⛛+⌃: Tecla que se convierte en Control (⌃) cuando se mantiene presionada │
 * │  ⛛+⇧: Tecla que se convierte en Shift (⇧) cuando se mantiene presionada   │
 * └─────────────────────────────────────────────────────────────────────────────┘
 *
 * TRANSFORMACIÓN DE LA FILA HOME:
 * ┌─────────────────────────────────────────────────────────────────────────────────────────────────────┐
 * │  IZQUIERDA (Mano izquierda)                      │                    DERECHA (Mano derecha)        │
 * ├─────────────────────────────────────────────────────────────────────────────────────────────────────┤
 * │  ⛛ → LGUI_T(⛛)  │ Command (⌘) + Tecla original  │  ⛛ → RSFT_T(⛛)  │ Shift (⇧) + Tecla original     │
 * │  ⛛ → LALT_T(⛛)  │ Option (⌥) + Tecla original   │  ⛛ → RCTL_T(⛛)  │ Control (⌃) + Tecla original   │
 * │  ⛛ → LCTL_T(⛛)  │ Control (⌃) + Tecla original  │  ⛛ → RALT_T(⛛)  │ Option (⌥) + Tecla original    │
 * │  ⛛ → LSFT_T(⛛)  │ Shift (⇧) + Tecla original    │  ⛛ → RGUI_T(⛛)  │ Command (⌘) + Tecla original   │
 * └─────────────────────────────────────────────────────────────────────────────────────────────────────┘
 *
 * NOTA: Esta configuración está optimizada para macOS y utiliza los modificadores
 * estándar del sistema: Command (⌘), Option (⌥), Control (⌃) y Shift (⇧).
 *
 * NOTA: ⛛ representa cualquier tecla de la fila home que se transformará.
 * La macro detecta automáticamente qué teclas están en la posición home row
 * y las convierte en mod-taps GACS correspondientes.
 *
 * FUNCIONAMIENTO:
 * - TOCAR RÁPIDAMENTE: Activa la tecla normal de la fila home
 * - MANTENER PRESIONADO: Activa el modificador correspondiente (Gui, Alt, Ctrl, Shift)
 * - COMBINACIONES: Se pueden combinar con otras teclas para atajos
 *
 * EJEMPLOS DE USO:
 * - Tecla 1 + C = Copiar (Gui + C)
 * - Tecla 2 + Z = Deshacer (Alt + Z)
 * - Tecla 3 + C = Seleccionar todo (Ctrl + C)
 * - Tecla 4 + A = Seleccionar todo (Shift + A)
 *
 * IMPLEMENTACIÓN TÉCNICA:
 * La macro recibe un layout base y transforma automáticamente:
 * - Fila 1: Teclas normales (sin cambios)
 * - Fila 2: Teclas normales (sin cambios)
 * - Fila 3: Home row transformada en mod-taps GACS
 * - Fila 4: Teclas normales (sin cambios)
 * - Thumbs: Teclas normales (sin cambios)
 *
 * Uso: HOME_ROW_MOD_GACS(LAYOUT_BASE)
 * Requisitos: El layout debe tener al menos 60 keycodes (4 filas: 12+12+12+14 teclas + 10 thumbs)
 * Compatible con cualquier distribución de teclado que tenga una fila home
 */
#define _HOME_ROW_MOD_GACS(                                            \
/*,------------------------------------------------.                    ,---------------------------------------------------.*/ \
    L00,    L01,    L02,    L03,     L04,       L05,                        R06,    R07,     R08,   R09,     R10,      R11,        \
/*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
    L12,    L13,    L14,    L15,    L16,    L17,                         R18,    R19,    R20,    R21,    R22,    R23,        \
/*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
    L24,    L25,    L26,    L27,    L28,    L29,                         R30,      R31,      R32,     R33,    R34,    R35,        \
/*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
    L36,    L37,    L38,    L39,    L40,    L41,                         R42,      R43,    R44,    R45,      R46,      R47,   \
/*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
                                                                ...)                                                               \
        /*            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------*/ \
/*,------------------------------------------------.                    ,---------------------------------------------------.*/ \
    L00,    L01,   L02,      L03,     L04,    L05,                        R06,    R07,     R08,     R09,    R10,       R11,  \
/*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
    L12,    L13,    L14,     L15,    L16,     L17,                        R18,    R19,    R20,     R21,      R22,       R23,  \
/*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
                            /* Home row mods GACS aplicados solo a las posiciones home */ \
   L24, LGUI_T(L25), LALT_T(L26), LCTL_T(L27), LSFT_T(L28),  L29,          R30, RSFT_T(R31), RCTL_T(R32), LALT_T(R33), RGUI_T(R34), R35,  \
/*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
    L36,    L37,    L38,     L39,    L40,     L41,                         R42,    R43,    R44,     R45,     R46,      R47,  \
/*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
    __VA_ARGS__
        /*            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------*/ \
#define HOME_ROW_MOD_GACS(...) _HOME_ROW_MOD_GACS(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM switchmod_combo[] = {KC_LGUI, KC_RGUI, COMBO_END};
combo_t key_combos[] = {
    COMBO(switchmod_combo, MO(_SWITCH)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-------------------------------------------.                  ,-----------------------------------------.
     * |   ESC  |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |--------+------+------+------+------+------|                  |------+------+------+------+------+------|
     * |   TAB  |   Q  |   W  |   E  |   R  |   T  |                  |   Y  |   U  |   I  |   O  |   P  |  `   |
     * |--------+------+------+------+------+------|                  |------+------+------+------+------+------|
     * |Cps-lsft|   A  |   S  |   D  |   F  |   G  |-------.  ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+--------|Click  |  |CMD(F)|------+------+------+------+------+------|
     * |   CTRL |   Z  |   X  |   C  |   V  |   B  |-------|  |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
     * `-----------------------------------------/        /    \      \`-----------------------------------------/'
     *            |LAlt | CMD  |SWITCH| LOWER| / Space  /       \Enter \ |Nump/Bsp| RAISE| CMD | RAlt |
     *            |     |      |      |      |/       /          \      \|      |      |      |      |
     *            `----------------------------------'             '------''---------------------------'
     */
    [_QWERTY] = LAYOUT_wrapper(LAYOUT_QWERTY_BASE),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | trans|      |      |      |      |      |                    |      |      |      |      |      |Delete|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |                    |⌥ + ← |      |      | ⌥ + →|Delete| Ps Cr|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right| Bspc |Insert|
     * |------+------+------+------+------+------|CMD(T)|    |CMD(N)  |------+------+------+------+------+------|
     * | trans| Undo | Cut  | Copy |Paste | Redo |-------|    |-------| Home |PageD |PageU | End  |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LAlt | CMD  | SWITCH|LOWER| / Space /       \Enter \ |NUMPAD|RAISE | CMD  | RAlt |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'           '------''---------------------------´
     */
    [_LOWER] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_TRNS,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_DEL,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS,   KC_NO,   KC_NO,  KC_NO,    KC_NO, KC_NO,               LOPT(KC_LEFT),KC_NO,KC_NO,LOPT(KC_RGHT),KC_DEL,  KC_PSCR,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,                      KC_LEFT, KC_DOWN , KC_UP, KC_RGHT, KC_BSPC,   KC_INS,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS,  KC_UNDO,KC_CUT, KC_COPY, KC_PASTE,KC_REDO, KC_CTRL_T, KC_CTRL_N,KC_HOME,KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

    /* RAISE
     * ,----------------------------------------.                     ,-----------------------------------------.
     * | trans|      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|   |  |  "   |      |      |      |                    |   ^  |  (   |  )   |  -   |   ´  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |  @   |  #   |  $   |  %   |-------.    ,-------|   &  |   {  |   }  |  =   |  ñ   |      |
     * |------+------+------+------+------+------|CMD(G) |    |CMD(S) |------+------+------+------+------+------|
     * | trans|      |      |      |  ?   |      |-------.    ,-------|   *  |   [  |   ]  |  !   |  \   |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LAlt | CMD  |SWITCH| LOWER| / Space /       \Enter \ |NUMPAD|RAISE | RAlt | Menu |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'            '------''--------------------------'
     */
    [_RAISE] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS,  S(KC_BSLS),S(KC_QUOT),KC_NO, KC_NO, KC_NO,                   S(KC_6), S(KC_9), S(KC_0), KC_MINS,  A(KC_E),   KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS,   KC_NO,  S(KC_2),S(KC_3), S(KC_4),S(KC_5),                   S(KC_7),S(KC_LBRC),S(KC_RBRC),KC_EQL, KC_NTIL,   KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS,  KC_NO,  KC_NO,   KC_NO, S(KC_SLSH), KC_NO, KC_CTRL_G, KC_CTRL_S,S(KC_8),KC_LBRC,KC_RBRC,S(KC_1), KC_BSLS,   KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      | bri ^|      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Reset|      |      | bri v|      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |UG_TOGG|hue^ |sat ^ | bri ^| vel+ |      |-------.   ,--------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
     * |Nxt mod| hue v|sat v| bri v| vel- |      |--------|   |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LAlt | CMD  |SWITCH| LOWER| / Space /       \Enter \ |NUMPAD|RAISE | CMD  | RAlt |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_NO,    KC_NO,    KC_NO, KC_BRIU,  KC_NO,  KC_NO,                       KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        QK_BOOT,  KC_NO,   KC_NO,   KC_BRID, KC_NO,  KC_NO,                       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,  UG_SPDU,  KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        UG_NEXT, UG_HUED, UG_SATD, UG_VALD,  UG_SPDD,  KC_NO, KC_NO,       KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
    /* NUMPAD
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    | Prev | Play | Next |      |      |   +   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                    |   .  |   7  |   8  |   9  |      |   -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
     * |      |      |      |      |      |      |-------.    ,-------|   ,  |   4  |   5  |   6  |      |   *   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+-------|
     * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |      |   /   |
     * `-----------------------------------------/       /    \      \-----------------------------------------'
     *            | LAlt | CMD  |SWITCH| LOWER| / Space /       \Enter \ |NUMPAD|RAISE | CMD  | RAlt |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMPAD] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_F1,     KC_F2,  KC_F3,    KC_F4,   KC_F5,  KC_F6,                     KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_NO,   KC_NO,   KC_PPLS,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_F7,     KC_F8,  KC_F9,   KC_F10,  KC_F11, KC_F12,                     KC_PDOT,  KC_P7,    KC_P8,     KC_P9,   KC_NO,   KC_PMNS,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_NO,     KC_NO,  KC_NO,    KC_NO,   KC_NO,  KC_NO,                     KC_PCMM,  KC_P4,    KC_P5,     KC_P6,   KC_NO,   KC_PAST,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_NO,     KC_NO,  KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,     KC_NO,  KC_P0,    KC_P1,    KC_P2,     KC_P3,   KC_NO,   KC_PSLS,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

    /* SWITCH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |QWERTY|      |LOWER |RAISE |      |                    |      |      |Ctrl+↑|      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |ADJUST|NUMPAD|      |      |      |-------.     ,-------|      |Ctrl+←|Ctrl+↓|Ctrl+→|      |      |
     * |------+------+------+------+------+------|Ctrl+0 |    |  Mute |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LAlt | CMD  |SWITCH| LOWER| / Space /       \Enter \ |NUMPAD|RAISE | CMD  | RAlt |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    // Capa para cambiar entre distribuciones y controles de navegación
    [_SWITCH] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_NO,     KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,                      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_NO,    TO(0),   KC_NO,   TO(1),   TO(2),  KC_NO,                      KC_NO,  KC_NO, KC_LCTRL_UP ,   KC_NO,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_NO,    TO(4),   TO(5),   KC_NO,   KC_NO,  KC_NO,                      KC_NO,  KC_LCTRL_LEFT,   KC_LCTRL_DOWN,   KC_LCTRL_RGHT,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_CTRL_0,  KC_MUTE, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),
};


/**
 * Definición de capas y configuración de iluminación RGB
 *
 * Este fragmento de código configura las diferentes capas del teclado y su iluminación RGB asociada.
 *
 * Capas definidas:
 * - QWERTY: Capa base con distribución QWERTY (luz blanca)
 * - LOWER: Capa de números y funciones (luz verde)
 * - RAISE: Capa de símbolos (luz azul)
 * - ADJUST: Capa de comandos y ajustes (luz rosa)
 * - NUMPAD: Teclado numérico (luz púrpura)
 * - SWITCH: Capa para cambiar entre distribuciones (luz amarilla)
 *
 * La iluminación RGB se configura por segmentos usando RGBLIGHT_LAYER_SEGMENTS
 * y se activa/desactiva según la capa activa mediante layer_state_set_user().
 *
 * Las capas superiores tienen prioridad sobre las inferiores en caso de
 * superposición de la iluminación.
 */

#ifdef RGBLIGHT_ENABLE
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[]  = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_WHITE));



// _LOWER,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_GREEN));

// _RAISE,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_BLUE));

// _ADJUST,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_PINK));

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_PURPLE));

// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_YELLOW));

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_num_lights, // overrides layer 1
    layer_symbol_lights,
    layer_command_lights,
    layer_numpad_lights,
    layer_switcher_lights // Overrides other layers
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY) && layer_state_cmp(default_layer_state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));

    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way
}
#endif



/**
 * Configuración y funciones para la pantalla OLED
 *
 * Este fragmento maneja la funcionalidad de las pantallas OLED del teclado.
 * Incluye:
 * - Renderizado del logo QMK en la pantalla secundaria
 * - Visualización del estado actual en la pantalla principal:
 *   - Modo actual (Game/Tech)
 *   - Distribución activa (QWERTY)
 *   - Capa actual (Base/Raise/Lower/Adjust/Numpad/Switch)
 * - Rotación de la pantalla principal a 270°
 */
#ifdef OLED_ENABLE

/**
 * Renderiza el logo QMK en la pantalla secundaria
 * Utiliza caracteres personalizados almacenados en PROGMEM
 */
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

/**
 * Muestra el estado actual del teclado en formato compacto
 * Incluye modo, distribución y capa activa
 */
static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Game\nTech"), false);

    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;



        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

/**
 * Configura la rotación inicial de las pantallas OLED
 * La pantalla principal se rota 270° para mejor visibilidad
 */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

/**
 * Función principal para actualizar las pantallas OLED
 * Muestra estado en la principal y logo en la secundaria
 */
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case KC_ALT_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_TAB);
            } else {
                unregister_code(KC_LALT);
            }
            return false;
            break;
        case KC_ALT_SHIFT_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_TAB);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
        case KC_NTIL:
            if (record->event.pressed) {
                register_code(KC_LOPT);
                tap_code(KC_N);
                unregister_code(KC_LOPT);
                tap_code(KC_N);
            }
            return false;
    }
    return true;
}

// =============================================================================
// CONFIGURACIÓN DE TAPPING TERMS - Tiempos de respuesta personalizados
// =============================================================================
//
// Esta función configura tiempos de respuesta personalizados para cada modificador
// del home row. Los tiempos se ajustan según la frecuencia de uso y la necesidad
// de evitar activaciones accidentales.
//
// TAPPING TERMS EXPLICADOS:
// ┌─────────────────────────────────────────────────────────────────────────────┐
// │  MODIFICADOR  │  TECLAS  │  TIEMPO  │  JUSTIFICACIÓN                      │
// ├─────────────────────────────────────────────────────────────────────────────┤
// │     Gui       │   A, ;   │  250ms   │  Más lento para evitar activaciones │
// │               │          │          │  accidentales del menú              │
// ├─────────────────────────────────────────────────────────────────────────────┤
// │    Shift      │   F, J   │  120ms   │  Más rápido para respuesta inmediata│
// │               │          │          │  en selección de texto              │
// ├─────────────────────────────────────────────────────────────────────────────┤
// │     Alt       │   S, L   │  200ms   │  Tiempo medio para equilibrio      │
// │               │          │          │  entre velocidad y precisión        │
// ├─────────────────────────────────────────────────────────────────────────────┤
// │     Ctrl      │   D, K   │  200ms   │  Tiempo medio para equilibrio      │
// │               │          │          │  entre velocidad y precisión        │
// └─────────────────────────────────────────────────────────────────────────────┘
//
// CÓMO FUNCIONA:
// - TOCAR RÁPIDAMENTE (< tiempo): Activa la tecla normal
// - MANTENER PRESIONADO (> tiempo): Activa el modificador
// - El tiempo se mide desde que se presiona hasta que se suelta
//
// =============================================================================
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Tecla de pulgar NUMPAD/BSPC - tiempo más rápido para mejor respuesta
    if (keycode == BSPC_NUM) return 150;

    // // Gui (A) - tiempo más largo para evitar activaciones accidentales
    // if (keycode == LGUI_T(KC_A)) return 250;

    // // Shift (F y J) - tiempo más corto para respuesta rápida
    // if (keycode == LSFT_T(KC_F) || keycode == RSFT_T(KC_J)) return 120;

    // // Alt (S y L) - tiempo medio
    // if (keycode == LALT_T(KC_S) || keycode == RALT_T(KC_L)) return 200;

    // // Ctrl (D y K) - tiempo medio
    // if (keycode == LCTL_T(KC_D) || keycode == RCTL_T(KC_K)) return 200;

    // // Gui (;) - tiempo más largo para evitar activaciones accidentales
    // if (keycode == RGUI_T(KC_SCLN)) return 250;

    // Para todas las demás teclas, usar el tapping term por defecto
    return TAPPING_TERM;
}

// uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         default:
//             return QUICK_TAP_TERM;
//     }
// }

// bool is_flow_tap_key(uint16_t keycode) {
//     if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
//         return false; // Disable Flow Tap on hotkeys.
//     }

//     // Verificar si es nuestra tecla personalizada LT(KC_NUMPAD, KC_BSPC)
//     if (keycode == LT(KC_NUMPAD, KC_BSPC)) {
//         return true;
//     }

//     switch (keycode) {
//         case KC_SPC:
//         case KC_A ... KC_Z:
//         case KC_DOT:
//         case KC_COMM:
//         case KC_SCLN:
//         case KC_SLSH:
//         case KC_BSPC:  // Agregar KC_BSPC para que funcione con Flow Tap
//             return true;
//     }
//     return false;
// }

// uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
//     uint16_t prev_keycode) {
//     // Para nuestra tecla personalizada, usar un Flow Tap Term más agresivo
//     if (keycode == LT(KC_NUMPAD, KC_BSPC)) {
//         return 100; // Más rápido para Flow Tap en esta tecla específica
//     }

//     // Para otras teclas, usar la lógica estándar
//     if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
//         return FLOW_TAP_TERM;
//     }
//     return 0;
// }

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    // Encoder izquierdo
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_WH_L); // Acción de rueda de mouse hacia la izquierda
                } else {
                    tap_code(KC_WH_R); // Acción de rueda de mouse hacia la derecha
                }
                return false;
            case _RAISE:
                if (clockwise) {
                    tap_code16(LGUI(KC_Z)); // Acción de la tecla Ctrl + Z
                } else {
                    tap_code16(LGUI(S(KC_Z))); // Acción de la tecla CMD + Shift + Z
                }
                return false;
            case _LOWER:
                if (clockwise) {
                    tap_code16(LCTL(KC_PGDN)); // Acción de la tecla Ctrl + Page Down
                } else {
                    tap_code16(LCTL(KC_PGUP)); // Acción de la tecla Ctrl + Page Up
                }
                return false;
            case _NUMPAD:
                if (clockwise) { // Alt + Shift + Tab - Cambiar entre ventanas hacia adelante
                    register_code(KC_RALT);
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_RALT);
                    unregister_code(KC_LSFT);
                } else { // Alt + Tab - Cambiar entre ventanas hacia atrás
                    register_code(KC_RALT);
                    tap_code(KC_TAB);
                    unregister_code(KC_RALT);
                }
                return false;
            // case _ADJUST:
            //     if (clockwise) {
            //         tap_code16(UG_SATU);
            //     } else {
            //         tap_code16(UG_SATD);
            //     }
            //     return false;
            case _SWITCH:
                if (clockwise) {
                    tap_code16(G(KC_MINUS)); // Acción de la tecla CMD + - (Numpad -)
                } else {
                    tap_code16(G(KC_EQUAL)); // Acción de la tecla CMD + + (Numpad +)
                }
                return false;
            default:
                if (clockwise) {
                    tap_code(KC_WH_L); // Acción de rueda de mouse hacia la izquierda
                } else {
                    tap_code(KC_WH_R); // Acción de rueda de mouse hacia la derecha
                }
                return false;
        }
    // Encoder derecho
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_WH_D); // Acción de rueda de mouse hacia abajo
                } else {
                    tap_code(KC_WH_U); // Acción de rueda de mouse hacia arriba
                }
                return false;
            // case _RAISE:
            //     if (clockwise) {
            //         tap_code16();
            //     } else {
            //         tap_code16();
            //     }
            //     break;
            case _LOWER:
                if (clockwise) {
                    tap_code16(KC_PGUP); // Acción de la tecla Page Up
                } else {
                    tap_code16(KC_PGDN); // Acción de la tecla Page Down
                }
                return false;
            case _NUMPAD:
                if (clockwise) {
                    tap_code16(LALT(KC_LEFT)); // CMD + Option + <-
                } else {
                    tap_code16(LALT(KC_RGHT)); // CMD + Option + ->
                }
                return false;
            // case _ADJUST:
            //     if (clockwise) {
            //         tap_code16(UG_HUEU); // Acción para avanzar página en la capa NUMPAD
            //     } else {
            //         tap_code16(UG_HUED); // Acción para retroceder página en la capa NUMPAD
            //     }
            //     break;
            case _SWITCH:
                if (clockwise) {
                    tap_code16(KC_VOLD); // Acción para disminuir el volumen
                } else {
                    tap_code16(KC_VOLU); // Acción para aumentar el volumen
                }
                return false;
            default:
                if (clockwise) {
                    tap_code(KC_WH_U); // Acción de rueda de mouse hacia arriba
                } else {
                    tap_code(KC_WH_D); // Acción de rueda de mouse hacia abajo
                }
                return false;
        }
    }
    // Siempre evitamos el comportamiento por defecto
    return false;
}

#endif
