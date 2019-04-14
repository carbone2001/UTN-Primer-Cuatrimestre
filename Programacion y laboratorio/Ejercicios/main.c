#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT 3
struct agenda
{
    char nombre[31];
    char apellido[31];
    int legajo;
};


int main()
{
    struct agenda persona[CANT];
    struct agenda datoNulo;
    char cadAux[100];
    int i=0;
    int opcion;
    int opcionBaja;
    int error=0;
    int j;
    int k;
    int l;
    int contador=0;

    strcpy(datoNulo.nombre,"Vacio");
    strcpy(datoNulo.apellido,"Vacio");
    datoNulo.legajo=0;

    while(opcion!=4)
    {
        printf(" 1. Realizar una alta\n 2. Realizar una baja \n 3. Mostrar listado por apellidos\n 4. Salir\n Seleccione opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nombre de la persona %d\n",i+1);
            setbuf(stdin,NULL);
            gets(persona[i].nombre);
            strcpy(cadAux,persona[i].nombre);
            while(strlen(cadAux)>30)
            {
                printf("El nombre no puede ser mayor de los 30 caracteres\n");
                printf("Ingrese nombre de la persona %d\n",i+1);
                setbuf(stdin,NULL);
                gets(persona[i].nombre);
                strcpy(cadAux,persona[i].nombre);

            }
            printf("Ingrese apellido de la persona %d\n",i+1);
            setbuf(stdin,NULL);
            gets(persona[i].apellido);
            strcpy(cadAux,persona[i].apellido);
            while(strlen(cadAux)>30)
            {
                printf("El nombre no puede ser mayor de los 30 caracteres\n");
                printf("Ingrese apellido de la persona %d\n",i+1);
                setbuf(stdin,NULL);
                gets(persona[i].apellido);
                strcpy(cadAux,persona[i].apellido);
            }
            printf("Ingrese legajo de la persona %d\n",i+1);
            scanf("%d",&persona[i].legajo);
            while(error==0 && i>0)
            {

                if(error==0)
                {
                    for(j=0; j<i; j++)
                    {
                        if(persona[j].legajo==persona[i].legajo)
                        {
                            error=1;
                            break;
                        }
                    }

                }
                while(error==1)
                {
                    printf("El legajo ingresado ya existe. Ingrese otro numero de legajo: ");
                    scanf("%d",&persona[i].legajo);
                    if(persona[j].legajo==persona[i].legajo)
                    {
                        error=1;
                    }
                    else
                    {
                        error=2;
                    }
                }
                error=2;
            }
            contador++;
            i++;
            break;
        case 2:
            printf("A que persona desea realizarle la baja?");
            scanf("%d",&opcionBaja);
            printf("La persona %d ha sido dada de baja\n",opcionBaja);
            persona[opcionBaja-1]=datoNulo;
            break;
            case 3:
            for(k=0; k<contador; k++)
            {
                strlwr(persona[k].apellido);
            }
            for(j=0; j<contador-1; j++)
            {

                for(l=j+1;l<contador;l++)
                {
                    if(strcmp(persona[j].apellido,persona[l].apellido)>0)
                    {
                        char auxCad[31];
                        strcpy(auxCad,persona[j].apellido);
                        strcpy(persona[j].apellido,persona[l].apellido);
                        strcpy(persona[l].apellido,auxCad);
                    }

                }


            }
            for(j=0; j<contador; j++)
            {
                printf("Pesona %d: Nombre: %s Apellido: %s Legajo: %d\n",j+1,persona[j].nombre,persona[j].apellido,persona[j].legajo);
            }
            break;

        }


    }


    /*for(i=0; i<CANT; i++)
    {
        printf("Ingrese nombre de la persona %d\n",i+1);
        setbuf(stdin,NULL);
        gets(persona[i].nombre);
        strcpy(cadAux,persona[i].nombre);
        while(strlen(cadAux)>30)
        {
            printf("El nombre no puede ser mayor de los 30 caracteres\n");
            printf("Ingrese nombre de la persona %d\n",i+1);
            setbuf(stdin,NULL);
            gets(persona[i].nombre);
            strcpy(cadAux,persona[i].nombre);
        }
        printf("Ingrese apellido de la persona %d\n",i+1);
        setbuf(stdin,NULL);
        gets(persona[i].apellido);
        strcpy(cadAux,persona[i].apellido);
        while(strlen(cadAux)>30)
        {
            printf("El nombre no puede ser mayor de los 30 caracteres\n");
            printf("Ingrese apellido de la persona %d\n",i+1);
            setbuf(stdin,NULL);
            gets(persona[i].apellido);
            strcpy(cadAux,persona[i].apellido);
        }
        printf("Ingrese legajo de la persona %d\n",i+1);
        scanf("%d",&persona[i].legajo);
    }

    for(i=0; i<CANT; i++)
    {
        printf("Pesona %d: Nombre: %s Apellido: %s Legajo: %d\n",i+1,persona[i].nombre,persona[i].apellido,persona[i].legajo);
    }*/




    return 0;
}
