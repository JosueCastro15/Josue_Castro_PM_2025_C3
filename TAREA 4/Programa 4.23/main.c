#include <stdio.h>

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x)
{
    return(x + x);
}

int main(void)
{
   int a = 5, b =10;

   printf("Antes del trueque: a=%D, b=%d\n", a, b);
   trueque (&a,&b);
   printf("Despues del trueque: a=%d, b=%d\n", a, b);
   printf("El doble de a es: %d\n", suma(a));

return 0;
}

