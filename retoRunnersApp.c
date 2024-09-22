#include <stdio.h>

void imprimirMejorTramo(int tiempos[], int hectometros);

int main() {
    int hectometros = 0;
    
    // Repetir mientras no se lea un 0
    while (1) {
        // Leer la cantidad de hectómetros
        scanf("%d", &hectometros);
        
        // Si es 0, terminamos el programa
        if (hectometros == 0) {
            break;
        }
        
        int tiempos[hectometros], i;
        
        // Leer los tiempos de cada hectómetro
        for (i = 0; i < hectometros; i++) {
            scanf("%d", &tiempos[i]);
        }
        
        // Llamar a la función para imprimir el mejor tramo
        imprimirMejorTramo(tiempos, hectometros);
    }

    return 0;
}

void imprimirMejorTramo(int tiempos[], int hectometros) {
    int mejorInicio = 0, mejorTiempo = 0, tiempoActual = 0, i;
    
    // Calcular el tiempo del primer kilómetro (los primeros 10 hectómetros)
    for (i = 0; i < 10; i++) {
        mejorTiempo += tiempos[i];
    }
    
    tiempoActual = mejorTiempo;

    // Deslizar la ventana de 10 hectómetros para buscar el mejor kilómetro
    for (i = 1; i <= hectometros - 10; i++) {
        tiempoActual = tiempoActual - tiempos[i - 1] + tiempos[i + 9];
        
        if (tiempoActual < mejorTiempo || (tiempoActual == mejorTiempo && i > mejorInicio)) {
            mejorTiempo = tiempoActual;
            mejorInicio = i;
        }
    }

    // Imprimir el mejor tramo en el formato adecuado, asegurándonos de que la salida tenga el formato correcto
    printf("%d-%d %d:%02d\n", (mejorInicio) * 100, (mejorInicio + 10) * 100, mejorTiempo / 60, mejorTiempo % 60);
}
