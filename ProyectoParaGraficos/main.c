#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define RES 20

int main()
{
    int matrizGrafica[RES][RES];
    int i;
    int j;
    for(i=0; i<RES; i++)
    {
        for(j=0; j<RES; j++)
        {
            matrizGrafica[i][j]=1;
        }

    }
    /*for(i=0; i<RES; i++)
    {
        for(j=0; j<RES; j++)
        {
            printf(" %d",matrizGrafica[i][j]);
        }

        printf("\n");
    }*/

    for(i=0; i<RES; i++)
    {
        int medio=10;
        int k;
        if(i<RES-1)
        {
            matrizGrafica[i][medio+i]=90;
        }

        for(j=0; j<RES; j++)
        {
            for(k=0; k<RES; k++)
            {

                printf(" %d",matrizGrafica[j][k]);
            }
            Sleep(22);

            printf("\n");
        }

        system("cls");

        printf("\n");

    }

    return 0;
}

