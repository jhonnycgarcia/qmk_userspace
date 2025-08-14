![SofleKeyboard default keymap](https://i.imgur.com/MZxVvm9.png)
![SofleKeyboard adjust layer](https://i.imgur.com/f5sKy0I.png)

# Keymap personalizado para Sofle Keyboard - JhonnyCGarcia v2

Layout en [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gifs/76efb423a46cbbea75465cb468eef7ff) y [adjust layer](http://www.keyboard-layout-editor.com/#/gifs/4bcf66f922cfd54da20ba04905d56bd4)

## Características del Keymap

- **Modificadores simétricos** (CMD/Super, Alt/Opt, Ctrl, Shift)
- **Múltiples modos** intercambiables (usando la capa Adjust, selección almacenada en EEPROM)
- **Soporte para Qwerty, Colemak y Dvorak**
- **Soporte para Mac vs Linux/Win** → diferente orden de modificadores y atajos en la capa "RAISE"
- **Pantalla OLED** en la mitad maestra muestra modo seleccionado y estado de caps lock (rotada)
- **Encoder izquierdo** controla volumen arriba/abajo/silenciar
- **Encoder derecho** controla PGUP/PGDOWN
- **9 capas personalizadas** con funcionalidades específicas por capa

## Capas del Keymap

| Capa | Nombre | Función | Color RGB |
|------|--------|---------|-----------|
| 0 | QWERTY | Distribución base QWERTY | Blanco |
| 1 | COLEMAK | Distribución alternativa Colemak | Púrpura |
| 2 | DVORAK | Distribución alternativa Dvorak | Turquesa |
| 3 | LOWER | Números y funciones | Verde |
| 4 | RAISE | Símbolos y caracteres especiales | Azul |
| 5 | ADJUST | Comandos y ajustes | Rosa |
| 6 | NUMPAD | Teclado numérico | Púrpura |
| 7 | SWITCH | Cambio entre distribuciones | Amarillo |

## Limitaciones del Teclado

### EEPROM y Capas Dinámicas
- **EEPROM disponible**: 28,672 bytes
- **Firmware máximo**: 28,672 bytes
- **Capas dinámicas máximas**: 8 (con VIA habilitado)
- **Capas estáticas máximas**: 9 (sin VIA)

### Configuración Actual
- **VIA_ENABLE**: Deshabilitado temporalmente
- **DYNAMIC_KEYMAP_LAYER_COUNT**: 8
- **Tamaño del firmware**: ~26,236 bytes (91% del máximo)

## Comandos de Compilación y Verificación

### Compilación Básica
```bash
# Compilar el keymap
qmk compile -kb sofle/rev1 -km jhonnycgarcia_v2
```

### Verificación y Linting
```bash
# Verificar sintaxis y estilo del código
qmk lint -km jhonnycgarcia_v2 -kb sofle/rev1 --strict

# Verificar configuración del keymap
qmk lint -km jhonnycgarcia_v2 -kb sofle/rev1
```

### Comandos de Verificación Adicionales
```bash
# Ver información del teclado
qmk info -kb sofle/rev1

# Ver configuración del keymap
qmk config

# Verificar dependencias
qmk doctor
```

### Compilación con Opciones Avanzadas
```bash
# Compilación con salida detallada
qmk compile -kb sofle/rev1 -km jhonnycgarcia_v2 -v

# Compilación con colores
qmk compile -kb sofle/rev1 -km jhonnycgarcia_v2 --color

# Compilación silenciosa
qmk compile -kb sofle/rev1 -km jhonnycgarcia_v2 -s
```

## Solución de Problemas Comunes

### Error: "Number of keymap layers exceeds maximum"
**Causa**: Demasiadas capas para keymaps dinámicos
**Solución**: 
1. Reducir `DYNAMIC_KEYMAP_LAYER_COUNT` en `config.h`
2. O deshabilitar `VIA_ENABLE` en `rules.mk`

### Error: "Dynamic keymaps use more EEPROM than available"
**Causa**: EEPROM insuficiente para capas dinámicas
**Solución**: 
1. Deshabilitar VIA temporalmente
2. Usar keymaps estáticos
3. Reducir número de capas

### Verificación del Tamaño del Firmware
Después de compilar, verifica que el firmware no exceda el límite:
```bash
# El output debe mostrar algo como:
# The firmware size is fine - 26236/28672 (91%, 2436 bytes free)
```

## Estructura de Archivos

```
jhonnycgarcia_v2/
├── config.h          # Configuración del keymap
├── keymap.c          # Definición de capas y teclas
├── rules.mk          # Configuración de compilación
└── readme.md         # Este archivo
```

## Notas Importantes

- **VIA**: Deshabilitado para evitar conflictos de EEPROM
- **Capas**: 9 capas definidas, pero limitadas por EEPROM
- **RGB**: Configurado con 72 LEDs (36 por lado)
- **OLED**: Rotación de 270° en la pantalla principal
- **Encoders**: Configuración personalizada por capa

## Próximos Pasos

1. **Flashear el firmware** en tu teclado Sofle/rev1
2. **Probar todas las capas** y funcionalidades
3. **Personalizar** según tus necesidades
4. **Habilitar VIA** solo si reduces el número de capas

## Referencias

- [Documentación QMK](https://docs.qmk.fm/)
- [Sofle Keyboard](https://github.com/josefadamcik/SofleKeyboard)
- [QMK Configurator](https://config.qmk.fm/)
