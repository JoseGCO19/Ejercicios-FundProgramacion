#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cant_v;
char aux[50];

void guardarmatriz(float a[cant_v][3],FILE *f);
void mostrarmatriz(float a[cant_v][3]);
void vaciar(char a[],int b);
float sumacat(float a[cant_v][3],int b);

int main(){
    FILE *p,*c;
    int i;
    float cat1,cat2,cat3,total;
    p=fopen("ventas.txt","r");
    if(p==NULL){
        printf("Error al abrir el archivo Ventas.txt\n");
        exit(1);
    }
    for (i=0;!feof(p);i++){
        fgets(aux,50,p);
    }
    cant_v=i;
    float mat[cant_v][3];
    rewind(p);
    guardarmatriz(mat,p);
    mostrarmatriz(mat);
    cat1=sumacat(mat,1);
    cat2=sumacat(mat,2);
    cat3=sumacat(mat,3);
    total=cat1+cat2+cat3;
    c=fopen("ventas_totales.txt","w");
    if(c==NULL){
        printf("Error al crear el archivo ventas_totales.txt\n");
        exit(1);
    }
    printf("\nVentas totales por categoría: \n\nCategoría 1: $%.2f\nCategoría 2: $%.2f\nCategoría 3: $%.2f\nVentas totales: $%.2f\n",cat1,cat2,cat3,total);
    fprintf(c,"Ventas_totales.txt\nVentas totales por categoría: \nCategoría 1: $%.2f\nCategoría 2: $%.2f\nCategoría 3: $%.2f\nVentas totales: $%.2f",cat1,cat2,cat3,total);
    printf("\nResultados Cargados a Ventas_totales.txt!\n\n");
    fclose(p);
    fclose(c);
    return 0;
}
void guardarmatriz(float a[cant_v][3],FILE *f){
    int i,j,k,numb;
    char c,c2[20];
    char *point;
    float numb2;
    for(i=0;i<cant_v;i++){
        for(j=0;j<3;j++){
            k=0;
            if(j<2){
                vaciar(c2,20);
                c=getc(f);
                while(c!=','){
                    c2[k]=c;
                    k++;
                    c=getc(f);
                }
                numb=atoi(c2);
                a[i][j]=numb;
            }
            else{
                vaciar(c2,20);
                fgets(c2,20,f);
                numb2=atof(c2);
                a[i][j]=numb2;
            }
        }
    }
}
void mostrarmatriz(float a[cant_v][3]){
    int i,j;
    for(i=0;i<cant_v;i++){
        for(j=0;j<3;j++){
            if(j<2){
                printf("%.0f ",a[i][j]);
            }
            else{
                printf("%.2f ",a[i][j]);
            }
        }
        printf("\n");
    }
}
void vaciar(char a[],int b){
    int i;
    for(i=0;i<b;i++){
        a[i]='\0';
    }
}
float sumacat(float a[cant_v][3],int b){
    int i;
    float sum;
    sum=0;
    for(i=0;i<cant_v;i++){
        if(a[i][0]==b){
            sum=sum+a[i][2];
        }
    }
    return sum;
}