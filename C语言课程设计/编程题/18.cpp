#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	double m,y,r;
	scd(m);
	scd(y);
	scd(r);
	m=m*pow(1+r,y)-m;
	printf("interest = %.2lf",m);
} 
