#include<stdio.h>
#include<math.h>
#define sc(a) scanf("%ld",&a);

int prime(int n)
{
	if (n==2) return 1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}

int main()
{
	long long a;
	sc(a);
	if (a==4) printf("4 = 2 + 2");
	else
	for(int i=3;i<=a/2;i+=2)
	{
		if (prime(i)&&prime(a-i)) 
		{
			printf("%d = %d + %d",a,i,a-i);
			break;
		}
	}
}
