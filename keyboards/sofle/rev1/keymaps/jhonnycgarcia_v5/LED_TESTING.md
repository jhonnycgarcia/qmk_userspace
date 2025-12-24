# Sofle RGB - Testing de Mapeo de LEDs

## Instrucciones
Usando el efecto `SOLID_REACTIVE_SIMPLE`, presioná cada tecla y anotá qué LED se enciende.

---

## LADO IZQUIERDO

### Fila 0 (números)
```
ESC    c 
1      d 
2      s 
3      x 
4      esc 
5      tab
```

### Fila 1 (QWERTY)
```
TAB    lower 
Q      e 
W      w 
E      switch 
R      1 
T      left shift 
```

### Fila 2 (home row)
```
LSHIFT+CAPS   SPACE 
A      3 
S      2 
D      left cmd 
F      q 
G      left ctrl 
```

### Fila 3 (ZXCV)
```
LOPT   v
Z      t 
X      5 
C      z 
V      a 
B      left option 
```

### Fila 4 (thumbs)
```
LALT   ninguna 
LGUI   ninguna
SWITCH g
LOWER  4 
SPACE  r 
```

---

## LADO DERECHO

### Fila 0 (números)
```
6      KC_GRV
7      BSPC
8      KC_DOT
9      l 
0      k 
BSPC   KC_COMM 
```

### Fila 1 (YUIOP)
```
Y      KC_QUOT
U      0
I      raise 
O      o 
P      i 
`      num 
```

### Fila 2 (home row)
```
H      KC_MINS
J      p 
K      KC_RGUI
L      9 
;      8 
'      KC_ENT
```

### Fila 3 (NM,.)
```
N      KC_ROPT
M      KC_SCLN
,      KC_SLSH
.      6 
/      y 
-      m 
```

### Fila 4 (thumbs)
```
ENTER  u
NUM    7
RAISE  h
RGUI   ninguna 
RALT   ninguna 
```

---

## NOTAS - TEST 1
- Fecha del testing: 
- Firmware usado: jhonnycgarcia_v5
- Efecto utilizado: SOLID_REACTIVE_SIMPLE

---
---

# TEST 2 - Después del primer ajuste de mapeo

## LADO IZQUIERDO

### Fila 0 (números)
```
ESC    c 
1      d 
2      s 
3      x 
4      ESC 
5      TAB
```

### Fila 1 (QWERTY)
```
TAB    LOWER 
Q      e 
W      w (CORRECTO)
E      SWITCH 
R      q 
T      KC_CAPS_MT
```

### Fila 2 (home row)
```
CAPS   KC_ENT
A      3 
S      2 
D      KC_LGUI
F      q 
G      KC_LCTL
```

### Fila 3 (ZXCV)
```
LCTRL  v 
Z      f 
X      r 
C      z 
V      a 
B      KC_LOPT
```

### Fila 4 (thumbs)
```
LOPT   ninguna 
LGUI   ninguna
SWITCH b
LOWER  4 
SPACE  g 
```

---

## LADO DERECHO

### Fila 0 (números)
```
6      KC_GRV
7      KC_BSPC
8      KC_DOT
9      l
0      k 
BSPC   KC_COMM
```

### Fila 1 (YUIOP)
```
Y      KC_QUOT
U      0
I      RAISE 
O      o
P      i 
`      NUM 
```

### Fila 2 (home row)
```
H      KC_MINS
J      p
K      KC_RGUI
L      9
;      8 
'      KC_ENT
```

### Fila 3 (NM,.)
```
N      KC_ROPT
M      KC_SCLN
,      KC_SLSH
.      6 
/      y 
-      m 
```

### Fila 4 (thumbs)
```
ENTER  h 
NUM    7 
RAISE  n 
RGUI   ninguna 
RALT   ninguna
```

---

## NOTAS - TEST 2
- Fecha del testing: 
- Firmware usado: jhonnycgarcia_v5 (después del primer ajuste)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- Observación inicial: ESC→c, W→w (correcto)

---
---

# TEST 3 - Después de recalcular posiciones físicas de LEDs

**Cambio realizado:** En lugar de cambiar la matriz de teclas a LEDs, se recalcularon las POSICIONES FÍSICAS de cada LED basándose en el testing anterior.

Lógica: Si presionar ESC (LED 25) enciende la posición de C, entonces LED 25 tiene posición física (60,48) que es C.

## LADO IZQUIERDO

### Fila 0 (números)
```
ESC    c 
1      d 
2      s 
3      x 
4      ESC 
5      TAB 
```

### Fila 1 (QWERTY)
```
TAB    LOWER 
Q      e 
W      w 
E      SWTICH 
R      1 
T      CAPS
```

### Fila 2 (home row)
```
CAPS   ENTER 
A      3 
S      2 
D      KC_LGUI
F      q 
G      KC_LCTL
```

### Fila 3 (ZXCV)
```
LCTRL  v 
Z      f 
X      r 
C      z 
V      a 
B      KC_LOPT
```

### Fila 4 (thumbs)
```
LOPT   t 
LGUI   5 
SWITCH b 
LOWER  4 
SPACE  g 
```

---

## LADO DERECHO

### Fila 0 (números)
```
6      KC_GRV
7      KC_BSPC
8      KC_DOT
9      l
0      k 
BSPC   KC_COMM
```

### Fila 1 (YUIOP)
```
Y      KC_QUOT
U      0
I      RAISE
O      o
P      i 
`      NUM 
```

### Fila 2 (home row)
```
H      KC_MINS
J      p
K      KC_RGUI
L      9
;      8 
'      KC_ENT
```

### Fila 3 (NM,.)
```
N      RALT
M      KC_SCLN
,      KC_SLSH
.      6 
/      y
-      m 
```

### Fila 4 (thumbs)
```
ENTER  j
NUM    u 
RAISE  7 
RGUI   h
RALT   n
```

---

## NOTAS - TEST 3
- Fecha del testing: 
- Firmware usado: jhonnycgarcia_v5 (posiciones físicas recalculadas)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- Método: Se invirtió la lógica - las posiciones físicas de los LEDs ahora reflejan dónde realmente encienden según el cableado del PCB

---
---

# TEST 4 - Intercambio de índices LED en la matriz

**Cambio realizado:** Se intercambiaron los índices de LED en la primera matriz basándose en el testing.

Lógica: Si presionar ESC enciende C, y presionar 4 enciende ESC, entonces ESC debe usar el LED que actualmente usa 4.

## LADO IZQUIERDO

### Fila 0 (números)
```
ESC    ESC
1      1 
2      2 
3      3 
4      4 
5      5 
```

### Fila 1 (QWERTY)
```
TAB    TAB 
Q      q 
W      w 
E      e 
R      r 
T      t 
```

### Fila 2 (home row)
```
CAPS   CAPS 
A      a 
S      s
D      d 
F      f 
G      g 
```

### Fila 3 (ZXCV)
```
LCTRL  LCTRL 
Z      z 
X      x 
C      c 
V      v 
B      b 
```

### Fila 4 (thumbs)
```
LOPT   LOPT 
LGUI   LGUI
SWITCH SWITCH 
LOWER  LOWER 
SPACE  SPACE 
```

---

## LADO DERECHO

### Fila 0 (números)
```
6      k 
7      0 
8      9 
9      8 
0      y 
BSPC   6 
```

### Fila 1 (YUIOP)
```
Y      KC_GRV
U      p 
I      RAISE 
O      i 
P      7 
`      y 
```

### Fila 2 (home row)
```
H      KC_MINS
J      l
K      KC_DOT
L      KC_BSPC
;      j 
'      h 
```

### Fila 3 (NM,.)
```
N      ENTER 
M      KC_SLSH
,      KC_QUOT
.      KC_ROPT
/      KC_SCLN
-      n 
```

### Fila 4 (thumbs)
```
ENTER  m
NUM    o 
RAISE  NUM 
RGUI   KC_RGUI
RALT   KC_COMM
```

---

## NOTAS - TEST 4
- Fecha del testing: 
- Firmware usado: jhonnycgarcia_v5 (índices LED intercambiados)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- Método: Intercambio de LEDs basándose en la cadena de "quién enciende a quién"
- **RESULTADO LADO IZQUIERDO: ✅ 100% CORRECTO**

---
---

# TEST 5 - Corrección del lado derecho con ciclos cerrados

**Cambio realizado:** Se aplicó la misma lógica del lado izquierdo al derecho, resolviendo 4 ciclos:

1. **Swap 8↔9**: Intercambio directo
2. **Swap Y↔GRV + cadena U→P→7→0→Y**: U toma LED sobrante (48)
3. **Ciclo I→RAISE→NUM→O→I**: Rotación de 4 LEDs
4. **Ciclo de 16**: ;→J→L→BSPC→6→K→.→RALT→,→'→H→-→N→ENTER→M→/→;

## LADO IZQUIERDO (ya verificado ✅)

*(No es necesario re-testear, TEST 4 confirmó que está 100% correcto)*

---

## LADO DERECHO

### Fila 0 (números)
```
6    KC_DOT
7    u  
8    8 
9    9 
0    p 
BSPC  k 
```

### Fila 1 (YUIOP)
```
Y     y
U     7
I     NUM
O     RAISE 
P     0
`     `
```

### Fila 2 (home row)
```
H     KC_ROPT
J     KC_SLSH
K     j
L     6
;     l
'     KC_MINS
```

### Fila 3 (NM,.)
```
N     h
M     KC_SCLN
,     KC_BSPC
.     m
/     KC_COMM
-     KC_ENT
```

### Fila 4 (thumbs)
```
ENTER  KC_QUOT
NUM    i
RAISE  o
RGUI   RGUI
RALT   n
```

---

## NOTAS - TEST 5
- Fecha del testing: 
- Firmware usado: jhonnycgarcia_v5 (ciclos cerrados lado derecho)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 8, 9, Y, `, RGUI (5 de 29)
- **Ciclos detectados:**
  - Swaps: 7↔U, 0↔P, I↔NUM, O↔RAISE
  - Ciclo 5: 6→.→M→;→L→6
  - Ciclo 5: BSPC→K→J→/→,→BSPC
  - Ciclo 3: H→RALT→N→H
  - Ciclo 3: '→-→ENTER→'

---
---

# TEST 6 - Segunda corrección lado derecho

**Cambio realizado:** Rotación de LEDs según los ciclos detectados en TEST 5.

## LADO DERECHO

### Fila 0 (números)
```
6      m
7      7
8      8
9      9
0      0
BSPC   j
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      n
J      KC_COMM
K      KC_SLSH
L      KC_DOT
;      6
'      KC_ENT
```

### Fila 3 (NM,.)
```
N      KC_ROPT
M      l
,      k
.      KC_SCLN
/      KC_BSPC
-      KC_QUOT
```

### Fila 4 (thumbs)
```
ENTER  KC_MINS
NUM    NUM
RAISE  RAISE
RGUI   RGUI
RALT   h
```

---

## NOTAS - TEST 6
- Fecha del testing: 
- Firmware usado: jhonnycgarcia_v5 (TEST 6)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, NUM, RAISE, RGUI (13 de 29)
- **Ciclos detectados:**
  - Ciclo 5: 6→M→L→.→;→6
  - Ciclo 5: BSPC→J→,→K→/→BSPC
  - Ciclo 3: H→N→RALT→H
  - Ciclo 3: '→ENTER→-→'

---
---

# TEST 7 - Tercera corrección lado derecho

## LADO DERECHO

### Fila 0 (números)
```
6      l
7      7
8      8
9      9
0      0
BSPC   KC_COMM
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      KC_ROPT
J      k
K      KC_BSPC
L      KC_SCLN
;      m
'      KC_MINS
```

### Fila 3 (NM,.)
```
N      h
M      KC_DOT
,      KC_SLSH
.      6
/      j
-      KC_ENT
```

### Fila 4 (thumbs)
```
ENTER  KC_QUOT
NUM   NUM
RAISE  RAISE
RGUI   RGUI
RALT   n
```

---

## NOTAS - TEST 7
- Firmware usado: jhonnycgarcia_v5 (TEST 7)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, NUM, RAISE, RGUI (13/29)
- **Mismos ciclos, rotados 1 posición**

---
---

# TEST 8 - Rotación completa de ciclos

**Cambio:** Cada elemento del ciclo toma el LED del elemento que lo enciende (usando LEDs originales del TEST 7).

## LADO DERECHO

### Fila 0 (números)
```
6      KC_SCLN
7      7
8      8
9      9
0      0
BSPC   KC_SLSH
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      n
J      KC_BSPC
K      KC_COMM
L      m
;      KC_DOT
'      KC_ENT
```

### Fila 3 (NM,.)
```
N      KC_ROPT
M      6
,      j
.      l
/      k
-      KC_QUOT
```

### Fila 4 (thumbs)
```
ENTER  KC_MINS
NUM    NUM
RAISE  RAISE
RGUI   RGUI
RALT   h
```

---

## NOTAS - TEST 8
- Firmware usado: jhonnycgarcia_v5 (TEST 8)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, NUM, RAISE, RGUI (13/29)
- Ver LED_CYCLES.md para historial completo de ciclos

---
---

# TEST 9 - Inversión de rotación

**Cambio:** Cada tecla toma LED de quien LA ENCIENDE (ver LED_CYCLES.md para detalles).

## LADO DERECHO

### Fila 0 (números)
```
6      KC_DOT
7      7
8      8
9      9
0      0
BSPC   k
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      KC_ROPT
J      KC_SLSH
K      j
L      6
;      l
'      KC_MINS
```

### Fila 3 (NM,.)
```
N      h
M      KC_SCLN
,      KC_BSPC
.      m
/      KC_COMM
-      KC_ENT
```

### Fila 4 (thumbs)
```
ENTER  KC_QUOT
NUM    NUM
RAISE  RAISE
RGUI   RGUI
RALT   n
```

---

## NOTAS - TEST 9
- Firmware usado: jhonnycgarcia_v5 (TEST 9)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, NUM, RAISE, RGUI (13/29)

---
---

# TEST 10 - Usando LEDs ORIGINALES + lógica del lado izquierdo

**Cambio:** Volvemos a aplicar la lógica que funcionó para el lado izquierdo (TEST 4), pero usando los LEDs ORIGINALES del commit inicial.

Lógica: Del TEST 4, si X→Y, buscar Z→X, entonces X usa LED ORIGINAL de Z.

## LADO DERECHO

### Fila 0 (números)
```
6      KC_DOT
7      u
8      8
9      9
0      p
BSPC   k
```

### Fila 1 (YUIOP)
```
Y      y
U      7
I      NUM
O      RAISE
P      0
`      `
```

### Fila 2 (home row)
```
H      KC_ROPT
J      KC_SLSH
K      j
L      6
;      l
'      KC_MINS
```

### Fila 3 (NM,.)
```
N      h
M      KC_SCLN
,      KC_BSPC
.      m
/      KC_COMM
-      KC_ENT
```

### Fila 4 (thumbs)
```
ENTER  KC_QUOT
NUM    i
RAISE  o
RGUI   RGUI
RALT   n
```

---

## NOTAS - TEST 10
- Firmware usado: jhonnycgarcia_v5 (TEST 10)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 8, 9, Y, `, RGUI (5/29) - ROMPIÓ los 13!
- **Problema:** Usé valores de TEST5/6 para I,O,NUM,RAISE que no funcionaban

---
---

# TEST 11 - Mantener 13 correctos + rotar ciclo 16

**Cambio:** Mantener los valores que funcionaron (TEST7-9) para los 13 correctos, y rotar el ciclo de 16 basado en TEST9.

## LADO DERECHO

### Fila 0 (números)
```
6      m
7      7
8      8
9      9
0      0
BSPC   j
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      n
J      KC_COMM
K      KC_SLSH
L      KC_DOT
;      6
'      KC_ENT
```

### Fila 3 (NM,.)
```
N      KC_ROPT
M      l
,      k
.      KC_SCLN
/      KC_BSPC
-      KC_QUOT
```

### Fila 4 (thumbs)
```
ENTER  KC_MINS
NUM    NUM
RAISE  RAISE
RGUI   RGUI
RALT   h
```

---

## NOTAS - TEST 11
- Firmware usado: jhonnycgarcia_v5 (TEST 11)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, NUM, RAISE, RGUI (13/29) ✅

---
---

# TEST 12 - Rotar ciclo 16 basado en TEST11

## LADO DERECHO

### Fila 0 (números)
```
6      l
7      7
8      8
9      9
0      0
BSPC   KC_COMM
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      KC_ROPT
J      k
K      KC_BSPC
L      KC_SCLN
;      m
'      KC_MINS
```

### Fila 3 (NM,.)
```
N      h
M      KC_DOT
,      KC_SLSH
.      6
/      j
-      KC_ENT
```

### Fila 4 (thumbs)
```
ENTER  KC_QUOT
NUM    NUM
RAISE  RAISE
RGUI   RGUI
RALT   n
```

---

## NOTAS - TEST 12
- Firmware usado: jhonnycgarcia_v5 (TEST 12)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, NUM, RAISE, RGUI (13/29) ✅
- Ciclos siguen rotando, patrón se repite (TEST12=TEST7 para ciclo A)

---
---

# TEST 13 - Rotar 2 posiciones en vez de 1

**Cambio:** En vez de rotar 1 posición por test, rotar 2 posiciones desde TEST11.

## LADO DERECHO

### Fila 0 (números)
```
6      KC_DOT
7      7
8      8
9      9
0      0
BSPC   KC_SLSH
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      h
J      KC_BSPC
K      KC_COMM
L      6
;      l
'      '
```

### Fila 3 (NM,.)
```
N      n
M      KC_SCLN
,      j
.      m
/      k
-      -
```

### Fila 4 (thumbs)
```
ENTER  ENTER
NUM   NUM
RAISE  RAISE
RGUI   RGUI
RALT   RALT
```

---

## NOTAS - TEST 13
- Firmware usado: jhonnycgarcia_v5 (TEST 13)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** 7, 8, 9, 0, Y, U, I, O, P, `, H, N, RALT, ', -, ENTER, NUM, RAISE, RGUI (19/29)
- **¡Ciclos C y D resueltos!**

---
---

# TEST 14 - Teoría del usuario: patrón secuencial

**Cambio:** El usuario propuso que los LEDs siguen un patrón geométrico ordenado (zig-zag por columnas).

Hipótesis: En vez de rotar ciclos, el PCB tiene un patrón matemático predecible.

Los 19 correctos del TEST 13 NO se modifican, solo las 10 teclas problemáticas.

## LADO DERECHO

### Fila 0 (números)
```
6      6
7      7
8      8
9      9
0      0
BSPC   BSPC
```

### Fila 1 (YUIOP)
```
Y      y
U      u
I      i
O      o
P      p
`      `
```

### Fila 2 (home row)
```
H      h
J      j
K      k
L      l
;      ;
'      '
```

### Fila 3 (NM,.)
```
N      n
M      m
,      ,
.      .
/      /
-      -
```

### Fila 4 (thumbs)
```
ENTER  ENTER
NUM    NUM
RAISE  RAISE
RGUI   RGUI
RALT   RALT
```

---

## NOTAS - TEST 14
- Firmware usado: jhonnycgarcia_v5 (TEST 14)
- Efecto utilizado: SOLID_REACTIVE_SIMPLE
- **Correctos:** ✅ **29/29 - 100% COMPLETADO** 🎉
- **Teoría del usuario confirmada:** Patrón zig-zag por columnas

---
---

# 🏆 RESUMEN FINAL

## Lado Izquierdo: ✅ Completado en TEST 4
## Lado Derecho: ✅ Completado en TEST 14

**Total de tests realizados:** 14
**Método ganador:** Patrón geométrico zig-zag por columnas (propuesto por el usuario)

### Matriz final lado derecho:
```c
{47, 48, 57, 58, 67, 68},     // Fila 5: 6,7,8,9,0,BSPC
{46, 49, 56, 59, 66, 69},     // Fila 6: Y,U,I,O,P,GRV
{45, 50, 55, 60, 65, 70},     // Fila 7: H,J,K,L,;,'
{44, 51, 54, 61, 64, 71},     // Fila 8: N,M,,,.,/,-
{43, 52, 53, 62, 63, NO_LED}, // Fila 9: ENT,RGUI,NUM,RAISE,RALT
```
