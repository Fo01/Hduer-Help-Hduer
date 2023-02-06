#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,b,c,d,sum;
	double ave;
	sc(a);
	sc(b);
	sc(c);
	sc(d);
	sum=a+b+c+d;
	ave=sum*1.0/4;
	printf("Sum = %d; ",sum);
	printf("Average = %.1lf",ave);
} 
