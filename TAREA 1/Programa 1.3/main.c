#include <stdio.h>

/*Pormedio de sueldo.
El program, al recibir como datos seis sueldos de un emplead, calcula tanto el
ingreso toal como el promedio mensual.

CLA: variable de tipo entero.
SU1, SU2, SU3, SU4, SU5, SU6, ING, PRO: variables de tipo real. */

void main (void)
{
int CLA;
float SU1, SU2, SU3, SU4, SU5, SU6, ING, PRO;
 printf("Ingrese la calve del empleado y los 6 sueldos: \n");
  ING = (SU1 + SU2 + SU3 + SU4 + SU5 + SU6);
  PRO = ING / 6;
   printf ("\n %d %5.2f %5.2f", CLA, ING, PRO);
}
