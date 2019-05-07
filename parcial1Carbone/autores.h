typedef struct
{
    int cod;
    char apellido[31];
    char nombre[31];
    int estado;

}eAutor;

/** \brief Hardcodea un vector de estructuras
 *
 * \param aut[] eAutor Estructura a harcodear
 * \param tamAut int Tamanio del vector de estructura
 * \return void
 *
 */
void hcdAut(eAutor aut[],int tamAut);
/** \brief Enlista un vector de estructura eAutor
 *
 * \param aut[] eAutor Estructura eAutor a listar
 * \param tamAut int tamanio del vector de estructura eAutor
 * \return void
 *
 */
void listarAutores(eAutor aut[],int tamAut);
/** \brief Ordena vector eAutor por apellido y nombre
 *
 * \param aut[] eAutor Es la estructura a ordenar
 * \param tamAut int tamanio del vector de estructura
 * \return void
 *
 */
void ordAsStructStrAut(eAutor aut[],int tamAut);
