#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

double fac(int i)
{
	int j;
	double temp=1;
	if (i==0) return 1;
	for(j=1;j<=i;j++) temp*=j;
	return temp;
}

int main()
{
	int i,n;
	double sum;
	sc(n);sum=0;
	for(i=0;i<=n;i++) 
	{
		sum+=1.0/fac(i);
	}
	printf("%.8lf",sum);
}
