/*Ejercicio 5: Escribir en lenguaje C un programa que:
1o) Pida por teclado dos números (datos enteros) y sean almacenados en
dos variables, llamadas v1 y v2.
2o) Intercambie los valores de las variables.
3o) Muestre por pantalla los valores contendidos en las variables.*/

#include <stdio.h>

int main(){
     int v1,v2,aux;
    printf("Introduzca valor de la variable 1: ");
    scanf("%i",&v1);
    printf("Introduzca valor de la variable 2: ");
    scanf("%i",&v2);
    printf("los valores introducidos son: %d y %d\n",v1,v2);
    aux=v1;
    v1=v2;
    v2=aux;
    printf("los valores intercambiados son: %d y %d\n",v1,v2);
    return 0;
}