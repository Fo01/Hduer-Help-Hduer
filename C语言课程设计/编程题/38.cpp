#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int ans,n=1,m=1,temp=1,a,i,sum=1;
	sc(n);
	if (n<0) printf("sign(%d) = -1",n);
	else if (n==0) printf("sign(0) = 0");
	else printf("sign(%d) = 1",n);
}
