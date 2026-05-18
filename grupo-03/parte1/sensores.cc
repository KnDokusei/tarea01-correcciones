#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema.
// No es necesario modificar su valor.
const int NUM_SENSORES = 10;

// Prototipo de la función que simula la lectura física de un sensor.
double lecturaSensor();

/*
Descripción:
    Acciones disponibles para la interfaz de sensores.
    INIT: inicializa el arreglo de sensores en cero.
    READ: realiza una lectura simulada para cada sensor.
    SHOW: muestra en pantalla los valores almacenados.
*/
enum Accion {
    INIT,
    READ,
    SHOW
};

/*
Descripción:
    Función que actúa como interfaz para los sensores del sistema.
Entradas:
    sensores[]: arreglo de sensores. Cada elemento representa el valor de un sensor.
    acc       : acción a realizar sobre el arreglo de sensores.
*/
void usarSensores(int sensores[], Accion acc) {
    switch (acc) {
        case INIT:
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = 0;
            }
            break;

        case READ:
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = (int) lecturaSensor();
            }
            break;

        case SHOW:
            for (int i = 0; i < NUM_SENSORES; i++) {
                printf("Sensor %i: %i [mV]\n", i, sensores[i]);
            }
            break;
    }
}

/*
Descripción:
    Módulo que simula la lectura de un sensor. La lectura es un número
    entero en el rango [0,255].
Entradas:
    No tiene.
Salida:
    Retorna un número aleatorio en el rango [0,255].
*/
double lecturaSensor() {
    double lecturaAleatoria;

    // Número aleatorio entero entre 0 y 255.
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sensores[NUM_SENSORES];

    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}
