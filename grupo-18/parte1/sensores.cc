#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

enum Accion {
    INIT,
    SHOW,
    READ,
};

double lecturaSensor(){
    double lecturaAleatoria;
    lecturaAleatoria = rand() % 256;//Función que retorna un valor aleatorio double
    return lecturaAleatoria;
}

void usarSensores(int sensores[], enum Accion acc) {
    switch (acc) {

        case INIT:
            for (int i = 0; i < NUM_SENSORES; i++) {
        sensores[i] = 0;
        }
                        break;
        case READ:
            for (int i = 0; i < NUM_SENSORES; i++) {
        sensores[i] = lecturaSensor();
        }
                        break;
        case SHOW:
            for (int i = 0; i < NUM_SENSORES; i++) {
        printf("Sensor %i: %i [mV]\n", i, sensores[i]); 
        }
                        break;


    }

}
int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sensores[NUM_SENSORES];

    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}
