#include <stdio.h>
#include <stdlib.h>
#include "autores.h"
#include "fechas.h"
#include "libros.h"
#include "prestamos.h"
#include "socios.h"


int main()
{
    eAutor aut[100];
    int codigoSoc=0;
    eLibro lib[100];
    hcdAut(aut,100);
    hcdLib(lib,100);

    //int codigoLib;
    //int codigoAut;
    //int codigoPres;
    //eAutor aut[100];
    //eLibro lib[100];
    eSocio soc[100];
    //ePrestamo pres[100];
    int opcion;

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
            //listarSocio;
            break;
        case 5:
            //listarLibros;
            break;
        case 6:
            //listarAutores;
            break;
        case 7:
            //prestamos;
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
