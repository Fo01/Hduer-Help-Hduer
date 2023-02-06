#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	int a,b,c,mini,maxi,sum;
	sc(a);
	sc(b);
	sc(c);
	sum=a+b+c;
	if (a<=b&&a<=c) mini=a;
	else if (b<=a&&b<=c) mini=b;
	else mini=c;
	if (a>=b&&a>=c) maxi=a;
	else if (b>=a&&b>=c) maxi=b;
	else maxi=c;
	pr(mini);
	printf("->");
	pr(sum-mini-maxi);
	printf("->");
	pr(maxi); 
}
