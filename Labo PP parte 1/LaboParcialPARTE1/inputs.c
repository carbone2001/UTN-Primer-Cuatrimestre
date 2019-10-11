#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "inputs.h"
int getIntIntentos(int* input,char* msj,char* eMsj,int minimo,int maximo,int reintentos)
{
    int i;
    int error;
    int num;
    error=0;
    num=*input;
    printf("%s",msj);
    scanf("%d",&num);
    if(num<minimo||num>maximo)
    {
        if(reintentos)
        {
            for(i=0; i<reintentos; i++)
            {
                printf("%s",eMsj);
                scanf("%d",&num);
                if(num>=minimo&&num<=maximo)
                {
                    *input=num;
                    error=0;
                    break;
                }
                else
                {

                    error=1;
                }
            }

        }
        else
        {
            while(num<minimo||num>maximo)
            {
                printf("%s",eMsj);
                scanf("%d",&num);
            }
            *input=num;
        }
    }
    else
    {
        *input=num;
    }
    return error;
}

int getInt(char * msj) //TERMINAR
{
    int aux;
    printf("%s",msj);
    scanf("%d",&aux);

    return aux;
}
void getIntPlus(int*input,char*msj,char*eMsj,int minimo,int maximo) //TERMINAR
{
    printf("%s",msj);
    scanf("%d",input);
    while(*input>maximo || *input<minimo)
    {
        printf("%s",eMsj);
        scanf("%d",input);
    }
}
int getRandom(int primerNumero, int ultimoNumero,int primeraVez)
{
    if(primeraVez)
    {
        srand(time(NULL));
    }
    int random;
    random=primerNumero+(rand()%((ultimoNumero+1)-primerNumero));
    return random;
}
int getChar(char*msj,char letraCorrecta)
{
    int confirmacion;
    char letraEntrada;
    confirmacion=0;
    printf("%s",msj);
    scanf("%c",&letraEntrada);

    if(letraEntrada==letraCorrecta)
    {
        confirmacion=1;
    }
    return confirmacion;
}
void getFloatPlus(float*input,char*msj,char*eMsj,int minimo,int maximo) //TERMINAR
{
    printf("%s",msj);
    scanf("%f",input);
    while(*input>maximo || *input<minimo)
    {
        printf("%s",eMsj);
        scanf("%f",input);
    }
}
int getString(char str[],char*msj,char*eMsj,int limite,int intentos)
{
    int error;
    int contador;
    contador=0;
    error=0;
    if(intentos!=0)
    {
        printf(msj);
        fflush(stdin);
        gets(str);
        contador++;
        while(strlen(str)>limite && contador<intentos)
        {
            printf(eMsj);
            fflush(stdin);
            gets(str);
            if(strlen(str)<=limite)
            {
                error=0;
                break;
            }
            printf(msj);
            error=1;
            contador++;
        }
    }
    else
    {
        printf(msj);
        fflush(stdin);
        gets(str);
        while(strlen(str)>limite)
        {
            printf(eMsj);

            fflush(stdin);
            gets(str);
            if(strlen(str)<=limite)
            {
                error=0;
                break;
            }
            printf(msj);
            error=1;
            contador++;
        }

    }
    return error;
}
