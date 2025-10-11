#include <stdio.h>

/* Primos.
El programa alamacena en un arreglo unidimensional los primeros 100 nuemros
primos.*/

const int TAM = 100;

void Imprime(int[], int);     /*Prototipos de funciones. */
void Primo(int, int *);

void main(void)
{
    int P[TAM];
    P[0] = 1;
    P[1] = 2;

    int FLA, J = 2, PRI = 3;

    while (J <= TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);    /* Se llama a la funcio que determina si PRI es
        primo. */

        if(FLA)            /*Si FLA es 1 entoces PRI es primo. */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);
}

void Primo(int A, int *B)
/*Esta funcion determina si A es primo, cuyo caso el valor de *B no se
altera*/
{
    int DI = 3;
    while (*B && (DI < (A / 2)))
    {
        if((A % DI) ==0)
            *B = 0;
        DI++;
}
}

void Imprime(int Primos[], int T)
/*Esta funcion imprime el arreglo unidmensional de los numeros primo. */
{
    int I;
    for (I=0; I < T; I++)
    printf("\nPrimos[%d]:  %d", I, Primos[I]);
}
