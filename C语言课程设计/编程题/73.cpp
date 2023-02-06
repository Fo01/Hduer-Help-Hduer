#include<stdio.h>
#include<math.h>
#include<string.h>
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%ld",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

long long a[20],k=0,sum=0,num=0,n,m,i,flag,maxi;

int main()
{
	maxi=-99999999;
	scanf("%ld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}
	for(int i=n-1;i>0;i--)
	{
		printf("%ld ",a[i]);
	}
	pr(a[0]);
} 
