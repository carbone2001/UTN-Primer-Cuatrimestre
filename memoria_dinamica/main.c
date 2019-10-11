#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

int nlptr(void* pointer);
int main()
{
    eEmpleado* emp;
    emp = (eEmpleado*) malloc (sizeof(eEmpleado));
    printf("\nIngrese legajo:");
    scanf("%d",&emp->legajo);
    printf("\nIngrese nombre:");
    fflush(stdin);
    gets(emp->nombre);
    printf("\nIngrese sexo");
    scanf("%c",&emp->sexo);
    printf("\nIngrese sueldo");
    scanf("%f",&emp->sueldo);

    printf("Leg: %d Nombre: %s Sexo: %c Sueldo: %.2f",emp->legajo,emp->nombre,emp->sexo,emp->sueldo);

    free(emp);

    /*
    int* pNum;
    int* aux;
    pNum = (int*) malloc (sizeof(int)*5);
    if(nlptr(pNum) == 1)
    {
        exit(1);
    }

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero %d:",i);
        scanf("%d",(pNum+sizeof(int)*i));
    }
    for(int i=0; i<5; i++)
    {
        printf("\nNumero ingresado: %d",*(pNum+sizeof(int)*i));
        printf(" Direccion: %x",pNum+i);
    }


    //AGRANDAR
    aux = (int*) realloc(pNum,10);
    if(aux!=NULL)
    {
        pNum = aux;
        printf("\n Se agrando array a 10 elementos\n");
    }
    else
    {
        printf("\nMEMORIA INSUFICIENTE\n");
        exit(1);
    }

    for(int i=5; i<10; i++)
    {
        printf("Ingrese un numero %d:",i);
        scanf("%d",pNum+sizeof(int)*i);
    }
    for(int i=0; i<10; i++)
    {
        printf("\nNumero ingresado: %d",*(pNum+i*sizeof(int)));
        printf(" Direccion: %x",pNum+i);
    }
    printf("\nPrograma terminado");


    //ACHICAR
    printf("\n\nAchicando array\n\n");

    pNum = (int*) realloc(pNum,sizeof(int)*5);
    for(int i=0; i<10; i++)
    {
        printf("\nNumero ingresado: %d",*(pNum+i*sizeof(int)));
        printf(" Direccion: %x",pNum+i);
    }*/
    return 0;
}
int nlptr(void* pointer)
{
    int null=0;
    if(pointer==NULL)
    {
        null=1;
    }
    return null;
}
