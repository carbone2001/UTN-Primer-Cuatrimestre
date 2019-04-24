typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
   int menuCod;
   char desc[52];
   int importe;
}eMenu;

typedef struct
{
    int codAlm;
    int codMenu;
    int codEmp;
    eFecha fechaAlm;

}eAlmuerzo;

typedef struct
{
    int legajo;
    char apellido[52];
    char nombre[52];
    char sexo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;
}eEmpleados;
void hcdMenu(eMenu menues[],int tamMenu);
