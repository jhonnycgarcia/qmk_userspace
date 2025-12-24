# Sofle RGB - Mapa de LEDs para RGB_MATRIX

## Resumen

El Sofle RGB tiene **72 LEDs** (36 por lado) con el siguiente layout:

| Rango LEDs | Cantidad | Descripción |
|------------|----------|-------------|
| 0          | 1        | Indicador izquierdo (debajo de OLED) |
| 1-6        | 6        | Underglow izquierdo |
| 7-35       | 29       | Per-key izquierdo |
| 36         | 1        | Indicador derecho (debajo de OLED) |
| 37-42      | 6        | Underglow derecho |
| 43-71      | 29       | Per-key derecho |

## Hallazgo del Cableado (Testing Real)

El cableado de los LEDs fue descubierto mediante testing del efecto `SOLID_REACTIVE_SIMPLE`, observando qué LED se enciende al presionar cada tecla.

### Datos del Testing (Lado Izquierdo)

| Tecla Presionada | LED que Enciende | Conclusión |
|------------------|------------------|------------|
| G                | Q                | Offset de ~1 fila hacia arriba |
| Q                | W                | Serpentina horizontal |
| W                | 2                | Salta a fila superior |
| 2                | F                | Serpentina vertical |
| F                | A                | Continúa serpentina |
| A                | V                | Baja a fila inferior |
| 1                | F                | Confirma patrón |
| ESC              | R                | Mapeo columna exterior |
| Z                | Left Shift       | Confirma orden |
| Space (thumb)    | T                | Thumbs van a columna interior |
| Enter (thumb)    | Y (lado derecho) | Confirma separación mitades |

### Datos del Testing (Lado Derecho)

| Tecla Presionada | LED que Enciende |
|------------------|------------------|
| P                | O                |

## Patrón de Cableado Identificado

El cableado sigue un patrón de **serpentina** que:

1. **Empieza** en la columna interior (cerca del centro del teclado)
2. **Sube** por la columna interior
3. **Baja** por la siguiente columna hacia el exterior
4. **Repite** el patrón hasta llegar a la columna exterior
5. Los **thumbs** se conectan al final de la cadena

```
Visualización del cableado (lado izquierdo):

     Col0    Col1    Col2    Col3    Col4    Col5
    (ESC)   (1)     (2)     (3)     (4)     (5)
      ↑       ↑       ↑       ↑       ↑       ↑
Row0  25  ←  24      19  ←  18      11  ←  10
                      ↑               ↑
Row1  26  →  23  →  20      17  ←  12       9
      ↓                      ↑               ↑
Row2  27      22  ←  21      16      13  ←   8
      ↓       ↑               ↓       ↑
Row3  28      33      32  ←  15      14       7
              ↑       ↑                       ↑
             (Z)     (X)    (C)     (V)     (B)

Thumbs: 34 → 31 → 30 → 29 (ALT → GUI → LWR → SPC → ENT)
```

## Matriz de Teclas a Índice LED

### Lado Izquierdo (Filas 0-4)

```c
// [fila][columna] = índice LED
{ 25, 24, 19, 18, 11, 10 },          // Fila 0: ESC, 1, 2, 3, 4, 5
{ 26, 23, 20, 17, 12,  9 },          // Fila 1: TAB, Q, W, E, R, T
{ 27, 22, 21, 16, 13,  8 },          // Fila 2: CAPS, A, S, D, F, G
{ 28, 33, 32, 15, 14,  7 },          // Fila 3: SHFT, Z, X, C, V, B
{ NO_LED, NO_LED, 34, 31, 30, 29 },  // Fila 4: -, -, ALT, LWR, SPC, ENT
```

### Lado Derecho (Filas 5-9)

```c
// Offset +36 respecto al izquierdo (mismo patrón espejado)
{ 61, 60, 55, 54, 47, 46 },          // Fila 5: 6, 7, 8, 9, 0, BSPC
{ 62, 59, 56, 53, 48, 45 },          // Fila 6: Y, U, I, O, P, `
{ 63, 58, 57, 52, 49, 44 },          // Fila 7: H, J, K, L, ;, '
{ 64, 69, 68, 51, 50, 43 },          // Fila 8: N, M, ,, ., /, -
{ NO_LED, NO_LED, 70, 67, 66, 65 },  // Fila 9: thumbs
```

## Posiciones Físicas de LEDs

Las coordenadas usan el sistema QMK: `x: 0-224`, `y: 0-64`

### Lado Izquierdo

| LED | Tecla | Posición (x, y) |
|-----|-------|-----------------|
| 0   | Indicador | (91, 40) |
| 1-6 | Underglow | (0,64) a (100,64) |
| 7   | B     | (100, 48) |
| 8   | G     | (100, 32) |
| 9   | T     | (100, 16) |
| 10  | 5     | (100, 0) |
| 11  | 4     | (80, 0) |
| 12  | R     | (80, 16) |
| 13  | F     | (80, 32) |
| 14  | V     | (80, 48) |
| 15  | C     | (60, 48) |
| 16  | D     | (60, 32) |
| 17  | E     | (60, 16) |
| 18  | 3     | (60, 0) |
| 19  | 2     | (40, 0) |
| 20  | W     | (40, 16) |
| 21  | S     | (40, 32) |
| 22  | A     | (20, 32) |
| 23  | Q     | (20, 16) |
| 24  | 1     | (20, 0) |
| 25  | ESC   | (0, 0) |
| 26  | TAB   | (0, 16) |
| 27  | CAPS  | (0, 32) |
| 28  | LSHFT | (0, 48) |
| 29  | ENT (thumb) | (100, 56) |
| 30  | SPC (thumb) | (80, 56) |
| 31  | LWR (thumb) | (60, 56) |
| 32  | X     | (40, 48) |
| 33  | Z     | (20, 48) |
| 34  | ALT (thumb) | (40, 56) |
| 35  | Extra thumb | (60, 56) |

### Lado Derecho

| LED | Tecla | Posición (x, y) |
|-----|-------|-----------------|
| 36  | Indicador | (133, 40) |
| 37-42 | Underglow | (124,64) a (224,64) |
| 43  | N     | (124, 48) |
| 44  | H     | (124, 32) |
| 45  | Y     | (124, 16) |
| 46  | 6     | (124, 0) |
| 47  | 7     | (144, 0) |
| 48  | U     | (144, 16) |
| 49  | J     | (144, 32) |
| 50  | M     | (144, 48) |
| 51  | ,     | (164, 48) |
| 52  | K     | (164, 32) |
| 53  | I     | (164, 16) |
| 54  | 8     | (164, 0) |
| 55  | 9     | (184, 0) |
| 56  | O     | (184, 16) |
| 57  | L     | (184, 32) |
| 58  | ;     | (204, 32) |
| 59  | P     | (204, 16) |
| 60  | 0     | (204, 0) |
| 61  | BSPC  | (224, 0) |
| 62  | `     | (224, 16) |
| 63  | '     | (224, 32) |
| 64  | -     | (224, 48) |
| 65-71 | Thumbs | (124-184, 56) |

## Flags de LEDs

```c
// 1 = LED_FLAG_MODIFIER
// 2 = LED_FLAG_UNDERGLOW  
// 4 = LED_FLAG_KEYLIGHT
// 8 = LED_FLAG_INDICATOR

// Izquierdo
8,                          // 0: Indicador
2, 2, 2, 2, 2, 2,           // 1-6: Underglow
4, 4, 4, 4, 4, 4,           // 7-12: Teclas
4, 4, 4, 4, 4, 4,           // 13-18: Teclas
4, 4, 4, 4, 4, 4,           // 19-24: Teclas
4, 4, 4, 4,                 // 25-28: Teclas
4, 4, 4, 4, 4, 4, 4,        // 29-35: Thumbs

// Derecho
8,                          // 36: Indicador
2, 2, 2, 2, 2, 2,           // 37-42: Underglow
4, 4, 4, 4, 4, 4,           // 43-48: Teclas
4, 4, 4, 4, 4, 4,           // 49-54: Teclas
4, 4, 4, 4, 4, 4,           // 55-60: Teclas
4, 4, 4, 4,                 // 61-64: Teclas
4, 4, 4, 4, 4, 4, 4,        // 65-71: Thumbs
```

## Notas Importantes

1. **El LED indicador (0 y 36)** está ubicado debajo de la pantalla OLED, se usa para mostrar cambios de capa.

2. **El patrón es espejado** entre ambos lados, con un offset de +36 para el lado derecho.

3. **Los underglow** están en la parte trasera del PCB, apuntando hacia abajo.

4. **El cableado serpentina** va desde la columna interior (cerca del split) hacia la exterior.

## Fecha de Documentación

- **Fecha**: Diciembre 2024
- **Método**: Testing manual con efecto SOLID_REACTIVE_SIMPLE
- **Hardware**: Sofle RGB v2.x con Pro Micro
