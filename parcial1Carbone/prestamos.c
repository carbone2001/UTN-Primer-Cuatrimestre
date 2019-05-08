#include <stdio.h>
#include <stdlib.h>
#include "prestamos.h"
#include "libros.h"
#include "inputs.h"
#include "socios.h"
void prestamos(ePrestamo pres[],int *codPres,eLibro lib[],int tamLib,eSocio soc[],int tamSoc,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        int codLib;
        int libro;
        int codSoc;
        int socio;
        int posiblePrestamo;
        printf("\nIngrese codigo del libro");
        scanf("%d",&codLib);
        libro=buscarCodLib(lib,tamLib,codLib);
        while(libro==-1)
        {
            printf("\nEl codigo ingresado no existe. Ingrese codigo del libro nuevamente: ");
            scanf("%d",&codLib);
            libro=buscarCodLib(lib,tamLib,codLib);
        }

        printf("\nIngrese codigo del socio");
        scanf("%d",&codSoc);
        socio=buscarCodSoc(soc,tamSoc,codSoc);
        while(socio==-1)
        {
            printf("\nEl codigo ingresado no existe. Ingrese codigo del socio nuevamente: ");
            scanf("%d",&codSoc);
            socio=buscarCodSoc(soc,tamSoc,codSoc);
        }
        posiblePrestamo=*codPres+1;
        pres[posiblePrestamo].codigoLib=lib[libro].cod;
        pres[posiblePrestamo].codigoSoc=soc[socio].codigo;
        getIntIntentos(&pres[posiblePrestamo].fechaPrest.dia,"\nIngrese fecha de prestamo. \n dia: ","Dia incorrecto",1,30,0);
        getIntIntentos(&pres[posiblePrestamo].fechaPrest.mes,"\n Mes: ","Mes incorrecto",1,12,0);
        getIntIntentos(&pres[posiblePrestamo].fechaPrest.anio,"\n Anio: ","Anio invalido",1950,2019,0);
        pres[posiblePrestamo].codigo=posiblePrestamo;
        pres[posiblePrestamo].estado=1;
        *codPres=posiblePrestamo;
        printf("El prestamo se ha realizado con exito");

    }
    else
    {
        printf("ERRO. Debe haberse dado de alta por lo menos un socio");
    }

}

