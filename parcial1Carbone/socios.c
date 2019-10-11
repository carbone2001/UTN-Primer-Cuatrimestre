#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fechas.h"
#include "inputs.h"
#include "socios.h"

int menu()
{
    int opcion;
    printf("\n***  ABM SOCIOS  ***\n");
    printf("1. Alta de socio.\n");
    printf("2. Modificar datos de socio.\n");
    printf("3. Baja de socio\n");
    printf("4. Listar socios\n");
    printf("5. Listar libros\n");
    printf("6. Listar autores\n");
    printf("7. Prestamos\n");
    scanf("%d",&opcion);
    return opcion;
}
void altaSocio(eSocio soc[],int tam,int *codigoSocio)
{
    int free;
    free=buscarLibre(soc,tam);
    if(free==-1)
    {
        printf("\nNo se ha encontrado un lugar en el sistema.\n");
    }
    else
    {

        getString(soc[free].nombre,"\nIngrese Nombre: ","El nombre no debe superar los 30 caracteres",31,0);
        getString(soc[free].apellido,"\nIngrese Apellido: ","El apellido no debe superar los 30 caracteres",31,0);
        soc[free].sexo=getCharSex("\nIngrese sexo");
        while(soc[free].sexo=='0')
        {
            soc[free].sexo=getChar("\nSexo invalido!!. Ingrese sexo nuevamente: ");

        }
        getString(soc[free].telefono,"Ingrese numero de telefono","No debe superar los 15 caracteres",15,0);
        getString(soc[free].eMail,"Ingrese eMail","No debe superar los 30 caracteres",30,0);
        printf("Ingerse fecha");
        getIntIntentos(&soc[free].fechaAsoc.dia,"\nIngrese fecha de asociacion. \n dia: ","Dia incorrecto",1,30,0);
        getIntIntentos(&soc[free].fechaAsoc.mes,"\n Mes: ","Mes incorrecto",1,12,0);
        getIntIntentos(&soc[free].fechaAsoc.anio,"\n Anio: ","Anio invalido",1950,2019,0);
        *codigoSocio=*codigoSocio+1;
        soc[free].codigo=*codigoSocio;
        soc[free].estado=1;
        printf("La alta del socio ha sido exitosa. El Codigo de socio: %d",soc[free].codigo);
    }

}
int buscarLibre(eSocio soc[],int tam)
{
    int i;
    int lugarLibre=-1;
    for(i=0; i<tam; i++)
    {
        if(soc[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}
void modificarSocio(eSocio soc[],int tam,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        int codigo;
        int socio;
        int opcion=0;
        printf("Ingrese el Codigo del socio que desea modificar");
        scanf("%d",&codigo);
        socio=buscarCodSoc(soc,tam,codigo);
        if(socio==-1)
        {
            printf("El cliente seleccionado no existe");
        }
        else
        {
            while(opcion!=6)
            {
                printf("\n\nQue desea modificar (codigo: %d):",soc[socio].codigo);
                printf("\n 1. Nombre");
                printf("\n 2. Apellido");
                printf("\n 3. Sexo");
                printf("\n 4. Telefono");
                printf("\n 5. eMail");
                printf("\n 6. Volver al menu");
                printf("\nSeleccione su opcion:");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getString(soc[socio].nombre,"\nIngrese Nombre: ","El nombre no debe superar los 30 caracteres",31,0);
                    printf("\nEl nombre se ha modificado con exito!!!\n");
                    break;
                case 2:
                    getString(soc[socio].apellido,"\nIngrese Apellido: ","El apellido no debe superar los 30 caracteres",31,0);
                    printf("\nEl apellido se ha modificado con exito!!!\n");
                    break;
                case 3:
                    soc[socio].sexo=getChar("\nIngrese sexo");
                    while(soc[socio].sexo=='0')
                    {
                        soc[socio].sexo=getChar("\nSexo invalido!!. Ingrese sexo nuevamente: ");

                    }
                    printf("\nEl sexo se ha modificado con exito!!!\n");
                    break;
                case 4:
                    getString(soc[socio].telefono,"Ingrese numero de telefono","No debe superar los 15 caracteres",15,0);
                    printf("\nEl telefono se ha modificado con exito!!!n");
                    break;
                case 5:
                    getString(soc[socio].eMail,"Ingrese eMail","No debe superar los 30 caracteres",30,0);
                    printf("\nEl eMail se ha modificado con exito!!!n");
                    break;
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
    else
    {
        printf("Debe haber al menos un alta!");
    }

}
int buscarCodSoc(eSocio soc[],int tam,int codigo)
{
    int sameCod=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(soc[i].estado==1 && soc[i].codigo==codigo)
        {
            sameCod=i;
            break;
        }
    }
    return sameCod;
}
void bajaSocio(eSocio soc[],int tam,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        int codigo;
        int socio;
        printf("\nIngrese codigo del socio para dar de baja: ");
        scanf("%d",&codigo);
        socio=buscarCodSoc(soc,tam,codigo);
        if(socio==-1)
        {
            printf("El socio seleccionado no existe");
        }
        else
        {
            soc[socio].estado=0;
            printf("El socio de codigo: %d fue dado de baja con exito!!!",soc[socio].codigo);
        }

    }
    else
    {
        printf("ERROR. Debe haber al menos un alta de socio");
    }

}
void listarSocios(eSocio soc[],int tamSoc,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        ordAsStructStrSoc(soc,tamSoc);
        printf("\n Apellido   Nombre   Codigo Sexo     Telefono                         eMail    Fecha de asociacion");
        int i;

        for(i=0; i<tamSoc; i++)
        {
            if(soc[i].estado==1)
            {
                printf("\n%s    %s     %d     %c         %s        %s  %2d/%2d/%2d\n",soc[i].apellido,soc[i].nombre,soc[i].codigo,soc[i].sexo,soc[i].telefono,soc[i].eMail,soc[i].fechaAsoc.dia,soc[i].fechaAsoc.mes,soc[i].fechaAsoc.anio);

            }
        }
    }
    else
    {
        printf("ERROR. Debe haber al menos un alta de socio");
    }

}
void ordAsStructStrSoc(eSocio soc[],int tam)
{
    int i;
    int j;
    eSocio aux;
    for(i=0; i<tam; i++)
    {
        strlwr(soc[i].nombre);
    }
    for(i=0; i<tam; i++)
    {
        strlwr(soc[i].apellido);
    }
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((strcmp(soc[i].apellido,soc[j].apellido))>0 && (soc[i].estado==1 && soc[j].estado==1))
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }
        }
    }
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((strcmp(soc[i].nombre,soc[j].nombre))>0 && (soc[i].estado==1 && soc[j].estado==1) && (strcmp(soc[i].apellido,soc[j].apellido))==0)
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }
        }
    }
}

