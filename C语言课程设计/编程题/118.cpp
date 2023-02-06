#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%l",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

struct thing
{
	char b[25];
	int n;
}a[25],c;
int n,i,j,cnt;

int main()
{
	cnt=0;
	while(1)
	{
		scanf("%s",a[cnt].b);
		if (a[cnt].b[0]=='#') break;
		a[cnt].n=strlen(a[cnt].b);
		cnt++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=cnt-1;j>0;j--)
		{
			if (a[j].n<a[j-1].n)
			{
				c=a[j];
				a[j]=a[j-1];
				a[j-1]=c;
			}
	    }
	}
	for(i=0;i<cnt;i++)
	{
		printf("%s ",a[i].b);
	}
} 
