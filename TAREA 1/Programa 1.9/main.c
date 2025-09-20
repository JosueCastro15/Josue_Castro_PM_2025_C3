#include <stdio.h>

/*Estancia
El programa, al recibir como dato la superficie de una estancia exresada
en acres, la convierte en hectarias.

ECA: variable de tipo real. */

void main(void)
{
    float ECA;
    printf("Ingrese la extension de la estancia: ");
    scanf("%f", &ECA);
    ECA = ECA * 4047 / 1000;
    printf("\nExtension de la estancia en hectarias: %5.2f", ECA);
}
