#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int n=1,m=1,temp=1,a,i,sum=1;
	sc(n);
	sum=pow(2,n+1)-2;
	printf("result = %d",sum);
}
