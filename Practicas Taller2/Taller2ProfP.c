#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct{
    char nombre[N];
    char apellido[N];
    int edad;
    int peso;
    float estatura;
    float IMC;
}personas;

personas *datospersonas;

void llenadoEstruc(int *c);
void calcIMC(int c);
void imprimirsalida(float a,int i);
float promedioIMC(int c);

int main(){
    int cant;
    float res;
    llenadoEstruc(&cant);
    calcIMC(cant);
    res=promedioIMC(cant);
    printf("\nLos datos han sido cargados al archivo IMC.txt\n\n");
    printf("El promedio IMC de todos los pacientes es %f\n\n",res/cant);
}
void llenadoEstruc(int *c){
    FILE *f;
    int i;
    f=fopen("Datos.in","r");
    if(f==NULL){
        printf("No se ha podido abrir el archivo Datos.in\n");
        exit(1);
    }
    fscanf(f,"%d",c);
    datospersonas=(personas*)malloc((*c)*(sizeof(personas)));
    for(i=0;i<*c;i++){
        fscanf(f,"%s %s %d %d %f",datospersonas[i].nombre,datospersonas[i].apellido,&datospersonas[i].edad,&datospersonas[i].peso,&datospersonas[i].estatura);
    }
    fclose(f);
}
void calcIMC(int c){
    int i;
    for(i=0;i<c;i++){
        datospersonas[i].IMC=datospersonas[i].peso/(datospersonas[i].estatura*datospersonas[i].estatura);
        imprimirsalida(datospersonas[i].IMC,i);
    }
}
void imprimirsalida(float a,int i){
    FILE *c;
    c=fopen("IMC.txt","a");
    if(c==NULL){
        printf("No se ha podido crear el archivo IMC.txt");
        exit(1);
    }
    if(a<16.00){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tInfrapeso: Delgadez Severa\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else if(a<17.00){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tInfrapeso: Delgadez moderada\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else if(a<18.50){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tInfrapeso: Delgadez aceptable\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else if(a<25.00){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tPeso Normal\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else if(a<30.00){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tSobrepeso\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else if(a<35.00){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tObeso: Tipo I\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else if(a<40.00){
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tObeso: Tipo II\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    else{
        fprintf(c,"%s %s \t\t%d \t\t%.2f \t\tObeso: Tipo III\n",datospersonas[i].nombre,datospersonas[i].apellido,datospersonas[i].edad,a);
    }
    fclose(c);
}
float promedioIMC(int c){
    int i;
    float resul;
    for(i=0;i<c;i++){
        resul+=datospersonas[i].IMC;
    }
    return resul;
}
