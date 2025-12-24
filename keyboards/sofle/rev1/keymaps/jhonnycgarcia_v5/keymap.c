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

enum sofle_layers { _QWERTY = 0, _LOWER, _RAISE, _ADJUST, _NUMPAD, _SWITCH };

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
    KC_RAISE,              // Definicion de tecla para la capa superior
    KC_ADJUST,             // Definicion de tecla para la capa de ajuste
    KC_ALT_TAB,            // Definicion de tecla para cambiar de ventana
    KC_ALT_SHIFT_TAB,      // Definicion de tecla para cambiar de ventana con shift
    KC_NTIL,               // Definicion de tecla para la letra ñ
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
#define LAYOUT_QWERTY_BASE                                                                                                                                                                                                                         \
    /*,------------------------------------------------.                    ,---------------------------------------------------.*/                                                                                                                \
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,                                  /*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,                               /*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
        KC_CAPS_MT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,                       /*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, MS_BTN1, KC_CTRL_F, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, /*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
        KC_LOPT, KC_LGUI, KC_SWITCH, KC_LOWER, KC_SPC, KC_ENT, BSPC_NUM, KC_RAISE, KC_RGUI, KC_ROPT
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
 * |  ⛛   |⛛+⌘   | ⛛+⌥  | ⛛+⌃  | ⛛+⇧  |   ⛛  |-------.  ,-------|   ⛛  |  ⛛+⇧ |  ⛛+⌃ | |⛛+⌥ |  ⛛+⌘ |  ⛛  |
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
 * https://precondition.github.io/home-row-mods
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
#define _HOME_ROW_MOD_GACS(                                                            /*,------------------------------------------------.                    ,---------------------------------------------------.*/                                                                                                                \
                           L00, L01, L02, L03, L04, L05, R06, R07, R08, R09, R10, R11, /*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/                                                                                                               \
                           L12, L13, L14, L15, L16, L17, R18, R19, R20, R21, R22, R23, /*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/                                                                                                               \
                           L24, L25, L26, L27, L28, L29, R30, R31, R32, R33, R34, R35, /*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/                                                                                                               \
                           L36, L37, L38, L39, L40, L41, R42, R43, R44, R45, R46, R47, /*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/                                                                                                               \
                           ...)                                                                                                                                                                                                                                                                                                       \
    /*            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------*/                                                                                                                                                                                                                   \
    /*,------------------------------------------------.                    ,---------------------------------------------------.*/                                                                                                                                                                                                   \
    L00, L01, L02, L03, L04, L05, R06, R07, R08, R09, R10, R11,                                                                                                                                      /*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ \
        L12, L13, L14, L15, L16, L17, R18, R19, R20, R21, R22, R23, /*|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|*/ /* Home row mods GACS aplicados solo a las posiciones home */                                                                    \
        L24, LGUI_T(L25), LALT_T(L26), LCTL_T(L27), LSFT_T(L28), L29, R30, RSFT_T(R31), RCTL_T(R32), LALT_T(R33), RGUI_T(R34), R35,                                                                  /*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
        L36, L37, L38, L39, L40, L41, R42, R43, R44, R45, R46, R47,                                                                                                                                  /*|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|*/ \
        __VA_ARGS__
/*            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------*/ \
#define HOME_ROW_MOD_GACS(...)                                                                                  \
    _HOME_ROW_MOD_GACS(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM switchmod_combo[] = {KC_LGUI, KC_RGUI, COMBO_END};
combo_t                key_combos[]      = {
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
    [_QWERTY] = LAYOUT_wrapper(HOME_ROW_MOD_GACS(LAYOUT_QWERTY_BASE)),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | trans|      |      |      |      |      |                    |Mouse1|Mouse2|      |      |      |Delete|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |                    |⌥ + ← |      |      | ⌥ + →|Delete| Ps Cr|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |      |Mouse1|Mouse2|S-lock|-------.    ,-------| Left | Down |  Up  | Right| Bspc |Insert|
     * |------+------+------+------+------+------|CMD(T)|    |CMD(N)  |------+------+------+------+------+------|
     * | trans| Undo | Cut  | Copy |Paste | Redo |-------|    |-------| Home |PageD |PageU | End  |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LAlt | CMD  | SWITCH|LOWER| / Space /       \Enter \ |NUMPAD|RAISE | CMD  | RAlt |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'           '------''---------------------------´
     */
    [_LOWER] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MS_BTN1, MS_BTN2, KC_NO, KC_NO, KC_NO, KC_DEL,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, LOPT(KC_LEFT), KC_NO, KC_NO, LOPT(KC_RGHT), KC_DEL, KC_PSCR,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_NO, KC_NO, MS_BTN1, MS_BTN2, KC_LSCR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_INS,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_REDO, KC_CTRL_T, KC_CTRL_N, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS, S(KC_BSLS), S(KC_QUOT), KC_NO, KC_NO, KC_NO, S(KC_6), S(KC_9), S(KC_0), KC_MINS, A(KC_E), KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_NO, S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_7), S(KC_LBRC), S(KC_RBRC), KC_EQL, KC_NTIL, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_NO, KC_NO, KC_NO, S(KC_SLSH), KC_NO, KC_CTRL_G, KC_CTRL_S, S(KC_8), KC_LBRC, KC_RBRC, S(KC_1), KC_BSLS, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
        KC_NO, KC_NO, KC_NO, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        QK_BOOT, KC_NO, KC_NO, KC_BRID, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        UG_NEXT, UG_HUED, UG_SATD, UG_VALD, UG_SPDD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
    /* NUMPAD
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    | Prev | Play | Next | Mute | Vol- | Vol+  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                    |   .  |   7  |   8  |   9  |      |   -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
     * |      |      |      |      |      |      |-------.    ,-------|   ,  |   4  |   5  |   6  |  +   |   *   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+-------|
     * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |      |   /   |
     * `-----------------------------------------/       /    \      \-----------------------------------------'
     *            | LAlt | CMD  |SWITCH| LOWER| / Space /       \Enter \ |NUMPAD|RAISE | CMD  | RAlt |
     *            |      |      |      |      |/       /         \      \|      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMPAD] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PDOT, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PCMM, KC_P4, KC_P5, KC_P6, KC_NO, KC_PAST,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_P1, KC_P2, KC_P3, KC_NO, KC_PSLS,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_NO, TO(0), KC_NO, TO(1), TO(2), KC_NO, KC_NO, KC_NO, KC_LCTRL_UP, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        KC_NO, TO(4), TO(5), KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTRL_LEFT, KC_LCTRL_DOWN, KC_LCTRL_RGHT, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CTRL_0, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
};

/* ============================================
 * RGB MATRIX CONFIGURATION
 * ============================================
 *
 * Sofle RGB LED Layout (36 LEDs por lado, 72 total)
 *
 * DESCUBRIMIENTO CLAVE:
 * --------------------
 * El testing mostró que las POSICIONES FÍSICAS de los LEDs no coinciden
 * con lo que asumíamos. Por ejemplo, presionar "4" enciende el LED en
 * posición de ESC, lo que significa que el LED asignado a "4" tiene
 * posición física de ESC.
 *
 * Solución: Reconstruir las posiciones físicas basándonos en el testing.
 *
 * Del TEST 1:
 * - matrix[ESC] enciende C → LED en matrix[ESC] tiene pos física de C
 * - matrix[4] enciende ESC → LED en matrix[4] tiene pos física de ESC
 * - matrix[W] enciende W → LED en matrix[W] tiene pos física de W (CORRECTO)
 *
 * Dado que matrix usa índices 7-35 para teclas (0=indicador, 1-6=underglow),
 * y el layout del keymap define matrix[fila][col]:
 * - matrix[0][0]=ESC, [0][1]=1, [0][2]=2, [0][3]=3, [0][4]=4, [0][5]=5
 * - matrix[1][0]=TAB, [1][1]=Q, [1][2]=W, etc.
 *
 * La matriz g_led_config[0] asigna qué LED índice tiene cada tecla.
 * La matriz g_led_config[1] asigna qué posición física tiene cada LED.
 *
 * Si matrix[0][0] (ESC) = 25, y eso enciende C, entonces LED 25 está en pos C.
 * Si matrix[0][4] (4) = 11, y eso enciende ESC, entonces LED 11 está en pos ESC.
 */

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {{
                                 // Key Matrix to LED Index
                                 // RECONSTRUIDO basándose en TEST 3
                                 //
                                 // Método: Si tecla X enciende posición Y, y tecla Z enciende posición X,
                                 // entonces X debe usar el LED de Z.
                                 //
                                 // TEST 3 lado izquierdo:
                                 // ESC→C, 1→D, 2→S, 3→X, 4→ESC, 5→TAB
                                 // TAB→LOWER, Q→E, W→W✓, E→SWITCH, R→1, T→CAPS
                                 // CAPS→ENTER, A→3, S→2, D→LGUI, F→Q, G→LCTL
                                 // LCTRL→V, Z→F, X→R, C→Z, V→A, B→LOPT
                                 // LOPT→T, LGUI→5, SWITCH→B, LOWER→4, SPACE→G

                                 // LADO IZQUIERDO (filas 0-4, columnas 0-5)
                                 // Para ESC: 4→ESC, entonces ESC usa LED de 4 (era 11)
                                 // Para 1: R→1, entonces 1 usa LED de R (era 12)
                                 // Para 2: S→2, entonces 2 usa LED de S (era 21)
                                 // Para 3: A→3, entonces 3 usa LED de A (era 22)
                                 // Para 4: LOWER→4, entonces 4 usa LED de LOWER (era 31)
                                 // Para 5: LGUI→5, entonces 5 usa LED de LGUI (era 32)
                                 // Para TAB: 5→TAB, entonces TAB usa LED de 5 (era 10)
                                 // Para Q: F→Q, entonces Q usa LED de F (era 13)
                                 // Para W: W→W, entonces W usa LED de W (era 20) ✓
                                 // Para E: (nadie→E directamente), Q→E, entonces E usa LED de Q (era 23)
                                 // Para R: X→R, entonces R usa LED de X (era 30)
                                 // Para T: LOPT→T, entonces T usa LED de LOPT (era 33)
                                 // Para CAPS: T→CAPS, entonces CAPS usa LED de T (era 9)
                                 // Para A: V→A, entonces A usa LED de V (era 14)
                                 // Para S: 2→S, entonces S usa LED de 2 (era 19)
                                 // Para D: (nadie→D), 1→D, entonces D usa LED de 1 (era 24)
                                 // Para F: Z→F, entonces F usa LED de Z (era 29)
                                 // Para G: SPACE→G, entonces G usa LED de SPACE (era 34)
                                 // Para LCTL: G→LCTL, entonces LCTL usa LED de G (era 8)
                                 // Para Z: C→Z, entonces Z usa LED de C (era 15)
                                 // Para X: 3→X, entonces X usa LED de 3 (era 18)
                                 // Para C: ESC→C, entonces C usa LED de ESC (era 25)
                                 // Para V: LCTL→V, entonces V usa LED de LCTL (era 28)
                                 // Para B: SWITCH→B, entonces B usa LED de SWITCH (era 35)
                                 // Para LOPT: B→LOPT, entonces LOPT usa LED de B (era 7)
                                 // Para LGUI: D→LGUI, entonces LGUI usa LED de D (era 16)
                                 // Para SWITCH: E→SWITCH, entonces SWITCH usa LED de E (era 17)
                                 // Para LOWER: TAB→LOWER, entonces LOWER usa LED de TAB (era 26)
                                 // Para SPACE: CAPS→ENTER(SPACE), entonces SPACE usa LED de CAPS (era 27)

                                 {11, 12, 21, 22, 31, 32},    // Fila 0: ESC,1,2,3,4,5
                                 {10, 13, 20, 23, 30, 33},    // Fila 1: TAB,Q,W,E,R,T
                                 {9, 14, 19, 24, 29, 34},     // Fila 2: CAPS,A,S,D,F,G
                                 {8, 15, 18, 25, 28, 35},     // Fila 3: LCTL,Z,X,C,V,B
                                 {7, 16, 17, 26, 27, NO_LED}, // Fila 4: LOPT,LGUI,SWITCH,LOWER,SPACE,-

                                 // LADO DERECHO (filas 5-9, columnas 0-5)
                                 // TEST 3: 6→GRV, 7→BSPC, 8→DOT, 9→L, 0→K, BSPC→COMM
                                 // Y→QUOT, U→0, I→RAISE, O→O✓, P→I, GRV→NUM
                                 // H→MINS, J→P, K→RGUI, L→9, ;→8, '→ENT
                                 // N→RALT, M→SCLN, ,→SLSH, .→6, /→Y, -→M
                                 // ENTER→J, NUM→U, RAISE→7, RGUI→H, RALT→N

                                 // Para 6: .→6, entonces 6 usa LED de . (era 68)
                                 // Para 7: RAISE→7, entonces 7 usa LED de RAISE (era 66)
                                 // Para 8: ;→8, entonces 8 usa LED de ; (era 58)
                                 // Para 9: L→9, entonces 9 usa LED de L (era 57)
                                 // Para 0: U→0, entonces 0 usa LED de U (era 48)
                                 // Para BSPC: 7→BSPC, entonces BSPC usa LED de 7 (era 60)
                                 // Para Y: /→Y, entonces Y usa LED de / (era 69)
                                 // Para U: NUM→U, entonces U usa LED de NUM (era 67)
                                 // Para I: P→I, entonces I usa LED de P (era 59)
                                 // Para O: O→O, entonces O usa LED de O (era 53) ✓
                                 // Para P: J→P, entonces P usa LED de J (era 49)
                                 // Para GRV: 6→GRV, entonces GRV usa LED de 6 (era 46)
                                 // Para H: RGUI→H, entonces H usa LED de RGUI (era 70)
                                 // Para J: ENTER→J, entonces J usa LED de ENTER (era 65)
                                 // Para K: 0→K, entonces K usa LED de 0 (era 47)
                                 // Para L: 9→L, entonces L usa LED de 9 (era 54)
                                 // Para ;: 8→;(8), entonces ; usa LED de 8 (era 55)
                                 // Para ': ;→ENT('), entonces ' usa LED de ; (era 58) - wait, ya usé 58
                                 // Para N: RALT→N, entonces N usa LED de RALT (era 71)
                                 // Para M: -→M, entonces M usa LED de - (era 50)
                                 // Para ,: BSPC→COMM, entonces , usa LED de BSPC (era 60) - ya usé 60
                                 // Para .: 8→DOT, entonces . usa LED de 8 (era 55) - ya usé 55
                                 // Para /: ,→SLSH, entonces / usa LED de , (era 51)
                                 // Para -: M→SCLN→ hmm...
                                 // Para ENT: H→MINS(ENT?), J→P... ENTER→J
                                 // Para NUM: GRV→NUM, entonces NUM usa LED de GRV (era 62)
                                 // Para RAISE: I→RAISE, entonces RAISE usa LED de I (era 56)
                                 // Para RGUI: K→RGUI, entonces RGUI usa LED de K (era 52)
                                 // Para RALT: N→RALT, entonces RALT usa LED de N (era 64)

                                 {68, 66, 58, 57, 48, 60},     // Fila 5: 6,7,8,9,0,BSPC
                                 {69, 67, 59, 53, 49, 46},     // Fila 6: Y,U,I,O,P,GRV
                                 {70, 65, 47, 54, 55, 44},     // Fila 7: H,J,K,L,;,'
                                 {71, 50, 43, 45, 51, 63},     // Fila 8: N,M,,,.,/,-
                                 {61, 52, 62, 56, 64, NO_LED}, // Fila 9: ENT,RGUI,NUM,RAISE,RALT,-
                             },
                             {
                                 // LED Index to Physical Position
                                 // RECONSTRUIDO basándose en el testing
                                 //
                                 // Del testing sabemos:
                                 // LED 25 (asignado a ESC) enciende en posición C → LED 25 pos = (60,48) = C
                                 // LED 11 (asignado a 4) enciende en posición ESC → LED 11 pos = (0,0) = ESC
                                 // LED 20 (asignado a W) enciende en posición W → LED 20 pos = (40,16) = W ✓
                                 //
                                 // Reconstruyendo basándose en el patrón del testing:

                                 // === LEFT SIDE (LEDs 0-35) ===
                                 {91, 40}, // 0: Indicador (debajo OLED)
                                 {0, 64},
                                 {20, 64},
                                 {40, 64},
                                 {60, 64},
                                 {80, 64},
                                 {100, 64}, // 1-6: Underglow

                                 // LEDs 7-35: Posiciones basadas en testing
                                 // TEST: B→LOPT, entonces LED 7 tiene pos LOPT = (20,56)
                                 {20, 56}, // 7: pos LOPT (B enciende LOPT)
                                           // TEST: G→LCTRL, entonces LED 8 tiene pos LCTRL = (0,48)
                                 {0, 48}, // 8: pos LCTRL (G enciende LCTRL)
                                          // TEST: T→LSHIFT/CAPS, entonces LED 9 tiene pos CAPS = (0,32)
                                 {0, 32}, // 9: pos CAPS (T enciende CAPS)
                                          // TEST: 5→TAB, entonces LED 10 tiene pos TAB = (0,16)
                                 {0, 16}, // 10: pos TAB (5 enciende TAB)
                                          // TEST: 4→ESC, entonces LED 11 tiene pos ESC = (0,0)
                                 {0, 0}, // 11: pos ESC (4 enciende ESC)
                                         // TEST: R→1, entonces LED 12 tiene pos 1 = (20,0)
                                 {20, 0}, // 12: pos 1 (R enciende 1)
                                          // TEST: F→Q, entonces LED 13 tiene pos Q = (20,16)
                                 {20, 16}, // 13: pos Q (F enciende Q)
                                           // TEST: V→A, entonces LED 14 tiene pos A = (20,32)
                                 {20, 32}, // 14: pos A (V enciende A)
                                           // TEST: C→Z, entonces LED 15 tiene pos Z = (20,48)
                                 {20, 48}, // 15: pos Z (C enciende Z)
                                           // TEST: D→LGUI, entonces LED 16 tiene pos LGUI = (40,56)
                                 {40, 56}, // 16: pos LGUI (D enciende LGUI)
                                           // TEST: E→SWITCH, entonces LED 17 tiene pos SWITCH = (60,56)
                                 {60, 56}, // 17: pos SWITCH (E enciende SWITCH)
                                           // TEST: 3→X, entonces LED 18 tiene pos X = (40,48)
                                 {40, 48}, // 18: pos X (3 enciende X)
                                           // TEST: 2→S, entonces LED 19 tiene pos S = (40,32)
                                 {40, 32}, // 19: pos S (2 enciende S)
                                           // TEST: W→W, entonces LED 20 tiene pos W = (40,16) ✓
                                 {40, 16}, // 20: pos W (W enciende W) ✓ CONFIRMADO
                                           // TEST: S→2, entonces LED 21 tiene pos 2 = (40,0)
                                 {40, 0}, // 21: pos 2 (S enciende 2)
                                          // TEST: A→3, entonces LED 22 tiene pos 3 = (60,0)
                                 {60, 0}, // 22: pos 3 (A enciende 3)
                                          // TEST: Q→E, entonces LED 23 tiene pos E = (60,16)
                                 {60, 16}, // 23: pos E (Q enciende E)
                                           // TEST: 1→D, entonces LED 24 tiene pos D = (60,32)
                                 {60, 32}, // 24: pos D (1 enciende D)
                                           // TEST: ESC→C, entonces LED 25 tiene pos C = (60,48)
                                 {60, 48}, // 25: pos C (ESC enciende C)
                                           // TEST: TAB→LOWER, entonces LED 26 tiene pos LOWER = (80,56)
                                 {80, 56}, // 26: pos LOWER (TAB enciende LOWER)
                                           // TEST: CAPS→SPACE/ENT, entonces LED 27 tiene pos SPACE = (100,56)
                                 {100, 56}, // 27: pos SPACE (CAPS enciende SPACE)
                                            // TEST: LCTRL→V, entonces LED 28 tiene pos V = (80,48)
                                 {80, 48}, // 28: pos V (LCTRL enciende V)
                                           // TEST: Z→T (test2: Z→F), entonces LED 29 tiene pos...
                                 {80, 32}, // 29: pos F (Z enciende F en test2)
                                           // TEST: X→5 (test2: X→R), entonces LED 30 tiene pos...
                                 {80, 16}, // 30: pos R (X enciende R en test2)
                                           // TEST: LOWER→4, entonces LED 31 tiene pos 4 = (80,0)
                                 {80, 0}, // 31: pos 4 (LOWER enciende 4)
                                          // TEST: LGUI→ninguna, LED 32...
                                 {100, 0}, // 32: pos 5
                                           // TEST: LOPT→ninguna, LED 33...
                                 {100, 16}, // 33: pos T
                                            // TEST: SPACE→R (test2: SPACE→G), entonces LED 34 tiene pos G = (100,32)
                                 {100, 32}, // 34: pos G (SPACE enciende G en test2)
                                            // TEST: SWITCH→G (test2: SWITCH→B), entonces LED 35 tiene pos B = (100,48)
                                 {100, 48}, // 35: pos B (SWITCH enciende B en test2)

                                 // === RIGHT SIDE (LEDs 36-71) ===
                                 {133, 40}, // 36: Indicador (debajo OLED)
                                 {124, 64},
                                 {144, 64},
                                 {164, 64},
                                 {184, 64},
                                 {204, 64},
                                 {224, 64}, // 37-42: Underglow

                                 // LEDs 43-71: Aplicando mismo patrón inverso para lado derecho
                                 // TEST: -→M, N→ROPT, M→SCLN...
                                 {204, 56}, // 43: pos basada en testing (N→ROPT)
                                 {224, 48}, // 44: pos - (H→MINS)
                                 {224, 32}, // 45: pos ' (Y→QUOT)
                                 {224, 16}, // 46: pos ` (6→GRV)
                                 {224, 0},  // 47: pos BSPC (7→BSPC)
                                 {144, 16}, // 48: pos U (I→RAISE? no, ver testing)
                                 {204, 16}, // 49: pos P (J→P)
                                 {144, 48}, // 50: pos M (-→M)
                                 {164, 48}, // 51: pos , (BSPC→COMM)
                                 {184, 32}, // 52: pos L (9→L)
                                 {164, 16}, // 53: pos I (P→I)
                                 {164, 0},  // 54: pos 8 (;→8)
                                 {184, 0},  // 55: pos 9 (L→9)
                                 {184, 16}, // 56: pos O (O→O) ✓
                                 {164, 32}, // 57: pos K (0→K)
                                 {204, 32}, // 58: pos ; (M→SCLN)
                                 {124, 16}, // 59: pos Y (/→Y)
                                 {124, 0},  // 60: pos 6 (.→6)
                                 {124, 48}, // 61: pos N (6?... revisar)
                                 {144, 0},  // 62: pos 7 (Y→QUOT? revisar)
                                 {124, 32}, // 63: pos H ('→ENT? revisar)
                                 {184, 48}, // 64: pos . (H→MINS? revisar)
                                 {144, 56}, // 65: pos RAISE thumb (ENT→U? no match)
                                 {164, 56}, // 66: pos NUM thumb
                                 {184, 56}, // 67: pos thumb
                                 {204, 48}, // 68: pos / (8→DOT)
                                 {124, 56}, // 69: pos ENT thumb (,→SLSH)
                                 {224, 56}, // 70: pos RALT (RGUI→ninguna)
                                 {144, 32}, // 71: pos J (ENTER→U)
                             },
                             {
                                 // LED Flags
                                 8,                // 0: Indicator
                                 2, 2, 2, 2, 2, 2, // 1-6: Underglow
                                 4, 4, 4, 4, 4, 4, // 7-12
                                 4, 4, 4, 4, 4, 4, // 13-18
                                 4, 4, 4, 4, 4, 4, // 19-24
                                 4, 4, 4, 4, 4, 4, // 25-30
                                 4, 4, 4, 4, 4,    // 31-35
                                 8,                // 36: Indicator
                                 2, 2, 2, 2, 2, 2, // 37-42: Underglow
                                 4, 4, 4, 4, 4, 4, // 43-48
                                 4, 4, 4, 4, 4, 4, // 49-54
                                 4, 4, 4, 4, 4, 4, // 55-60
                                 4, 4, 4, 4, 4, 4, // 61-66
                                 4, 4, 4, 4, 4,    // 67-71
                             }};

#endif // RGB_MATRIX_ENABLE

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

    if (keycode == LGUI_T(KC_A)) return 180;
    if (keycode == LSFT_T(KC_F)) return 180;
    if (keycode == LALT_T(KC_S) || keycode == LCTL_T(KC_D)) return 200;

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
