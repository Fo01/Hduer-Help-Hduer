#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int i,a;
	double p[5]={0.00,3.00,2.50,4.10,10.20};
	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
	for(i=0;i<5;i++)
	{
		sc(a);
		if (a==0) break;
		if (a<=4&&a>=1) printf("price = %.2lf\n",p[a]);
		else printf("price = 0.00\n");
	}
}
