#include "clientes.h"
typedef struct
{
    int idCli;
    int rubro;
    char aviso[65];
    int idPub;
    int estado;
} publicacion;
typedef struct
{
    int id;
    char desc[15];
} eRubro;
/** \brief Inicializa todas las variables estado del vector de estructuras con 0
 * \param El vector de tipo estructura
 * \param El tamanio del vector
 */
void inicializarPubs(publicacion pub[],int tam);
void publicarPub(publicacion pub[],int tamPub,cliente cli[],int tam);
int buscarLibrePub(publicacion pub[],int tam);
int buscarIdPub(publicacion pub[],int tam,int id);
int buscarIdPubAll(publicacion pub[],int tam,int id);
void pausarPub(publicacion pub[],int tamPub,cliente cli[],int tam);
void reanudarPub(publicacion pub[],int tamPub,cliente cli[],int tam);
