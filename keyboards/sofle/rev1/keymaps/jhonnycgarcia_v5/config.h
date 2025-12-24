/* Copyright 2021 Dane Evans
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
#pragma once

// Aumenta el número máximo de capas para keymaps dinámicos (VIA/QMK Toolbox)
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* Configuración de mano maestra para split keyboards */
#define MASTER_LEFT

// Reduce tamaño de firmware
#define CUSTOM_FONT
#define CUSTOM_LAYER_READ

/* Configuración de tapping */
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

/* Encoders */
#define ENCODER_DIRECTION_FLIP
#ifdef ENCODER_RESOLUTION
#    undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4

/* ============================================
 * RGB MATRIX CONFIGURATION
 * ============================================ */
#ifdef RGB_MATRIX_ENABLE

// Pin de datos para LEDs WS2812
#    define WS2812_DI_PIN D3

// Número total de LEDs (36 por lado = 72 total)
// Nota: RGB_MATRIX_LED_COUNT y RGB_MATRIX_SPLIT se definen automáticamente
// en info_config.h cuando RGB_MATRIX_ENABLE está activo
#    ifndef RGB_MATRIX_LED_COUNT
#        define RGB_MATRIX_LED_COUNT 72
#    endif

// Sincronizar RGB entre mitades
#    define SPLIT_TRANSPORT_MIRROR

// Comportamiento general
#    define RGB_MATRIX_KEYPRESSES             // Reacciona a pulsaciones de teclas
#    define RGB_MATRIX_SLEEP                  // Apaga cuando suspendido
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // Límite de brillo (evita crasheos)

// Valores por defecto
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL 150

// Pasos de ajuste
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 16
#    define RGB_MATRIX_VAL_STEP 16
#    define RGB_MATRIX_SPD_STEP 16

/* ============================================
 * EFECTOS RGB_MATRIX
 * Habilitamos solo algunos para ahorrar espacio
 * ============================================ */

// Efectos básicos (bajo consumo de memoria)
#    define ENABLE_RGB_MATRIX_SOLID_COLOR // Color sólido
#    define ENABLE_RGB_MATRIX_BREATHING   // Respiración

// Efectos de arcoíris (medio consumo)
#    define ENABLE_RGB_MATRIX_CYCLE_ALL        // Ciclo de colores
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT // Ciclo izquierda-derecha

// Efectos reactivos (requieren RGB_MATRIX_KEYPRESSES)
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Destello simple al presionar

// Deshabilitamos el resto para ahorrar espacio
// Si querés más efectos, habilitá estos y deshabilitá otros:
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP      // Mapa de calor (consume mucho)
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN        // Lluvia Matrix (consume mucho)
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define ENABLE_RGB_MATRIX_SPLASH
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH

#endif // RGB_MATRIX_ENABLE
