#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 85
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);
int main()
{
	int a1,b1,a2,b2;
	double sum1,sum2;
	sc(a1); 
	getchar();
	sc(b1);
	getchar(); 
	sc(a2); 
	getchar();
	sc(b2);
	sum1=a1*1.0/b1;
	sum2=a2*1.0/b2;
	if (sum1>sum2) printf("%d/%d > %d/%d\n",a1,b1,a2,b2);
	else if(sum1==sum2) printf("%d/%d = %d/%d\n",a1,b1,a2,b2);
	else printf("%d/%d < %d/%d\n",a1,b1,a2,b2);
}
