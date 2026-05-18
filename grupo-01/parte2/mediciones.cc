#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// No modificar la siguiente estructura enum.
typedef enum {
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE
} caso_t;

/*
    Función que realiza la medición de la duración de un
    ciclo for de 1e8 iteraciones, donde cada iteración 
    muestra el caracter '*'
*/
double cicloPrueba(caso_t caso){
    double tiempoPromedio;
    double cantidadIteraciones;
    clock_t inicio, fin; 
    double tiempoTotal;

    tiempoPromedio      = 0.0;
    cantidadIteraciones = 1e8; 

    inicio = clock(); 
    for(int64_t i = 0; i < (int64_t)cantidadIteraciones; i++)
    {
        switch(caso)
        {
            case VACIO:
                // Operación nula para medir el overhead del ciclo
                break;
            case ESPACIO:
                printf(" ");
                break;
            case ASTERISCO:
                printf("*");
                break;
            case NEWLINE:
                printf("\n");
                break;
        }
    }
    fin = clock(); 

    // En el contenido debe estar explicado el cast entre tipo de datos.
    // Se transforma la diferencia de ticks a segundos y luego a nanosegundos (1e9).
    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;

    // Tiempo promedio por cada iteración individual
    tiempoPromedio = tiempoTotal / cantidadIteraciones;

    return tiempoPromedio;
}

int main(int argc, char* argv[]) {

    // No modificar las siguientes líneas
    double casos[4];
    casos[VACIO] = cicloPrueba(VACIO);
    casos[ESPACIO] = cicloPrueba(ESPACIO);
    casos[ASTERISCO] = cicloPrueba(ASTERISCO);
    casos[NEWLINE] = cicloPrueba(NEWLINE);

    printf("=== Mediciones realizadas ===\n");
    printf("VACIO     : Tiempo promedio %f [ns]\n", casos[VACIO]);
    printf("ESPACIO   : Tiempo promedio %f [ns]\n", casos[ESPACIO]);
    printf("ASTERISCO : Tiempo promedio %f [ns]\n", casos[ASTERISCO]);
    printf("NEWLINE   : Tiempo promedio %f [ns]\n", casos[NEWLINE]);
    
    exit(EXIT_SUCCESS);
}