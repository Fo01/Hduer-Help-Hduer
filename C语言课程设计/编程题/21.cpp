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
	if (a==10) printf("f(10.0) = 0.1");
	else printf("f(%.1lf) = %.1lf",a,a);
} 
