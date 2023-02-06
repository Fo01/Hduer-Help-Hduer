#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,i,temp;
	double sum=0;
	sc(a);temp=1;
	for(i=1;i<=3*a;i=i+3)
	{
		sum+=1.0/(i*1.0)*temp;
		if (temp==1) temp=-1;
		else temp=1;
	}
	printf("sum = %.3lf",sum);
} 
