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
	char c='A';
	int n,i,j;
	sc(n);
	for(i=n;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			prc(c);
			printf(" ");
			c++;
		}
		printf("\n");
	}
} 
