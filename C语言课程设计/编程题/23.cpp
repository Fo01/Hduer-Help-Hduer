#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a;
	double sum;
	sc(a);
	if (a<0)
	{
		printf("Invalid Value!");
	}
	else if (a<=50) 
	{
		sum=a*0.53;
		printf("cost = %.2lf",sum);
	}
	else
	{
		sum=26.5+(a-50)*0.58;
		printf("cost = %.2lf",sum);
	}
} 
