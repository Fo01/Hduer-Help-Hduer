#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

int main()
{
	int a,b,a1,b1,c;
	sc(a);
	sc(b);
	a1=a;b1=b;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	pr(a);
	printf(" %d",a1*b1/a);
}
