#include <stdio.h>
#include <stdlib.h>
int obtenerMaximo(int x, int y, int z); //prototipo de la funcion
int main()
{
    int num1;
    int num2;
    int num3;
    int maximo;
    printf("Ingrese el primer numero\n");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&num2);
    printf("Ingrese el tercer numero\n");
    scanf("%d",&num3);
    maximo=obtenerMaximo(num1,num2,num3);
    printf("El numero maximo es %d",maximo);
    return 0;

}
int obtenerMaximo(int x, int y, int z)
{
    int maximo;
    if(x>y && x>z)
    {
        maximo=x;
    }
    else
    {
        if(y>x && y>z)
        {
            maximo=y;
        }
        else
        {
            maximo=z;
        }
    }
    return maximo;
}

