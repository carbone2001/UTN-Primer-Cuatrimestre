int fsumar(int x, int y)
{
    int rta;
    rta=x+y;

    return rta;
}
int frestar(int x,int y)
{
    int rta;
    rta=x-y;

    return rta;
}
float fdivision(int x,int y)
{
    float rta;
    rta=(float)x/y;
    return rta;
}

int fmultiplicacion(int x, int y)
{
    int rta;
    rta=x*y;

    return rta;
}

int ffactorial(int x)
{
    int i;
    int fact;
    fact=x;

    if(x<0)
    {
        fact=(-1);
    }
    else if(x==0)
    {
        fact=1;
    }
    else
    {
        int i;
        int fact;
        fact=x;
        for(i=1;i<x;i++)
        {
            fact=fact*i;
        }
    }

    for(i=1;i<x;i++)
    {
        fact=fact*i;
    }

    return fact;
}

