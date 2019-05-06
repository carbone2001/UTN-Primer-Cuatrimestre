#include "empleados.h"
void hcdMenu(eMenu menues[],int tamMenu)
{
    eMenu menuesHcd[5]={{1,"Sopa",14},{2,"Sanguche",10},{3,"Paty",69},{4,"Ensalada",43}};
    int i;
    for(i=0;i<tamMenu;i++)
    {
        menues[i]=menuesHcd[i];
    }
}
void hcdEmp(eEmpleados emp[],int tamEmp)
{
    eEmpleados empHcd[]={{0001,"Juan","Benitez",'m',{10,01,2001},2,0},{0002,"Alberto","Luis",'m',{19,03,2005},2,0}};
    int i;
    for(i=0;i<tamEmp;i++)
    {
        emp[i]=empHcd[i];
    }
}
