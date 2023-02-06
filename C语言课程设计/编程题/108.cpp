#include<stdio.h>
#include<string.h>
#define MAX 85
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);
int main()
{
	int i,j,flag,num,now,temp,len1=0,cnt=0,b[4];
	char a[100];
	scanf("%s",a);
	num=0; now=1; temp=3;
	for(i=31;i>=0;i--)
	{
		num=num+(a[i]-'0')*now;
		now=now*2;
		if (i%8==0) 
		{
			b[temp--]=num;
			num=0;
			now=1;
		}
	}
	for(i=0;i<4;i++)
	{
		pr(b[i]);
		if (i!=3) printf(".");
	}

}

