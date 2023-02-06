#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int a,b,c,d,e;

void judge(int s)
{
	if (s<60) e++;
	else if (s<70) d++;
	else if (s<80) c++;
	else if (s<90) b++;
	else a++;
}

int main()
{
	int n,ss;
	double sum,in;
	sc(n);
	for(int i=0;i<n;i++)
	{
		sc(ss);
		judge(ss);
	}
	printf("%d %d %d %d %d",a,b,c,d,e);
}
