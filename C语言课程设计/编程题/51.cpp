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
	int n,a=0,b=0;
	sc(n);
	while(n)
	{
		a++;
		b+=n%10;
		n=n/10;
	}
	pr(a);
	printf(" ");
	pr(b);
}
