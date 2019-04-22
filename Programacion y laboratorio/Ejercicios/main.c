#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define TAM_SEC 4
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "biblioteca.h"
int main()
{
    char salir='n';
    int selecSec;
    empleado emp[TAM]= {{1423,"Juan",'m',13500,{1,10,1998},19002,1},{1001,"Lucas",'m',65000,{10,01,2001},19001,1},{6543,"Sol",'f',32000,{23,04,1999},19002,1},{3265,"Alberto",'m',15437.78,{15,06,1989},19004,1},{2876,"Cristal",'f',45700.65,{21,11,2000},19003,1}};
    eSector sectores[TAM_SEC] = {{19001,"Ventas"},{19002,"Finanzas"},{19003,"Sistemas"},{19004,"RRHH"}};
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
            modificarEmpleado(sectores,TAM_SEC,emp,TAM);
            break;
        case 4:
            printf("Legajo     Nombre     Sexo       Sueldo    Fecha de nacimiento");
            mostrarEmpleados(sectores,TAM_SEC,emp,TAM);
            break;
        case 5:
            ordenarEmpleados(emp,TAM);
            break;
        /*case 7:
            listarSectores(sectores,TAM_SEC,selecSec,emp,TAM);
            break;*/
        case 6:
            listarSectores(sectores,TAM_SEC,emp,TAM);
            printf("Ingrese el sector que desee listar en particular: ");
            scanf("%d",&selecSec);
            listarSector(sectores,TAM_SEC,selecSec,emp,TAM);
            break;
        case 7:
            cantidadEmpSector(sectores,TAM_SEC,emp,TAM);
            break;

        case 8:
            printf("Seguro que quiere salir? s/n \n");
            salir=getche();
            salir=tolower(salir);
            system(("cls"));
            break;
        }
    }
    return 0;
}
