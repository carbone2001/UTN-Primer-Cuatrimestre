#include <stdio.h>
#include <stdlib.h>
#include "pubs.h"
void inicializarPubs(publicacion pub[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        pub[i].estado=0;
    }
}

void publicarPub(publicacion pub[],int tam)
{
    int sameId;
    int id;
    int free=buscarLibrePub(pub,tam);
    printf("Ingresar ID del cliente: ");
    scanf("%d",&pub[free].idCli);
    printf("Ingrese numero de rubro\n");
    scanf("%d",&pub[free].rubro);
    printf("Ingrese texo del aviso\n");
    getString(pub[free],65);
    id=getRandom(0,99999,1);
    sameId=buscarIdPub(pub,tam,id);
    while(sameId==id)
    {
        id=getRandom(0,99999,1);
        sameId=buscarIdPub(pub,tam,id);
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
