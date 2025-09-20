#include <stdio.h>

/* Superficie del triangulo
El proograma, al recibir como daros la base y la altura de un triangulo,
calcula su superficie.

BAS, ALT y SUP: variables de tipo real. */

void main (void)
{
    float BAS, ALT, SUP;
    printf("Ingrese la base y la altura del triangulo: ");
    scanf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT / 2;
    printf("\nLa superfice del triangulo es: %5.2f", SUP);
}
