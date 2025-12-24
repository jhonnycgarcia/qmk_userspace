# Bootloader selection
BOOTLOADER = caterina  # Bootloader para ATmega32U4 (Pro Micro), permite flashear via USB

MOUSEKEY_ENABLE = yes  # Habilita emulación de mouse (movimiento, clics, scroll)

EXTRAKEY_ENABLE = yes  # Habilita teclas extra (multimedia, navegación, sistema)

CONSOLE_ENABLE = no    # Deshabilita consola de depuración (ahorra espacio)

# Deshabilitamos RGBLIGHT para usar RGB_MATRIX
RGBLIGHT_ENABLE = no

# Habilitamos RGB_MATRIX para efectos per-key
RGB_MATRIX_ENABLE = yes

ENCODER_ENABLE = yes   # Habilita soporte para encoders (perillas rotativas)

LTO_ENABLE = yes       # Optimiza el código para reducir tamaño del firmware

OLED_ENABLE = yes      # Habilita pantalla OLED para mostrar info (capa, modo)

# DYNAMIC_TAPPING_TERM_ENABLE = yes  # Permite ajustar tapping term dinámicamente (comentado para ahorrar espacio)

# VIA_ENABLE = yes      # Habilita VIA configurator (comentado para ahorrar espacio)

COMBO_ENABLE = yes # Habiliar combos para crear combinaciones personalizadas
