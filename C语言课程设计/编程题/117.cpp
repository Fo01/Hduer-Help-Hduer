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
int n,i;

void sb()
{
	printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
}

void solve1()
{
	double a;
	printf("Please enter the radius:\n");
	scd(a);
	printf("%.2lf\n",3.141592653589793/3.0*a*a*a*4);
}

void solve2()
{
	double a,h;
	printf("Please enter the radius and the height:\n");
	scd(a); scd(h);
	printf("%.2lf\n",3.141592653589793*a*a*h);
}

void solve3()
{
	double a,h;
	printf("Please enter the radius and the height:\n");
	scd(a); scd(h);
	a=3.141592653589793/3.0*a*a*h;
	printf("%.2lf\n",a);
}

int main()
{
	while(1)
	{
		sb();
		sc(n);
		if (n==1) solve1();
		else if (n==2) solve2();
		else if (n==3) solve3();
		else break;
	}
} 
