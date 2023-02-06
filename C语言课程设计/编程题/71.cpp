#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%ld",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%ld",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)
long long a[20],k=0,sum=0,num=0,n,m,i,flag;
int main()
{
	
	sc(n);
	for(int i=0;i<n;i++)
	{
		sc(a[i]);
	} 
	sc(m);flag=0;
	for(i=0;i<n;i++)
	{
		if (m<=a[i]&&flag==0) 
		{
			flag=1;
			pr(m);
			printf(" ");
			pr(a[i]);
		}
		else pr(a[i]);
		printf(" ");
	}
	if (flag==0) printf("%ld ",m);
} 
