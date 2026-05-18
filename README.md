# Tarea 01 — Correcciones ELO20225 (2026-01)

Repositorio de corrección para las entregas de la **Tarea 01** de ELO20225.  
Contiene **19 grupos** extraídos y organizados desde el paquete de entregas de Moodle.

---

## Estructura

```
tarea01-correcciones/
├── grupo-01/
│   ├── informe.pdf
│   ├── parte1/
│   │   ├── Makefile
│   │   └── sensores.cc
│   └── parte2/
│       ├── Makefile
│       └── mediciones.cc
├── grupo-02/ ...
...
└── grupo-20/
```

Cada carpeta `grupo-XX/` contiene la entrega tal como fue recibida (sin modificaciones de contenido).  
Solo se eliminaron archivos de sistema irrelevantes (`.DS_Store`, `__MACOSX`, `desktop.ini`, `._*`).

---

## Grupos entregados

| Grupo | Informe | Parte 1 | Parte 2 | Anomalías |
|-------|---------|---------|---------|-----------|
| 01 | informe.pdf | sensores.cc | mediciones.cc | — |
| 02 | informe.pdf | sensores.cc | mediciones.cc | — |
| 03 | informe.pdf | sensores.cc | mediciones.cc | — |
| 04 | Tarea 1.docx | sensores.cc | mediciones.cc | Sin carpetas parte1/parte2; informe en .docx |
| 05 | tarea01-grupo5.pdf | sensores.c + main.c | mediciones.c | Usa C (no C++); incluye header sensores.h |
| 06 | informe.pdf | sensores.cc | mediciones.cc | — |
| 07 | informe.pdf | sensores.cc | mediciones.cc | Makefile con extensión .txt |
| 08 | informe.pdf | sensores.cc | mediciones.cc | — |
| 09 | informe.pdf | sensores.cc | mediciones.cc | Makefile con espacios en el nombre |
| 10 | informe.pdf | sensores.cc | mediciones.cc | — |
| 11 | informe.docx | sensores.cc | mediciones.c | Informe en .docx; Makefile parte2 con .txt |
| 12 | Tarea1Elo.pdf | sensores.cpp | mediciones.cpp | Extensión .cpp en lugar de .cc |
| 13 | Informe Tarea 1.pdf | solucion_sensores.cc + diagrama .puml | solucion_mediciones.cc + diagrama .puml | Nombres de carpetas distintos; incluye diagramas PlantUML |
| 14 | informe.pdf | sensores.cc | mediciones.cc | Makefile como .exe |
| 15 | tarea01-informe.pdf | SENSORES2.CC | mediciones.cc | Makefile con .txt; nombre en mayúsculas |
| 17 | INFORME.pdf | Tarea1PPOO_ParteA.c | mediciones.cc | Parte 1 en C (no C++); binario compilado incluido |
| 18 | Informe.pdf | sensores.cc | mediciones.cc | — |
| 19 | informe.pdf | sensores.cc | mediciones.cc | Makefile con .txt; carpetas con espacios |
| 20 | tarea01 PPOO 2.0.pdf | sensores.cpp | mediciones2.cc | Makefile con .txt; extensión .cpp; nombre distinto en parte2 |

> **Nota:** No hay entrega del **grupo 16**.

---

## Guía de corrección

### Criterios a revisar (por completar con la pauta del profesor)

- [ ] Informe presente y en formato correcto
- [ ] Parte 1: implementación de `sensores`
- [ ] Parte 2: implementación de `mediciones`
- [ ] Makefile funcional
- [ ] Uso correcto de C++ (`.cc` / `.cpp`)
- [ ] ...

### Calificaciones

Ver archivo [`calificaciones.md`](./calificaciones.md) para registrar notas y comentarios por grupo.

---

## Cómo usar este repositorio

```bash
# Clonar
git clone <url-del-repo>

# Ver el código de un grupo
cd grupo-01/parte1
cat sensores.cc

# Compilar (si el Makefile está bien)
make
```
