#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_VEC 5
struct agenda
{
    char nombre[20];
    char apellido[20];
    char calle[30];
    int altura;
};

int main()
{
    struct agenda persona[TAM_VEC],aux;
    int i;
    int j;

    //HARCODEO
    strcpy(persona[0].nombre,"lucas");
    strcpy(persona[0].apellido,"carbone");
    strcpy(persona[0].calle,"852");
    persona[0].altura=2317;

    strcpy(persona[1].nombre,"juan");
    strcpy(persona[1].apellido,"perez");
    strcpy(persona[1].calle,"893");
    persona[1].altura=4765;

    strcpy(persona[2].nombre,"luis");
    strcpy(persona[2].apellido,"espert");
    strcpy(persona[2].calle,"Mitre");
    persona[2].altura=750;

    strcpy(persona[3].nombre,"alberto");
    strcpy(persona[3].apellido,"spineta");
    strcpy(persona[3].calle,"Arredondo");
    persona[3].altura=940;

    strcpy(persona[4].nombre,"gustavo");
    strcpy(persona[4].apellido,"cerati");
    strcpy(persona[4].calle,"Humberto Primo");
    persona[4].altura=3544;



    printf("Tamaño de personas es %d\n",TAM_VEC);
    /*
    for(i=0; i<TAM_VEC; i++)
    {
        printf("Ingresar nombre persona %d\n",i+1);
        fflush(stdin);
        gets(persona[i].nombre);
        printf("Ingresar apellido persona %d\n",i+1);
        fflush(stdin);
        gets(persona[i].apellido);
        printf("Ingresar la calle de la persona %d\n",i+1);
        gets(persona[i].calle);
        printf("Ingresar altura (direccion) de la persona %d\n",i+1);
        scanf("%d",&persona[i].altura);
    }
    */
    printf("Antes del ordenamiento\n");
    for(i=0; i<TAM_VEC; i++)
    {
        printf("Persona %d se llama %s %s, su calle es %s y su altura es %d\n",i+1,persona[i].nombre,persona[i].apellido,persona[i].calle,persona[i].altura);
    }
    printf("\n\nDespues del ordenamiento\n");
    for(i=0; i<TAM_VEC-1; i++)
    {
        for(j=i+1; j<TAM_VEC; j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }
        }
    }
    for(i=0; i<TAM_VEC; i++)
    {
        printf("Persona %d se llama %s %s, su calle es %s y su altura es %d\n",i+1,persona[i].nombre,persona[i].apellido,persona[i].calle,persona[i].altura);
    }

    //ORDENAMIENTO POR INSERCION
    for(i=1; i<TAM_VEC; i++)
    {
        aux=persona[i];
        j=i-1;
        while((strcmp(persona[i].nombre,persona[j].nombre)<0)&& j>=0)
        {

            persona[j+1]=persona[j];
            j--;
        }
        persona[j+1]=aux;
    }
    printf("\n\nDespues del ordenamiento por insercion\n");
    for(i=0; i<TAM_VEC; i++)
    {
        printf("Persona %d se llama %s %s, su calle es %s y su altura es %d\n",i+1,persona[i].nombre,persona[i].apellido,persona[i].calle,persona[i].altura);
    }


    return 0;
}
