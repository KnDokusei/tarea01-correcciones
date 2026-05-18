#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/sensores.h" // Asegúrate que la ruta sea correcta

#define NUM_SENSORES 10 // Aquí definimos la constante correctamente

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sensores[NUM_SENSORES];

    // Llamamos a las funciones del módulo
    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    return 0;
}