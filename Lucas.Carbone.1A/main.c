#include <stdio.h>
#include <stdlib.h>
#include "socios.h"


int main()
{
    eSocio soc[100];
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
            prestamos(pres,&codigoPres,lib,100,soc,100,&codigoSoc);
            break;
        case 8:
            sociosSolicitaronPrestamoLibro(soc,100,pres,100,&codigoSoc);
            break;
        case 9:
            librosPrestadosSocioDeterminado(lib,100,pres,100,&codigoSoc);
            break;
        case 10:
            listarLibroMenosSolicitado(lib,100,pres,100,&codigoSoc);
            break;
        case 11:
            listarSocioMasPrestamos(soc,100,pres,100,&codigoSoc);
            break;
        case 12:
            listarLibroFechaDeterminda(lib,100,pres,100,&codigoSoc);
            break;
        case 13:
            listarSociosPrestamoFechaDeterminada(soc,100,pres,100,&codigoSoc);
            break;
        case 14:
            ordSocioApellido(soc,100,&codigoSoc);
            break;
        case 15:
            ordLibTit(lib,100,&codigoSoc);
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

