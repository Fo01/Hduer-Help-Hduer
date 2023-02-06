#include<stdio.h>
#define sc(a) scanf("%d",&a);

int main()
{
	int n,a,b,c,big,small,del=0,cnt=0;
	sc(n);
	while(del!=495)
	{
		a=n%10;
		b=(n/10)%10;
		c=n/100;
		if (a>=b&&b>=c) 
		{
			big=a*100+b*10+c;
			small=c*100+b*10+a;
		}
		else if (a>=c&&c>=b)
		{
			big=a*100+c*10+b;
			small=b*100+c*10+a;
		}
		else if (b>=a&&a>=c)
		{
			big=b*100+a*10+c;
			small=c*100+a*10+b;
		}
		else if (b>=c&&c>=a)
		{
			big=b*100+c*10+a;
			small=a*100+c*10+b;
		}
		else if (c>=b&&b>=a)
		{
			big=c*100+b*10+a;
			small=a*100+b*10+c;
		}
		else if (c>=a&&a>=b)
		{
			big=c*100+a*10+b;
			small=b*100+a*10+c;
		}
		del=big-small;
		cnt++;
		printf("%d: %d - %d = %d\n",cnt,big,small,del);
		n=del;
	}
}
