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
	sc(n);
	sc(m);
	for(i=n;i<=m;i++)
	{
		sum+=i*i+1/(i*1.0);
	}
	printf("sum = %.6lf",sum);
}
