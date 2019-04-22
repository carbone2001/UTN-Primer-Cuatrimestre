#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientes.h"
/*void ordAsStructStr(cliente cli[],int tam)
{
    int i;
    int j;
    cliente aux;
    for(i=0;i<tam;i++)
    {
        strlwr(cli[i].nombre);
    }
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if((strcmp(pers[i].nombre,pers[j].nombre))>0 && (pers[i].estado==1 && pers[j].estado==1))
            {
                aux=pers[i];
                pers[i]=pers[j];
                pers[j]=aux;
            }
        }
    }
}*/

void ordAs(int * nombreVector, int sizeVector)
{
    int i;
    int j;
    int aux;
    int vector[sizeVector];
    for(i=0;i<sizeVector;i++)
    {
        vector[i]=nombreVector[i];
    }
    for(i=0;i<sizeVector-1;i++)
    {
        for(j=i+1;j<sizeVector;j++)
        {
            if(vector[i]>vector[j])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
    for(i=0;i<sizeVector;i++)
    {
        nombreVector[i]=vector[i];
    }
}

void ordDes(int * nombreVector, int sizeVector)
{
    int i;
    int j;
    int aux;
    int vector[sizeVector];
    for(i=0;i<sizeVector;i++)
    {
        vector[i]=nombreVector[i];
    }
    for(i=0;i<sizeVector-1;i++)
    {
        for(j=i+1;j<sizeVector;j++)
        {
            if(vector[i]<vector[j])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
    for(i=0;i<sizeVector;i++)
    {
        nombreVector[i]=vector[i];
    }
}
void ordIncer(int * vector,int lenght)
{
    int i;
    int j;
    int aux;
    for(i=1;i<lenght;i++)
    {
        aux=vector[i];
        j=i-1;
        while(aux<vector[j]&&j>=0)
        {
            vector[j+1]=vector[j];
            j--;
        }
        vector[j+1]=aux;
    }
}
