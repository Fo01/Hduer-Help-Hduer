#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a;
	sc(a);
	if (a%5==0) printf("Drying in day %d",a);
	else if (a%5<=3) printf("Fishing in day %d",a);
	else printf("Drying in day %d",a);
}
