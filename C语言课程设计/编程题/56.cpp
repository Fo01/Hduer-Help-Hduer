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
	int ran,i,n,t;
	sc(ran);
	sc(n);
	for(i=0;i<n;i++)
	{
		sc(t);
		if (t<0) 
		{
			printf("Game Over");
			break;
		}
		if (t==ran&&i==0) 
		{
			printf("Bingo!");
			break;
		}
		if (t==ran&&i<3)
		{
			printf("Lucky You!");
			break;
		}
		if (t==ran)
		{
			printf("Good Guess!");
			break;
		}
		if (t<ran) printf("Too small\n");
		if (t>ran) printf("Too big\n");
	}
	if (i>=n) printf("Game Over");
}
