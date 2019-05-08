#include "fechas.h"
#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
//#include "prestamos.h"
typedef struct
{
    int codigo;
    int codigoLib;
    int codigoSoc;
    eFecha fechaPrest;
    int estado;
}ePrestamo;
//void prestamos(ePrestamo pres[],int *codPres,eLibro lib[],int tamLib,eSocio soc[],int tamSoc);
#endif // LIBROS_H_INCLUDED
#endif // SOCIOS_H_INCLUDED


