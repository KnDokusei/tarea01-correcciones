#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parámetros de configuración del sistema
// No es necesario modificar su valor
const int NUM_SENSORES = 10;

// Se definen las acciones que puede tomar la función usarSensores
typedef enum Accion
{
    INIT,
    READ,
    SHOW
} Accion;

/*
Descripción:
    simula la lectura de un sensor. La lectura es un número
    entero en el rango [0,255]
Entradas:
    No tiene
Salida:
    retorna un número aleatorio en el rango [0,255]
*/
double lecturaSensor()
{
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
    acc       : enum Accion {INIT, READ, SHOW}
*/
void usarSensores(int sensores[], Accion acc)
{
    // utilizamos un switch para evaluar la acción solicitada
    switch (acc)
    {
    case INIT:
        for (int i = 0; i < NUM_SENSORES; i++)
        {
            sensores[i] = 0;
        }
        break;

    case READ:
        for (int i = 0; i < NUM_SENSORES; i++)
        {
            // se pasa a int
            sensores[i] = (int)lecturaSensor();
        }
        break;

    case SHOW:
        for (int i = 0; i < NUM_SENSORES; i++)
        {
            printf("Sensor %i: %i [mV]\n", i, sensores[i]);
        }
        break;
    }
}

int main(int argc, char *argv[])
{
    // crea numeros aleatorios
    srand(time(NULL));

    int sensores[NUM_SENSORES];

    // reemplaza los bucles originales
    usarSensores(sensores, INIT);
    usarSensores(sensores, READ);
    usarSensores(sensores, SHOW);

    exit(EXIT_SUCCESS);
}