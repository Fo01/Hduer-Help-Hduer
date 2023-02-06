#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%ld",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%ld",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

long long a[10][10],k=0,sum=0,num=0,n,m,i,j,flag,maxi;

int main()
{
	sc(m); sc(n);
	for(i=0;i<m;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			sc(a[i][j]);
			sum+=a[i][j];
		}
		pr(sum);
		printf("\n");
	}
} 
