#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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







    return 0;
}
