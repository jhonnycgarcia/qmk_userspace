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

 // #define USE_MATRIX_I2C  // Habilita comunicación I2C para la matriz (no usado en Sofle)

 /* Configuración de mano maestra para split keyboards */
 #define MASTER_LEFT  // La mano izquierda es la maestra (controla OLED, RGB, etc.)

 /// https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/  // Link a guía para reducir tamaño de firmware

 #define CUSTOM_FONT  // Usa fuente personalizada para OLED (reduce tamaño)

 #define CUSTOM_LAYER_READ // Lectura personalizada de capas; no remover, causa problemas

 /* Configuración de tapping (tiempo para distinguir tap vs hold en mod-taps) */
//  #define QUICK_TAP_TERM 0  // Deshabilita quick tap (tap rápido después de tap)
//  #define QUICK_TAP_TERM_PER_KEY  // Permite quick tap por tecla individual

//  #ifdef TAPPING_TERM  // Código comentado para ajustar tapping term global
//  #    undef TAPPING_TERM
//  #    define TAPPING_TERM 200
//  #endif
#define TAPPING_TERM 200  // Tapping term global: 200ms para tap vs hold
#define TAPPING_TERM_PER_KEY  // Permite tapping term personalizado por tecla

/* Configuraciones para mejorar la responsividad de Layer Taps (mod-taps) */
// #define FLOW_TAP_TERM 150  // Tiempo para flow tap: permite taps rápidos consecutivos
// #define PERMISSIVE_HOLD  // Permite hold si se suelta otra tecla primero
// #define IGNORE_MOD_TAP_INTERRUPT  // Ignora interrupción de mod-tap (comentado)

 #define ENCODER_DIRECTION_FLIP  // Invierte la dirección de los encoders (izq/derecha)

 #ifdef ENCODER_RESOLUTION  // Si está definido, lo undefine para redefinir
 #    undef ENCODER_RESOLUTION
 #endif
 #define ENCODER_RESOLUTION 4  // Resolución de encoders: 4 pulsos por paso

 #define RGBLIGHT_SLEEP  // Apaga RGB cuando el teclado está suspendido

 #define RGBLIGHT_LAYERS  // Habilita capas RGB (colores por capa activa)

 /* Configuración para LEDs WS2812 RGB */
 #define WS2812_DI_PIN D3  // Pin de datos para LEDs WS2812

 #ifdef RGB_MATRIX_ENABLE  // Si se habilita RGB matrix (per-key)
 #    define RGBLIGHT_LED_COUNT 35 // Número de LEDs (duplicado, error?)
 #    define RGBLIGHT_LED_COUNT 35 // Número de LEDs
 #    define RGB_MATRIX_LED_COUNT RGBLIGHT_LED_COUNT  // LEDs para matrix
 #endif

 #ifdef RGBLIGHT_ENABLE  // Configuración para RGBLIGHT (underglow)
 #    undef RGBLIGHT_LED_COUNT  // Undefine para redefinir

 // Efectos RGB habilitados (comentados = deshabilitados para ahorrar espacio)
 // #define RGBLIGHT_EFFECT_BREATHING  // Efecto respiración
 #    define RGBLIGHT_EFFECT_RAINBOW_MOOD  // Arcoíris lento
 // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL  // Arcoíris giratorio
 // #define RGBLIGHT_EFFECT_SNAKE  // Efecto serpiente
 // #define RGBLIGHT_EFFECT_KNIGHT  // Efecto caballero
 // #define RGBLIGHT_EFFECT_CHRISTMAS  // Efecto navideño
 // #define RGBLIGHT_EFFECT_STATIC_GRADIENT  // Gradiente estático
 // #define RGBLIGHT_EFFECT_RGB_TEST  // Test de colores
 // #define RGBLIGHT_EFFECT_ALTERNATING  // Alternancia
 // #define RGBLIGHT_EFFECT_TWINKLE  // Brillo intermitente

 #    define RGBLIGHT_LED_COUNT 72  // Total de LEDs RGB (36 por lado)
 #    undef RGBLED_SPLIT  // Undefine para redefinir
 #    define RGBLED_SPLIT {36, 36} // División: 36 LEDs izquierda, 36 derecha

 // #define RGBLIGHT_LED_COUNT 30  // Alternativa comentada
 #    undef RGBLIGHT_LIMIT_VAL  // Undefine para redefinir
 #    define RGBLIGHT_LIMIT_VAL 120  // Límite de brillo: 120/255
 #    define RGBLIGHT_HUE_STEP 10  // Paso de cambio de tono (0-255)
 #    define RGBLIGHT_SAT_STEP 17  // Paso de saturación
 #    define RGBLIGHT_VAL_STEP 17  // Paso de valor (brillo)
 #endif

 #ifdef RGB_MATRIX_ENABLE  // Configuración para RGB matrix (per-key lighting)
 #    define RGB_MATRIX_KEYPRESSES // Reacciona a pulsaciones de teclas
 // #   define RGB_MATRIX_KEYRELEASES // Reacciona a liberaciones (en lugar de pulsaciones)
 #    define RGB_MATRIX_SLEEP // Apaga efectos cuando suspendido
 #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // Efectos de framebuffer
 // #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // Limita LEDs procesados por tarea (mejora responsividad)
 // #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // Limita frecuencia de actualización a 60fps (mejora responsividad)
 #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // Límite de brillo máximo: 150/255 (más alto puede crashear)

 #    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT  // Modo por defecto: gradiente izquierda-derecha

 #    define RGB_MATRIX_HUE_STEP 8  // Paso de tono (0-255)
 #    define RGB_MATRIX_SAT_STEP 8  // Paso de saturación
 #    define RGB_MATRIX_VAL_STEP 8  // Paso de valor (brillo)
 #    define RGB_MATRIX_SPD_STEP 10  // Paso de velocidad

 /* Deshabilita animaciones no usadas para ahorrar espacio. Deshabilita hasta compilar exitosamente. */
 // #   undef ENABLE_RGB_MATRIX_ALPHAS_MODS  // Mods alfas
 // #   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN  // Gradiente arriba-abajo
 // #   undef ENABLE_RGB_MATRIX_BREATHING  // Respiración
 // #   undef ENABLE_RGB_MATRIX_CYCLE_ALL  // Ciclo todos
 // #   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT  // Ciclo izq-der
 // #   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN  // Ciclo arriba-abajo
 // #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN  // Ciclo fuera-dentro
 // #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL  // Ciclo dual fuera-dentro
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Arcoíris chevron móvil
 // #   undef ENABLE_RGB_MATRIX_DUAL_BEACON  // Beacon dual
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON  // Beacon arcoíris
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS  // Molinillos arcoíris
 // #   undef ENABLE_RGB_MATRIX_RAINDROPS  // Gotas de lluvia
 // #   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS  // Gotas jellybean
 // #   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP  // Mapa de calor de tipeo
 // #   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN  // Lluvia digital
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE  // Reactivo sólido
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE  // Reactivo sólido simple
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE  // Reactivo sólido ancho
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Reactivo sólido multi-ancho
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS  // Reactivo sólido cruz
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS  // Reactivo sólido multi-cruz
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS  // Reactivo sólido nexus
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS  // Reactivo sólido multi-nexus
 // #   undef ENABLE_RGB_MATRIX_SPLASH  // Splash
 // #   undef ENABLE_RGB_MATRIX_MULTISPLASH  // Multi-splash
 // #   undef ENABLE_RGB_MATRIX_SOLID_SPLASH  // Splash sólido
 // #   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH  // Multi-splash sólido
 #endif
