#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 85
#define pr(a) printf("%d",a);
#define sc(a) scanf("%lf",&a);
char s[4][100],b[4][2];
int main()
{
	int i,n;
	for(i=0;i<4;i++) scanf("%s",s[i]);
	for(i=0;i<4;i++)
	{
		n=strlen(s[i]);
		b[i][0]=s[i][n-2];
		b[i][1]=s[i][n-1];
		printf("%s",b[i]);
	}
	printf("\n");
}
