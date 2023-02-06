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
	int a[200],i,ans,n;
	sc(n);
	a[1]=1;a[2]=1;
	for(i=3;i<40;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	for(i=1;i<100;i++) if (a[i]>=n) break;
	pr(i);
}
