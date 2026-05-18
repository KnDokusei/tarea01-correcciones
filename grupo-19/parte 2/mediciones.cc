#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
    NEWLINE
};

double cicloPrueba(caso_t caso){
    double tiempoPromedio;
    double tiempoTotal;
    int64_t cantidadIteraciones;
    uint64_t inicio, fin;

    tiempoPromedio      = 0.0;
    cantidadIteraciones = 1e8;
    tiempoTotal = 0;

    if(caso == VACIO){

        inicio = clock();
        for(int t=0; t<cantidadIteraciones; t++){
            ;
        }
        fin = clock();
    }
    else if (caso == ESPACIO)
    {
        inicio = clock();
        for(int t=0; t<cantidadIteraciones; t++){
            printf(" ");
        }
        fin = clock();
    }
    else if (caso == ASTERISCO)
    {   
        inicio = clock();
        for(int t=0; t<cantidadIteraciones; t++){
            printf("*");
        }
        fin = clock();
    }
    else if (caso == NEWLINE){

        inicio = clock();
        for(int t=0; t<cantidadIteraciones; t++){
            printf("\n");
        }
        fin = clock();
    }
    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
    tiempoPromedio = tiempoTotal/cantidadIteraciones;

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

