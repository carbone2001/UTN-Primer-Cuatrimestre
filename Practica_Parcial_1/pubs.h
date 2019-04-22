
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
void publicarPub(publicacion pub[],int tam);
int buscarLibrePub(publicacion pub[],int tam);
int buscarIdPub(publicacion pub[],int tam,int id);
