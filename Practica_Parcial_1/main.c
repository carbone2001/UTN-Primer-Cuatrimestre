#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "pubs.h"
int main()
{
    int opcion;
    opcion=0;
    cliente cli[100];
    publicacion pub[1000];
    inicializarCliente(cli,100);
    inicializarPubs(pub,100);
    while(opcion==0)
    {
        switch(menu())
        {
        case 1:
            altaCliente(cli,100);
            break;
        case 2:
            //modificarCliente(pub,100);
            break;
        case 3:
            bajaCliente(cli,100);
            break;
        case 4:
            publicarPub(pub,1000);
            break;
        case 5:
        case 6:
        case 7:
        //listarClietes();
        case 8:
        case 9:
        case 10:
            break;
        default:
            opcion=1;
            break;
        }

    }


    return 0;
}
