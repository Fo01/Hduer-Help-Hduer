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
	int a,b,c,sum=0;
	sc(a);
	sc(b);
	c=a;
	for(int i=0;i<b;i++)
	{
		sum+=c;
		c=c*10+a;
	}
	printf("s = %ld",sum);
}
