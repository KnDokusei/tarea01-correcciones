#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>

enum caso_t{
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE
};

double cicloPrueba(caso_t caso){
    double tiempoPromedio;
    double cantidadIteraciones;
    double fin;
    tiempoPromedio      = 0.0;
    cantidadIteraciones = 1e7;
    double inicio = clock();


    for (int i=0; i<cantidadIteraciones; i++)
    {
        switch (caso)
        {
        case VACIO:
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
        
        default:
            break;
        }
    }

    fin = clock();
    tiempoPromedio = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
    tiempoPromedio /= cantidadIteraciones;
    return tiempoPromedio;

}


int main(int argc, char* argv[]) {
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

