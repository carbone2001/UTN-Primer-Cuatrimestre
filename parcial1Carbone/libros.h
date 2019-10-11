#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char titulo[51];
    int codAutor;
    int estado;

}eLibro;
/** \brief Hardcodea un vector de estructuras
 *
 * \param lib[] eLibro Estructura a harcodear
 * \param tamlib int Tamanio del vector de estructura
 * \return void
 *
 */
void hcdLib(eLibro lib[],int tamLib);
/** \brief Enlista un vector de estructura eAutor
 *
 * \param lib[] eLibro Estructura eLibro a listar
 * \param tamLib int tamanio del vector de estructura eAutor
 * \return void
 *
 */
void listarLibros(eLibro lib[],int tamLib,int *codigoSocio);
/** \brief Ordena vector eLibro por titulo
 *
 * \param lib[] eLibro Es la estructura a ordenar
 * \param tamLib int tamanio del vector de estructura
 * \return void
 *
 */
void ordAsStructStrLib(eLibro lib[],int tamLib);

/** \brief Inicializa un vector de estructuras eLibro
 *
 * \param lib[] eLibro el vector a ordenar
 * \param tamLib int tamanio del vecotr
 * \return void
 *
 */
void inicializarLibros(eLibro lib[],int tamLib);
/** \brief Buscar libros segun por codigo .
 *
 * \param lib[] eLibro El vector donde se buscara
 * \param tamLib int tamanio del vector
 * \param codigo int Codigo del libro a buscar
 * \return int El indice del libro encontrado. Si no se encuetra se devuelve -1
 *
 */
int buscarCodLib(eLibro lib[],int tamLib,int codigo);
