#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,b,h1,h2;
	sc(a);
	sc(b);
	h1=a/100*60+a%100;
	h2=b/100*60+b%100;
	h1=h2-h1;
	h2=h1%60;
	h1=h1/60;
	if (h1<10) printf("0");
	printf("%d:",h1);
	if (h2<10) printf("0");
	printf("%d",h2);
} 
