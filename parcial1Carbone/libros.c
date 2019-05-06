#include <stdio.h>
#include <stdlib.h>
#include "libros.h"
void hcdLib(eLibro lib[],int tamLib)
{
    eLibro libHcd[5]=
    {
        {2001,"name1",1001,1},
        {2002,"name2",1002,1},
        {2003,"name3",1003,1},
        {2004,"name4",1004,1},
        {2005,"name5",1005,1},
    };

    int i;
    for(i=0;i<tamLib;i++)
    {
        lib[i]=libHcd[i];
    }
}
