#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,i,n,m;
	double temp,sum=0;
	sc(n);
	sc(m);
	if (n<=m)
	{
	    printf("fahr celsius\n");
		for(i=n;i<=m;i=i+2)
		{
			pr(i);
			temp=(i-32)*5/9.0;
			printf("%6.1lf\n",temp);
		}	
	}
	else printf("Invalid.\n");
	
} 
