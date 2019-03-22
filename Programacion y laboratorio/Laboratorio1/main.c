#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //para habilitar toupper o tolower


int main()
{
    int valor,min,max,flag=0;
    char rta;
    do
    {
        printf("Ingrese un valor: ");
        scanf("%d",&valor);
        if(flag==0 || valor>max)
        {
            max=valor;
        }
        if(flag==0 || valor<min)
        {
            min=valor;
            flag=1;
        }
        fflush(stdin);
        printf("Continuar [S/N]?");
        scanf("%c",&rta);
        rta=toupper(rta);
    }while(rta!='S'&& rta!='N');

    printf("El minimo es %d y el maximo %d",min,max);
    /*
    char hora;
    int horaInt;
    printf("Ingrese horario\n");
    scanf("%c",&hora);
    switch(hora)
    {
        case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    printf("A dormir\n");
    break;
    case '7':
    case '8':
    printf("Buenos dias\n");
    break;
    case '9':
    printf("Cualquier hora\n");
    break;
    default:
    printf("El numero ingresado es invalido\n");
    break;



    }

    fflush(stdin);
    printf("Ingrese horario (int)\n");
    scanf("%d",&horaInt);


    switch(horaInt)
    {
        case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        printf("A dormir");
        break;
    case 7:
    case 8:
    case 9:
        printf("Buenos dias");
        break;
    case 10:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    printf("Cualquier cosa");
    break;
    default:
    printf("El dato ingresado es invalido");
    break;

    }
    */
    return 0;
}
