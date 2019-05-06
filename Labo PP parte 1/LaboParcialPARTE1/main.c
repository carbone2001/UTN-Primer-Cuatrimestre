#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "empleados.h"
#define MENU 2
#define LEG 3

int main()
{
    eMenu menues[20];
    eEmpleados emp[100];
    hcdMenu(menues,20);
    hcdEmp(emp,100);
    //printf("%d   %s   %d",menues[MENU].menuCod,menues[MENU].desc,menues[MENU].importe);
    printf("%0.4d   %s   %s   %c    %d  %d  %d    %d   ",emp[LEG].legajo,emp[LEG].nombre,emp[LEG].apellido,emp[LEG].sexo,emp[LEG].fechaIngreso.dia,emp[LEG].fechaIngreso.mes,emp[LEG].fechaIngreso.anio,emp[LEG].idSector);
    return 0;
}
