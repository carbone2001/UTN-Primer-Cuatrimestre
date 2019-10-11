#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    int i;
    int cant;
    int num[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int num1,num2,num3,num4;
    //printf("Hello world!\n");
    f = fopen("archivo.txt","w");
    for (i=0; i<12; i++)
    {
        if((i+1)%4 != 0)
        {
            fprintf(f,"%d,",num[i]);
        }
        else
        {
            fprintf(f,"%d\n",num[i]);
        }
        /*if(i==0)
        {
            fprintf(f,"%d",num[i]);
            fprintf(f,",");
        }
        else
        {
            if(i%4==0 && i!=0)
            {
                fprintf(f,"\n");
            }
            else
            {
                fprintf(f,"%d",num[i]);
                fprintf(f,",");
            }
        }*/


    }
    fclose(f);
    f = fopen("archivo.txt","r");
    while(!feof(f))
    {
        cant = fscanf(f,"%d,%d,%d,%d\n",&num1,&num2,&num3,&num4);
        if (cant < 4)
        {
            break;
        }
        printf("%d %d %d %d ",num1,num2,num3,num4);
    }
    fclose(f);
    return 0;
}
