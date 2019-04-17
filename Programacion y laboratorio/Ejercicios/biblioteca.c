#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int menu()
{
    int opcion;
    printf("\n***  ABM Empleados  ***\n");
    printf("1. Alta empleado.\n");
    printf("2. Baja empleado.\n");
    printf("3. Modificar\n");
    printf("4. Listar empleado\n");
    printf("5. Ordenar empleado\n");
    printf("6. Salir\n");
    scanf("%d",&opcion);
    return opcion;
}
void altaEmpleado(empleado emp[],int tam)
{
    int legajo;
    int sameLegajo;
    int free;
    free=buscarLibre(emp,tam);
    if(free==-1)
    {
        printf("\nNo se ha encontrado un lugar en el sistema.\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d",&legajo);
        sameLegajo=buscarLegajo(emp,tam,legajo);
        if(sameLegajo!=-1)
        {
            printf("\nEl legajo ingresado ya existe\n");
            mostrarEmpleado(emp[sameLegajo]);
        }
        else
        {
            emp[free].legajo=legajo;
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            gets(emp[free].nombre);
            printf("\nIngrese sexo: ");
            fflush(stdin);
            scanf("%c",&emp[free].sexo);
            emp[free].sexo=tolower(emp[free].sexo);
            printf("\nIngrese su sueldo: ");
            scanf("%f",&emp[free].sueldo);
            printf("\nIngrese fecha de nacimiento: ");
            printf("\nDia: ");
            scanf("%d",&emp[free].fechaNac.dia);
            printf("\nMes: ");
            scanf("%d",&emp[free].fechaNac.mes);
            printf("\nAnio: ");
            scanf("%d",&emp[free].fechaNac.anio);
            emp[free].estado=1;
            fflush(stdin);
        }
    }
}
void bajaEmpleado(empleado emp[],int tam)
{
    int legajo;
    int empleado;
    printf("\nIngrese legajo para dar de baja: ");
    scanf("%d",&legajo);
    empleado=buscarLegajo(emp,tam,legajo);
    if(empleado==-1)
    {
        printf("El empleado seleccionado no existe");
    }
    else
    {
        emp[empleado].estado=0;
        printf("El empleado de legajo %d fue dado de baja con exito!!!",emp[empleado].legajo);
    }

}
void modificarEmpleado(empleado emp[],int tam)
{
    int legajo;
    int empleado;
    int opcion=0;
    int newLegajo;
    int sameLegajo;
    printf("Ingrese el legajo del empleado que desea modificar");
    scanf("%d",&legajo);
    empleado=buscarLegajo(emp,tam,legajo);
    if(empleado==-1)
    {
        printf("El empleado seleccionado no existe");
    }
    else
    {
        while(opcion!=6)
        {
            printf("\n\nQue desea modificar (legajo: %d):",emp[empleado].legajo);
            printf("\n 1. Legajo");
            printf("\n 2. Nombre");
            printf("\n 3. Sexo");
            printf("\n 4. Sueldo");
            printf("\n 5. Fecha de nacimiento");
            printf("\n 6. Volver al menu");
            printf("\nSeleccione su opcion:");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo legajo: ");
                scanf("%d",&newLegajo);
                sameLegajo=buscarLegajo(emp,tam,newLegajo);
                if(sameLegajo!=-1)
                {
                    printf("\nEl legajo ingresado ya existe\n");
                    mostrarEmpleado(emp[sameLegajo]);
                }
                else
                {
                    emp[empleado].legajo=newLegajo;
                    printf("\nEl legajo ha sido modificado con exito!!!\n");
                }
                break;
            case 2:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(emp[empleado].nombre);
                printf("\nEl nombre se ha modificado con exito!!!\n");
                break;
            case 3:
                printf("Ingrese nuevo sexo: ");
                fflush(stdin);
                scanf("%c",&emp[empleado].sexo);
                printf("\nEl sexo se ha modificado con exito!!!n");
                break;

            case 4:
                printf("Ingrese nuevo sueldo: ");
                scanf("%f",&emp[empleado].sueldo);
                printf("\nEl sueldo se ha modificado con exito!!!n");
                break;
            case 5:
                printf("Ingrese nueva fecha de nacimiento: ");
                printf("\nDia: ");
                scanf("%d",&emp[empleado].fechaNac.dia);
                printf("\nMes: ");
                scanf("%d",&emp[empleado].fechaNac.mes);
                printf("\nAnio: ");
                scanf("%d",&emp[empleado].fechaNac.anio);
                printf("\n La fecha de nacimiento se ha modificado exitosamente");
            case 6:
                system(("cls"));
                break;
            default:
                printf("\n***Opcion invalida***\n");
                break;
            }
        }
    }
}
void ordenarEmpleados(empleado emp[],int tam)
{
    int opcion=0;
    while(opcion!=5)
    {
        printf("\nOrdenar por:\n");
        printf("1.Legajo\n");
        printf("2.Nombre\n");
        printf("3.Sexo\n");
        printf("4.Sueldo\n");
        printf("5. Volver a menu\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ordenarLegajos(emp,tam);
            printf("\n\nSe ha ordenado con exito!!!");
            opcion=5;
            break;
        case 2:
            ordenarNombres(emp,tam);
            printf("\n\nSe ha ordenado con exito!!!");
            \
            opcion=5;
            break;
        case 3:
            ordenarSexos(emp,tam);
            printf("\n\nSe ha ordenado con exito!!!");
            opcion=5;
            break;
        case 4:
            ordenarSueldos(emp,tam);
            printf("\n\nSe ha ordenado con exito!!!");
            opcion=5;
            break;
        case 5:
            system(("cls"));
            break;
        default:
            printf("\n***Opcion invalida***\n");
            break;
        }
    }
}

void inicializarEmpleados(empleado emp[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        emp[i].estado=0;
    }
}
int buscarLibre(empleado emp[],int tam)
{
    int i;
    int lugarLibre=-1;
    for(i=0; i<tam; i++)
    {
        if(emp[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}
int buscarLegajo(empleado emp[],int tam,int legajo)
{
    int sameLegajo=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(emp[i].estado==1 && emp[i].legajo==legajo)
        {
            sameLegajo=i;
            break;
        }
    }
    return sameLegajo;
}
void mostrarEmpleado(empleado emp)
{
    printf("%5d %10s        %1c     %.2f    %2d/%2d/%4d",emp.legajo,emp.nombre,emp.sexo,emp.sueldo,emp.fechaNac.dia,emp.fechaNac.mes,emp.fechaNac.anio);
}
void mostrarEmpleados(empleado emp[],int tam)
{
    int i;
    int contador;
    contador=0;
    for(i=0; i<tam; i++)
    {
        if(emp[i].estado==1)
        {
            printf("\n %5d %10s        %1c     %.2f    %02d/%02d/%4d\n",emp[i].legajo,emp[i].nombre,emp[i].sexo,emp[i].sueldo,emp[i].fechaNac.dia,emp[i].fechaNac.mes,emp[i].fechaNac.anio);
            contador++;
        }
    }
    if(contador==0)
    {
        printf("\nNo se encontraron empleados\n");
    }
}
void ordenarLegajos(empleado emp[],int tam)
{
    int i;
    int j;
    empleado aux;
    for(i=0; i<tam-1; i++)
    {
        aux=emp[i];
        for(j=i+1; j<tam; j++)
        {
            if(emp[i].legajo>emp[j].legajo && emp[i].estado!=0 && emp[j].estado!=0)
            {
                emp[i]=emp[j];
                emp[j]=aux;
            }
        }
    }
}
void ordenarNombres(empleado emp[],int tam)
{
    int i=1;
    int j;
    empleado aux;
    for(i=0; i<tam; i++)
    {
        strlwr(emp[i].nombre);
    }

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((strcmp(emp[i].nombre,emp[j].nombre))>0 && emp[i].estado!=0 && emp[j].estado!=0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
        }
    }
}
void ordenarSexos(empleado emp[],int tam)
{
    int i=1;
    int j;
    empleado aux;
    for(i=0; i<tam; i++)
    {
        emp[i].sexo=toupper(emp[i].sexo);
    }

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(emp[i].sexo>emp[j].sexo && emp[i].estado!=0 && emp[j].estado!=0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
        }
    }
}

void ordenarSueldos(empleado emp[],int tam)
{
    int i=1;
    int j;
    empleado aux;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(emp[i].sueldo<emp[j].sueldo && emp[j].estado!=0 && emp[i].estado!=0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
        }
    }
}

