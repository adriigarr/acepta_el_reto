#include <stdio.h>

int calendarioConCero(int);
int casoPrueba(void);
void imprimeArray(int arr[], int);

int main() {
    
    int casosPrueba = 0;
    scanf("%d", &casosPrueba);
    int arr[casosPrueba];
    
    int i;
    for(i= 0; i < casosPrueba; i++) {
        int res = casoPrueba();
        arr[i] = res;
    }
    imprimeArray(arr, casosPrueba);
    
    return 0;
}

int calendarioConCero (int anio){
    int anioSalida = anio - 1;
    return anioSalida;
};

int casoPrueba(){
    int anioEntrada = 0;
    int anioResultado = 0;
    // insert code here...
    scanf("%d",&anioEntrada);
    
    if (anioEntrada <= 3000 && anioEntrada >= 1) {
        anioResultado = calendarioConCero(anioEntrada);
        return anioResultado;
    }
    else if (anioEntrada >= -3000 && anioEntrada <= -1){
        anioResultado = anioEntrada;
        return anioEntrada;
    }
    else{
        printf("Los anios deben de estar entre los valores -3000 y 3000 o no ser 0\n");
    }
    return 0;
}

void imprimeArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
