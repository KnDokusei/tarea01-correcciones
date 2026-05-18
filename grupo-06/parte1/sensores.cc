#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

enum Accion {
    INIT, READ, SHOW
    //Completar código
};

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
/*
Descripción:
    Función que actúa como interfaz para los sensores 
    del sistema.
Entradas:
    sensores[]: arreglo de sensores. Cada elemento del arreglo representa el 
                valor del dato que tiene un determinado sensor.
    acciones  : enum Accion {INIT, READ, SHOW}

*/
void usarSensores(int sensores[], Accion acc) {
    switch (acc){
        // Inicializar los sensores
        case INIT:
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = 0;
            }
            break;
        // Realizar lectura de los sensores
        case READ:
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = lecturaSensor();
            }
            break;
        // Mostrar los resultados
        case SHOW:
            for (int i = 0; i < NUM_SENSORES; i++) {
                printf("Sensor %i: %i [mV]\n", i, sensores[i]); 
            }
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


