/*Ejercicio 6: Escribir en lenguaje C un programa que:
1o) Pida por teclado una cantidad (dato entero) en dolares.
2o) Calcule su equivalente en euros.
3o) Muestre por pantalla el resultado (dato real).
Nota: 1 euro = 166,386 dolares.*/

#include <stdio.h>

int main(){
    int dol;
    float eur;
    do{
        printf("Ingrese la cantidad en dólares: ");
        scanf("%d",&dol);
    } while(dol<0);
    eur=dol/166.386;
    printf("Su equivalente en euros (1 euro = 166,386 dolares) es: %f\n",eur);
    return 0;
}