#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

enum Accion {

    //Se les dan nombre a los 3 estados de análisis de datos para que asi sea más facil llamarlos dentro de la función main.
    INIT, //valor 0, datos iniciales
    READ, //valor 1, lee datos
    SHOW  //valor 2, datos finales
    
//Completar código
};

double lecturaSensor(){
    return (double)(rand() % 256);

/*
Descripción:
    Función que actúa como interfaz para los sensores 
    del sistema.
Entradas:
    sensores[]: arreglo de sensores. Cada elemento del arreglo representa el 
                valor del dato que tiene un determinado sensor.
    acciones  : enum Accion {INIT, READ, SHOW}

*/
}
void usarSensores(int sensores[], Accion acc) {
    //Aca se define el trabajo a realizar en cada uno de los 3 estados definidos en la función num. 
    switch (acc) {
        case INIT:
            // Ponemos todos los sensores en 0
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = 0;
            }
            printf("Sensores inicializados.\n");
            break;

        case READ:
            // Llenamos el arreglo con lecturas aleatorias
            for (int i = 0; i < NUM_SENSORES; i++) {
                
                sensores[i] = (int)lecturaSensor();
            }
            printf("Lectura de sensores completada.\n");
            break;

        case SHOW:
            // Imprimimos los valores actuales
            printf("--- Datos de Sensores ---\n");
            for (int i = 0; i < NUM_SENSORES; i++) {
                printf("Sensor %i: %i [mV]\n", i, sensores[i]);
            }
            break;
            
        default:
            printf("Acción no reconocida.\n");
            break;
    }
    // Recomendación, utilizar instrucción switch en vez de if anidados.
}



int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sensores[NUM_SENSORES];

    //Se lleva todo el trabajo la función void de arriba

    usarSensores(sensores, INIT); // Inicializa
    usarSensores(sensores, READ); // Lee
    usarSensores(sensores, SHOW); // Muestra

    exit(EXIT_SUCCESS);
}
