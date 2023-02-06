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
	int n,a,mini=9999999;
	sc(n);
	for(int i=0;i<n;i++)
	{
		sc(a);
		if (a<mini) mini=a;
	}
	printf("min = %d",mini);
}
