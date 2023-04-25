#include<stdio.h>
#include<stdio_ext.h>
//Programa probado en linux
void suma(int a,int b);
void resta(int a,int b);
void multip(int a,int b);
void div(int a,int b);
void menu(int *a,int *b);
char Check(char a);
int main(){
    int a,b;
    printf("\n\t\t\t**Calculadora de números enteros**\n\n");
    printf("Ingrese el primer valor: ");
    scanf("%d",&a);
    printf("Ingrese el segundo valor: ");
    scanf("%d",&b);
    __fpurge(stdin);
    menu(&a,&b);
    return 0;
}
void menu(int *a,int *b){
    char x,op2;
    do{
        printf("\nOpciones:\n(A)-Suma\n(B)-Resta\n(C)-Multiplicación\n(D)-División\n\nIngrese su opción: ");
        scanf("%c",&x);
        __fpurge(stdin);
        switch (x){
            case 'A':suma(*a,*b);break;
            case 'B':resta(*a,*b);break;
            case 'C':multip(*a,*b);break;
            case 'D':div(*a,*b);break;
            case 'a':suma(*a,*b);break;
            case 'b':resta(*a,*b);break;
            case 'c':multip(*a,*b);break;
            case 'd':div(*a,*b);break;
            default: printf("ERROR: Opción ingresada inválida. Vuelva a intentarlo.\n");
        }
        printf("\nQuiere usarla otra vez? (S/N): ");
        scanf("%c",&op2);
        __fpurge(stdin);
        op2=Check(op2);
        if((op2=='S')||(op2=='s')){
            printf("\nIngrese el primer valor: ");
            scanf("%d",a);
            printf("Ingrese el segundo valor: ");
            scanf("%d",b);
            __fpurge(stdin);
        }
    }while((op2=='S')||(op2=='s'));
}
void suma(int a,int b){
    printf("La suma entre %d y %d es %d\n",a,b,a+b);
}
void resta(int a,int b){
    printf("La resta entre %d y %d es %d\n",a,b,a-b);
}
void multip(int a,int b){
    printf("La multiplicación entre %d y %d es %d\n",a,b,a*b);
}
void div(int a,int b){
    if (b==0){
        printf("ERROR: Division entre 0.\n");
    }else{
        printf("La división entre %d y %d es %f\n",a,b,(float)a/b);
    }
}
char Check(char a){
    while((a!='S')&&(a!='s')&&(a!='N')&&(a!='n')){
        printf("ERROR: Opción introducida inválida.\nVuelva a intentarlo: ");
        scanf("%c",&a);
        __fpurge(stdin);
    }
    return a;
}
//(x!='A')&&(x!='B')&&(x!='C')&&(x!='D')&&(x!='a')&&(x!='b')&&(x!='c')&&(x!='d')