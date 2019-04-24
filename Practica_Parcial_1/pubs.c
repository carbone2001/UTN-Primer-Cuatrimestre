#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "pubs.h"
#include "clientes.h"
#include "inputs.h"
void inicializarPubs(publicacion pub[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        pub[i].estado=0;
    }
}

void publicarPub(publicacion pub[],int tamPub,cliente cli[],int tam)
{
    int sameId;
    int clienteFound;
    int idCli;
    int id;
    int free;
    free=buscarLibrePub(pub,tamPub);
    printf("Ingresar ID del cliente: ");
    scanf("%d",&idCli);
    clienteFound=buscarId(cli,tam,idCli);
    if(clienteFound==-1)
    {
        printf("Cliente no encontrado.");
    }
    else
    {
        printf("Ingrese numero de rubro\n");
        scanf("%d",&pub[free].rubro);
        getString(pub[free].aviso,"Ingrese texo del aviso\n","Solo puedes escribir un maximo de 64 caracteres\n",65,-1);
        id=getRandom(1,9999,1);
        sameId=buscarIdPub(pub,tam,id);
        while(sameId!=-1)
        {
            id=getRandom(1,9999,1);
            sameId=buscarIdPub(pub,tam,id);
        }
        pub[free].idPub=id;
        pub[free].estado=1;
        printf("El ID de la publicacion es %0004d",id);

    }


}
int buscarLibrePub(publicacion pub[],int tam)
{
    int i;
    int lugarLibre=-1;
    for(i=0; i<tam; i++)
    {
        if(pub[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}
int buscarIdPub(publicacion pub[],int tam,int id)
{
    int sameId=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(pub[i].estado==1 && pub[i].idPub==id)
        {
            sameId=i;
            break;
        }
    }
    return sameId;
}
void pausarPub(publicacion pub[],int tamPub,cliente cli[],int tam)
{
    int idPub;
    int pausePub;
    int idCliPause;
    char confirm;
    printf("\nIngrese ID de la publicacion: ");
    scanf("%d",&idPub);
    pausePub=buscarIdPub(pub,tamPub,idPub);

    if(pausePub==-1)
    {
        printf("\nEl ID ingresado no corresponde a ninguna publicacion.\n");
    }
    else
    {
        printf("\nLa publicacion (ID: %0004d) corresponde al cliente:\n",idPub);
        idCliPause=buscarCliente(cli,tam,(pub[pausePub].idCli));
        mostrarCliente(cli[idCliPause]);
        printf("Confirme para pausar la publicacion (s/n)\n");
        confirm=getche();
        confirm=tolower(confirm);
        if(confirm=='s')
        {
            pub[pausePub].estado=0;
            printf("La publicacion se ha pausado con exito!!!");
        }
        else
        {
            printf("La publicacion no ha sido pausada.");
        }
    }
}
void reanudarPub(publicacion pub[],int tamPub,cliente cli[],int tam)
{
    int idPub;
    int resumePub;
    int idCliResume;
    char confirm;
    printf("\nIngrese ID de la publicaion: ");
    scanf("%d",&idPub);
    resumePub=buscarIdPubAll(pub,tamPub,idPub);
    if(resumePub==-1)
    {
        printf("\nEl ID ingresado no corresponde a ninguna publicacion.\n");
    }
    else
    {
        if(pub[resumePub].estado==0)
        {
            printf("\nLa publicacion (ID: %0004d) corresponde al cliente:\n",idPub);
        idCliResume=buscarCliente(cli,tam,pub[resumePub].idCli);
        mostrarCliente(cli[idCliResume]);
        printf("Confirme para reanudar la publicacion (s/n)\n");
        confirm=getche();
        confirm=tolower(confirm);
        if(confirm=='s')
        {
            pub[resumePub].estado=0;
            printf("La publicacion se ha reanudado con exito!!!");
        }
        else
        {
            printf("La publicacion no ha sido reanudada!");
        }

        }
        else
        {
            printf("La publicacion NO esta pausada.");
        }

    }
}
int buscarIdPubAll(publicacion pub[],int tam,int id)
{
    int sameId=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(pub[i].idPub==id)
        {
            sameId=i;
            break;
        }
    }
    return sameId;
}
