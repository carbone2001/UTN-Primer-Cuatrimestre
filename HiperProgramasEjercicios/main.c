#include <stdio.h>
#include <stdlib.h>
#define TAM 20
#include <ctype.h>
#include <string.h>
#include <conio.h>


typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;
} empleado;

int menu();
void altaEmpleado(empleado emp[], int tam);
void bajaEmpleado(empleado emp[],int tam);
void modificarEmpleado(empleado emp[],int tam);
void ordenarEmpleados(empleado emp[],int tam);
void inicializarEmpleados(empleado emp[],int tam);
int buscarLegajo(empleado emp[],int tam,int legajo);
int buscarLibre(empleado emp[],int tam);
void mostrarEmpleado(empleado emp);
void mostrarEmpleados(empleado emp[],int tam);
void ordenarLegajos(empleado emp[],int tam);
void ordenarNombres(empleado emp[],int tam);
void ordenarSexos(empleado emp[],int tam);
void ordenarSueldos(empleado emp[],int tam);

int main()
{
    char salir='n';
    empleado emp[TAM]= {{1423,"Juan",'m',13500,1},{1001,"Lucas",'m',65000,1},{6543,"Sol",'f',32000,0},{3265,"Alberto",'m',15437.78,1},{2876,"Cristal",'f',45700.65,1}};
    //inicializarEmpleados(emp,TAM);
    while(salir!='s')
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(emp,TAM);
            break;
        case 2:
            bajaEmpleado(emp,TAM);
            break;
        case 3:
            modificarEmpleado(emp,TAM);
            break;
        case 4:
            printf("Legajo     Nombre     Sexo       Sueldo");
            mostrarEmpleados(emp,TAM);
            break;
        case 5:
            ordenarEmpleados(emp,TAM);
            break;
        case 6:
            printf("Seguro que quiere salir? s/n \n");
            salir=getche();
            salir=tolower(salir);
            system(("cls"));
            break;

        }
    }
    return 0;
}

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
        while(opcion!=5)
        {
            printf("\n\nQue desea modificar (legajo: %d):",emp[empleado].legajo);
            printf("\n 1. Legajo");
            printf("\n 2. Nombre");
            printf("\n 3. Sexo");
            printf("\n 4. Sueldo\n");
            printf(" 5. Volver al menu\n");
            printf("Seleccione su opcion:");
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
    printf("%5d %10s        %1c     %.2f ",emp.legajo,emp.nombre,emp.sexo,emp.sueldo);
}
void mostrarEmpleados(empleado emp[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(emp[i].estado==1)
        {
            printf("\n %5d %10s        %1c     %.2f\n",emp[i].legajo,emp[i].nombre,emp[i].sexo,emp[i].sueldo);
        }
    }
}
void ordenarLegajos(empleado emp[],int tam)
{
    int i;
    int j;
    empleado aux;


    for(i=0; i<tam-1; i++)
    {
        if(emp[i].estado!=0)
        {
            aux=emp[i];
            for(j=i+1; j<tam; j++)
            {
                if(emp[j].estado!=0)
                {
                    if(emp[i].legajo>emp[j].legajo)
                    {
                        emp[i]=emp[j];
                        emp[j]=aux;

                    }
                }

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
        if(emp[i].estado!=0)
        {

            for(j=i+1; j<tam; j++)
            {
                if(emp[j].estado!=0)
                {
                    if((strcmp(emp[i].nombre,emp[j].nombre))>0)
                    {
                        aux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=aux;
                    }
                }

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
        if(emp[i].estado!=0)
        {

            for(j=i+1; j<tam; j++)
            {
                if(emp[j].estado!=0)
                {
                    if(emp[i].sexo>emp[j].sexo)
                    {
                        aux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=aux;
                    }
                }

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


