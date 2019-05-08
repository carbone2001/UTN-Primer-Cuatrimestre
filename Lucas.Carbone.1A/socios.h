#include "fechas.h"
#include "prestamos.h"
//#include "libros.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;
typedef struct
{
    int cod;
    char apellido[31];
    char nombre[31];
    int estado;

}eAutor;


typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha fechaAsoc;
    int estado;


}eSocio;
typedef struct
{
    int cod;
    char titulo[51];
    int codAutor;
    int estado;

}eLibro;
typedef struct
{
    int codigo;
    int codigoLib;
    int codigoSoc;
    eFecha fechaPrest;
    int estado;
}ePrestamo;

/** \brief Da de alta a un elemento de un vector estructura eSocio
 *
 * \param soc[] eSocio el vector a utilizar
 * \param tam int el tamanio del vector
 * \param codigoSocio int* puntero de la variable que se utiliza contador del codigo de los socios. De forma que sea incremental
 * \return void
 *
 */
void altaSocio(eSocio soc[],int tam,int *codigoSocio);
/** \brief Modifica los datos de un socio
 *
 * \param soc[] eSocio El vector de estructura eSocio que contiene a los mismos
 * \param tam int Tamanio del vector
 * \param codigoSocio int* Codigo del socio para poder modificarlo especificamente
 * \return void
 *
 */
void modificarSocio(eSocio soc[],int tam,int *codigoSocio);
/** \brief Busca si hay un espacio libre
 *
 * \param soc[] eSocio vector estructura eSocio
 * \param tam int Tamanio del vector
 * \return int El indice donde se halla el espacio libre. Si no hay devuelve -1
 *
 */
int buscarLibre(eSocio soc[],int tam);
/** \brief Busca un socio segun el codigo ingresado
 *
 * \param soc[] eSocio vector estructura eSocio en la que se trabajara
 * \param tam int Tamanio del vector
 * \param codigo int El codigo que se desea buscar
 * \return int El indice donde se encuetra el socio
 *
 */
int buscarCodSoc(eSocio soc[],int tam,int codigo);
/** \brief Realiza una baja logica al socio.
 *
 * \param soc[] eSocio  vector estructura eSocio en la que se desea trabajar
 * \param tam int  Tamanio del vector
 * \param codigoSocio int* El codigo del socio que se desea bajar
 * \return void
 *
 */
void bajaSocio(eSocio soc[],int tam,int *codigoSocio);

/** \brief Imprime por pantalla un listado de los empleados activos
 *
 * \param soc[] eSocio El vector estructura eSocio en la que se desea trabajar
 * \param tamSoc int Tamanio del vector ingresado
 * \param codigoSocio int* Se utiliza este puntero para verificar si hay por lo menos un socio registrado
 * \return void
 *
 */
void listarSocios(eSocio soc[],int tamSoc,int *codigoSocio);
/** \brief Ordena vector eSocio por apellido y nombre
 *
 * \param soc[] eSocio Es la estructura a ordenar
 * \param tamSoc int tamanio del vector de estructura
 * \return void
 *
 */
void ordAsStructStrSoc(eSocio soc[],int tam);
/** \brief Contiene el menu de opciones
 *
 * \return int Devuelve la opcion seleccionada segun ese menu.
 *
 */
void sociosSolicitaronPrestamoLibro(eSocio soc[],int tamSoc,ePrestamo pres[],int tamPres,int *codigoSocio);

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
void listarAutores(eAutor aut[],int tamAut,int *codigoSocio);
/** \brief Ordena vector eAutor por apellido y nombre
 *
 * \param aut[] eAutor Es la estructura a ordenar
 * \param tamAut int tamanio del vector de estructura
 * \return void
 *
 */
void ordAsStructStrAut(eAutor aut[],int tamAut);







//PRESTAMOS!!!!!!!!!!!!!!!!!!!!!!
void prestamos(ePrestamo pres[],int *codPres,eLibro lib[],int tamLib,eSocio soc[],int tamSoc,int *codigoSocio);


//INFORMES Y LISTAS

/** \brief  Informa los libros prestados a un socio determinado
 *
 * \param lib[] eLibro Vector de estructura eLibro
 * \param tamLib int tamanio de la estructura anteriormente mencionada
 * \param pres[] ePrestamo Vector de estructura epRESTAMO
 * \param tamPres int tamanio de la estructura anteriormente mencionada
 * \param codigoSocio int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */
void librosPrestadosSocioDeterminado(eLibro lib[],int tamLib, ePrestamo pres[], int tamPres, int *codigoSocio);
/** \brief  Informa el libro menos slicitado
 *
 * \param lib[] eLibro Vector de estructura eLibro
 * \param tamLib int tamanio de la estructura anteriormente mencionada
 * \param pres[] ePrestamo Vector de estructura epRESTAMO
 * \param tamPres int tamanio de la estructura anteriormente mencionada
 * \param codigoSocio int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */
void listarLibroMenosSolicitado(eLibro lib[],int tamLib, ePrestamo pres[], int tamPres, int *codigoSocio);

/** \brief Lista al socio con mayor cantidad de prestamos realizados
 *
 * \param soc[] eSocio Contiene los socios disponibles.
 * \param tamSoc int Tamanio del vector anteriormente mencionado
 * \param pres[] ePrestamo Contiene los prestamos que pudieron realizarse
 * \param tamPres int Tamanio del vector anteriormente mencionado
 * \param codigoLibro int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */
void listarSocioMasPrestamos(eSocio soc[],int tamSoc,ePrestamo pres[],int tamPres,int *codigoLibro);

/** \brief Lista los libros prestados en una fecha determinada
 *
 * \param lib[] eLibro Contiene los libros
 * \param tamLib int Tamanio del vector anteriormente mencionado
 * \param pres[] ePrestamo Contiene los prestamos que pudieron realizarse
 * \param tamPres int Tamanio del vector anteriormente mencionado
 * \param codigoSocio int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */
void listarLibroFechaDeterminda(eLibro lib[],int tamLib, ePrestamo pres[], int tamPres, int *codigoSocio);
/** \brief Lista los socios que realizaron al menos un prestamo en un fecha determinada
 *
 * \param soc[] eSocio Contiene los socios registrados
 * \param tamSoc int tamanio del vector anteriormente mencionado
 * \param pres[] ePrestamo Contiene los prestamos que pudieron realizarse
 * \param tamPres int tamanio del vector anteriormente mencionado
 * \param codigoSocio int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */
void listarSociosPrestamoFechaDeterminada(eSocio soc[],int tamSoc,ePrestamo pres[],int tamPres,int *codigoSocio);
/** \brief Ordena al vector de socios por el apellido
 *
 * \param soc[] eSocio Contiene los socios
 * \param tamSoc int Tamanio del vector anteriormente mencionado
    \param codigoSocio int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */

void ordSocioApellido(eSocio soc[],int tamSoc,int *codSoc);
/** \brief Ordena vector estructura eLibro por titulo
 *
 * \param lib[] eLibro Contiene los libros registrados
 * \param tamLib int Tamanio del vector eLibros ingresado
 * \param codigoSocio int* puntero hacia la variable del codigo de los socios. Pra verificar si hubo almenos un alta.
 * \return void
 *
 */
void ordLibTit(eLibro lib[],int tamLib,int *codigoSocio);
/** \brief Se muestra un menu de opciones
 * \return int La opcion seleccionada
 *
 */

int menu();
/** \brief Inicializa los el vector eSocio
 *
 * \param soc[] eSocio El vector de eSocio
 * \param tamSoc int El tamanio del vector ingresado
 * \return void
 *
 */
void inicializarSocios(eSocio soc[],int tamSoc);
