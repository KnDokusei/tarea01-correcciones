#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h> // se añade la librería stdint para los enteros de 64 bits de la función cicloEjemplo().

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

double cicloPrueba(enum caso_t caso){ // se define para que retorne un double y se especifica el tipo de dato del parámetro como enum caso_t para que no de error.
    double tiempoPromedio; //se declara como double la variable que guardará el tiempo promedio de la medición.
    double cantidadIteraciones; //se declara como double la variable que guardará la cantidad de veces que se realizarán los ciclos.

    tiempoPromedio      = 0.0; //se le asigna el valor inicial 0.0 al tiempo promedio.
    cantidadIteraciones = 1e6; //se cambió las iteraciones a 1e6 para que no colapse

    // Completar código
    double tiempoTotal; //se declara como double la variable que guardará el tiempo total de los ciclos.
    uint64_t inicio,fin; //se declara como entero de 64 bits a las variables que guardarán los instantes antes y después de cada ciclo.
    
    tiempoTotal = 0.0; //se le asigna el valor inicial 0.0 al tiempo total.
    inicio = clock(); //se usa clock() para guardar el instante (ticks) justo antes de iniciar los ciclos.
    
    switch(caso){ //se usa switch() para separar cada caso del enum.
    case VACIO: // en este caso se usa un ciclo for, para realizar la cantidad indicada de ciclos vacíos.
        for(int64_t i = 0; i < cantidadIteraciones; i++){ 
            ;
        }
        break;
    case ESPACIO: // en este caso se usa un ciclo for, para imprimir la cantidad de espacios indicados.
        for(int64_t i = 0; i < cantidadIteraciones; i++){
            printf(" ");
        }
        break;
    case ASTERISCO: //en este caso se usa un ciclo for, para imprimir la cantidad de asteriscos indicados.
        for(int64_t i = 0; i < cantidadIteraciones; i++){
            printf("*");
        }
        break;
    case NEWLINE: //en este caso se usa un ciclo for, para imprimir la cantidad de saltos de línea indicados.
        for(int64_t i = 0; i < cantidadIteraciones; i++){
            printf("\n");
        }
        break;
    }
    
    fin = clock(); //se usa clock() para guardar el instante (ticks) justo después de realizar los ciclos.
    printf("\n"); //se imprime un salto de línea para separar visualmente al siguiente llamado de la función.

    tiempoTotal = (((double) (fin - inicio)) / CLOCKS_PER_SEC) * 1e9; // se calcula la duración del ciclo convirtiendo la diferencia de ticks a nanosegundos mediante un cast explícito de uint64_t a double y la constante CLOCKS_PER_SEC.
    tiempoPromedio = tiempoTotal / (double)cantidadIteraciones; // se divide el tiempo total por el número de iteraciones realizadas para obtener el tiempo promedio.
    return tiempoPromedio; //se retorna el tiempo promedio de la medición hecha.

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
