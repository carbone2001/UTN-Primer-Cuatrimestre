#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>

int main()
{
    int num1;
    int num2;
    int opcion;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoFactorial;
    int resultadoFactorial2;
    num1=0;
    num2=0;

    while(opcion!=5)
    {
        printf("\nTRABAJO PRACTICO Nª1\n");

        printf("1) Ingresar 1er operando(A=%d)\n",num1);
        printf("2) Ingresar 2do operando(B=%d)\n",num2);
        printf("3) Calcular todas las operaciones\n");
        printf("  a) Calcular la suma (%d+%d)\n",num1,num2);
        printf("  b) Calcular la resta (%d-%d)\n",num1,num2);
        printf("  c) Calcular la division(%d/%d)\n",num1,num2);
        printf("  d) Calcular la multiplicacion(%d*%d)\n",num1,num2);
        printf("  e) Calcular el factorial (%d!)\n",num1);
        printf("4) Informar resultados \n");
        printf("5) Salir.\n");
        scanf("%d",&opcion);
        while(opcion>5 || opcion<1)
        {
            printf("La opcion ingresada es incorrecta.\n");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
            printf("Ingrese el numero: ");
            scanf("%d",&num1);
            break;
            case 2:
            printf("Ingrese el numero: ");
            scanf("%d",&num2);
            break;
            case 3:
            resultadoSuma=fsumar(num1,num2);
            resultadoResta=frestar(num1,num2);
            resultadoDivision=fdivision(num1,num2);
            resultadoMultiplicacion=fmultiplicacion(num1,num2);
            resultadoFactorial=ffactorial(num1);
            resultadoFactorial2=ffactorial(num2);
            break;
            case 4:
            printf("El resultado de %d+%d es: %d\n",num1,num2,resultadoSuma);
            printf("El resultado de %d-%d es: %d\n",num1,num2,resultadoResta);
            if(num1==0||num2==0)
            {
                printf("No es posible dividir por cero\n");
            }
            else
            {
                if(num1%num2!=0)
                {
                    printf("El resultado de %d/%d es: %f\n",num1,num2,resultadoDivision);

                }
                else
                {
                    printf("El resultado de %d/%d es: %.0f\n",num1,num2,resultadoDivision);
                }

            }

            printf("El resultado de %d*%d es: %d\n",num1,num2,resultadoMultiplicacion);
            printf("El factorial de %d es: %d y El factorial de %d es %d\n",num1,resultadoFactorial,num2,resultadoFactorial2);
            system(("pause"));
            break;
        }

    }

    /*
    printf("\nTRABAJO PRACTICO Nª1\n");
    printf(" Ingrese primer operando\n");
    scanf("%d",&num1);
    printf(" Ingrese segundo operando\n");
    scanf("%d",&num2);
    printf("Menu\n");
    printf("1) Ingresar 1er operando(A=%d)\n",num1);
    printf("2) Ingresar 2do operando(B=%d)\n",num2);
    printf("3) Calcular todas las operaciones\n");
    printf("  a) Calcular la suma (%d+%d)\n",num1,num2);
    printf("  b) Calcular la resta (%d-%d)\n",num1,num2);
    printf("  c) Calcular la division(%d/%d)\n",num1,num2);
    printf("  d) Calcular la multiplicacion(%d*%d)\n",num1,num2);
    printf("  e) Calcular el factorial (%d!)\n",num1);
    printf("4) Informar resultados \n");
    printf("5) Salir.\n");


    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
        printf("Ingrese el numero: ");
        fflush(stdin);
        scanf("%d",&num1);
        printf("Modificacion realizada. Que quiere hacer ahora?\n");
        fflush(stdin);
        scanf("%d",opcion);
        break;

        case 3:
        resultadoSuma=fsumar(num1,num2);
        resultadoResta=frestar(num1,num2);
        resultadoDivision=fdivision(num1,num2);
        resultadoMultiplicacion=fmultiplicacion(num1,num2);
        resultadoFactorial=ffactorial(num1);
        resultadoFactorial2=ffactorial(num2);

        break;
        case 4:
        printf("El resultado de %d+%d es: %d",num1,num2,resultadoSuma);
        printf("El resultado de %d-%d es: %d",num1,num2,resultadoResta);
        printf("El resultado de %d/%d es: %f",num1,num2,resultadoDivision);
        printf("El resultado de %d*%d es: %d",num1,num2,resultadoMultiplicacion);
        printf("El factorial de %d es: %d y El factorial de %d es: %d",num1,resultadoFactorial,num2,resultadoFactorial2);
        break;
    }
    */

    return 0;
}
