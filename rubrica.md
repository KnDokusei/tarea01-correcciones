# Rúbrica de Evaluación — Tarea 01
## ELO20225 Programación Procedural y Orientada a Objetos · Semestre 1, 2026

> **Escala:** 1.0 – 7.0  
> **Puntaje total:** 100 pts → nota final con escala lineal (0 pts = 1.0, 100 pts = 7.0)  
> **Fórmula:** `Nota = 1.0 + (puntaje / 100) * 6.0`

---

## Distribución de puntaje

| Sección | Ítem | Pts |
|---------|------|-----|
| **Informe** | Estructura y formato | 10 |
| **Parte 1** | `enum Accion` | 5 |
| **Parte 1** | `usarSensores()` — implementación | 15 |
| **Parte 1** | `usarSensores()` — diagrama de flujo | 10 |
| **Parte 1** | Nueva `main()` | 5 |
| **Parte 2 · Hito 1** | Preguntas sobre `cicloEjemplo()` | 15 |
| **Parte 2 · Hito 2** | `cicloPrueba()` — implementación | 10 |
| **Parte 2 · Hito 2** | `cicloPrueba()` — diagrama de flujo | 10 |
| **Parte 2 · Hito 3** | Tabla de mediciones (10 ejecuciones) | 10 |
| **Parte 2 · Hito 3** | Análisis de resultados | 10 |
| | **TOTAL** | **100** |

---

## 1. Informe (10 pts)

Evalúa el documento entregado (PDF o DOCX) en relación a la plantilla proporcionada.

| Criterio | Pts máx | Descripción |
|----------|---------|-------------|
| Estructura completa | 4 | Contiene portada, Parte 1, Parte 2 con sus hitos, y Anexo A |
| Redacción y claridad | 3 | El texto explica el código en lenguaje natural (no solo muestra el código) |
| Formato aceptable | 2 | Usa la plantilla del curso; figuras numeradas y referenciadas en el texto |
| Datos del grupo | 1 | Nombres y correos de los integrantes presentes |

**Observaciones sobre formato:**
- Informe en `.docx` sin convertir a PDF → descontar 1 pt
- Sin informe → 0 pts en esta sección y también en los ítems que requieren explicación (diagramas)

---

## 2. Parte 1 — Programación modular (35 pts)

### 2.1 `enum Accion` (5 pts)

El enum debe tener exactamente los valores `INIT`, `READ`, `SHOW`.

| Pts | Criterio |
|-----|----------|
| 5 | Definido correctamente con los 3 valores |
| 3 | Definido pero con nombre o valores incorrectos / incompletos |
| 0 | Ausente o completamente incorrecto |

### 2.2 `usarSensores()` — implementación (15 pts)

La función debe recibir `int sensores[]` y `Accion acc`, y usar `switch` (no `if` anidados).

| Pts | Criterio |
|-----|----------|
| **INIT** (5 pts) | |
| 5 | Inicializa todos los elementos del arreglo a 0 correctamente |
| 3 | Inicializa pero con errores menores (límites, índice) |
| 0 | No implementado o incorrecto |
| **READ** (5 pts) | |
| 5 | Lee todos los sensores llamando a `lecturaSensor()` correctamente |
| 3 | Lee parcialmente o con errores menores |
| 0 | No implementado o incorrecto |
| **SHOW** (5 pts) | |
| 5 | Muestra todos los valores con formato igual o equivalente al original (`Sensor %i: %i [mV]`) |
| 3 | Muestra valores pero con formato distinto o errores menores |
| 0 | No implementado o incorrecto |

**Penalizaciones:**
- Usa `if`/`else if` en vez de `switch` → −2 pts
- No compila → máximo 3 pts en esta sección (se evalúa intención del código)

### 2.3 Diagrama de flujo de `usarSensores()` (10 pts)

Debe estar en formato PlantUML (`.puml`) y explicado en el informe.

| Pts | Criterio |
|-----|----------|
| 4 | Diagrama correcto en PlantUML (`.puml` presente en la entrega) |
| 3 | Diagrama correcto pero en otro formato (imagen, draw.io, etc.) |
| 3 | Explicación en texto del informe coherente con el diagrama |
| 0 | Sin diagrama |

> ℹ️ Si el grupo no entregó `.puml` pero tiene imagen del diagrama en el informe, se evalúa con el criterio de 3 pts para el diagrama y se mantienen los 3 pts de explicación.

### 2.4 Nueva `main()` (5 pts)

La nueva `main()` debe usar exclusivamente las llamadas `usarSensores(sensores, INIT)`, `usarSensores(sensores, READ)`, `usarSensores(sensores, SHOW)`.

| Pts | Criterio |
|-----|----------|
| 5 | Exactamente igual a lo pedido; el programa ejecuta y produce salida correcta |
| 3 | Estructura correcta pero con llamadas adicionales o comentarios del código viejo |
| 1 | Intento visible pero incorrecto |
| 0 | No modificó la `main()` o dejó el código original |

---

## 3. Parte 2 — Mediciones de tiempo (55 pts)

### 3.1 Hito 1 — Análisis de `cicloEjemplo()` (15 pts, 3 pts c/u)

Cada pregunta vale 3 puntos: 3 = correcto, 1-2 = parcialmente correcto, 0 = incorrecto/ausente.

| # | Pregunta | Respuesta esperada |
|---|----------|--------------------|
| 1 | ¿Qué retorna `clock()`? | Retorna el tiempo de CPU consumido por el proceso desde su inicio, en unidades de `clock_t` |
| 2 | ¿Qué unidades tienen `inicio` y `fin`? | Unidades de reloj del procesador (`clock ticks`), **no** segundos |
| 3 | ¿Por qué dividir por `CLOCKS_PER_SEC`? | Para convertir de ticks de reloj a segundos; `CLOCKS_PER_SEC` indica cuántos ticks hay en un segundo |
| 4 | ¿Qué hace `(double)` como prefijo? | Es un *cast* explícito que convierte el resultado de `(fin - inicio)` de `uint64_t`/`clock_t` a `double` |
| 5 | ¿Para qué sirve ese `(double)`? | Evita división entera; sin el cast, si `(fin - inicio)` fuera entero y `CLOCKS_PER_SEC` también, el resultado se truncaría perdiendo precisión decimal |

> ℹ️ Preguntas 4 y 5 son distintas: la 4 pide *qué hace* (mecánica del cast) y la 5 pide *para qué sirve* (propósito/utilidad). Si el grupo da la misma respuesta para ambas, evaluar con criterio: si la respuesta única cubre ambas, dar 3+2; si solo cubre una, dar 3+0.

### 3.2 Hito 2 — `cicloPrueba()` implementación (10 pts)

La función debe medir el tiempo de un `for` de `1e8` iteraciones para cada caso del enum `caso_t`.

| Criterio | Pts |
|----------|-----|
| Estructura correcta: usa `clock()`, resta `fin - inicio`, divide por `CLOCKS_PER_SEC`, multiplica por `1e9`, divide por `cantidadIteraciones` | 4 |
| Maneja correctamente los 4 casos del enum con `switch` o equivalente | 4 |
| `VACIO` implementado con ciclo vacío (`;`) | 1 |
| Elimina la llamada a `cicloEjemplo()` de la `main()` (líneas que debían borrarse) | 1 |

**Penalizaciones:**
- No compila → máximo 2 pts (se evalúa intención)
- Usa `cantidadIteraciones = 1e6` en vez de `1e8` → −1 pt

### 3.3 Hito 2 — Diagrama de flujo de `cicloPrueba()` (10 pts)

Mismo criterio que el diagrama de la Parte 1 (sección 2.3).

| Pts | Criterio |
|-----|----------|
| 4 | Diagrama correcto en PlantUML (`.puml` presente) |
| 3 | Diagrama correcto en otro formato |
| 3 | Explicación en informe coherente con el diagrama |
| 0 | Sin diagrama |

### 3.4 Hito 3 — Tabla de mediciones (10 pts)

Deben presentar **10 ejecuciones** para cada uno de los 4 casos, más promedio y desviación estándar.

| Criterio | Pts |
|----------|-----|
| Tabla con 10 columnas de mediciones para los 4 casos | 4 |
| Columna de promedio calculada correctamente | 2 |
| Columna de desviación estándar calculada correctamente | 2 |
| Especifica características del computador y versión del compilador | 2 |

**Penalizaciones:**
- Menos de 10 ejecuciones → −1 pt por cada ejecución faltante (mínimo 0)
- Sin desviación estándar pero con promedio → máximo 6 pts

### 3.5 Hito 3 — Análisis de resultados (10 pts)

| Criterio | Pts |
|----------|-----|
| Identifica y explica la diferencia entre el ciclo `VACIO` y los ciclos con `printf` | 3 |
| Explica por qué `NEWLINE` tarda más que `ESPACIO` y `ASTERISCO` (flush de buffer / I/O) | 4 |
| Relaciona los resultados con el concepto de velocidad de memoria vs E/S (objetivo del curso) | 3 |

> ℹ️ El análisis clave es: `VACIO` ≈ acceso a memoria RAM; `ESPACIO`/`ASTERISCO` ≈ E/S con buffer; `NEWLINE` ≈ E/S con flush forzado → evidencia la diferencia de velocidades entre memoria y E/S.

---

## Resumen de penalizaciones globales

| Situación | Penalización |
|-----------|-------------|
| No compila ninguna de las dos partes | −10 pts adicionales |
| Código no es propio (copia entre grupos o generado sin comprensión) | Caso académico — consultar al profesor |
| Entrega tardía | Según reglamento del curso |
| `cicloEjemplo()` no eliminada de `main()` antes de entregar | −1 pt (ya incluido en 3.2) |
| Archivos de sistema innecesarios (`.exe`, `.DS_Store`, etc.) | Sin penalización en nota, anotar en observaciones |

---

## Conversión puntaje → nota

| Puntaje | Nota |
|---------|------|
| 100 | 7.0 |
| 92 | 6.5 |
| 83 | 6.0 |
| 75 | 5.5 |
| 67 | 5.0 |
| 58 | 4.5 |
| 50 | 4.0 ← aprobación |
| 42 | 3.5 |
| 33 | 3.0 |
| 25 | 2.5 |
| 17 | 2.0 |
| 8 | 1.5 |
| 0 | 1.0 |

---

*Rúbrica elaborada en base al enunciado del repositorio `gabriel-astudillo/ELO20225/tarea01` y la plantilla de informe oficial del curso.*
