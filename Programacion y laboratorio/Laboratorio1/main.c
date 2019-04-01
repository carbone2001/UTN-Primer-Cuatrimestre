#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5];
    int i;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&vec[i]);
    }
    printf("\nLos numeros ingresados son:");
    for(i=0;i<5;i++)
    {
        printf(" %d ",vec[i]);
    }



    return 0;
}
