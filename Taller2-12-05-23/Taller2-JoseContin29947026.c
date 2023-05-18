#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[20];
    float prom;
    int pos;
}estudiantes;

int cant_alum;

void leerficheroycalcular(FILE *f,float a[]);
void ordenar(float a[]);
void salidaycreacion(float a[],FILE *f,estudiantes est[]);

int main(){
    char aux[30];
    int i;
    FILE *f;
    f=fopen("notas_alumnos.txt","r");
    if(f==NULL){
        printf("Error al abrir el archivo notas_alumnos.txt\n");
        exit(1);
    }
    for(i=0;!feof(f);i++){
        fgets(aux,30,f);
    }
    cant_alum=i;
    estudiantes est[cant_alum];
    float prom[cant_alum];
    rewind(f);
    leerficheroycalcular(f,prom);
    ordenar(prom);
    rewind(f);
    salidaycreacion(prom,f,est);
    return 0;
}
void leerficheroycalcular(FILE *f,float a[]){
    int i,nota1,nota2,nota3;
    char nombre[20];
    float prom;
    for(i=0;i<cant_alum;i++){
        fscanf(f,"%s %d %d %d",nombre,&nota1,&nota2,&nota3);
        prom=(nota1+nota2+nota3)/3.0;
        a[i]=prom;
    }
}
void ordenar(float a[]){
    int i,j;
    float aux;
    for(i=0;i<cant_alum;i++){
        for(j=i;j<cant_alum;j++){
            if(a[j]>a[i]){
                aux=a[j];
                a[j]=a[i];
                a[i]=aux;
            }
        }
    }
}
void salidaycreacion(float a[],FILE *f,estudiantes est[]){
    int i,j,auxpos;
    char nombre[20],Chj,auxnombre[20];
    float nota1,nota2,nota3,prom,auxprom;
    FILE *c;
    c=fopen("resultados.txt","w");
    if(c==NULL){
        printf("Error al crear el archivo\n");
        exit(1);
    }
    for(i=0;i<cant_alum;i++){
        fscanf(f,"%s %f %f %f",nombre,&nota1,&nota2,&nota3);
        prom=(nota1+nota2+nota3)/3;
        for(j=0;j<cant_alum;j++){
            if(prom==a[j]){
                strcpy(auxnombre,nombre);
                auxprom=prom;
                auxpos=j+1;
                break;
            }
        }
        strcpy(est[i].nombre,auxnombre);
        est[i].prom=auxprom;
        est[i].pos=auxpos;
    }
    for(i=0;i<cant_alum;i++){
        for(j=0;j<cant_alum;j++){
            if(est[i].pos<est[j].pos){
                strcpy(auxnombre,est[i].nombre);
                auxprom=est[i].prom;
                auxpos=est[i].pos;
                strcpy(est[i].nombre,est[j].nombre);
                est[i].prom=est[j].prom;
                est[i].pos=est[j].pos;
                strcpy(est[j].nombre,auxnombre);
                est[j].prom=auxprom;
                est[j].pos=auxpos;
            }
        }
    }
    for(i=0;i<cant_alum;i++){
        if(i<(cant_alum-1)){
            fprintf(c,"%d\t\t%s\t\t%f\n",est[i].pos,est[i].nombre,est[i].prom);
        }
        else{
            fprintf(c,"%d\t\t%s\t\t%f",est[i].pos,est[i].nombre,est[i].prom);
        }
    }
}
