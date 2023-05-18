/*1) Desarrolle un programa en C que permita determinar si dos números ingresados por
teclado son amigos
Dos números se consideran amigos si la suma de sus divisores es igual al otro número, por
ejemplo.
Los números 220 y 284
220: 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 10 = 284
284: 1, 2, 4, 71, 142 = 220*/

#include<stdio.h>

int main(){
    int a,b,i,j,suma=0,suma2=0;
    printf("\t\t\t**Programa para determinar si dos números son amigos**\n");
    printf("Introduzca el primer número: ");
    scanf("%d",&a);
    printf("Introduzca el segundo número: ");
    scanf("%d",&b);
    printf("los divisores de el primer número son: ");
    for (i=1;i<a;i++){
        if((a%i)==0){
            printf("%d, ",i);
            suma+=i;
        }
    }
    printf("\n");
    printf("La suma de los divisores del primer número es: %d\n",suma);
    printf("los divisores de el segundo número son: ");
    for (j=1;j<b;j++){
        if((b%j)==0){
            printf("%d, ",j);
            suma2+=j;
        }
    }
    printf("\n");
    printf("La suma de los divisores del segundo número es: %d\n",suma2);
    if ((suma==b)&&(suma2==a)){
        printf("Ya que, %d = %d y %d = %d, Entonces, son números amigos\n",suma,b,suma2,a);
    }else{
        printf("Ya que, %d != %d y %d != %d, Entonces, No son números amigos\n",suma,b,suma2,a);
    }
}