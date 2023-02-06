#include <stdio.h>

int main()
{
    double h,n,d,sum;
    scanf("%lf %lf", &h, &n);
    sum=h;
    double m=n;
    while(n--)
    {
    	h=h/2;
    	sum+=h*2;
	}
    if (m!=0) sum=sum-h*2;
    else 
	{
		sum=0;
		h=0;
	}
    printf("%.1lf %.1lf",sum,h);
    return 0;
}
