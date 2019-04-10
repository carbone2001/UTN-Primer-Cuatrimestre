#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#include <ctype.h>
#include <string.h>

int main()
{
    char nombre[][20]= {{"sebastian"},{"luz"},{"Margarita"},{"esteban"},{"cristal"}};
    char apellido[][20]= {{"Aguirre"},{"aVELLANEDA"},{"LOPEZ"},{"baracus"},{"carbone"}};
    char sexo[]= {'m','f','f','m','f'};
    int legajo[]= {48654,76854,83974,50375,17492};
    float sueldo[]= {11500.99,21870.45,16200.60,23835.21,63800.77};
    int i;
    int j;
    int auxInt;
    char auxChar;
    float auxFloat;
    char auxCad[30];
    char auxCad2[30];
    int opcion;

    while(opcion!=7)
    {
        printf("\n\nMENU\n");
        printf(" 1) Ordenar por nombre\n 2) Ordenar por apellido\n 3) Ordenar por legajo\n 4) Ordenar por sueldo\n 5) Ordenar por sexo\n 6) Mostrar formulario\n 7) Salir\n Escriba la opcion: ");
        scanf("%d",&opcion);
        for(i=0; i<TAM; i++)
        {
            strlwr(nombre[i]);
            strlwr(apellido[i]);
        }
        switch(opcion)
        {
            case 1:
            for(i=1; i<TAM; i++)
            {
                for(j=i-1; j<TAM-1; j++)
                {
                    if(strcmp(nombre[i],nombre[j])<0)
                    {
                        strcpy(auxCad,nombre[i]);
                        strcpy(nombre[i],nombre[j]);
                        strcpy(nombre[j],auxCad);

                        auxFloat = sueldo[i];
                        sueldo[i] = sueldo[j];
                        sueldo[j] = auxFloat;

                        auxChar = sexo[i];
                        sexo[i] = sexo[j];
                        sexo[j] = auxChar;

                        auxInt = legajo[i];
                        legajo[i] = legajo[j];
                        legajo[j] = auxInt;

                        strcpy(auxCad, apellido[i]);
                        strcpy(apellido[i],apellido[j]);
                        strcpy(apellido[j],auxCad);
                    }
                }
            }
            printf("\nLa operacion se ha realizado con exito!\n");
            break;

        case 2:
            for(i=1; i<TAM; i++)
            {
                for(j=i-1; j<TAM-1; j++)
                {
                    if(strcmp(apellido[i],apellido[j])<0)
                    {
                        strcpy(auxCad, apellido[i]);
                        strcpy(apellido[i],apellido[j]);
                        strcpy(apellido[j],auxCad);

                        strcpy(auxCad,nombre[i]);
                        strcpy(nombre[i],nombre[j]);
                        strcpy(nombre[j],auxCad);

                        auxFloat = sueldo[i];
                        sueldo[i] = sueldo[j];
                        sueldo[j] = auxFloat;

                        auxChar = sexo[i];
                        sexo[j] = sexo[j];
                        sexo[j] = auxChar;

                        auxInt = legajo[i];
                        legajo[i] = legajo[j];
                        legajo[j] = auxInt;
                    }

                }
            }
            printf("\nLa operacion se ha realizado con exito!\n");
            break;

        case 3:
            for(i=1; i<TAM; i++)
            {
                auxInt=legajo[i];
                strcpy(auxCad,apellido[i]);
                strcpy(auxCad2,nombre[i]);
                auxFloat = sueldo[i];
                auxChar = sexo[i];
                j=i-1;

                while(auxInt<legajo[j]&&j>=0)
                {
                    legajo[j+1]=legajo[j];
                    strcpy(apellido[j+1],apellido[j]);
                    strcpy(nombre[j+1],nombre[j]);
                    sueldo[j+1] = sueldo[j];
                    sexo[j+1] = sexo[j];
                    j--;
                }
                legajo[j+1]=auxInt;
                strcpy(apellido[j+1],auxCad);
                strcpy(nombre[j+1],auxCad2);
                sueldo[j+1] = auxFloat;
                sexo[j+1] = auxChar;
            }
            printf("\nLa operacion se ha realizado con exito!\n");
            break;

        case 6:
            for(i=0; i<TAM; i++)
            {
                strlwr(nombre[i]);
                nombre[i][0]=toupper(nombre[i][0]);
                strlwr(apellido[i]);
                apellido[i][0]=toupper(apellido[i][0]);
            }
            printf("    Nombres    Apellidos Sexo Legajo   Sueldo\n\n");
            for(i=0; i<TAM; i++)
            {
                printf("%12s %12s  %c   %d   %.2f  \n",nombre[i],apellido[i],sexo[i],legajo[i],sueldo[i]);
            }
            break;



        }

    }





    //Poner maxusculas solo al comienzo de los nombres/apellidos.


    //ORDENADO POR SEXO
    for(i=1; i<TAM; i++)
    {

        for(j=i-1; j<TAM-1; j++)
        {
            if(sueldo[i]<sueldo[j])
            {
                auxFloat = sueldo[i];
                sueldo[i] = sueldo[j];
                sueldo[j] = auxFloat;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;
                /*

                strcpy(auxCad[i], nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxCad[i]);

                strcpy(auxCad[i], apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j],auxCad[i]);
                */

                auxInt = legajo[i];
                printf("\nLa operacion se ha realizado con exito!\n");
                legajo[i] = legajo[j];
                legajo[j] = auxInt;
            }
        }
    }

    return 0;
}
