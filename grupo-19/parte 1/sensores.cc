#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

enum Accion { // Declara variables para los estados
    INIT, // Modo: Inicializar
    READ, // Modo: Leer
    SHOW // Modo: Mostrar
};

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

/*
Descripción:
    Función que actúa como interfaz para los sensores 
    del sistema.
Entradas:
    sensores[]: arreglo de sensores. Cada elemento del arreglo representa el 
                valor del dato que tiene un determinado sensor.
    acciones  : enum Accion {INIT, READ, SHOW}

*/

void usarSensores(int sensores[], enum Accion acc) {
    static int estadoInit = 0; // Recuerda entre llamadas si ya se inicializaron los sensores
    static int estadoRead = 0; // Recuerda entre llamadas si ya se leyeron los seonsores
    
    switch(acc){

        case INIT: // Caso: INICIAR SENSORES
            estadoInit = 1;
            for (int i = 0; i < NUM_SENSORES; i++) {
                sensores[i] = 0;
            } 
            break;
        
        case READ: //Caso: LECTURA SENSORES
            if (estadoInit == 1){ // Si se inicializaron los sensores
                estadoRead = 1;
                for (int i = 0; i < NUM_SENSORES; i++) {
                    sensores[i] = lecturaSensor();
                }
            }
            else{ // Si NO se inicializaron los sensores
                printf("Primero debes iniciar los sensores antes de leer su valor\n");
            }
            break;
        
        case SHOW: // Caso: MOSTRAR LECTURAS
            if (estadoInit == 1 && estadoRead == 1){ // Si se leyeron los sensores
                for (int i = 0; i < NUM_SENSORES; i++) {
                    printf("Sensor %i: %i [mV]\n", i, sensores[i]);
                }
            }
            else{ // Si NO se leyeron los sensores
                printf("Primero debes leer los sensores antes de mostrarlos\n");
            }   
            break;
    }
}

int main(int argc, char* argv[]) {
    int sensores[NUM_SENSORES];
    
    usarSensores(sensores, INIT); // Aplica caso: INICIAR SENSORES
    usarSensores(sensores, READ); // Aplica caso: LECTURA SENSORES
    usarSensores(sensores, SHOW); // Aplica caso: MOSTRAR LECTURAS

    exit(EXIT_SUCCESS); // Cierra el programa
}