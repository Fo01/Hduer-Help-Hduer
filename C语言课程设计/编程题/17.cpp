#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a;
	sc(a);
	a=(a-32)*5/9;
	printf("Celsius = ");
	pr(a);
} 
