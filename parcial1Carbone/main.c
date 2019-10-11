#include <stdio.h>
#include <stdlib.h>
#include "autores.h"
#include "fechas.h"
#include "libros.h"
#include "prestamos.h"
#include "socios.h"


int main()
{
    eSocio soc[100];
    /*eSocio soc[100]=
    {
        {1,"SURNAME1","NAME1",'M',"42131234","NAME.SURNAME@mail.com",{01,01,2001},1},
        {2,"SURNAME1","NAME2",'M',"42131234","NAME.SURNAME@mail.com",{01,01,2001},1},
        {3,"SURNAME1","NAME3",'M',"42131234","NAME.SURNAME@mail.com",{01,01,2001},1},
        {4,"SURNAME2","NAME3",'M',"42131234","NAME.SURNAME@mail.com",{01,01,2001},1},
        {5,"SURNAME2","NAME5",'M',"42131234","NAME.SURNAME@mail.com",{01,01,2001},1},
        {6,"SURNAME2","NAME1",'M',"42131234","NAME.SURNAME@mail.com",{01,01,2001},1},
    };*/
    eAutor aut[100];
    int codigoSoc;
    int codigoPres;
    eLibro lib[100];
    inicializarLibros(lib,100);
    hcdAut(aut,100);
    hcdLib(lib,100);
    ePrestamo pres[100];
    int opcion;
    codigoSoc=0;
    codigoPres=0;

    do
    {
        opcion=menu();
        switch(opcion)
        {
        case 1:
            altaSocio(soc,100,&codigoSoc);
            break;
        case 2:
            modificarSocio(soc,100,&codigoSoc);
            break;
        case 3:
            bajaSocio(soc,100,&codigoSoc);
            break;
        case 4:
            listarSocios(soc,100,&codigoSoc);
            break;
        case 5:
            listarLibros(lib,100,&codigoSoc);
            break;
        case 6:
            listarAutores(aut,100,&codigoSoc);
            break;
        case 7:
            prestamos(pres,&codigoPres,lib,100,soc,100);
            break;
        default:
            printf("Opcion invalida");
            opcion=0;
            break;

        }

    }
    while(opcion);
    return 0;
}
