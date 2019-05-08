#include <stdio.h>
#include <stdlib.h>
/** \brief Solicita un dato de tipo entero y luego evalua si este dato corresponde segun los parametros dados.
 * \param input int* La direccion de la variable donde se escribira el valor ingresado
 * \param msj char* Mensaje que solicita el ingreso de un numero
 * \param eMsj char* Mensaje en caso de error
 * \param minimo int El valor minimo que puede ingresar
 * \param maximo int El valor maximo que puede ingresar
 * \param reintentos int Si la cantidad de intentos es 0, solicitara el numero correcto de forma infinita. Caso contrario, solo tendra una cantidad limitada de intentos
 * \return int Si hubo error (1) o no (0)
 */
int getIntIntentos(int* input,char* msj,char* eMsj,int minimo,int maximo,int reintentos);
/** \brief Solicita un dato de tipo entero
 * \param msj char* Mensaje que solicita el ingreso de un numero
 * \return int El entero ingresado.
 */
int getInt(char * msj);

/** \brief Se genera un numero aleatorio
 *
 * \param primerNumero int El numero minimo que se desea obtener
 * \param ultimoNumero int El numero maximo que se desea obtener
 * \param primeraVez int Si se utiliza por primera vez (1) sino (0)
 * \return int El numero generado
 *
 */
int getRandom(int primerNumero, int ultimoNumero,int primeraVez);
/** \brief Solicita un dato de tipo caracter y este debe coincidir con ciertos parametros
 *
 * \param char*msj El mensaje que solicita el ingreso de un caracter
 * \param letraCorrecta char El caracter al cual debe asemejarse el dato ingresado
 * \return cahr El caracter ingresado. Devuelve 0 si algo salio mal.
 *
 */
char getCharSex(char*msj);

/** \brief Solicita el ingreso de un caracter que corresponda al sexo del individuo
 *
 * \param str[] char La variable a cargar
 * \param char*msj El mensaje que solicita el ingreso del caracter m o f
 * \param char*eMsj El mensaje que se muestra en caso de error
 * \param limite int Limite de elementos de la cadena
 * \param intentos int Cantidad de intentos
 * \return int Si hubo error (1) sino (0)
 *
 */
int getString(char str[],char*msj,char*eMsj,int limite,int intentos);

