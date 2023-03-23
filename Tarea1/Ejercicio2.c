/*Ejercicio 2: Escribir en lenguaje C un programa que:
1o) Pida por teclado la arista (dato real) de un cubo.
2o) Calcule el volumen del cubo.
3o) Muestre por pantalla el resultado (dato real).*/

#include <stdio.h>
#define false 0
#define true 1

int main(){
    float ari,vol;
    char band;
    band=true;
    do {
        if (band){
            printf("Ingrese la arísta del cubo: ");
            scanf("%f",&ari);
        }
        else {
            printf("Ingrese un dato válido para la arista del cubo, por favor:");
            scanf("%f",&ari);
        }
        band=false;
    } while (ari<0);
    vol=(ari*ari*ari);
    printf("El volumen del cubo es %f",vol)
    return 0;
}