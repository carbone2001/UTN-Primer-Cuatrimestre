#include <stdio.h>
#include <stdlib.h>
int getIntIntentos(int* input,char* msj,char* eMsj,int minimo,int maximo,int reintentos)
{
    int i;
    int error;
    error=0;
    int num;
    num=*input;
    printf("%s",msj);
    scanf("%d",&num);
    if(num<minimo||num>maximo)
    {
        if(reintentos)
        {
            for(i=0;i<reintentos;i++)
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
int getRandom(int primerNumero, int ultimoNumero,int primeraVez)
{
    if(primeraVez)
    {
        srand(time(NULL));
    }
    int random;
    random=primerNumero+(rand()%(ultimoNumero+1-primerNumero));
    return random;
}
