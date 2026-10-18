#include<stdio.h>

int main(){

    // Varibles
    char nomAlumno[5][20], nomMateria[3][20];
    int calificaciones[5][3], i, j, promedioALuno[5], promedioMateria[3];
int opcion, opcion2;
int mayor, menor, indiceMayor, indiceMenor;
int aprobados, reprobados;
    // Ingreso de datos
 // Menu de opciones
do
{
    printf("Menu de opciones\n");
    printf("1.Ingresar Materias:\n");
    printf("2.Ingresar Alumnos:\n");
    printf("3.Ingresar Calificaciones:\n");
    printf("4.Mostrar Promedio de cada Alumno:\n");
    printf("5.Mostrar Promedio de cada Materia:\n");
    printf("6.Calificacion mas alta y baja por estudiante y por asignatura.\n");
    printf("7.El numero de estudiantes aprobados y reprobados por asignatura.\n");
    printf("8.Salir\n");
    scanf("%d", &opcion);

switch (opcion)
{ 
    case 1:
        printf("Usted ha seleccionado la opcion 1: Ingresar Materias\n");
        for (i = 0; i < 3; i++)
        {
            printf("Ingrese el nombre de la materia %d:\n", i + 1);
            scanf("%s", nomMateria[i]);
        }
        break;  

    case 2:
        printf("Usted ha seleccionado la opcion 2: Ingresar Alumnos\n");
        for (i = 0; i < 5; i++)
        {
            printf("Ingrese el nombre del alumno %d:\n", i + 1);
            scanf("%s", nomAlumno[i]);
        }
        break;  
    
    case 3:
        printf("Usted ha seleccionado la opcion 3: Ingresar Calificaciones\n");
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("Ingrese la calificacion del alumno %s en la materia %s:\n", nomAlumno[i], nomMateria[j]);
                scanf("%d", &calificaciones[i][j]);
            do
            {
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                {
                    printf("Calificacion invalida. Ingrese una calificacion entre 0 y 10:\n");
                    scanf("%d", &calificaciones[i][j]);
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
            
            }
        }
        break;
    case 4:
        printf("Usted ha seleccionado la opcion 4: Mostrar Promedio de cada Alumno\n");
        for (i = 0; i < 5; i++)
        {
            promedioALuno[i] = 0;
            for (j = 0; j < 3; j++)
            {
                promedioALuno[i] += calificaciones[i][j];
            }
            promedioALuno[i] /= 3;
            printf("El promedio del alumno %s es: %d\n", nomAlumno[i], promedioALuno[i]);
        }
        break;
    case 5:
        printf("Usted ha seleccionado la opcion 5: Mostrar Promedio de cada Materia\n");
        for (j = 0; j < 3; j++)
        {
            promedioMateria[j] = 0;
            for (i = 0; i < 5; i++)
            {
                promedioMateria[j] += calificaciones[i][j];
            }
            promedioMateria[j] /= 5;
            printf("El promedio de la materia %s es: %d\n", nomMateria[j], promedioMateria[j]);
        }
        break;
    case 6:
        printf("Usted ha seleccionado la opcion 6: Calificación más alta y baja por estudiante y por asignatura\n");
         // Mayor y menor nota de cada estudiante
    for (i = 0; i < 5; i++)
    {
        mayor = calificaciones[i][0];
        menor = calificaciones[i][0];
        indiceMayor = 0;
        indiceMenor = 0;

        for (j = 1; j < 3; j++)
        {
            if (calificaciones[i][j] > mayor)
            {
                mayor = calificaciones[i][j];
                indiceMayor = j;
            }

            if (calificaciones[i][j] < menor)
            {
                menor = calificaciones[i][j];
                indiceMenor = j;
            }
        }

        printf("%s: mayor nota %d en %s; menor nota %d en %s\n",
               nomAlumno[i], mayor, nomMateria[indiceMayor],
               menor, nomMateria[indiceMenor]);
    }

    // Mayor y menor nota de cada materia
    for (j = 0; j < 3; j++)
    {
        mayor = calificaciones[0][j];
        menor = calificaciones[0][j];
        indiceMayor = 0;
        indiceMenor = 0;

        for (i = 1; i < 5; i++)
        {
            if (calificaciones[i][j] > mayor)
            {
                mayor = calificaciones[i][j];
                indiceMayor = i;
            }

            if (calificaciones[i][j] < menor)
            {
                menor = calificaciones[i][j];
                indiceMenor = i;
            }
        }

        printf("%s: mayor nota %d de %s; menor nota %d de %s\n",
               nomMateria[j], mayor, nomAlumno[indiceMayor],
               menor, nomAlumno[indiceMenor]);
    }

        break;
    case 7:
        printf("Usted ha seleccionado la opcion 7: El número de estudiantes aprobados y reprobados por asignatura\n");
        
    for (j = 0; j < 3; j++)
    {
        aprobados = 0;
        reprobados = 0;

        for (i = 0; i < 5; i++)
        {
            if (calificaciones[i][j] >= 7)
            {
                aprobados++;
            }
            else
            {
                reprobados++;
            }
        }

        printf("%s: %d aprobados y %d reprobados\n",
               nomMateria[j], aprobados, reprobados);
    }
        break;
    case 8:
        printf("Usted ha seleccionado la opcion 8: Salir\n");
        return 0;
        break;

    default:
        printf("Opcion no valida\n");
}

     printf("Desea continuar con el menu de opciones? (1=si, 0=no)\n");
     scanf("%d", &opcion2);

     } while (opcion2 == 1);

    return 0;
}



