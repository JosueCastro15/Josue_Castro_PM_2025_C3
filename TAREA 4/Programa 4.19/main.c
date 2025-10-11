#include <stdio.h>

/* Funciones y parametros. */

int a, b, c, d;           /* Variables globales. */

void funcion1(int r, int *b, int *c);  /* Prototipos de funciones. */
int funcion2(int *dpa, int cpa);

void main(void)
{
    int a1;
    a1 = 1;
    b = 2;
    c = 3;
    d = 4;
    printf("\n%d %d %d %d", a1, b, c, d);

    a1 = funcion2 (&a1, c);
    printf("\n%d %d %d %d", a1, b, c, d);
}

void funcion1(int r, int *b, int *c)
{
    int d1;
    a = *c;
    b = a + 3 + *b;
    if (r)
    {
        *b = *b + 2;
        *c = *c + 3;
        printf("\n%d %d %d %d", a, b, c, d1);
    }
    else
    {
        *b = *b + 5;
        *c = *c + 4;
        printf("\n%d %d %d %d", a, b, c, d1);
    }
    }

int funcion2(int *dpa, int cpa)
{
    int b1;
    a = 1;
    b1 = 7;

    funcion1(-1, dpa, &b1);
    /*Obseva que el parametro d que enviamos a funcion1 es por referencia.
    Es equivalente escribir &*d a escribir solamente d. */

    printf("\n%d %d %d %d", a, b, c, d);
    cpa += 3;
    (*dpa) += 2;
    printf("\n%d %d %d %d", a, b1, cpa, dpa);
    return (cpa);
}
