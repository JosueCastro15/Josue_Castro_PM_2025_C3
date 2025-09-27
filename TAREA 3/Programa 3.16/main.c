#include <stdio.h>

/* Calificaciones.
El programa, al recibir un grupo de calificaciones de un alumn, obtiene el pro
medio de calificaciones de cada uno de ellosy, ademas, los alumnos con el mejor
y peor promedio.

I, MAT, MAMAT y MEMAT: variables de tipo entero.
CAL, NUM, MAPRO, MEPRO y PRO: variables de tipo real. */

void main(void)
{
    int I, MAT, MAMAT, MEMAT;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;
    printf("Ingrese la matricula del primer alumno:\t");
    scanf("%d", &MAT);

    while (MAT)
    {
        SUM = 0;
        for (I = 1; I <= 5; I++)
        {
            printf("\tIngrese la calificacion del alumno: ", I);
            scanf("%f", &CAL);
            SUM += CAL;
        }
        PRO = SUM / 5;
        printf("\nMatricula:%d\tPromedio:%5.2f", MAT, PRO);
        if (PRO > MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }
        if (PRO < MEPRO)
        {
            MEPRO = PRO;
            MEMAT = MAT;
        }
        printf("\nIngrese la matricula del siguiente alumno: ");
        scanf("%d", &MAT);
    }
    printf("\nAlumno con mejor Promedi:\t%d\t\%5.2f", MAMAT, MAPRO);
    printf("\nAlumno con peor Promedio:\t%d\t\%5.2f", MEMAT, MEPRO);
}
