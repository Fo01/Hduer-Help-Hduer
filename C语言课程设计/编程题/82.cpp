#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
    int a[1002],b[1002],flag,temp=0,c,i,j,n,max=0,min=0;
    for(i=0;i<10;i++) sc(a[i]);
    for(i=1;i<10;i++)
    {
    	if (a[i]) 
    	{
    		pr(i);
    		a[i]--;
    		break;
		}
	}
	for(i=0;i<10;i++)
	{
		while(a[i]--) pr(i);
	}
}
