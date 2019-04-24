
#ifndef pubs_H_INCLUDED
#define pubs_H_INCLUDED

//aca van las estructuras y prototipos



typedef struct
{
    int id;
    char nombre[25];
    char apellido[25];
    long long int cuit;
    int estado;
} cliente;

int menu();
void altaCliente(cliente cli[], int tam);
void bajaCliente(cliente cli[],int tam);
void modificarCliente(cliente cli[],int tam);
void printClientes(cliente cli[],int tam, publicacion pub[], int tamPub);
void ordenarCliente(cliente cli[],int tam);
void inicializarCliente(cliente cli[],int tam);
int buscarId(cliente cli[],int tam,int legajo);
int buscarLibre(cliente cli[],int tam);
int buscarCliente(cliente cli[],int tam,int id);
void mostrarCliente(cliente cli);
void mostrarClientes(cliente cli[],int tam);
void ordenarId(cliente cli[],int tam);
void ordenarNombres(cliente cli[],int tam);
//void ordenarSexos(cliente cli[],int tam);
//void ordenarSueldos(cliente cli[],int tam);
//CUIDADO CUIDADO BORRAR ABAJO SI NO SE USARA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*void listarSector(eSector sector[],int tamSec, int idIngresado,empleado emp[],int tamEmp);
void listarSectores(eSector sector[],int tamSec,empleado emp[],int tamEmp);*/
#endif // employee_H_INCLUDED
