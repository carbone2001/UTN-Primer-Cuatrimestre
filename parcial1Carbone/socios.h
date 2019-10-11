#include "fechas.h"

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
int menu();
