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
	int n;
	double a=2,b=1,c,sum=0;
	sc(n);
	for(int i=0;i<n;i++)
	{
		sum+=a/b;
		c=a;
		a=a+b;
		b=c;
	}
	printf("%0.2lf",sum);
}
