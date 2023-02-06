#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%l",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

double b,c,d;
char a[2000][20];
long long n,i;

int main()
{
	sc(n);
	for(i=0;i<n;i++) 
	{
		scanf("%s",a[i]);
		scd(b); scd(c); scd(d);
		b=b+c-d;
		printf("%s %.2lf\n",a[i],b);
	}
} 
