#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%l",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

string c,d;
long long n,i;

int main()
{
	maxi=-1;
	sc(n);
	for(i=0;i<n;i++)
	{
		gets(c);
		if (c.strlen()>maxi) 
		{
			maxi=strlen(c);
			d=c;
		}
	}
	printf("The longest is: %s",d);
} 
