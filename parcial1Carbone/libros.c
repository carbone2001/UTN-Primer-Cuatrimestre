#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libros.h"
void hcdLib(eLibro lib[],int tamLib)
{
    eLibro libHcd[100]=
    {
        {2001,"title2",1,1},
        {2002,"title5",2,1},
        {2003,"title4",3,1},
        {2004,"title3",4,1},
        {2005,"title1",5,1},
    };

    int i;
    for(i=0;i<tamLib;i++)
    {
        lib[i]=libHcd[i];
    }
}
void listarLibros(eLibro lib[],int tamLib)
{
    int j;
    ordAsStructStrLib(lib,tamLib);
    printf("Codigo de libro    Titulo         Codigo de Autor");
    for(j=0;j<tamLib;j++)
    {
        if(lib[j].estado)
        {
            printf("\n%d                %s         %d\n",lib[j].cod,lib[j].titulo,lib[j].codAutor);
        }


    }
}
void ordAsStructStrLib(eLibro lib[],int tamLib)
{
    int i;
    int j;
    eLibro aux;
    for(i=0;i<tamLib;i++)
    {
        strlwr(lib[i].titulo);
    }
    for(i=0;i<tamLib-1;i++)
    {
        for(j=i+1;j<tamLib;j++)
        {
            if((strcmp(lib[i].titulo,lib[j].titulo))>0 && (lib[i].estado==1 && lib[j].estado==1))
            {
                aux=lib[i];
                lib[i]=lib[j];
                lib[j]=aux;
            }
        }
    }
}
void inicializarLibros(eLibro lib[],int tamLib)
{
    int i;
    for(i=0; i<tamLib; i++)
    {
        lib[i].estado=0;
    }
}
int buscarCodLib(eLibro lib[],int tamLib,int codigo)
{
    int sameCod=-1;
    int i;
    for(i=0; i<tamLib; i++)
    {
        if(lib[i].estado==1 && lib[i].cod==codigo)
        {
            sameCod=i;
            break;
        }
    }
    return sameCod;
}
