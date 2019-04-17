#include <stdio.h>
#include <stdlib.h>
#define TAM 20
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "biblioteca.h"
int main()
{
    char salir='n';
    empleado emp[TAM]= {{1423,"Juan",'m',13500,{1,10,1998},1},{1001,"Lucas",'m',65000,{10,01,2001},1},{6543,"Sol",'f',32000,{23,04,1999},0},{3265,"Alberto",'m',15437.78,{15,06,1989},1},{2876,"Cristal",'f',45700.65,{21,11,2000},1}};
    //inicializarEmpleados(emp,TAM);
    while(salir!='s')
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(emp,TAM);
            break;
        case 2:
            bajaEmpleado(emp,TAM);
            break;
        case 3:
            modificarEmpleado(emp,TAM);
            break;
        case 4:
            printf("Legajo     Nombre     Sexo       Sueldo    Fecha de nacimiento");
            mostrarEmpleados(emp,TAM);
            break;
        case 5:
            ordenarEmpleados(emp,TAM);
            break;
        case 6:
            printf("Seguro que quiere salir? s/n \n");
            salir=getche();
            salir=tolower(salir);
            system(("cls"));
            break;
        }
    }
    return 0;
}
