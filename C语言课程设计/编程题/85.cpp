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
	sc(m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			sc(a[i][j]);
			sum+=a[i][j];
		}
	}
	for(i=0;i<m;i++) sum-=a[m-1][i]+a[i][m-1];
	sum+=a[m-1][m-1];
	for(i=1;i<m-1;i++) sum-=a[i][m-1-i];
	pr(sum);
	printf("\n");
} 
