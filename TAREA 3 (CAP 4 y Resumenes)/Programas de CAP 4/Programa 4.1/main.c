#include <stdio.h>

/* Cubo-1
El programa calcula el cubo de los 10 prieros numeros naturales con la
ayuda de una funcion. en la solucion del problema se ultiliza una variable
global, aunque esto, como veremos mas adelante, no es my reconocible. */

int cubo(void);          /* Prototipo de funcion. */
int I;                   /* Variable gobal*/

void main(void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo();  /*Llamada a la funcion cubo. */
        printf("\nEl cubo de %d es:  %d", I, CUB);
    }
}
   int cubo(void)    /*Declaracion de la funcon.*/
   /*La funcion calcula el cubo de la variable gobal I. */
{
    return (I*I*I);
}
