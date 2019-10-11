#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"
#include "socios.h"

int menu()
{
    int opcion;
    printf("\n***  ABM SOCIOS  ***\n");
    printf("1. Alta de socio.\n");
    printf("2. Modificar datos de socio.\n");
    printf("3. Baja de socio\n");
    printf("4. Listar socios\n");
    printf("5. Listar libros\n");
    printf("6. Listar autores\n");
    printf("7. Prestamos\n");
    printf("8. Listar socios que realizaron prestamos de un libro determinado.\n");
    printf("9. Listar libros solicitados por un socio determinado\n");
    printf("10. Listar libro menos solicitado\n");
    printf("11. Listar socio que mas prestamos ha solicitado\n");
    printf("12. Listar libros prestados en una fecha determinada\n");
    printf("13. Listar socios que realizaron solicitud de prestamos en una fecha determianda");
    printf("14. Listar socios por apellido ");
    printf("\n15. Listar libros por titulo\n");
    scanf("%d",&opcion);
    return opcion;
}
void altaSocio(eSocio soc[],int tam,int *codigoSocio)
{
    int free;
    free=buscarLibre(soc,tam);
    if(free==-1)
    {
        printf("\nNo se ha encontrado un lugar en el sistema.\n");
    }
    else
    {

        getString(soc[free].nombre,"\nIngrese Nombre: ","El nombre no debe superar los 30 caracteres",31,0);
        getString(soc[free].apellido,"\nIngrese Apellido: ","El apellido no debe superar los 30 caracteres",31,0);
        soc[free].sexo=getCharSex("\nIngrese sexo");
        while(soc[free].sexo=='0')
        {
            soc[free].sexo=getCharSex("\nSexo invalido!!. Ingrese sexo nuevamente: ");

        }
        getString(soc[free].telefono,"Ingrese numero de telefono","No debe superar los 15 caracteres",15,0);
        getString(soc[free].eMail,"Ingrese eMail","No debe superar los 30 caracteres",30,0);
        printf("Ingerse fecha");
        getIntIntentos(&soc[free].fechaAsoc.dia,"\nIngrese fecha de asociacion. \n dia: ","Dia incorrecto",1,30,0);
        getIntIntentos(&soc[free].fechaAsoc.mes,"\n Mes: ","Mes incorrecto",1,12,0);
        getIntIntentos(&soc[free].fechaAsoc.anio,"\n Anio: ","Anio invalido",1950,2019,0);
        *codigoSocio=*codigoSocio+1;
        soc[free].codigo=*codigoSocio;
        soc[free].estado=1;
        printf("La alta del socio ha sido exitosa. El Codigo de socio: %d",soc[free].codigo);
    }

}
int buscarLibre(eSocio soc[],int tam)
{
    int i;
    int lugarLibre=-1;
    for(i=0; i<tam; i++)
    {
        if(soc[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}
void modificarSocio(eSocio soc[],int tam,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        int codigo;
        int socio;
        int opcion=0;
        printf("Ingrese el Codigo del socio que desea modificar");
        scanf("%d",&codigo);
        socio=buscarCodSoc(soc,tam,codigo);
        if(socio==-1)
        {
            printf("El cliente seleccionado no existe");
        }
        else
        {
            while(opcion!=6)
            {
                printf("\n\nQue desea modificar (codigo: %d):",soc[socio].codigo);
                printf("\n 1. Nombre");
                printf("\n 2. Apellido");
                printf("\n 3. Sexo");
                printf("\n 4. Telefono");
                printf("\n 5. eMail");
                printf("\n 6. Volver al menu");
                printf("\nSeleccione su opcion:");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getString(soc[socio].nombre,"\nIngrese Nombre: ","El nombre no debe superar los 30 caracteres",31,0);
                    printf("\nEl nombre se ha modificado con exito!!!\n");
                    break;
                case 2:
                    getString(soc[socio].apellido,"\nIngrese Apellido: ","El apellido no debe superar los 30 caracteres",31,0);
                    printf("\nEl apellido se ha modificado con exito!!!\n");
                    break;
                case 3:
                    soc[socio].sexo=getCharSex("\nIngrese sexo");
                    while(soc[socio].sexo=='0')
                    {
                        soc[socio].sexo=getCharSex("\nSexo invalido!!. Ingrese sexo nuevamente: ");

                    }
                    printf("\nEl sexo se ha modificado con exito!!!\n");
                    break;
                case 4:
                    getString(soc[socio].telefono,"Ingrese numero de telefono","No debe superar los 15 caracteres",15,0);
                    printf("\nEl telefono se ha modificado con exito!!!n");
                    break;
                case 5:
                    getString(soc[socio].eMail,"Ingrese eMail","No debe superar los 30 caracteres",30,0);
                    printf("\nEl eMail se ha modificado con exito!!!n");
                    break;
                case 6:
                    system(("cls"));
                    break;
                default:
                    printf("\n***Opcion invalida***\n");
                    break;
                }
            }
        }
    }
    else
    {
        printf("Debe haber al menos un alta!");
    }

}
int buscarCodSoc(eSocio soc[],int tam,int codigo)
{
    int sameCod=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(soc[i].estado==1 && soc[i].codigo==codigo)
        {
            sameCod=i;
            break;
        }
    }
    return sameCod;
}
void bajaSocio(eSocio soc[],int tam,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        int codigo;
        int socio;
        printf("\nIngrese codigo del socio para dar de baja: ");
        scanf("%d",&codigo);
        socio=buscarCodSoc(soc,tam,codigo);
        if(socio==-1)
        {
            printf("El socio seleccionado no existe");
        }
        else
        {
            soc[socio].estado=0;
            printf("El socio de codigo: %d fue dado de baja con exito!!!",soc[socio].codigo);
        }

    }
    else
    {
        printf("ERROR. Debe haber al menos un alta de socio");
    }

}
void listarSocios(eSocio soc[],int tamSoc,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        ordAsStructStrSoc(soc,tamSoc);
        printf("\n Apellido   Nombre   Codigo Sexo     Telefono                         eMail    Fecha de asociacion");
        int i;

        for(i=0; i<tamSoc; i++)
        {
            if(soc[i].estado==1)
            {
                printf("\n%s    %s     %d     %c         %s        %s  %2d/%2d/%2d\n",soc[i].apellido,soc[i].nombre,soc[i].codigo,soc[i].sexo,soc[i].telefono,soc[i].eMail,soc[i].fechaAsoc.dia,soc[i].fechaAsoc.mes,soc[i].fechaAsoc.anio);

            }
        }
    }
    else
    {
        printf("ERROR. Debe haber al menos un alta de socio");
    }

}
void ordAsStructStrSoc(eSocio soc[],int tam)
{
    int i;
    int j;
    eSocio aux;
    for(i=0; i<tam; i++)
    {
        strlwr(soc[i].nombre);
    }
    for(i=0; i<tam; i++)
    {
        strlwr(soc[i].apellido);
    }
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((strcmp(soc[i].apellido,soc[j].apellido))>0 && (soc[i].estado==1 && soc[j].estado==1))
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }
        }
    }
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((strcmp(soc[i].nombre,soc[j].nombre))>0 && (soc[i].estado==1 && soc[j].estado==1) && (strcmp(soc[i].apellido,soc[j].apellido))==0)
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }
        }
    }
}
void sociosSolicitaronPrestamoLibro(eSocio soc[],int tamSoc,ePrestamo pres[],int tamPres,int *codigoSocio)
{
    int i;
    int j;
    int codLibro;
    int encontrado;
    if(*codigoSocio>0)
    {
        encontrado=0;
        printf("\nIngrese el codigo del libro: ");
        scanf("%d",&codLibro);

        printf("\nSocios que realizaron prestamos");
        for(i=0; i<tamSoc; i++)
        {

            for(j=0; j<tamPres; j++)
            {
                if(soc[i].codigo==pres[j].codigoSoc && pres[j].codigoLib==codLibro &&soc[i].estado==1 &&pres[j].estado==1)
                {
                    encontrado++;
                    printf("\n%s      %s      Cod. Socio: %d      ",soc[i].nombre,soc[i].apellido,soc[i].codigo);
                    break;
                }
            }
        }
        if(encontrado==0)
        {
            printf("\nNo se ha encontrado prestamos del libro (cod: %d)",codLibro);
        }

    }
    else
    {
        printf("Error. Debe haber al menos un socio");

    }


}



//AUTORES

void hcdAut(eAutor aut[],int tamAut)
{
    int i;
    eAutor autHcd[5]=
    {
        {1001,"name1","surname1",1},
        {1002,"name2","surname2",1},
        {1003,"name3","surname3",1},
        {1004,"name4","surname4",1},
        {1005,"name5","surname5",1},
    };
    for(i=0; i<tamAut; i++)
    {
        aut[i]=autHcd[i];
    }
}
void listarAutores(eAutor aut[],int tamAut,int *codigoSocio)
{
    int j;
    if(*codigoSocio>0)
    {
        ordAsStructStrAut(aut,tamAut);
        printf("Codigo de autor    Apellido         Nombre");
        for(j=0; j<tamAut; j++)
        {
            if(aut[j].estado)
            {
                printf("\n%d                %s         %s\n",aut[j].cod,aut[j].apellido,aut[j].nombre);
            }


        }

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }


}
void ordAsStructStrAut(eAutor aut[],int tamAut)
{
    int i;
    int j;
    eAutor aux;
    for(i=0; i<tamAut; i++)
    {
        strlwr(aut[i].nombre);
    }
    for(i=0; i<tamAut; i++)
    {
        strlwr(aut[i].apellido);
    }
    for(i=0; i<tamAut-1; i++)
    {
        for(j=i+1; j<tamAut; j++)
        {
            if((strcmp(aut[i].apellido,aut[j].apellido))>0 && (aut[i].estado==1 && aut[j].estado==1))
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
        }
    }
    for(i=0; i<tamAut-1; i++)
    {
        for(j=i+1; j<tamAut; j++)
        {
            if((strcmp(aut[i].nombre,aut[j].nombre))>0 && (aut[i].estado==1 && aut[j].estado==1) && (strcmp(aut[i].apellido,aut[j].apellido))==0)
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
        }
    }
}










//LIBROS
void hcdLib(eLibro lib[],int tamLib)
{
    eLibro libHcd[100]=
    {
        {2001,"title2",1,1},
        {2002,"title5",2,1},
        {2003,"title4",3,1},
        {2004,"title3",4,1},
        {2005,"title1",5,1},
    };

    int i;
    for(i=0; i<tamLib; i++)
    {
        lib[i]=libHcd[i];
    }
}
void listarLibros(eLibro lib[],int tamLib,int *codigoSocio)
{
    int j;
    if(*codigoSocio>0)
    {
        ordAsStructStrLib(lib,tamLib);
        printf("Codigo de libro    Titulo         Codigo de Autor");
        for(j=0; j<tamLib; j++)
        {
            if(lib[j].estado)
            {
                printf("\n%d                %s         %d\n",lib[j].cod,lib[j].titulo,lib[j].codAutor);
            }


        }

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }


}
void ordAsStructStrLib(eLibro lib[],int tamLib)
{
    int i;
    int j;
    eLibro aux;
    for(i=0; i<tamLib; i++)
    {
        strlwr(lib[i].titulo);
    }
    for(i=0; i<tamLib-1; i++)
    {
        for(j=i+1; j<tamLib; j++)
        {
            if((strcmp(lib[i].titulo,lib[j].titulo))>0 && (lib[i].estado==1 && lib[j].estado==1))
            {
                aux=lib[i];
                lib[i]=lib[j];
                lib[j]=aux;
            }
        }
    }
}
void inicializarLibros(eLibro lib[],int tamLib)
{
    int i;
    for(i=0; i<tamLib; i++)
    {
        lib[i].estado=0;
    }
}
void inicializarSocios(eSocio soc[],int tamSoc)
{
    int i;
    for(i=0; i<tamSoc; i++)
    {
        soc[i].estado=0;
    }
}
int buscarCodLib(eLibro lib[],int tamLib,int codigo)
{
    int sameCod=-1;
    int i;
    for(i=0; i<tamLib; i++)
    {
        if(lib[i].estado==1 && lib[i].cod==codigo)
        {
            sameCod=i;
            break;
        }
    }
    return sameCod;
}





void prestamos(ePrestamo pres[],int *codPres,eLibro lib[],int tamLib,eSocio soc[],int tamSoc,int *codigoSocio)
{
    int codLib;
    int libro;
    int codSoc;
    int socio;
    int posiblePrestamo;
    if(*codigoSocio>0)
    {

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
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }

}
void librosPrestadosSocioDeterminado(eLibro lib[],int tamLib, ePrestamo pres[], int tamPres, int *codigoSocio)
{
    int i;
    int j;
    int encontrado;
    int codSoc;
    if(*codigoSocio>0)
    {
        encontrado=0;
        printf("\nIngrese el codigo del socio: ");
        scanf("%d",&codSoc);

        printf("\nLibros que se prestaron a este socio (Cod: %d)",codSoc);
        for(i=0; i<tamLib; i++)
        {

            for(j=0; j<tamPres; j++)
            {
                if(lib[i].cod==pres[j].codigoLib && pres[j].codigoSoc==codSoc &&lib[i].estado==1 &&pres[j].estado==1)
                {
                    encontrado++;
                    printf("\n%s        Cod. Libro: %d      ",lib[i].titulo,lib[i].cod);
                    break;
                }
            }
        }
        if(encontrado==0)
        {
            printf("\nNo se ha encontrado prestamos del socio (cod: %d)",codSoc);
        }

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }
}
void listarLibroMenosSolicitado(eLibro lib[],int tamLib, ePrestamo pres[], int tamPres, int *codigoSocio)
{
    int i;
    int j;
    int libMenosSolicitado;
    int solicitudesLib;
    int contadorSolicitud;
    if(*codigoSocio>0)
    {
        for(i=0; i<tamLib; i++)
        {
            contadorSolicitud=0;
            for(j=0; j<tamPres; j++)
            {
                if(pres[j].codigoLib==lib[i].cod && lib[i].estado==1)
                {
                    contadorSolicitud++;
                }
            }
            if(i==0)
            {
                libMenosSolicitado=i;
                solicitudesLib=contadorSolicitud;
            }
            else if(contadorSolicitud<solicitudesLib)
            {
                libMenosSolicitado=i;
                solicitudesLib=contadorSolicitud;
            }

        }
        printf("El libro menos solicitado es: %s          Cod. Libro: %d",lib[libMenosSolicitado].titulo,lib[libMenosSolicitado].cod);

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }


}
void listarSocioMasPrestamos(eSocio soc[],int tamSoc,ePrestamo pres[],int tamPres,int *codigoSocio)
{
    int i;
    int j;
    int socMasPres;
    int solicitudesPres;
    int contadorPres;
    if(*codigoSocio>0)
    {
        for(i=0; i<tamSoc; i++)
        {
            contadorPres=0;
            for(j=0; j<tamPres; j++)
            {
                if(pres[j].codigoSoc==soc[i].codigo && soc[i].estado==1)
                {
                    contadorPres++;
                }
            }
            if(i==0)
            {
                socMasPres=i;
                solicitudesPres=contadorPres;
            }
            else if(contadorPres>solicitudesPres)
            {
                socMasPres=i;
                solicitudesPres=contadorPres;
            }

        }
        printf("El socio que mas prestamos solicito es: %s         %s         Cod. Socio: %d",soc[socMasPres].nombre,soc[socMasPres].apellido,soc[socMasPres].codigo);

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }

}
void listarLibroFechaDeterminda(eLibro lib[],int tamLib, ePrestamo pres[], int tamPres, int *codigoSocio)
{
    int i;
    int j;
    int encontrado;
    eFecha fechaBuscar;
    if(*codigoSocio>0)
    {
        encontrado=0;
        printf("\nIngrese la fecha: ");
        getIntIntentos(&fechaBuscar.dia,"\n dia: ","\n Dia incorrecto",1,30,0);
        getIntIntentos(&fechaBuscar.mes,"\n Mes: ","\n Mes incorrecto",1,12,0);
        getIntIntentos(&fechaBuscar.anio,"\n Anio: ","\n Anio invalido",1950,2019,0);
        printf("\nLibros que se prestaron en la fecha %d/%d/%d",fechaBuscar.dia,fechaBuscar.mes,fechaBuscar.anio);
        for(i=0; i<tamPres; i++)
        {
            if(pres[i].fechaPrest.dia==fechaBuscar.dia && pres[i].fechaPrest.mes==fechaBuscar.mes && pres[i].fechaPrest.anio==fechaBuscar.anio)
            {
                for(j=0; j<tamLib; j++)
                {
                    if(lib[j].cod==pres[i].codigoLib && lib[j].estado==1 &&pres[i].estado==1)
                    {
                        encontrado=1;
                        printf("\n%s        Cod. Libro: %d      ",lib[j].titulo,lib[j].cod);
                        break;
                    }
                }

            }


        }
        if(encontrado==0)
        {
            printf("\nNo se ha encontrado prestamos en la fecha %d/%d/%d",fechaBuscar.dia,fechaBuscar.mes,fechaBuscar.anio);
        }

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }
}
void listarSociosPrestamoFechaDeterminada(eSocio soc[],int tamSoc,ePrestamo pres[],int tamPres,int *codigoSocio)
{
    int i;
    int j;
    int encontrado;
    eFecha fechaBuscar;
    if(*codigoSocio>0)
    {
        encontrado=0;
        printf("\nIngrese la fecha: ");
        getIntIntentos(&fechaBuscar.dia,"\n dia: ","\n Dia incorrecto",1,30,0);
        getIntIntentos(&fechaBuscar.mes,"\n Mes: ","\n Mes incorrecto",1,12,0);
        getIntIntentos(&fechaBuscar.anio,"\n Anio: ","\n Anio invalido",1950,2019,0);
        printf("\nSocios que relizaron solicitud de prestamo en la fecha %d/%d/%d",fechaBuscar.dia,fechaBuscar.mes,fechaBuscar.anio);
        for(i=0; i<tamPres; i++)
        {
            if(pres[i].fechaPrest.dia==fechaBuscar.dia && pres[i].fechaPrest.mes==fechaBuscar.mes && pres[i].fechaPrest.anio==fechaBuscar.anio)
            {
                for(j=0; j<tamSoc; j++)
                {
                    if(soc[j].codigo==pres[i].codigoSoc && (soc[j].estado==1 &&pres[i].estado==1))
                    {
                        encontrado=1;
                        printf("\n%s       %s         Cod. Libro: %d      ",soc[j].nombre,soc[j].apellido,soc[j].codigo);
                        break;
                    }
                }

            }


        }
        if(encontrado==0)
        {
            printf("\nNo se ha encontrado prestamos en la fecha %d/%d/%d",fechaBuscar.dia,fechaBuscar.mes,fechaBuscar.anio);
        }

    }
    else
    {
        printf("ERROR. Debe haberse dado de alta por lo menos un socio");
    }

}
void ordSocioApellido(eSocio soc[],int tamSoc, int * codSoc)
{
    int i;
    int j;
    eSocio aux;
    if(*codSoc>0)
    {
        for(i=1; i<tamSoc; i++)
        {
            aux=soc[i];
            j=i-1;
            while(aux.apellido>soc[j].apellido&&j>=0)
            {
                soc[j+1]=soc[j];
                j--;
            }
            soc[j+1]=aux;
        }
        for(i=0; i<tamSoc; i++)
        {
            if(soc[i].estado==1)
            {
                printf("\n%s      %s     %d",soc[i].nombre,soc[i].apellido,soc[i].codigo);
            }
        }

    }
    else
    {
        printf("Error. Debe darse de alta a al menos un socio");
    }


}
void ordLibTit(eLibro lib[],int tamLib,int *codigoSocio)
{
    if(*codigoSocio>0)
    {
        ordAsStructStrLib(lib,tamLib);
        printf("\n Titulo         Codigo  ");
        int i;

        for(i=0; i<tamLib; i++)
        {
            if(lib[i].estado==1)
            {
                printf("\n%s         %d    ",lib[i].titulo,lib[i].cod);

            }
        }
    }
    else
    {
        printf("ERROR. Debe haber al menos un alta de socio");
    }

}
