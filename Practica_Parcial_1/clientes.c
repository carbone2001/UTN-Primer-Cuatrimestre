#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "inputs.h"
#include "pubs.h"
int menu()
{
    int opcion;
    printf("\n***  ABM Clientes  ***\n");
    printf("1. Alta de cliente.\n");
    printf("2. Modificar datos de cliente.\n");
    printf("3. Baja de cliente\n");
    printf("4. Publicar\n");
    printf("5. Pausar publicacion\n");
    printf("6. Reanudar publicacion\n");
    printf("7. Imprimir Clientes\n");
    printf("8. Imprimir publicaciones\n");
    printf("9. Informar clientes\n");
    printf("10. Informar publicaciones\n");
    scanf("%d",&opcion);
    return opcion;
}
void altaCliente(cliente cli[],int tam)
{
    int id;
    int sameId;
    int free;
    free=buscarLibre(cli,tam);
    if(free==-1)
    {
        printf("\nNo se ha encontrado un lugar en el sistema.\n");
    }
    else
    {

        getString(cli[free].nombre,"\nIngrese Nombre: ","El nombre no debe superar los 25 caracteres",25,0);
        getString(cli[free].nombre,"\nIngrese Apellido: ","El apellido no debe superar los 25 caracteres",25,0);
        printf("Ingrese CUIT: ");
        scanf("%lld",&cli[free].cuit);
        id=getRandom(1,9999,1);
        sameId=cli[buscarId(cli,tam,id)].id;
        while(sameId==id)
        {
            id=getRandom(1,9999,0);
            sameId=cli[buscarId(cli,tam,id)].id;
        }
        cli[free].id=id;
        cli[free].estado=1;
        printf("La alta del cliente ha sido exitosa. El ID: %d",cli[free].id);

    }
}
void bajaCliente(cliente cli[],int tam)
{
    int id;
    int cliente;
    printf("\nIngrese ID del cliente para dar de baja: ");
    scanf("%d",&id);
    cliente=buscarId(cli,tam,id);
    if(cliente==-1)
    {
        printf("El cliente seleccionado no existe");
    }
    else
    {
        cli[cliente].estado=0;
        printf("El cliente de ID: %d fue dado de baja con exito!!!",cli[cliente].id);
    }

}
void modificarCliente(cliente cli[],int tam)
{
    int id;
    int cliente;
    int opcion=0;
    int newId;
    int sameId;
    printf("Ingrese el ID del cliente que desea modificar");
    scanf("%d",&id);
    cliente=buscarId(cli,tam,id);
    if(cliente==-1)
    {
        printf("El cliente seleccionado no existe");
    }
    else
    {
        while(opcion!=5)
        {
            printf("\n\nQue desea modificar (ID: %d):",cli[cliente].id);
            printf("\n 1. ID");
            printf("\n 2. Nombre");
            printf("\n 3. Apellido");
            printf("\n 4. CUIT");
            printf("\n 5. Volver al menu");
            printf("\nSeleccione su opcion:");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo id: ");
                scanf("%d",&newId);
                sameId=buscarId(cli,tam,newId);
                if(sameId!=-1)
                {
                    printf("\nEl ID ingresado ya existe\n");
                    mostrarCliente(cli[sameId]);
                }
                else
                {
                    cli[cliente].id=newId;
                    printf("\nEl ID ha sido modificado con exito!!!\n");
                }
                break;
            case 2:
                getString(cli[cliente].nombre,"Ingrese nuevo nombre: ","El nombre ingresado no puede superar los 25 caracteres",25,0);
                printf("\nEl nombre se ha modificado con exito!!!\n");
                break;
            case 3:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                getString(cli[cliente].apellido,"Ingrese nuevo apellido: ","El apellido ingresado no puede superar los 25 caracteres",25,0);
                printf("\nEl apellido se ha modificado con exito!!!\n");
                break;
            case 4:
                printf("Ingrese nuevo CUIT: ");
                scanf("%lld",&cli[cliente].cuit);
                printf("\nEl CUIT se ha modificado con exito!!!n");
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
/*void ordenarEmpleados(cliente cli[],int tam)
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
}*/

void inicializarCliente(cliente cli[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cli[i].estado=0;
    }
}
int buscarLibre(cliente cli[],int tam)
{
    int i;
    int lugarLibre=-1;
    for(i=0; i<tam; i++)
    {
        if(cli[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}
int buscarId(cliente cli[],int tam,int id)
{
    int sameId=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(cli[i].estado==1 && cli[i].id==id)
        {
            sameId=i;
            break;
        }
    }
    return sameId;
}
int buscarCliente(cliente cli[],int tam,int id)
{
    int cliFound;
    int i;
    cliFound=-1;
    for(i=0;i<tam;i++)
    {
        if(id==cli[i].id)
        {
            cliFound=i;
            break;
        }
    }
    return cliFound;
}



void mostrarCliente(cliente cli)
{
    printf("%5d %20s     %20s     %11lld        ",cli.id,cli.nombre,cli.apellido,cli.cuit);
}
/*void mostrarEmpleados(empleado emp[],int tam)
{
    int i;
    int contador;
    contador=0;
    for(i=0; i<tam; i++)
    {
        if(emp[i].estado==1)
        {
           printf("%5d %20s     %20     %11d        ",cli[i].id,cli[i].nombre,cli[i].apellido,cli[i].cuit);
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
    int i;
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
}*/
/*void ordenarSexos(empleado emp[],int tam)
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
}*/

/*void ordenarSueldos(empleado emp[],int tam)
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
}*/
/*void listarSector(eSector sector[],int tamSec, int idIngresado,empleado emp[],int tamEmp)
{
    int i;
    int j;
    printf("\nEl ID Ingresado: %d ",idIngresado);
    for(i=0;i<tamSec;i++)
    {
        for(j=0;j<tamEmp;j++)
        {
            if(idIngresado==sector[i].id && idIngresado==emp[j].idSector &&emp[j].estado!=0)
            {
                printf("\nID Sector: %d Sector: %s Empleado: %s Legajo: %d\n",sector[i].id,sector[i].desc,emp[j].nombre,emp[j].legajo);

            }
        }
    }
}*/
/*void listarSectores(eSector sectores[],int tamSec,empleado emp[],int tamEmp)
{
    int i;
    int j;
    for(i=0;i<tamSec;i++)
    {
        printf("\n%s (ID: %d)",sectores[i].desc,sectores[i].id);
        for(j=0;j<tamEmp;j++)
        {
            if(sectores[i].id==emp[j].idSector)
            {
                printf("\n %5d %10s        %1c     %.2f    %02d/%02d/%4d\n",emp[i].legajo,emp[i].nombre,emp[i].sexo,emp[i].sueldo,emp[i].fechaNac.dia,emp[i].fechaNac.mes,emp[i].fechaNac.anio);
            }
        }
    }
}

*/
void printClientes(cliente cli[],int tam,publicacion pub[], int tamPub)
{
    printf("\nID               Nombre            Apellido            CUIT    Cant. Pubs");
    int i;
    int j;
    int cantPubs;

    for(i=0;i<tam;i++)
    {

        cantPubs=0;
        if(cli[i].estado==1)
        {

            for(j=0;j<tamPub;j++)
            {
                //printf("\nEntro al FOR J");
                if(pub[j].idCli==cli[i].id && pub[j].estado==1)
                {

                    cantPubs++;
                }
            }
            printf("\n%4d    %15s     %15s     %lld        %d\n",cli[i].id,cli[i].nombre,cli[i].apellido,cli[i].cuit,cantPubs);

        }


    }
}
