#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,b;
	double x;
	sc(a);
	sc(b);
	x=(a-b)*1.0/(b*1.0)*100;
	if (x<10) printf("OK");
	else if (x<50) printf("Exceed %.0lf%%. Ticket 200",x);
	else printf("Exceed %.0lf\%%. License Revoked",x);
	
}
