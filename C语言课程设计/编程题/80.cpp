#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
    int a[12],c,i,n,max=0,min=0;
    sc(n);
    sc(a[0]);
    for(i=1;i<n;i++)
    {
    	sc(a[i]);
    	if (a[i]>=a[max]) max=i;
    	if (a[i]<=a[min]) min=i;
	}
	c=a[0]; a[0]=a[min]; a[min]=c;
	if (max==0) max=min;
	c=a[n-1]; a[n-1]=a[max]; a[max]=c;
	for(i=0;i<n;i++) 
	{
		printf("%d ",a[i]);
	}
}
