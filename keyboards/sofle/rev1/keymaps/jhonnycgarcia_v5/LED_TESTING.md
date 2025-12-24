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
