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

    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
    double tiempoPromedio = tiempoTotal / cantidadIteraciones;

    return tiempoPromedio;
}


enum caso_t{
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE
};

double cicloPrueba(caso_t caso){
    
    double tiempoPromedio = 0.0;
    double cantidadIteraciones = 1e8;
    uint64_t inicio, fin;

  
    inicio = clock();

    
    for(int64_t i = 0; i < (int64_t)cantidadIteraciones; i++) {
        if(caso == VACIO) {
            
        } else if(caso == ESPACIO) {
            printf(" ");
        } else if(caso == ASTERISCO) {
            printf("*");
        } else if(caso == NEWLINE) {
            printf("\n");
        }
    }

   
    fin = clock();


    double tiempoTotal = (((double)(fin - inicio)) / CLOCKS_PER_SEC) * 1e9;

    
    tiempoPromedio = tiempoTotal / cantidadIteraciones;

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