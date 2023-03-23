/*Ejercicio 4: Escribir en lenguaje C un programa que:
1o) Pida por teclado una hora en horas, minutos y segundos (datos enteros).
2o) Calcule cuántos segundos han pasado desde las 0:0:0 horas.
3o) Muestre por pantalla el resultado (dato entero).*/

#include <stdio.h>
#define true 1
#define false 0
int main(){
    int hh,mm,ss;
    char n_check;
    n_check=false;
    do{
        if(n_check){
            printf("Ingresó una hora negativa, por favor ingrese una hora válida\n");
        }
        printf("Ingrese las hora: ");
        scanf("%d",&hh);
        printf("Ingrese los minutos: ");
        scanf("%d",&mm);
        printf("Ingrese los segundos: ");
        scanf("%d",&ss);
        n_check=true;
    } while ((hh<0) || (mm<0) || (ss<0));
    printf("Los segundos que han pasado desde las 0:0:0 son: %i\n",(hh*3600)+(mm*60)+ss);
    return 0;
}