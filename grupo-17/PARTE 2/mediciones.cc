#include <stdio.h>
#include <stdint.h>
#include <time.h>

// Definición de etiquetas para identificar cada tipo de prueba
typedef enum {
    VACIO,
    ESPACIO,
    ASTERISCO,
    NEWLINE
} caso_t;

// Función que mide el tiepo promedio de ejecución de un bloque de control
double cicloPrueba(caso_t caso){
    int64_t cantidadIteraciones = 1e6; // Definimos un millón de iteraciones para ganar precisión
    uint64_t inicio, fin;

    inicio = clock(); // Captura del tiempo inicial del sistema

    // Bucle principal para medir el impacto del switch en el rendimiento del procesador
    for(int64_t i = 0; i < cantidadIteraciones; i++){
        switch (caso)
        {
        case VACIO:
            ; // Instrucción nula para medir la latencia mínima
            break;
        
        /*Casos vacíos para aislar latencia de memoria y omisión printf para evita los cuellos de botella en E/S*/
        case ESPACIO:
             break; 
        
        case ASTERISCO:
             break;

        case NEWLINE:
             break;
        }
    }

    fin = clock(); // Captura del tiempo final tras un millón de ciclos

    // Cálculo del tiempo total transcurrido convertido a nanosegundos
    double tiempoTotalNS = (((double)(fin-inicio))/CLOCKS_PER_SEC)*1e9;

    // Obtenemos el promedio unitario dividiendo por el total de iteraciones
    double tiempoPromedioNS = tiempoTotalNS / (double)cantidadIteraciones;

    return tiempoPromedioNS; // Retorna la latencia promedio al main
}

int main() {
    // Arreglos para iterar sobre lso casos y mostrar sus nombres en la tabla
    caso_t tipos[] = {VACIO, ESPACIO, ASTERISCO, NEWLINE};
    const char* nombres[] = {"NADA", "ESPACIO", "ASTERISCO", "NEW LINE"};

    // Impresión del encabezado formateado de la tabla de resultados
    printf("Iniciando pruebas\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("%-12s\tp1\tp2\tp3\tp4\tp5\tp6\tp7\tp8\tp9\tp10\n", "Caso");
    printf("--------------------------------------------------------------------------------------------\n");

    // Ciclo externo: recorre cada uno de los 4 casos de prueba
    for(int i = 0; i < 4; i++){
        printf("%-12s\t", nombres[i]);// Imprime el nombre del caso actual en la fila

        // Ciclo interno: realiza 10 mediciones por caso para obtener una muestra estadística
        for(int j = 0; j < 10; j++){
            // Llama a la función y almacena el resultado de la latenciaa medida
            double tprom = cicloPrueba(tipos[i]);
            printf("%.2f\t", tprom); // Muestra el resultado con 2 decimales
        }
        printf("\n"); // Salto de línea para pasas al siguiente caso en la tabla
    }
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Pruebas finalizadas");

    return 0;// Finalización exitosa del programa
}