/*2) Desarrollar un programa en C que permita dado n numeros ingresados por
teclado realizar las siguientes validaciones:
a) Si el numero ingresado por teclado tiene mas de 3 dígitos mostrar por
pantalla la cifra invertida:
Ejm: 345 → 543
b) Mostrar por pantalla la cantidad de veces que el usuario ingreso el
nro 3 y el nro 5*/

#include<stdio.h>

int main(){
    int n,i,num,NCinc=0,Ntre=0,aux,Ninvert,temp;
    printf("                **Programa para validar N números**\n");
    printf("Introduzca la cantidad de números a ser tomados: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("Introduzca un número: ");
        scanf("%d",&num);
        aux=num;
        Ninvert=0;
        do{
            temp=aux%10;
            aux=aux/10;
            if((temp==5)||(temp==-5)){
                NCinc++;
            }
            if((temp==3)||(temp==-3)){
                Ntre++;
            }
            Ninvert*=10;      //Para asegurar lo hago separado, pero se podría hacer
            Ninvert+=temp;
        }while(aux!=0);
        if((num>99)||(num<-100)){
            printf("El número invertido es %d\n",Ninvert);
        }
    }
    printf("El usuario ingresó %d cincos y %d treses\n",NCinc,Ntre);
}