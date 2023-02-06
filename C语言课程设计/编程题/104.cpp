#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%l",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

double ave=0,maxi=-999999,mini=9999999;
float a[100];
long long n,i;

int main()
{
	scanf("%lld",&n);
	for(i=0;i<n;i++) 
	{
		scanf("%f",&a[i]);
		ave+=a[i];
		if (a[i]>=maxi) maxi=a[i];
		if (a[i]<=mini) mini=a[i];
	}
	ave=ave/n;
	printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf",ave,maxi,mini);
} 
