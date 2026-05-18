#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>

/*
    Función que realiza la medición de la duración de un
    ciclo for de 1e6 iteraciones, donde cada iteración
    muestra el caracter '*'
*/
double cicloEjemplo()
{
    std::int64_t cantidadIteraciones;
    double tiempoTotal;
    std::uint64_t inicio, fin;

    cantidadIteraciones = 1e6;
    tiempoTotal = 0.0;

    inicio = clock();
    printf("Inicio: %lu\n", inicio);
    for (int64_t i = 0; i < cantidadIteraciones; i++)
    {
        printf("*");
    }
    fin = clock();
    printf("\n");
    printf("Fin: %lu\n", fin);
    // En el contenido debe estar explicado el cast entre tipo de datos.
    tiempoTotal = (((double)(fin - inicio)) / CLOCKS_PER_SEC) * 1e9;

    double tiempoPromedio = tiempoTotal / cantidadIteraciones;

    return tiempoPromedio;
}

// No modificar la siguiente estructura enum.
enum caso_t
{
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE
};

double cicloPrueba(caso_t caso)
{
    double tiempoPromedio;
    double cantidadIteraciones;

    tiempoPromedio = 0.0;
    cantidadIteraciones = 1e5;

    uint64_t inicio, fin;

    inicio = clock();

    switch (caso)
    {
    case VACIO:
        for (int64_t i = 0; i < cantidadIteraciones; i++)
        {
        }
        break;

    case ESPACIO:
        for (int64_t i = 0; i < cantidadIteraciones; i++)
        {
            printf(" ");
        }
        break;

    case ASTERISCO:
        for (int64_t i = 0; i < cantidadIteraciones; i++)
        {
            printf("*");
        }
        break;

    case NEWLINE:
        for (int64_t i = 0; i < cantidadIteraciones; i++)
        {
            printf("\n");
        }
        break;

    default:
        break;
    }
    fin = clock();
    double tiempoTotal = ((double)(fin - inicio) / CLOCKS_PER_SEC) * 1e9;
    tiempoPromedio = tiempoTotal / (double)cantidadIteraciones;
    return tiempoPromedio;
}

int main(int argc, char *argv[])
{
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
