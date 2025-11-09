#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Decodifica.

El programa decodifica una cadena de caracteres compuesta por numeros
y letras. */

void interpreta(char *); //Prototipo de funcion.

void main(void)
{

    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    interpreta(cad);

}

void interpreta(char *cadena)
{
    //Esta funcion se utiliza para decodificar la cadena de caracteres.

    int i = 0, j, k;

    while(cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))
        {
            k = cadena[i - 1] - 48;
            /* En la variable entera k se alamcena el ascili del numero
            -convertido en caracter- que nos interesa, menos 48 que
            corresponde al ascili del digito 0.*/

            for(j = 0; j < k; j++)
            {
                putchar(cadena[i]);
            }
        }

        i++;

    }
}
