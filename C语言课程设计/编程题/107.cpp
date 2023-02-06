#include<stdio.h>
#include<string.h>
#define MAX 85
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);
int main()
{
	int i,j,flag,len1=0,cnt=0;
	char a[5][100],t[100];
	for(int i=0;i<5;i++) scanf("%s",a[i]);
	for(i=0;i<4;i++)
		for(j=0;j<4-i;j++)
			if(strcmp(a[j],a[j+1])>0)
			{
				strcpy(t,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],t);
			}
	printf("After sorted:\n");
	for(i=0;i<5;i++)
		printf("%s\n",a[i]);

}

