#include<stdio.h>
#include<math.h>
#include<string.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)

char a[200],c;
int t[30],odd=0,even=0,cnt,n,flag,flag2,i,j,k;

int main()
{
	cnt=0;
	sc(n);
	scanf("%s",a);
	for(i=0;i<n;i++) {t[a[i]-'a']++;}
	for(i=0;i<n;i++)
	{
		if (t[i]%2) odd++;
		else even++;
	}
	flag2=0;
	if (odd>=2) printf("Impossible\n");
	else
	{
		for(i=0;i<n/2;i++)
		{
			flag=0;
			if (t[a[i]]%2)
			{
				flag2=1; continue;
			}
			for(j=n-i-1+flag2;j>=0;j--)
			{
				if (a[j]==a[i])
				{
					flag=1;
					c=a[j];
					for(k=j;k<n-i-1+flag2;k++) 
					{
						a[k]=a[k+1];
						cnt++;
					}
					a[k]=c;
				}
				if (flag) break;
			}
		}
		pr(cnt);
	}  
} 
