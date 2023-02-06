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
	int a,sum=0;
	while(1)
	{
		sc(a);
		if (a<=0) break;
		if (a%2) sum+=a;
	}
	pr(sum);
}
