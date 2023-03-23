/*Ejercicio 3: Suponiendo que el kilo de azúcar y de café están a 3$ y 0.72$
respectivamente, escribir
en lenguaje C un programa que:
1o) Pida por teclado una cantidad (dato real) en euros.
2o) Si la mitad de la cantidad introducida se destina a comprar azúcar,
una tercera parte a comprar café, y el resto no se gasta. Calcule cuántos
kilos de azúcar y café (datos reales) se pueden comprar
con dicha cantidad de dinero, así como la cantidad (dato real) de dinero sobrante.
3o) Muestre por pantalla los resultados (datos reales).*/

#include <stdio.h>

int main(){
    float cant,sug,cof,res;
    do{
        printf("Ingrese la cantidad de dinero en euros: ");
        scanf("%f",&cant);
    } while(cant<0);
    sug=cant/2;
    cof=cant/3;
    res=cant-(sug+cof);
    printf("De el total %f se destinarán, %f en azúcar, %f en café y te queda %f\n",cant,sug,cof,res);
    printf("(Todos los precios antes mencionados está en euros)\n");
    return 0;
    /*no lo hice directo por hacerlo mas largo :P*/
}