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

void altaSocio(eSocio soc[],int tam,int *codigoSocio);
void modificarSocio(eSocio soc[],int tam,int *codigoSocio);
int buscarLibre(eSocio soc[],int tam);
int buscarCodSoc(eSocio soc[],int tam,int codigo);
void bajaSocio(eSocio soc[],int tam,int *codigoSocio);
void ordAsStructStr(eSocio soc[],int tam);
int menu();
