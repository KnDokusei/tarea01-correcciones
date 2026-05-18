#ifndef SENSORES_H
#define SENSORES_H

typedef enum {
    INIT,
    READ,
    SHOW
} Accion;

void usarSensores(int sensores[], Accion acc);
double lecturaSensor(void);

#endif