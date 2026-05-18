#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum {
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE
} caso_t;

/*
    Funcion que mide tiempo promedio
    por iteracion en nanosegundos
*/
double cicloPrueba(caso_t caso) {

    long long cantidadIteraciones;

    /*
        Muchas iteraciones para el ciclo vacio
        y menos para printf para no congelar
        la consola.
    */
    if(caso == VACIO) {
        cantidadIteraciones = 100000000;
    }
    else {
        cantidadIteraciones = 10000;
    }

    clock_t inicio;
    clock_t fin;

    inicio = clock();

    switch(caso) {

        case VACIO:

            for(long long i = 0; i < cantidadIteraciones; i++) {
                ;
            }

            break;

        case ESPACIO:

            for(long long i = 0; i < cantidadIteraciones; i++) {
                printf(" ");
            }

            break;

        case ASTERISCO:

            for(long long i = 0; i < cantidadIteraciones; i++) {
                printf("*");
            }

            break;

        case NEWLINE:

            for(long long i = 0; i < cantidadIteraciones; i++) {
                printf("\n");
            }

            break;
    }

    fin = clock();

    /*
        Tiempo total en nanosegundos
    */
    double tiempoTotal =
        ((double)(fin - inicio) / CLOCKS_PER_SEC) * 1e9;

    /*
        Tiempo promedio por iteracion
    */
    double tiempoPromedio =
        tiempoTotal / (double)cantidadIteraciones;

    return tiempoPromedio;
}

int main() {

    double tiempoVacio;
    double tiempoEspacio;
    double tiempoAsterisco;
    double tiempoNewline;

    printf("====================================\n");
    printf("MEDICION DE TIEMPOS\n");
    printf("====================================\n\n");

    tiempoVacio = cicloPrueba(VACIO);
    printf("\nVACIO terminado\n");

    tiempoEspacio = cicloPrueba(ESPACIO);
    printf("\nESPACIO terminado\n");

    tiempoAsterisco = cicloPrueba(ASTERISCO);
    printf("\nASTERISCO terminado\n");

    tiempoNewline = cicloPrueba(NEWLINE);
    printf("\nNEWLINE terminado\n");

    printf("\n====================================\n");
    printf("RESULTADOS\n");
    printf("====================================\n\n");

    printf("VACIO      : %.6f ns\n", tiempoVacio);
    printf("ESPACIO    : %.6f ns\n", tiempoEspacio);
    printf("ASTERISCO  : %.6f ns\n", tiempoAsterisco);
    printf("NEWLINE    : %.6f ns\n", tiempoNewline);

    return 0;
}