#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,b;
	sc(a);
	sc(b);
	printf("%d + %d = %d\n%d - %d = %d\n%d * %d = %d\n%d / %d = %d",a,b,a+b,a,b,a-b,a,b,a*b,a,b,a/b);
} 
