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
	int cnt=0,flag=0;;
	double now=1,eps,sum;
	scd(eps);
	while(1)
	{
		if (1.0/now<=eps) flag=1;
		if (cnt%2) sum-=1.0/now; 
		else sum+=1.0/now;
		cnt++;
		now+=3;
		if (flag) break;
	}
	printf("sum = %lf",sum);
}
