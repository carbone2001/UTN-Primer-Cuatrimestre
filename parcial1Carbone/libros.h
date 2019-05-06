#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char titulo[51];
    int codAutor;
    int estado;

}eLibro;
void hcdLib(eLibro lib[],int tamLib);
