#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
	int n,i,cnt=0;
    char s[100],k;
    gets(s);
    n=strlen(s);
    for(i=n-1;i>=0;i--)
    {
    	if (isupper(s[i]))   s[i]=tolower(s[i]);
    	else if (islower(s[i])) s[i]=toupper(s[i]);
	}
	for(i=0;i<n-1;i++) printf("%c",s[i]);
}
