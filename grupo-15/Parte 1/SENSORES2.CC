#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_SENSORES = 100;
enum Accion {INIT, READ, SHOW};

double lecturaSensor(){
    double lecturaAleatoria;
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}

void usarSensores(int sensores[], Accion acc) {
    switch (acc)
    {
    case INIT:
        for (int i=0; i< NUM_SENSORES;i++){
            sensores[i]=0;                    
        }
        /* code */
        break;
    case READ:
        for (int i=0; i< NUM_SENSORES;i++){
            sensores[i]=lecturaSensor();
        }
        break;
    case SHOW:
        for (int i=0; i< NUM_SENSORES;i++){
            printf("Sensor %i: %i [mV]\n", i, sensores[i]);
        }
        break;
    default:
        printf("Acción no válida\n");
        break;
    }
    // Completar código.
    // Recomendación, utilizar instrucción switch en vez de if anidados.
}

int main(int argc, char* argv[]) {
    int sensores[NUM_SENSORES];
    
    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}

