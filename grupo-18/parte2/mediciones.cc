#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

/*
    Función que realiza la medición de la duración de un
    ciclo for de 1e6 iteraciones, donde cada iteración 
    muestra el caracter '*'
*/
double cicloEjemplo(){
    int64_t cantidadIteraciones;
    double tiempoTotal;
    uint64_t inicio, fin;

    cantidadIteraciones = 1e6;
    tiempoTotal = 0.0;

    inicio = clock(); 
    for(int64_t i=0; i<cantidadIteraciones; i++)
    {
        printf("*");
    }
    fin = clock(); 
    printf("\n");

    // En el contenido debe estar explicado el cast entre tipo de datos.
    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;

    double tiempoPromedio = tiempoTotal / cantidadIteraciones;

    return tiempoPromedio;
}

// No modificar la siguiente estructura enum.
enum caso_t{
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE,
};

double cicloPrueba(caso_t caso){
    double tiempoPromedio;
    double cantidadIteraciones;

    tiempoPromedio      = 0.0;
    cantidadIteraciones = 1e6;
    uint64_t inicio, fin;

    switch (caso){

        case VACIO:
            inicio = clock(); 
            for(int64_t i = 0; i < cantidadIteraciones; i++){
            }
            fin = clock(); 
            printf("\n");
            tiempoPromedio = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;

                    break;

        case ESPACIO:
            inicio = clock(); 
            for(int64_t i = 0; i < cantidadIteraciones; i++){
                printf(" ");
            }
            fin = clock(); 
            printf("\n");
            tiempoPromedio = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
                    break;
            

        case ASTERISCO:
            inicio = clock();
            for(int64_t i=0; i < cantidadIteraciones; i++)            {
                printf("*");
            }
            fin = clock();
            tiempoPromedio = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
            break;


        case NEWLINE:
            inicio = clock();
            for(int64_t i=0; i < cantidadIteraciones; i++)            {
                printf("\n");
            }
            fin = clock();
            tiempoPromedio = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
            break;


    }
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

