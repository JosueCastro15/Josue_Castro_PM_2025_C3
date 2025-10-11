#include <stdio.h>

/*Ordenacion por selccion directa. */

const int MAX = 100;

void Lectura(int *, int);
void Ordena(int *, int);      /*Prototipos de funciones.*/
void Imprime (int *, int);

void main(void)
{
    int TAM, VEC[MAX];
    do
    {
      printf("Ingrese el tamano del arreglo: ");
      scanf("%d", &TAM);
    }
    while (TAM>MAX || TAM<1);
        /*Se verifica el tamano del arreglo correcto. */
        Lectura(VEC, TAM);
        Ordena(VEC, TAM);
        Imprime(VEC, TAM);
}

void Lectura(int A[], int T)
/*La funcion lectura se usa para leer un arreglo unidimensional de T
elementos de tipo entereo. */
{
    int I;
    for (I=0;I<T;I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[1]);
    }
}

void Imprime(int A[], int T)
/*Esta funcion se utiliza para escribir un arreglo unidimensional
ordenado de T elementos de tipo entero. */
{
    int I;
    for (I=0;I<T;I++)
        printf("\nA[%d]: %d", I, A[I]);
}

void Ordena(int A[], int T)
/*La funcion Ordena utiliza el metodo de seleccion directa para ordenar
los elementos del arreglo unidimensional A.*/
{
    int I, J, MEN, L;
    for (I=0;I<T;I++)
    {
        MEN = A[I];
        L = I;
        for (J=(I+1); J<T; J++)
            if (A[J] < MEN)
        {
            MEN = A[J];
            L = J;
        }
        A[L] = A[I];
        A[I] = MEN;
}
}
