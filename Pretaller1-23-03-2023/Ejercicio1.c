/*Escribir un programa en C que pida por teclado n números enteros. cada uno de
ellos deberá ser introducido. Calcular:
1) Cuantos son pares e impares
2) Cuantos ceros se ha introducido por teclado
3) Cuantos son primos*/

#include<stdio.h>
#include<stdbool.h>

int main(){
    int n,i,num,c_par=0,c_imp=0,aux,check0,c_0=0,j,band,primcheck,prim;
    printf("Ingrese la cantidad de números que va a evaluar: ");
    scanf("%d",&n);
    while(n<1){
        printf("ERROR: Número ingresado negativo ó 0\n");
        printf("Ingrese la cantidad de números que va a evaluar: ");
        scanf("%d",&n);
    }
    for (i=1;i<=n;i++){
        printf("Ingrese un número: ");
        scanf("%d",&num);
        while(num<0){
            printf("ERROR: Número ingresado negativo\n");
            printf("Ingrese un número: ");
            scanf("%d",&num);
        }
        if ((num%2)==0){
            c_par++;
        }else{
            c_imp++;
        }
        aux=num;
        do{
            check0=aux%10;
            aux=aux/10;
            if(check0==0){
                c_0++;
            }
        }while(aux!=0);
        if((num!=0)&&(num!=1)){
            primcheck=0;
            for(j=2;(j<num)&&(primcheck!=1);j++){
                band=num%j;
                if(band==0){
                    primcheck=1;
                }
            }
            if(primcheck!=1){
            prim++;
            }
        }
    }
    printf("La cantidad de pares es %d\n",c_par);
    printf("La cantidad de impares es %d\n",c_imp);
    printf("La cantidad de ceros introducidos es %d\n",c_0);
    printf("La cantidad de primos es %d\n",prim);
    return 0;
}