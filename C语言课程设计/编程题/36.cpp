#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

double fact(int n)
{
	int i;
	double sum=1;
	for (i=1;i<=n;i++) sum=sum*i;
	return sum;
}

int main()
{
	long long ans,n=1,m=1,temp=1,a,i,sum=1;
	sc(m);
	sc(n);
	ans=fact(n)/fact(m)/fact(n-m);
	printf("result = %ld",ans);
}
