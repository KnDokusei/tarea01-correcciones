#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
const int NUM_SENSORES = 10;

// Enum con las acciones que puede realizar usarSensores()
enum Accion {
    INIT,   // Inicializar sensores a 0
    READ,   // Leer valores de los sensores
    SHOW    // Mostrar resultados
};

// Prototipo de función (declaración anticipada)
double lecturaSensor();

/*
Descripción:
    Función que actúa como interfaz para los sensores del sistema.
Entradas:
    sensores[]: arreglo de sensores. Cada elemento del arreglo representa el 
                valor del dato que tiene un determinado sensor.
    acc       : enum Accion {INIT, READ, SHOW}
*/
void usarSensores(int sensores[], enum Accion acc) {
    switch(acc) {
        case INIT:
            // Inicializar todos los sensores a 0
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = 0;
            }
            break;
            
        case READ:
            // Realizar lectura de cada sensor
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = (int)lecturaSensor();
            }
            break;
            
        case SHOW:
            // Mostrar los resultados
            for (int i = 0; i < NUM_SENSORES; i++) {
                printf("Sensor %i: %i [mV]\n", i, sensores[i]);
            }
            break;
            
        default:
            printf("Error: Acción no válida\n");
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
double lecturaSensor() {
    double lecturaAleatoria;
    // número aleatorio entero entre 0 y 255
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}

int main(int argc, char* argv[]) {
    // Inicializar semilla de números aleatorios
    srand(time(NULL));
    
    int sensores[NUM_SENSORES];
    
    // Versión MODULAR del programa
    usarSensores(sensores, INIT);   // Inicializar sensores a 0
    usarSensores(sensores, READ);   // Leer valores de sensores
    usarSensores(sensores, SHOW);   // Mostrar resultados

    exit(EXIT_SUCCESS);
}