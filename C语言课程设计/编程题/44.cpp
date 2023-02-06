#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	double a,b,c,area,s;
	scd(a);
	scd(b);
	scd(c);
	if (a+b>c&&a+c>b&&b+c>a) 
	{
		s=(a+b+c)/2.0;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		s=a+b+c;
		printf("area = %.2lf; perimeter = %.2lf",area,s);
	}
	else printf("These sides do not correspond to a valid triangle");
}
