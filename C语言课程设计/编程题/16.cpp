#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	double a;
	scanf("%lf",&a);
	if (a==0) printf("f(0.0) = 0.0");
	else 
	{
		printf("f(%.1lf) = ",a);
		a=1/a;
		printf("%.1lf",a);
	}
} 
