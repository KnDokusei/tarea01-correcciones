#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

enum Accion {  //creamos el enum con los casos INIT, READ y SHOW
    INIT,
    READ,
    SHOW    
};

/*
Descripción:
    Función que actúa como interfaz para los sensores 
    del sistema.
Entradas:
    sensores[]: arreglo de sensores. Cada elemento del arreglo representa el 
                valor del dato que tiene un determinado sensor.
    acciones  : enum Accion {INIT, READ, SHOW}

*/

double lecturaSensor(); // declaramos la salida de lecturaSensor() como double para que sea reconocido en el switch

void usarSensores(int sensores[], Accion acc) {  

    switch (acc){
    case INIT:
        for(int i = 0; i < NUM_SENSORES; i++){  // usamremos NUMSENSORES y recorreremos el arreglo sensores[] con un entero i para dejar en 0 cada sensor
            sensores[i] = 0;
        }
        printf("Iniciando lectura de sensores.\n");
        break;
    
    case READ:
        for(int i = 0; i < NUM_SENSORES; i++){
            sensores[i] = lecturaSensor(); // a cada sensor del arreglo se le asignara un valor aleatorio desde la funcion lecturaSensor con un ciclo for
        }
        printf("La lectura de sensores esta completa\n");
        break;
    
    case SHOW:
        for (int i = 0, n = 1; i < NUM_SENSORES; i++, n++) {  // Creamos adicionalmente un contador n que vaya del 1 al 10 para numerar sensores
            printf("Sensor %i: %i [mV]\n", n, sensores[i]); // Mostramos cada valor del arreglo con otro ciclo for
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
double lecturaSensor(){  //Cambiamos el double por int, ya que todos los valores son numeros enteros
    double lecturaAleatoria;

    // número aleatorio entero entre 0 y 255
    lecturaAleatoria = rand() % 256;
    return lecturaAleatoria;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sensores[NUM_SENSORES];

// Cambiamos el main que contenia muchos ciclos por el llamado de la funcion usarSensores

    usarSensores(sensores, INIT); 
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}
