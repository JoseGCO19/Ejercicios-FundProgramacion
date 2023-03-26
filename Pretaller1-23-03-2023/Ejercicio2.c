/*Desarrolle un programa en C que permita registrar las cifras medicas de la clinica
ABC de n cantidad de pacientes, permitiendo mostrar por pantalla:
1) Cantidad de pacientes femeninos
2) Cantidad de pacientes masculinos
3) Cantidad de pacientes mayores de edad
4) Cantidad de pacientes menores de edad
y que además permita validar las fechas de nacimiento de cada paciente. los pacientes
cuya cedula de identidad termine en un número par y sean del sexo femenino, tendran
un descuento del 15% sobre el costo de la consulta. Los pacientes del sexo masculino
que tengan una edad mayor a 60 años, tendran un descuento del 30%*/

//**CODIGO HECHO EN LINUX, NOTECE LIBRERIA stdio_ext.h**

#include<stdio.h>
#include<stdio_ext.h>

int Checknegativo(int a){
    while(a<0){
        printf("ERROR: Valor ingresado negativo!\n");
        printf("Vuelva a intentarlo: ");
        scanf("%d",&a);
    }
    return a;
}

int fechacheck(int *d,int *m,int *a){
    int band=1;
    while(((*d<1)||(*d>=31))||((*m<1)||(*m>12)||(*a<0))){
        printf("ERROR: Fecha inválida, vuelva a intentarlo\n");
        printf("Introduzca el día (desde 1 hasta 31): ");
        scanf("%d",d);
        printf("Introduzca el mes (desde 1 hasta 12 ): ");
        scanf("%d",m);
        printf("Introduzca el año: ");
        scanf("%d",a);
    }
    if (*d==31){
        switch(*m){
            case 4:band=0;*d=32;break;
            case 6:band=0;*d=32;break;
            case 9:band=0;*d=32;break;
            case 11:band=0;*d=32;break;
        }
    }
    if((*m==2)&&(*d==29)){
        band=0;
        *d=32;
        if ((*a%4)==0){
            if ((*a%100)==0){
                if ((*a%400)==0){
                    band=1;
                    *d=29;
                }
                else{
                    band=0;
                    *d=32;
                }
            }
            else{
                band=1;
                *d=29;
            }
        }
        else{
            band=0;
            *d=32;
        }
    }
    if ((*m==2)&&(*d>29)){
        band=0;
        *d=32;
    }
    if (band){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int n,i,ced,dd,mm,aa,Add,Amm,Aaa,C_F=0,C_M=0,edad,C_May=0,C_Men=0;
    char sex,Ctime,ACtime;
    float cost,cost_D=0,t_cost=0;
    printf("Ingrese fecha actual\nIntroduzca el día (del 1 al 31): ");
    scanf("%d",&Add);
    printf("Introduzca el mes (del 1 al 12): ");
    scanf("%d",&Amm);
    printf("Introduzca el año: ");
    scanf("%d",&Aaa);
    ACtime=1;
    while(ACtime){
        ACtime=fechacheck(&Add,&Amm,&Aaa);
    }
    printf("%d %d %d\n",Add,Amm,Aaa);
    printf("Introduzca la cantidad de pacientes de la clinica ABC: ");
    scanf("%d",&n);
    n=Checknegativo(n);
    for(i=1;i<=n;i++){
        printf("Cédula del paciente N°%d: ",i);
        scanf("%d",&ced);
        ced=Checknegativo(ced);
        printf("Sexo del paciente (F ó M) N°%d: ",i);
        __fpurge(stdin);
        scanf("%c",&sex);
        while((sex!='F')&&(sex!='M')&&(sex!='f')&&(sex!='m')){
            printf("ERROR: Caracter introducido inválido, solo se puede F ó M\n");
            printf("Sexo del paciente (F ó M) N°%d: ",i);
            __fpurge(stdin);
            scanf("%c",&sex);
        }
        printf("Fecha de nacimiento del paciente N°%d\nIntroduzca el día (del 1 al 31): ",i);
        scanf("%d",&dd);
        printf("Introduzca el mes (del 1 al 12): ");
        scanf("%d",&mm);
        printf("Introduzca el año: ");
        scanf("%d",&aa);
        Ctime=1;
        while(Ctime){
            Ctime=fechacheck(&dd,&mm,&aa);
        }
        printf("Introduzca el costo de la consulta del paciente N°%d: ",i);
        scanf("%f",&cost);
        while(cost<0){
            printf("ERROR: Valor ingresado negativo!\n");
            printf("Vuelva a intentarlo: ");
            scanf("%f",&cost);
        }
        edad=Aaa-aa;
        if(mm>Amm){
            edad--;
        }else if(mm=Amm){
            if(dd>Add){
                edad--;
            }
        }
        if(edad>=18){
            C_May++;
        }
        else{
            C_Men++;
        }
        if ((sex=='F')||(sex=='f')){
            C_F++;
            if((ced%2)==0){
                cost_D=cost-(cost*0.15);
                t_cost+=cost_D;
            }
        }
        else{
            C_M++;
            if(edad>60){
                cost_D=cost-(cost*0.30);
                t_cost+=cost_D;
            }
        }
        t_cost+=cost;
    }
    printf("La cantidad de pacientes femeninos es: %d\n",C_F);
    printf("La cantidad de pacientes masculinos es: %d\n",C_M);
    printf("La cantidad de pacientes mayores de edad es: %d\n",C_May);
    printf("La cantidad de pacientes menores de edad es: %d\n",C_Men);
    printf("El costo total de los pacientes es: %f\n",t_cost);
    printf("%d\n",edad);
}
