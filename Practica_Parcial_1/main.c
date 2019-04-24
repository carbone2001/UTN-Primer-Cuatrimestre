#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "pubs.h"
int main()
{
    int opcion;
    opcion=0;
    cliente cli[100]=
    {
        {4573,"Alberto","Costa",27897634751,1},
        {8765,"Enrique","Segobiano",27327459381,1},
        {3821,"Elvira","Chernov",27598476521,1},
        {5493,"Luis","Perales",27372849221,1},
        {1094,"Priscila","Avellaneda",27534944931,1},
    };
    publicacion pub[1000]=
    {
        {4573,13009,"Me gustan los trenes",8574,1},
        {4573,130069,"Me gustan los tkrenes",5644,1},
        {3821,13009,"Me gustan los trenes",9353,1},
        {5493,130069,"Me gustan los tkrenes",4246,1},
    };

    //inicializarCliente(cli,100);
    //inicializarPubs(pub,100);
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
