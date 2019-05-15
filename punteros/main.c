#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[40];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
}eEmpleado;

void mostrarCadena2(char* punteroCadena);
int main()
{
    int a=3;
    int* punteroInt=&a;
    int** punteroPuntero=&punteroInt;
    printf("\n%d",**punteroPuntero);
    printf("\n%d",*punteroInt);





    /*char letra='a';
    char palabra[]="Hola";
    mostrarCadena2(palabra);*/



    /*eEmpleado unEmpleado = {1234,"Juan",'m',30000,{1,1,2011}};
    eEmpleado otroEmpleado = {4321,"Ana",'f',20000,{10,10,2019}};
    eEmpleado lista[] = {unEmpleado,otroEmpleado};
    eEmpleado* punteroEmpleado;
    punteroEmpleado = &unEmpleado;
    printf("Legajo: %d", punteroEmpleado->legajo);
    printf("\n anio: %d", punteroEmpleado->fechaIngreso.anio);
    printf("\n nombre %s", (*punteroEmpleado).nombre);
    printf("\nNomre de otroEmpleado: %s", (lista+1)->nombre);
    int i;
    for(i=0;i<2;i++)
    {
         printf("\nNombre: %s", (lista+i)->nombre);
    }*/

    return 0;
}
void mostrarCadena2(char* punteroCadena)
{
    int i;
    i=0;
    while(*(punteroCadena+i) != '\0')
    {
        printf("\n%c    %p",*(punteroCadena+i),punteroCadena);
        i++;
    }
}
