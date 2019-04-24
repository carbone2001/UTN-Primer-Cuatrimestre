#include "clientes.h"
//#ifndef pubs_H_INCLUDED
//#define pubs_H_INCLUDED
typedef struct
{
    int idCli;
    int rubro;
    char aviso[65];
    int idPub;
    int estado;
} publicacion;
/** \brief Inicializa todas las variables estado del vector de estructuras con 0
 * \param El vector de tipo estructura
 * \param El tamanio del vector
 */
void inicializarPubs(publicacion pub[],int tam);
void publicarPub(publicacion pub[],int tamPub,cliente cli[],int tam);
int buscarLibrePub(publicacion pub[],int tam);
int buscarIdPub(publicacion pub[],int tam,int id);
int buscarIdPubAll(publicacion pub[],int tam,int id);
//void printClientes(cliente cli[],int tam,publicacion pub[], int tamPub);
void pausarPub(publicacion pub[],int tamPub,cliente cli[],int tam);
void reanudarPub(publicacion pub[],int tamPub,cliente cli[],int tam);
//#endif
