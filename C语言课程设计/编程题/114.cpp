#include<stdio.h>
#include<string.h>
#define MAX 85
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

struct people
{
	char name[10];
	int born;
	char number[20];	
}p[10],t;

int main()
{
	int n,i,j;
	sc(n);
	for(i=0;i<n;i++)
		scanf("%s %d %s",p[i].name,&p[i].born,p[i].number);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)	
			if(p[j].born>p[j+1].born)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
	for(i=0;i<n;i++) printf("%s %d %s\n",p[i].name,p[i].born,p[i].number);
}
