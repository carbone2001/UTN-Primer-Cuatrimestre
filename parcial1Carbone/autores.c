#include <stdio.h>
#include <stdlib.h>
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
