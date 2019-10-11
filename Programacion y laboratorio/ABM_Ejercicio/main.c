#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT 4
#include <conio.h>

typedef struct agenda
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;
}eEmpleado;
void marcadorEmpleados(eEmpleado vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vec[i].estado=0;

    }
}
void mostrarEmpleado(eEmpleado emp)
{
    if(emp.estado==1)
    {
        printf("\n %5d  %8s       %1c    %.2f\n",emp.legajo,emp.nombre,emp.sexo,emp.sueldo);
    }
    else
    {
        printf("\nEl empleado ingresado no existe\n");
    }
}
void mostrarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    printf("Legajo    Nombre    Sexo    Sueldo");

    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==1)
        {

             mostrarEmpleado(vec[i]);
        }
    }
}
int buscarLibre(eEmpleado vec[],int tam)
{
    int i;
    int lugarLibre=-1;
    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
        {
            lugarLibre=i;
        }
    }
    return lugarLibre;
}


int main()
{
    eEmpleado empleados[CANT]={{1234,"Juan",'m',3000,0},{1122,"JOrge",'m',31000,1},{2211,"Alfedo",'m',22000,1},{3344,"Julieta",'m',25000,1}};
    int opcion;
    char exitConfirm='n';
    int lugarLibre;

    while(exitConfirm!='s')
    {
        printf("  *** ABM Empleados *** \n 1. Alta empleados\n 2. Baja empleados \n 3. Modificacion empleado\n 4. Listar\n 5. Ordenar\n 6. Salir\n Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("\nAlta empleado\n");
            lugarLibre=buscarLibre(empleados,CANT);
            if(lugarLibre==-1)
            {
                printf("\nNo se encontro un espacio libre\n\n");
                break;
            }
            system(("pause"));
            break;
        case 2:
            printf("Baja empleado");
            system(("pause"));
            break;
        case 3:
            printf("Modificaion empleado");
            system(("pause"));
            break;
        case 4:
            printf("\nListar empleados\n\n");
            mostrarEmpleados(empleados,3);
            system(("pause"));
            break;
        case 5:
            break;
        case 6:
            printf("Desea salir? s/n: ");
            fflush(stdin);
            exitConfirm=getche();
            exitConfirm=tolower(exitConfirm);
            printf("\n");
            system(("cls"));
            break;

        }


    }
    return 0;
}
