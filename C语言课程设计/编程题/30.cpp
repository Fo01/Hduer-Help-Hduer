#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int n=1,m=1,temp=1,a,i;
	double sum=0;
	sc(a);
	for(i=0;i<a;i++)
	{
		sum+=temp*n/(m*1.0);
		n++;
		m+=2;
		if (temp==1) temp=-1;
		else temp=1;
	}
	printf("%.3lf",sum);
} 
