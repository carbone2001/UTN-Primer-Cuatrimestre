#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "pubs.h"
#include "listar.h"
int main()
{
    int opcion;
    opcion=0;
    cliente cli[100]=
    {
        {4573,"Alberto","Costa","27897634751",1,5,4,1},
        {8765,"Enrique","Segobiano","27327459381",1,4,4,0},
        {3821,"Elvira","Chernov","27598476521",1,1,0,1},
        {5493,"Luis","Perales","27372849221",1,99,9,90},
        {1094,"Priscila","Avellaneda","27534944931",1,9,9,0},
    };
    publicacion pub[1000]=
    {
        {4573,13,"Me gustan los trenes",8574,1},
        {4573,13,"Me gustan los tkrenes",5644,1},
        {3821,15,"Me gustan los trenes",9353,1},
        {5493,13,"Me gustan los tkrenes",4246,1},
        {4573,13,"Me gustan los trenes",8984,1},
        {4573,15,"Me gustan los tkrenes",9584,1},
        {3821,15,"Me gustan los trenes",3421,1},
        {1094,19,"Me gustan los tkrenes",1934,1}
    };
    eRubro rubros[3]=
    {
        {13,"Finzanzas"},
        {15,"RRHH"},
        {19,"Sistemas"}
    };

    //inicializarCliente(cli,100);
    //inicializarPubs(pub,1000);
    while(opcion==0)
    {
        switch(menu())
        {
        case 1:
            altaCliente(cli,100);
            break;
        case 2:
            modificarCliente(cli,100);
            break;
        case 3:
            bajaCliente(cli,100);
            break;
        case 4:
            publicarPub(pub,1000,cli,100);
            break;
        case 5:
            pausarPub(pub,1000,cli,100);
            break;
        case 6:
            reanudarPub(pub,1000,cli,100);
            break;
        case 7:
            printClientes(cli,100,pub,1000);
            break;
        case 8:
            printPublicaciones(cli,100,pub,1000);
            break;
        case 9:
            informarClientes(cli,100,pub,1000);
            break;
        case 10:
            informarPublicaciones(pub,1000,rubros,3);
            break;
        default:
            opcion=1;
            break;
        }

    }


    return 0;
}
