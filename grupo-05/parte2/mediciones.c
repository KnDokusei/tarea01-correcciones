#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Función del Hito 1 
double cicloEjemplo(){
    int64_t cantidadIteraciones;
    double tiempoTotal;
    uint64_t inicio, fin;

    cantidadIteraciones = 1e8;
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

double cicloPrueba(enum caso_t caso){
    double tiempoPromedio;
    double cantidadIteraciones;
    uint64_t inicio, fin;
    double tiempoTotal;

    tiempoPromedio      = 0.0;
    cantidadIteraciones = 1e5; 

    // Inicio de la medición
    inicio = clock();

    for(int64_t i = 0; i < cantidadIteraciones; i++){
        
        if (caso == VACIO){
            ; // No hace nada, solo el ciclo
        }
        else if (caso == ESPACIO){
            printf(" ");
        }
        else if (caso == ASTERISCO){
            printf("*");
        }
        else if (caso == NEWLINE){
            printf("\n");
        }
    }

    fin = clock();

    
    tiempoTotal = (((double)(fin - inicio)) / CLOCKS_PER_SEC) * 1e9;
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

    printf("\n=== Mediciones realizadas ===\n");
    printf("VACIO     : Tiempo promedio %f [ns]\n", casos[VACIO]);
    printf("ESPACIO   : Tiempo promedio %f [ns]\n", casos[ESPACIO]);
    printf("ASTERISCO : Tiempo promedio %f [ns]\n", casos[ASTERISCO]);
    printf("NEWLINE   : Tiempo promedio %f [ns]\n", casos[NEWLINE]);
    
    exit(EXIT_SUCCESS);
}