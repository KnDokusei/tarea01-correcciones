#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_SENSORES = 10;

enum Accion {
    INIT,
    READ,
    SHOW
};

void usarSensores(int sensores[], enum Accion acc) {
    switch (acc) {
        case INIT:
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = 0;
            }
            printf("Sistema: Sensores inicializados.\n");
            break;

        case READ:
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = (int)lecturaSensor();
            }
            printf("Sistema: Lectura de sensores completada.\n");
            break;

        case SHOW:
            printf("--- Valores de Sensores ---\n");
            for (int i = 0; i < NUM_SENSORES; i++) {
                printf("Sensor %i: %i [mV]\n", i, sensores[i]);
            }
            break;

        default:
            printf("Error: Accion no reconocida.\n");
            break;
    }
}

double lecturaSensor(){
    double lecturaAleatoria;
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}


int main(int argc, char* argv[]) {
    int sensores[NUM_SENSORES];
    
    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}

