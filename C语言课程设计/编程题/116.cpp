#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 85
#define pr(a) printf("%d",a);
#define sc(a) scanf("%lf",&a);
int main()
{
	double x1,y1,x2,y2;
	sc(x1);
	sc(y1);
	sc(x2);
	sc(y2);
	x1=x1+x2;
	y1=y1+y2;
	if (x1<0.05&&x1>-0.05) x1=0;
	if (y1<0.05&&y1>-0.05) y1=0;
	printf("(%.1lf, %.1lf)",x1,y1);
}
