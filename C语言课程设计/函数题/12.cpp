#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

double factorial(int x)
{
    double y=1;
    for(int i=x;i>0;i--)
	{
        y*=i;
    }
    return y;
}

double funcos( double e, double x )
{
    double cos=0,item=1;
    int i=0,p=1;
    while(item>=e)
	{
        item=pow(x,i)/factorial(i);
        cos+=p*item;
        i=i+2;
        p=-p;
    }
    return cos;
}
