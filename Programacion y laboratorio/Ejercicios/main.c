#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
<<<<<<< HEAD
#include <ctype.h>
#include "utn.h"
#define CANT 5


int main()
{
    int numIngresado;
    int random;
    char again;
    random=getRandom(0,100,1);
    again='s';
    while(again=='s')
    {

        while(numIngresado!=random)
        {
            numIngresado=getInt("\nIngrese un numero entre el 0 y el 100\n");
            if(numIngresado<0)
            {
                printf("El numero ingresado no corresponde a un abonado en servicio");
                break;
            }

            else if(numIngresado>random)
            {
                printf("\nTE PASASTE!");
            }
            else if(numIngresado<random)
            {
                printf("\nMUY POCO!");
            }
            else if(numIngresado==random)
            {
                printf("\nFELICIDADES!! GANASTE!!");
            }

        }

        printf("Desea jugar otra vez? (s/n)");
        setbuf(stdin,NULL);
        scanf("%c",&again);
        again=tolower(again);
    }


=======
#include <conio.h>
#include <windows.h>
#include "biblioteca.h"
void mostrarVector1(int vec[],int tam); //Ultiliza vectores muestra con vectores
void mostrarVector2(int vec[],int tam); //Ultiliza vectores muestra con punters
void mostrarVector3(int* vec,int tam); //Ultiliza punteros muestra con punteros
void mostrarVector4(int* vec,int tam); //Ultiliza punteros muestra con vectores
void mostrarCadena(char* cadena);
int main()
{
    int x[6] = {10,5,4,6,3};
    int *p;
    char nombre[]="\nSebastian";
    //int ** r;
    //p=&x;
    //r=&p;
    mostrarVector1(x,5);
    mostrarVector2(x,5);
    mostrarVector3(x,5);
    mostrarVector4(x,5);
    mostrarCadena(nombre);
>>>>>>> 32cd6c1737b6aff7283019a39cb4229111acdf03





    return 0;

}
void mostrarVector1(int vec[],int tam)
{
    printf("Motrar vector 1: ");
    int i;
    for(i=0;i<tam;i++)
    {
        printf(" %d",*(vec+i));
    }

}
void mostrarVector2(int vec[],int tam)
{
    printf("\nMotrar vector 2: ");
    int i;
    for(i=0;i<tam;i++)
    {
        printf(" %d",vec[i]);
    }
}
void mostrarVector3(int* vec,int tam)
{
    printf("\nMotrar vector 3: ");
    int i;
    for(i=0;i<tam;i++)
    {
        printf(" %d",*(vec+i));
    }

}
void mostrarVector4(int* vec,int tam)
{
    printf("\nMotrar vector 4: ");
    int i;
    for(i=0;i<tam;i++)
    {
        printf(" %d", vec[i]);
    }

}
void mostrarCadena(char* cadena)
{
    int i;
    for(i=0;*(cadena+i)!= '\0';i++)
    {
        printf("%c",*(cadena+i));
    }
    /*
    while(*cadena!='\0')
    {
        printf("%c",*cadena);
        cadena++;
    }*/

}
