#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	double sum,in;
	scd(in);
	if (in<=1600) sum=0;
	else if (in<=2500) sum=(in-1600)*0.05;
	else if (in<=3500) sum=(in-1600)*0.1;
	else if (in<=4500) sum=(in-1600)*0.15;
	else sum=(in-1600)*0.2;
	printf("%.2lf",sum);
}
