#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
   char nombre[20]={"juan carlos raul"};
   char apellido[20]={"perez"};
   char nombreCompleto[41];
   int i;
   /*printf("Ingrese nombre: ");
   gets(nombre);
   printf("Ingrese apellido: ");
   gets(apellido);*/
   strcpy(nombreCompleto,apellido);
   strcat(nombreCompleto,", ");
   strcat(nombreCompleto,nombre);
   strlwr(nombreCompleto);
   nombreCompleto[0]=toupper(nombreCompleto[0]);
   for(i=0;i<strlen(nombreCompleto);i++)
   {
       if(nombreCompleto[i]==' ')
       {
           nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
       }
   }


   printf(nombreCompleto);

   /*
   strcat(nombreCompleto,nombre);
   nombreCompleto[tamCadNo]=',';
   nombreCompleto[tamCadNo+1]=' ';
   nombreCompleto[tamCadNo+2]='\0';
   strcat(nombreCompleto,apellido);
   strlwr(nombreCompleto);
   nombreCompleto[0]=toupper(nombreCompleto[0]);
   nombreCompleto[tamCadNo+2]=toupper(nombreCompleto[tamCadNo+2]);
   printf(nombreCompleto);
   */
    return 0;
}
