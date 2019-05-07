#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autores.h"

void hcdAut(eAutor aut[],int tamAut)
{
    int i;
    eAutor autHcd[5]=
    {
        {1001,"name1","surname1",1},
        {1002,"name2","surname2",1},
        {1003,"name3","surname3",1},
        {1004,"name4","surname4",1},
        {1005,"name5","surname5",1},
    };
    for(i=0;i<tamAut;i++)
    {
        aut[i]=autHcd[i];
    }
}
void listarAutores(eAutor aut[],int tamAut)
{
    int j;
    ordAsStructStrAut(aut,tamAut);
    printf("Codigo de autor    Apellido         Nombre");
    for(j=0;j<tamAut;j++)
    {
        if(aut[j].estado)
        {
            printf("\n%d                %s         %s\n",aut[j].cod,aut[j].apellido,aut[j].nombre);
        }


    }
}
void ordAsStructStrAut(eAutor aut[],int tamAut)
{
    int i;
    int j;
    eAutor aux;
    for(i=0; i<tamAut; i++)
    {
        strlwr(aut[i].nombre);
    }
    for(i=0; i<tamAut; i++)
    {
        strlwr(aut[i].apellido);
    }
    for(i=0; i<tamAut-1; i++)
    {
        for(j=i+1; j<tamAut; j++)
        {
            if((strcmp(aut[i].apellido,aut[j].apellido))>0 && (aut[i].estado==1 && aut[j].estado==1))
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
        }
    }
    for(i=0; i<tamAut-1; i++)
    {
        for(j=i+1; j<tamAut; j++)
        {
            if((strcmp(aut[i].nombre,aut[j].nombre))>0 && (aut[i].estado==1 && aut[j].estado==1) && (strcmp(aut[i].apellido,aut[j].apellido))==0)
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
        }
    }
}

