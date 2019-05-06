#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "clientes.h"
#include "pubs.h"
#include "listar.h"
void printClientes(cliente cli[],int tam, publicacion pub[], int tamPub)
{
    printf("\nID               Nombre            Apellido            CUIT    Cant. Pubs");
    int i;
    int j;

    for(i=0; i<tam; i++)
    {

        cli[i].avisos=0;
        if(cli[i].estado==1)
        {

            for(j=0; j<tamPub; j++)
            {
                //printf("\nEntro al FOR J");
                if(pub[j].idCli==cli[i].id && pub[j].estado==1)
                {

                    cli[i].avisos++;
                }
            }
            printf("\n%4d    %15s     %15s     %s        %d\n",cli[i].id,cli[i].nombre,cli[i].apellido,cli[i].cuil,cli[i].avisos);

        }


    }
}
void printPublicaciones(cliente cli[],int tam, publicacion pub[], int tamPub)
{
    printf("\nNumero de Aviso             ID Cliente               Cuil Cliente              Numero Rubro          ");
    int i;
    int j;

    for(i=0; i<tamPub; i++)
    {


        if(pub[i].estado==1)
        {

            for(j=0; j<tam; j++)
            {
                //printf("\nEntro al FOR J");
                if(pub[i].idCli==cli[j].id && pub[j].estado==1)
                {

                    printf("\n%d    %d    %s     %d    \n",pub[i].idPub,pub[i].idCli,cli[j].cuil,pub[i].rubro);
                }
            }

        }


    }
}
void informarClientes(cliente cli[], int tam, publicacion pub[], int tamPub)
{
    int opcion;
    printf("\n1. Cliente con mas avisos activos");
    printf("\n2. Cliente con mas avisos pausados");
    printf("\n3. Cliente con mas avisos");
    opcion=getInt("\nIngrese opcion");
    switch(opcion)
    {
    case 1:
        clienteMasAvisosActivos(cli,tam,pub,tamPub);
        break;
    case 2:
        clienteMasAvisosPausados(cli,tam,pub,tamPub);
        break;
    case 3:
        clienteMasAvisos(cli,tam,pub,tamPub);
        break;
    default:
        printf("Opcion invalida");
        break;
    }
}
void clienteMasAvisos(cliente cli[], int tam, publicacion pub[], int tamPub)
{
    int maximo;
    int i;
    int j;
    int cliente;
    int flag;
    flag=0;

    for(i=0; i<tam; i++)
    {

        cli[i].avisos=0;
        if(cli[i].estado==1)
        {

            for(j=0; j<tamPub; j++)
            {

                if(pub[j].idCli==cli[i].id)
                {

                    cli[i].avisos++;
                }
            }


        }


    }



    for(i=0; i<tam; i++)
    {
        if(flag==0)
        {
            if(cli[i].estado==1)
            {
                maximo=cli[i].avisos;
                cliente=i;
                flag=1;

            }
        }
        else
        {
            if(cli[i].avisos>maximo)
            {
                maximo=cli[i].avisos;
                cliente=i;
            }
        }
    }
    printf("\nEl cliente con mas avisos es %s    %s    cuit: %s con %d avisos",cli[cliente].nombre,cli[cliente].apellido,cli[cliente].cuil,cli[cliente].avisos);
}
void clienteMasAvisosActivos(cliente cli[],int tam,publicacion pub[],int tamPub)
{
    int i;
    int j;
    int maximo;
    int cliente;
    int flag;
    flag=0;
    for(i=0; i<tam; i++)
    {
        cli[i].avisosActivos=0;
        for(j=0; j<tamPub; j++)
        {
            if(pub[j].idCli==cli[i].id && pub[j].estado==1 && cli[i].estado==1)
            {

                cli[i].avisosActivos++;
            }

        }
    }
    for(i=0; i<tam; i++)
    {
        if(flag==0)
        {
            if(cli[i].estado==1)
            {
                maximo=cli[i].avisosActivos;
                cliente=i;
                flag=1;

            }
        }
        else
        {

            if(maximo<cli[i].avisosActivos && cli[i].estado==1)
            {
                maximo=cli[i].avisosActivos;
                cliente=i;
            }

        }

    }
    printf("\nEl cliente con mayor avisos activos:");
    printf("\n %s    %s     %s    cantidad de avisos activos: %d",cli[cliente].nombre,cli[cliente].apellido,cli[cliente].cuil,cli[cliente].avisosActivos);
}
void clienteMasAvisosPausados(cliente cli[],int tam,publicacion pub[],int tamPub)
{
    int i;
    int j;
    int maximo;
    int cliente;
    int flag;
    flag=0;
    for(i=0; i<tam; i++)
    {
        cli[i].avisosPausados=0;
        for(j=0; j<tamPub; j++)
        {
            if(pub[j].idCli==cli[i].id && pub[j].estado==0 && cli[i].estado==1)
            {

                cli[i].avisosPausados++;
            }

        }
    }
    for(i=0; i<tam; i++)
    {
        if(flag==0)
        {
            if(cli[i].estado==1)
            {
                maximo=cli[i].avisosPausados;
                cliente=i;
                flag=1;

            }
        }
        else
        {

            if(maximo<cli[i].avisosPausados && cli[i].estado==1)
            {
                maximo=cli[i].avisosPausados;
                cliente=i;
            }

        }

    }
    printf("\nEl cliente con mayor avisos activos:");
    printf("\n %s    %s     %s    cantidad de avisos pausados: %d",cli[cliente].nombre,cli[cliente].apellido,cli[cliente].cuil,cli[cliente].avisosActivos);
}
void informarPublicaciones(publicacion pub[],int tamPub,eRubro rubros[],int tamRub)
{
    int opcion;
    printf("\n1. Cantidad de publicaciones de un rubro.");
    printf("\n2. Rubro con mas publicaciones activas.");
    printf("\n3. Rubro con menos publicaciones activas.");
    getIntIntentos(&opcion,"\nIngrese opcion","\nOpcion invalida",1,3,1);
    switch(opcion)
    {
    case 1:
        cantidadPubRubro(pub,tamPub);
        break;
    case 2:
        rubroMasPubActivas(pub,tamPub,rubros,tamRub);
        break;
    case 3:
        break;
    default:
        system(("cls"));
        break;
    }

}
void cantidadPubRubro(publicacion pub[],int tamPub)
{
    int i;
    int rubro;
    int cantPubRubro;
    cantPubRubro=0;
    rubro=getInt("\nIngrese rubro: ");
    for(i=0; i<tamPub; i++)
    {

        if(rubro==pub[i].rubro && pub[i].estado==1)
        {
            cantPubRubro=cantPubRubro+1;
        }
    }
    printf("La cantidad de publicaciones activas correspondientes al rubro %d son %d",rubro,cantPubRubro);
}
void rubroMasPubActivas(publicacion pub[],int tamPub,eRubro rubros[],int tamRub)
{
    int i;
    int j;
    int cantPubRubro;
    int maxPub;
    int maxRub;
    for(i=0; i<tamRub; i++)
    {
        cantPubRubro=0;
        for(j=0; j<tamPub; j++)
        {
            if(rubros[i].id==pub[i].rubro && pub[i].estado==1)
            {
                cantPubRubro=cantPubRubro+1;
            }
        }
        if(i==0)
        {
            maxPub=cantPubRubro;
            maxRub=i;
        }
        else
        {
            if(cantPubRubro>maxPub)
            {
                maxPub=cantPubRubro;
                maxRub=i;

            }
        }

    }
    printf("El rubro con mayor cantidad de publicaciones es: %d (%s). Con %d publicaciones.",rubros[maxRub].id,rubros[maxRub].desc,maxPub);
}
void rubroMenosPubActivas(publicacion pub[],int tamPub,eRubro rubros[],int tamRub)
{
    int i;
    int j;
    int cantPubRubro;
    int minPub;
    int minRub;
    for(i=0; i<tamRub; i++)
    {
        cantPubRubro=0;
        for(j=0; j<tamPub; j++)
        {
            if(rubros[i].id==pub[i].rubro && pub[i].estado==1)
            {
                cantPubRubro=cantPubRubro+1;
            }
        }
        if(i==0)
        {
            minPub=cantPubRubro;
            minRub=i;
        }
        else
        {
            if(cantPubRubro<minPub)
            {
                minPub=cantPubRubro;
                minRub=i;

            }
        }

    }
    printf("El rubro con menor cantidad de publicaciones es: %d (%s). Con %d publicaciones.",rubros[minRub].id,rubros[minRub].desc,minPub);
}
