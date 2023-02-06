#include<stdio.h>
#include<math.h>
#include<string.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
	int n,i;
    char s[100];
    gets(s);
    n=strlen(s);
    for(i=n-1;i>=0;i--)
    {
    	printf("%c",s[i]);
	}
}
