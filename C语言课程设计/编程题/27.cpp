#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,i;
	double sum=0;
	sc(a);
	for(i=1;i<=2*a;i=i+2)
	{
		sum+=1.0/(i*1.0);
	}
	printf("sum = %lf",sum);
} 
