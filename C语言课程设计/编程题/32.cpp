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
	for(i=0;i<=n;i++)
	{
		temp=pow(3,i);
		printf("pow(3,%d) = %d\n",i,temp);
	}
}
