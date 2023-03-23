/*Ejercicio 1: Escribir en lenguaje C un programa que:
1o) Pida por teclado la nota de tres exámenes (datos reales).
2o) Calcule la nota media de los tres exámenes.
3o) Muestre por pantalla el resultado (dato real).*/

#include<stdio.h>

int main(){
    /*se podría pedir de manera directa los 3 pero los voy a pedir separados, para
    especificar dónde debe repetir la nota (de ser necesario)*/
    float a,b,c;
    do {
        printf("Ingrese la nota del primer exámen: ");
        scanf("%f",&a);
    } while ((a<0) || (a>20));
    do {
        printf("Ingrese la nota del segundo exámen: ");
        scanf("%f",&b);
    } while ((b<0) || (b>20));
    do {
        printf("Ingrese la nota del tercer exámen: ");
        scanf("%f",&c);
    } while ((c<0) || (c>20));
    printf("La nota media de los tres exámenes es: %f\n",(a+b+c)/3);
    return 0;
}