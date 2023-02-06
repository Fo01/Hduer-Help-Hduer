#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
    int a[1002],b[1002],flag,temp=0,c,i,j,n,max=0,min=0;
    sc(n);
    for(i=0;i<n;i++)
    {
    	a[i]=0;
    	b[i]=0;
	}
    for(i=0;i<n;i++) 
	{
		sc(c);
		flag=0;
		for(j=0;j<temp;j++)
		{
			if (a[j]==c) 
			{
				b[j]++;
				flag=1;
				break;	
			}
		}
		if (flag==0)
		{
			a[temp]=c;
			b[temp]=1;
			temp++;
		}
	}
	max=0;
	for(i=0;i<n;i++)
	{
		if (b[i]>=b[max]) max=i;
	}
	printf("%d %d",a[max],b[max]);
}
