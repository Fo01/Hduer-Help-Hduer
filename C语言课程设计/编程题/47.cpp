#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

int main()
{
	int a,b;
	double sum;
	char s;
	sc(a);
	sc(b);
	getchar();
    s=getchar();
	if (b==90) sum=6.95;
	else if (b==93) sum=7.44;
	else sum=7.93;
	if (s=='m') sum=sum*a*0.95;
	else sum=sum*a*0.97;
	printf("%.2lf",sum);
}
