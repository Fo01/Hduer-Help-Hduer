#include<stdio.h>
#include<math.h>
#include<string.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
	int n,i,cnt=0;
    char s[100],k;
    gets(s);
    n=strlen(s);
    scanf("%c",&k);
    for(i=n-1;i>=0;i--)
    {
    	if (s[i]==k) cnt++;
	}
	pr(cnt);
}
