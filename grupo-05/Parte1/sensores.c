#include <stdio.h>
#include <stdlib.h>
#include "include/sensores.h" // La ruta debe ser igual que en el main

const int NUM_SENSORES = 10;

// La función debe ir ARRIBA para que usarSensores la conozca
double lecturaSensor(void){
    double lecturaAleatoria;
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}

void usarSensores(int sensores[], Accion acc) {
    switch (acc)
    {
    case INIT:
        for (int i = 0; i < NUM_SENSORES; i++)
        {
            sensores[i] = 0;
        }
        break;
    case READ:
        for (int i = 0; i < NUM_SENSORES; i++)
        {
            sensores[i] = (int)lecturaSensor();
        }
        break;
    case SHOW:
        for (int i = 0; i < NUM_SENSORES; i++)
        {
            printf("Sensor %i: %i [mV]\n", i, sensores[i]);
        }
        break;
    }
}