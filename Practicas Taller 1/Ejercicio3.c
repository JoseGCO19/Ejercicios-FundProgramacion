/*3) “La empresa ToyLandia C.A. Para este primer semestre del año desea otorgar un
descuento especial a sus clientes del 50% del monto de la factura mediante un
concurso, que se basa en las siguientes reglas:
a) Compras mayores o iguales a 1000$ pero que no excedan de 5000$,
b) Los Productos en juego solo serán aquellos que tengan la etiqueta color Morado(M) ó
Amarillo(A),
c) La cantidad de productos comprados no debe ser menor de 3 articulos.
d) Si la cédula del cliente termina en un digito par. Se le otorgara un 5% mas
del descuento. Si termina en un numero impar se le asignara solo un 3%.
e) Al monto de la factura mas alta se le otorgara una Gif de 300$ sobre su próxima
compra. Mostrar por pantalla el porcentaje de clientes ganadores del descuento y
la cantidad de ganadores de la GIF y cuantos obtuvieron el 5% y el 3%*/

#include<stdio.h>
#include<stdio_ext.h>

int checknegativo(int a);
float checknegativofloat(float b);
char checketic(char e);
int main(){
    int n,i,Cant,ced;
    float cost;
    char etic;
    printf("*Programa para otorgar descuentos en para la empresa ToyLandia C.A.*\n");
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&n);
    n=checknegativo(n);
    for(i=1;i<=n;i++){
        printf("CLIENTE N°%d\n",i);
        printf("        Ingrese el costo de la compra: ");
        scanf("%f",&cost);
        cost=checknegativofloat(cost);
        printf("         Ingrese el primer caracter del color de la etiqueta: ");
        scanf("%c",&etic);
        etic=checketic(etc);
        printf("         Ingrese la cantidad de productos comprados: ");
        scanf("%d",&Cant);
        Cant=checknegativo(Cant);
        printf("         Ingrese cédula de identidaad: ");
        scanf("%d",&ced);
        ced=checknegativo(ced);

    }
}

int checknegativo(int a){
    while(a<0){
        printf("ERROR: Número ingresado negativo.\n");
        printf("Intentelo otra vez: ");
        scanf("%d",&a);
    }
    return (a);
}

float checknegativofloat(float b){
    while(b<0){
        printf("ERROR: Número ingresado negativo.\n");
        printf("Intentelo otra vez: ");
        scanf("%d",&b);
    }
    return (b);
}

char checketic(char e){
    while((etic!='M')||(etic!='A')){
        printf("ERROR: Solo Pueden participar aquellos con etiqueta Morada o Amarilla.\n");
        printf("Intentelo otra vez: ");
        scanf("%d",&b);
    }
    return(etc);
}