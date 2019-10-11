
#ifndef pubs_H_INCLUDED
#define pubs_H_INCLUDED

//aca van las estructuras y prototipos



typedef struct
{
    int id;
    char nombre[25];
    char apellido[25];
    char cuil[12];
    int estado;
    int avisos;
    int avisosActivos;
    int avisosPausados;
} cliente;

int menu();
void altaCliente(cliente cli[], int tam);
void bajaCliente(cliente cli[],int tam);
void modificarCliente(cliente cli[],int tam);

void ordenarCliente(cliente cli[],int tam);
void inicializarCliente(cliente cli[],int tam);
int buscarId(cliente cli[],int tam,int legajo);
int buscarLibre(cliente cli[],int tam);
int buscarCliente(cliente cli[],int tam,int id);
void mostrarCliente(cliente cli);
void mostrarClientes(cliente cli[],int tam);
void ordenarId(cliente cli[],int tam);
void ordenarNombres(cliente cli[],int tam);

#endif // employee_H_INCLUDED
