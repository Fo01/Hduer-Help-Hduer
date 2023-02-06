#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	double a;
	scd(a);
	if (a>=0) 
	{
		printf("f(%.2lf) = ",a);
	    printf("%.2lf",sqrt(a));
	}
	else 
	{
		printf("f(%.2lf) = ",a);
		a=(a+1)*(a+1)+2*a+1/a;
		printf("%.2lf",a);
	}
} 
