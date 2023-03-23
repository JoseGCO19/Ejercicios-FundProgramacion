/*Ejercicio 8: Escribir en lenguaje C un programa que:
1o) Pida por teclado tres números (datos enteros).
2o) Muestre el mayor de los tres números introducidos.*/

#include <stdio.h>

int main(){
    int x,y,z,mayor;
    /*Se podría hacer unido de una, lo voy a hacer separado*/
    printf("Introduzca el primer número: ");
    scanf("%d",&x);
    printf("Introduzca el segundo número: ");
    scanf("%d",&y);
    printf("Introduzca el tercer número: ");
    scanf("%d",&z);
    if (x>y){
        if (x>z){
            mayor=x;
        }
        else{
            mayor=z;
        }
    }
    else if (y>z){
        mayor=y;
    }
    else{
        mayor=z;
    }
    printf("El número mayor es: %d\n",mayor);
}