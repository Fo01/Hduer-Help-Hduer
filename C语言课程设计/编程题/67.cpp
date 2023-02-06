#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%ld",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%ld",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

int main()
{
	long long n,a[100]={0},k=0;
	sc(n); k=0;
	a[2]=3; a[3]=7; a[5]=31; a[7]=127; a[13]=8191; a[17]=131071; a[19]=524287;
	for(int i=0;i<=n;i++)
	{
		if (a[i]!=0) 
		{
			pr(a[i]);
			printf("\n");
			k=1;
		}
	}
	if (k==0) printf("None\n");
} 
