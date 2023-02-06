#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
    int a,b,c,d,e,i,n;
    sc(n);
    a=(n%10+9)%10;
    n=n/10;
	b=(n%10+9)%10;
    n=n/10;
	c=(n%10+9)%10;
    n=n/10;
	d=(n%10+9)%10;
	e=a; a=c; c=e;
	e=b; b=d; d=e;
	printf("The encrypted number is ");
	pr(d);
	pr(c);
	pr(b);
	pr(a);
}
