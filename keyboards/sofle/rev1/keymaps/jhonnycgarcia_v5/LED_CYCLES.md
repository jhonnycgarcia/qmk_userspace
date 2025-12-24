# Control de Ciclos LED - Lado Derecho Sofle RGB

## LEDs que YA FUNCIONAN (no tocar)
Estos quedaron correctos desde TEST 6 y no cambiaron:
- 7, 8, 9, 0 (fila números)
- Y, U, I, O, P, ` (fila YUIOP completa)
- NUM, RAISE, RGUI (thumbs)

**Total correctos fijos: 13 de 29**

---

## CONFIGURACIÓN POR TEST

### TEST 5 - Configuración aplicada:
```c
{60, 49, 57, 58, 66, 54},     // Fila 5: 6,7,8,9,0,BSPC
{46, 48, 53, 62, 67, 69},     // Fila 6: Y,U,I,O,P,GRV
{44, 55, 68, 65, 51, 43},     // Fila 7: H,J,K,L,;,'
{63, 61, 64, 47, 50, 70},     // Fila 8: N,M,,,.,/,-
{71, 52, 56, 59, 45, NO_LED}, // Fila 9: ENT,RGUI,NUM,RAISE,RALT
```
**Resultado:** 5 correctos (8,9,Y,`,RGUI)

---

### TEST 6 - Configuración aplicada:
```c
{60, 49, 57, 58, 66, 54},     // Fila 5: 6=60,7=49,8=57,9=58,0=66,BSPC=54
{46, 67, 53, 62, 67, 69},     // Fila 6: Y=46,U=67,I=53,O=62,P=67,GRV=69
{44, 55, 68, 65, 55, 43},     // Fila 7: H=44,J=55,K=68,L=65,;=55,'=43
{63, 61, 64, 47, 50, 63},     // Fila 8: N=63,M=61,,=64,.=47,/=50,-=63
{71, 52, 56, 59, 45, NO_LED}, // Fila 9: ENT=71,RGUI=52,NUM=56,RAISE=59,RALT=45
```
**Resultado:** 13 correctos (7,8,9,0,Y,U,I,O,P,`,NUM,RAISE,RGUI)

---

### TEST 7 - Configuración aplicada:
```c
{61, 48, 57, 58, 67, 55},     // Fila 5: 6=61,7=48,8=57,9=58,0=67,BSPC=55
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{44, 64, 50, 47, 60, 43},     // Fila 7: H=44,J=64,K=50,L=47,;=60,'=43
{63, 65, 68, 51, 54, 70},     // Fila 8: N=63,M=65,,=68,.=51,/=54,-=70
{71, 52, 53, 62, 45, NO_LED}, // Fila 9: ENT=71,RGUI=52,NUM=53,RAISE=62,RALT=45
```
**Resultado:** 13 correctos (mismos)

---

### TEST 8 - Configuración aplicada:
```c
{51, 48, 57, 58, 67, 50},     // Fila 5: 6=51,7=48,8=57,9=58,0=67,BSPC=50
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{63, 54, 64, 61, 47, 71},     // Fila 7: H=63,J=54,K=64,L=61,;=47,'=71
{45, 60, 55, 65, 68, 43},     // Fila 8: N=45,M=60,,=55,.=65,/=68,-=43
{70, 52, 53, 62, 44, NO_LED}, // Fila 9: ENT=70,RGUI=52,NUM=53,RAISE=62,RALT=44
```
**Resultado:** 13 correctos (mismos)

**Ciclos detectados en TEST 8:**
- Ciclo A: 6→SCLN, ;→DOT, .→L, L→M, M→6
- Ciclo B: BSPC→SLSH, /→K, K→COMM, ,→J, J→BSPC
- Ciclo C: H→N, N→ROPT, RALT→H
- Ciclo D: '→ENT, ENTER→MINS, -→QUOT

---

### TEST 9 - Configuración aplicada:
```c
{60, 48, 57, 58, 67, 54},     // Fila 5: 6=60,7=48,8=57,9=58,0=67,BSPC=54
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{44, 55, 68, 65, 51, 43},     // Fila 7: H=44,J=55,K=68,L=65,;=51,'=43
{63, 61, 64, 47, 50, 70},     // Fila 8: N=63,M=61,,=64,.=47,/=50,-=70
{71, 52, 53, 62, 45, NO_LED}, // Fila 9: ENT=71,RGUI=52,NUM=53,RAISE=62,RALT=45
```

**Lógica aplicada:** Cada tecla toma el LED de quien LA ENCIENDE (basado en TEST 8).

| Tecla | Encendida por | LED que toma |
|-------|---------------|--------------|
| 6 | M | 60 |
| ; | 6 | 51 |
| . | ; | 47 |
| L | . | 65 |
| M | L | 61 |
| BSPC | J | 54 |
| / | BSPC | 50 |
| K | / | 68 |
| , | K | 64 |
| J | , | 55 |
| H | RALT | 44 |
| N | H | 63 |
| RALT | N | 45 |
| ' | - | 43 |
| ENTER | ' | 71 |
| - | ENTER | 70 |

**Resultado:** 13 correctos (7,8,9,0,Y,U,I,O,P,`,NUM,RAISE,RGUI) - mismos ciclos rotando

---

### TEST 10 - Configuración aplicada:
```c
{60, 49, 57, 58, 66, 54},     // Fila 5: 6=60,7=49,8=57,9=58,0=66,BSPC=54
{46, 48, 53, 62, 67, 69},     // Fila 6: Y=46,U=48,I=53,O=62,P=67,GRV=69
{44, 55, 68, 65, 51, 43},     // Fila 7: H=44,J=55,K=68,L=65,;=51,'=43
{63, 61, 64, 47, 50, 70},     // Fila 8: N=63,M=61,,=64,.=47,/=50,-=70
{71, 52, 56, 59, 45, NO_LED}, // Fila 9: ENT=71,RGUI=52,NUM=56,RAISE=59,RALT=45
```

**Lógica:** Volver a usar LEDs ORIGINALES del commit inicial + lógica TEST 4.

Usando datos del TEST 4 lado derecho:
- 6→K, 7→0, 8↔9, 0→Y, BSPC→6
- Y↔`, U→P→7, I→RAISE→NUM→O→I
- Ciclo 16: ;→J→L→BSPC→6→K→.→RALT→,→'→H→-→N→ENTER→M→/→;

| Tecla | Quién→Tecla | LED ORIGINAL de "Quién" |
|-------|-------------|------------------------|
| 6 | BSPC | 60 |
| 7 | P | 49 |
| 8 | 9 | 57 |
| 9 | 8 | 58 |
| 0 | 7 | 66 |
| BSPC | L | 54 |
| Y | ` | 46 |
| U | (cadena, toma sobrante) | 48 |
| I | O | 53 |
| O | NUM | 62 |
| P | U | 67 |
| ` | Y | 69 |
| H | ' | 44 |
| J | ; | 55 |
| K | 6 | 68 |
| L | J | 65 |
| ; | / | 51 |
| ' | , | 43 |
| N | - | 63 |
| M | ENTER | 61 |
| , | RALT | 64 |
| . | K | 47 |
| / | M | 50 |
| - | H | 70 |
| ENTER | N | 71 |
| NUM | RAISE | 56 |
| RAISE | I | 59 |
| RGUI | (correcto) | 52 |
| RALT | . | 45 |

**Resultado:** 5 correctos (rompió los 13, volvió a config similar a TEST5)

---

### TEST 11 - Configuración aplicada:
```c
{65, 48, 57, 58, 67, 64},     // Fila 5: 6=65,7=48,8=57,9=58,0=67,BSPC=64
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{63, 68, 54, 51, 61, 71},     // Fila 7: H=63,J=68,K=54,L=51,;=61,'=71
{45, 47, 50, 60, 55, 43},     // Fila 8: N=45,M=47,,=50,.=60,/=55,-=43
{70, 52, 53, 62, 44, NO_LED}, // Fila 9: ENT=70,RGUI=52,NUM=53,RAISE=62,RALT=44
```

**Lógica:** Mantener los 13 correctos (TEST7-9) + rotar ciclo 16 basado en TEST9.
Del TEST9, cada tecla del ciclo 16 toma LED de quien la enciende:
- 6←L(65), BSPC←,(64), H←N(63), J←K(68), K←BSPC(54), L←;(51), ;←M(61), '←ENTER(71)
- N←RALT(45), M←.(47), ,←/(50), .←6(60), /←J(55), -←'(43), ENTER←-(70), RALT←H(44)

**Resultado:** 13 correctos (7,8,9,0,Y,U,I,O,P,`,NUM,RAISE,RGUI) ✅ Los 13 se mantienen!

Ciclo 16 sigue rotando:
- 6→M, BSPC→J, H→N, J→COMM, K→SLSH, L→DOT, ;→6, '→ENT
- N→ROPT, M→L, ,→K, .→SCLN, /→BSPC, -→QUOT, ENTER→MINS, RALT→H

---

## CICLOS IDENTIFICADOS

### Ciclo A: 5 elementos (6, L, ;, M, .)

| TEST | 6→ | L→ | ;→ | M→ | .→ |
|------|-----|-----|-----|-----|-----|
| TEST5 | DOT | BSPC | L | SCLN | ROPT |
| TEST6 | M | DOT | 6 | L | SCLN |
| TEST7 | L | SCLN | M | DOT | 6 |
| TEST8 | SCLN | M | DOT | 6 | L |
| TEST9 | DOT | 6 | L | SCLN | M |
| TEST10 | DOT | 6 | L | SCLN | M |
| TEST11 | M | DOT | 6 | L | SCLN |
| TEST12 | L | SCLN | M | DOT | 6 |
| TEST13 | ? | ? | ? | ? | ? |

---

### Ciclo B: 5 elementos (BSPC, K, J, /, ,)

| TEST | BSPC→ | K→ | J→ | /→ | ,→ |
|------|-------|-----|-----|-----|-----|
| TEST5 | K | DOT | SLSH | COMM | BSPC |
| TEST6 | J | SLSH | COMM | BSPC | K |
| TEST7 | COMM | BSPC | K | J | SLSH |
| TEST8 | SLSH | COMM | BSPC | K | J |
| TEST9 | K | J | SLSH | COMM | BSPC |
| TEST10 | K | J | SLSH | COMM | BSPC |
| TEST11 | J | SLSH | COMM | BSPC | K |
| TEST12 | COMM | BSPC | K | J | SLSH |
| TEST13 | ? | ? | ? | ? | ? |

---

### Ciclo C: 3 elementos (H, N, RALT)

| TEST | H→ | N→ | RALT→ |
|------|-----|-----|-------|
| TEST5 | ROPT | H | N |
| TEST6 | ROPT | H | N |
| TEST7 | N | H | N |
| TEST8 | N | ROPT | H |
| TEST9 | ROPT | H | N |
| TEST10 | ROPT | H | N |
| TEST11 | N | ROPT | H |
| TEST12 | ROPT | H | N |
| TEST13 | ? | ? | ? |

---

### Ciclo D: 3 elementos (', -, ENTER)

| TEST | '→ | -→ | ENTER→ |
|------|-----|-----|--------|
| TEST5 | MINS | ENT | QUOT |
| TEST6 | ENT | QUOT | MINS |
| TEST7 | MINS | ENT | QUOT |
| TEST8 | ENT | QUOT | MINS |
| TEST9 | MINS | ENT | QUOT |
| TEST10 | MINS | ENT | QUOT |
| TEST11 | ENT | MINS | QUOT |
| TEST12 | MINS | ENT | QUOT |
| TEST13 | ? | ? | ? |

---

### TEST 13 - Configuración aplicada:
```c
{51, 48, 57, 58, 67, 54},     // Fila 5: 6=51,7=48,8=57,9=58,0=67,BSPC=54
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{45, 55, 68, 61, 47, 70},     // Fila 7: H=45,J=55,K=68,L=61,;=47,'=70
{44, 60, 64, 65, 50, 71},     // Fila 8: N=44,M=60,,=64,.=65,/=50,-=71
{43, 52, 53, 62, 63, NO_LED}, // Fila 9: ENT=43,RGUI=52,NUM=53,RAISE=62,RALT=63
```

**Estrategia:** Rotar 2 posiciones (en vez de 1) en cada ciclo desde TEST11.
- Ciclo A (5): 6=51, L=61, ;=47, M=60, .=65
- Ciclo B (5): BSPC=54, K=68, J=55, /=50, ,=64  
- Ciclo C (3): H=45, N=44, RALT=63
- Ciclo D (3): '=70, -=71, ENTER=43

**Resultado:** 19 correctos ✅ ¡Ciclos C y D resueltos!
- Nuevos correctos: H, N, RALT, ', -, ENTER
- Ciclos A y B siguen rotando

---

### TEST 14 - Configuración aplicada (TEORÍA DEL USUARIO):
```c
{47, 48, 57, 58, 67, 68},     // Fila 5: 6=47,7=48,8=57,9=58,0=67,BSPC=68
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{45, 50, 55, 60, 65, 70},     // Fila 7: H=45,J=50,K=55,L=60,;=65,'=70
{44, 51, 54, 61, 64, 71},     // Fila 8: N=44,M=51,,=54,.=61,/=64,-=71
{43, 52, 53, 62, 63, NO_LED}, // Fila 9: ENT=43,RGUI=52,NUM=53,RAISE=62,RALT=63
```

**Estrategia:** Hipótesis del usuario - patrón secuencial/geométrico zig-zag por columnas.

Observación clave: Los LEDs parecen seguir un patrón matemático:
- Columna 0: 47, 46, 45, 44, 43 (decrece)
- Columna 1: 48, 49, 50, 51, 52 (crece)
- Columna 2: 57, 56, 55, 54, 53 (decrece)
- Columna 3: 58, 59, 60, 61, 62 (crece)
- Columna 4: 67, 66, 65, 64, 63 (decrece)
- Columna 5: 68, 69, 70, 71, NO_LED (crece)

**Cambios vs TEST 13:**
| Tecla | TEST13 | TEST14 |
|-------|--------|--------|
| 6 | 51 | 47 |
| BSPC | 54 | 68 |
| J | 55 | 50 |
| K | 68 | 55 |
| L | 61 | 60 |
| ; | 47 | 65 |
| M | 60 | 51 |
| , | 64 | 54 |
| . | 65 | 61 |
| / | 50 | 64 |

**Los 19 correctos NO se modifican.**

**Resultado:** ✅ **29/29 CORRECTOS - 100% COMPLETADO** 🎉

---

## RESUMEN DE LEDs POR TECLA (lado derecho)

| Tecla | Pos | TEST5 | TEST6 | TEST7 | TEST8 | TEST9 | TEST10 | TEST11 |
|-------|-----|-------|-------|-------|-------|-------|--------|--------|
| 6 | [5][0] | 60 | 60 | 61 | 51 | 60 | 60 | **65** |
| 7 | [5][1] | 49 | 49 | 48 | 48 | 48 | 49 | 48 |
| 8 | [5][2] | 57 | 57 | 57 | 57 | 57 | 57 | 57 |
| 9 | [5][3] | 58 | 58 | 58 | 58 | 58 | 58 | 58 |
| 0 | [5][4] | 66 | 66 | 67 | 67 | 67 | 66 | 67 |
| BSPC | [5][5] | 54 | 54 | 55 | 50 | 54 | 54 | **64** |
| Y | [6][0] | 46 | 46 | 46 | 46 | 46 | 46 | 46 |
| U | [6][1] | 48 | 67 | 49 | 49 | 49 | 48 | 49 |
| I | [6][2] | 53 | 53 | 56 | 56 | 56 | 53 | 56 |
| O | [6][3] | 62 | 62 | 59 | 59 | 59 | 62 | 59 |
| P | [6][4] | 67 | 67 | 66 | 66 | 66 | 67 | 66 |
| GRV | [6][5] | 69 | 69 | 69 | 69 | 69 | 69 | 69 |
| H | [7][0] | 44 | 44 | 44 | 63 | 44 | 44 | 63 |
| J | [7][1] | 55 | 55 | 64 | 54 | 55 | 55 | **68** |
| K | [7][2] | 68 | 68 | 50 | 64 | 68 | 68 | 54 |
| L | [7][3] | 65 | 65 | 47 | 61 | 65 | 65 | 51 |
| ; | [7][4] | 51 | 55 | 60 | 47 | 51 | 51 | **61** |
| ' | [7][5] | 43 | 43 | 43 | 71 | 43 | 43 | 71 |
| N | [8][0] | 63 | 63 | 63 | 45 | 63 | 63 | 45 |
| M | [8][1] | 61 | 61 | 65 | 60 | 61 | 61 | **47** |
| , | [8][2] | 64 | 64 | 68 | 55 | 64 | 64 | **50** |
| . | [8][3] | 47 | 47 | 51 | 65 | 47 | 47 | **60** |
| / | [8][4] | 50 | 50 | 54 | 68 | 50 | 50 | **55** |
| - | [8][5] | 70 | 63 | 70 | 43 | 70 | 70 | 43 |
| ENT | [9][0] | 71 | 71 | 71 | 70 | 71 | 71 | 70 |
| RGUI | [9][1] | 52 | 52 | 52 | 52 | 52 | 52 | 52 |
| NUM | [9][2] | 56 | 56 | 53 | 53 | 53 | 56 | 53 |
| RAISE | [9][3] | 59 | 59 | 62 | 62 | 62 | 59 | 62 |
| RALT | [9][4] | 45 | 45 | 45 | 44 | 45 | 45 | 44 |

**Nota TEST11:** Valores en **negrita** son nuevos (no probados antes). Mantiene los 13 correctos de TEST7-9.

---

### TEST 12 - Configuración aplicada:
```c
{61, 48, 57, 58, 67, 55},     // Fila 5: 6=61,7=48,8=57,9=58,0=67,BSPC=55
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{44, 64, 50, 47, 60, 43},     // Fila 7: H=44,J=64,K=50,L=47,;=60,'=43
{63, 65, 68, 51, 54, 70},     // Fila 8: N=63,M=65,,=68,.=51,/=54,-=70
{71, 52, 53, 62, 45, NO_LED}, // Fila 9: ENT=71,RGUI=52,NUM=53,RAISE=62,RALT=45
```

**Lógica:** Rotar ciclo 16 basado en TEST11. Cada tecla toma LED de quien la enciende.

| Tecla | Encendida por (TEST11) | LED que toma |
|-------|------------------------|--------------|
| 6 | ; | 61 |
| M | 6 | 65 |
| L | M | 47 |
| . | L | 51 |
| ; | . | 60 |
| BSPC | / | 55 |
| J | BSPC | 64 |
| , | J | 68 |
| K | , | 50 |
| / | K | 54 |
| H | RALT | 44 |
| N | H | 63 |
| RALT | N | 45 |
| ' | - | 43 |
| ENTER | ' | 71 |
| - | ENTER | 70 |

**Resultado:** 13 correctos (igual que TEST7)

---

## ✅ MATRIZ FINAL - LADO DERECHO COMPLETADO

**TEST 14 - Teoría del usuario: Patrón secuencial zig-zag por columnas**

```c
// LADO DERECHO - CONFIGURACIÓN FINAL (29/29 correctos)
{47, 48, 57, 58, 67, 68},     // Fila 5: 6=47,7=48,8=57,9=58,0=67,BSPC=68
{46, 49, 56, 59, 66, 69},     // Fila 6: Y=46,U=49,I=56,O=59,P=66,GRV=69
{45, 50, 55, 60, 65, 70},     // Fila 7: H=45,J=50,K=55,L=60,;=65,'=70
{44, 51, 54, 61, 64, 71},     // Fila 8: N=44,M=51,,=54,.=61,/=64,-=71
{43, 52, 53, 62, 63, NO_LED}, // Fila 9: ENT=43,RGUI=52,NUM=53,RAISE=62,RALT=63
```

### Patrón descubierto:

El PCB del Sofle RGB tiene un cableado de LEDs en patrón **zig-zag por columnas**:

| Columna | LEDs (de arriba a abajo) | Dirección |
|---------|--------------------------|-----------|
| 0 | 47 → 46 → 45 → 44 → 43 | ↓ Decrece |
| 1 | 48 → 49 → 50 → 51 → 52 | ↓ Crece |
| 2 | 57 → 56 → 55 → 54 → 53 | ↓ Decrece |
| 3 | 58 → 59 → 60 → 61 → 62 | ↓ Crece |
| 4 | 67 → 66 → 65 → 64 → 63 | ↓ Decrece |
| 5 | 68 → 69 → 70 → 71 → NO_LED | ↓ Crece |

### Lección aprendida:

Después de 13 tests rotando ciclos, el usuario propuso buscar un **patrón geométrico** 
en vez de seguir rotando. El "ojo porcentaje" le ganó al método de prueba y error.

🍺 Se le debe una birra virtual al usuario.
