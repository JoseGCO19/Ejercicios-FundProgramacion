/*Ejercicio 7: Escribir en lenguaje C un programa que:
1o) Pida por teclado un número (dato entero).
2o) Muestre por pantalla:
• "ES PAR", en el caso de que el número sea divisible entre 2.
• "ES IMPAR", en el caso de que el número no sea divisible entre 2.*/

#include<stdio.h>

int main(){
    int x;
    printf("Ingrese un número: ");
    scanf("%d",&x);
    if ((x%2)==0){
        printf("Es par\n");
    }
    else {
        printf("Es impar\n");
    }
    return 0;
}