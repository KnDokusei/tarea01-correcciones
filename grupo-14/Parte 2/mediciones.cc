#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>

double cicloEjemplo(){
    int64_t cantidadIteraciones;
    double tiempoTotal;
    uint64_t inicio, fin;
    cantidadIteraciones =1e1;
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
    double tiempoTotal;
    uint64_t cantidadIteraciones;   
    uint64_t inicio, fin;
    tiempoTotal     = 0.0;
    cantidadIteraciones =1e3;
    char caracter;
    switch(caso){
        case VACIO:
            caracter='\0';
            break;
        case ESPACIO:
            caracter=' ';
            break;
        case ASTERISCO:
            caracter='*';
            break;
        case NEWLINE:
            caracter='\n';
            break;
    }
    inicio = clock(); 
    for(int64_t i=0; i<cantidadIteraciones; i++)
    {
        printf("%c",caracter);
    }
    fin = clock(); 
    printf("\n");
    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC)*1e9;
    double tiempoPromedio = tiempoTotal / cantidadIteraciones;
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

