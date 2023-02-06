#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%ld",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%ld",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

int main()
{
	double now=1,sum=0,eps;
	long long n,a[100]={0},k=1;
	scanf("%le", &eps);
	while(now>=eps)
	{
		sum+=now;
		now=now*k/((2*k+1)*1.0);
		k++;
	}
	sum+=now;
	sum=sum*2;
	printf("PI = %.5lf",sum);
} 
