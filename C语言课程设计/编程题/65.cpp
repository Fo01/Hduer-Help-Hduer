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
	int a[4]={6,28,496,8128};
	char c='A';
	int n,m,flag,i,j;
	sc(m);
	sc(n);
	flag=0;
	for(i=0;i<4;i++)
	{
		if (a[i]>=m&&a[i]<=n)
		{
			flag=1;
			if (i==0) printf("6 = 1 + 2 + 3\n");
            if (i==1) printf("28 = 1 + 2 + 4 + 7 + 14\n");
            if (i==2) printf("496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248\n");
            if (i==3) printf("8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064");
		} 
    }
    if (flag==0) printf("None");
} 
