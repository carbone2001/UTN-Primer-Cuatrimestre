#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "empleados.h"
#define MENU 2

int main()
{
    eMenu menues[20];
    eEmpleados emp[100];
    hcdMenu(menues,20);
    printf("%d   %s   %d",menues[MENU].menuCod,menues[MENU].desc,menues[MENU].importe);
    return 0;
}
