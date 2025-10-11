#include <stdio.h>

/* Conflicto de variables con el mismo nombre.  */

void f1(void);    /* Prototipo de funcion. */
int K = 5;        /* Variable gobal. */

void main (void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
}
void f1(void)
/*La funcion utiliza tanto la variable local I como la variable
gobal I. */
{
    int K1 = 2;        /*Variable local.  */
    K1 += K1;
    printf("\nEl valor de la varaible local es: %d", K1);

    K = K + K1;           /*Uso de ambas variables. */
    printf("\nEl valor de la variable gobal es: %d", K);
}
