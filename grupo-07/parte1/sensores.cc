#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

// Acciones disponibles para trabajar con los sensores
enum Accion {
    INIT, READ, SHOW
};

double lecturaSensor();

// Función principal para manejar los sensores
void usarSensores(int sensores[], Accion acc) {
    switch(acc) {
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

/*
Descripción:
    módulo que simula la lectura de un sensor. La lectura es un número
    entero en el rango [0,255]
Entradas:
    No tiene
Salida:
    Retorna un número aleatorio en el rango [0,255]
*/
double lecturaSensor(){
    double lecturaAleatoria;

    // número aleatorio entero entre 0 y 255
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}

// Ejecuta las acciones principales
int main(int argc, char* argv[]) {
    int sensores[NUM_SENSORES];
    
    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}