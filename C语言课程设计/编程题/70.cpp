#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%ld",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%ld",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

int main()
{
	char s[1000];
	long long sum=0,num=0,n,i;
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if (i!=0&&s[i]==' '&&s[i-1]!=' ') num++;
	}
	if (s[n-1]!=' ') num++;
	pr(num); 
} 
