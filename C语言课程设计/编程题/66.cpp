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
	long long n,a[100],k=0;
	sc(n);
	while(n)
	{
		a[k]=n%10;
		n=n/10;
		k++;
	}
	for(int i=k-1;i>=0;i--) 
	{
		pr(a[i]);
		printf(" ");
	}
	if (k==0) printf("0 ");
} 
