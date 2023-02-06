#include<stdio.h>
#include<math.h>
#define sc(a) scanf("%d",&a);

int main()
{
    int a[10],i,n;
    sc(n);
    for(i=0;i<n;i++)
    {
    	sc(a[i]);
	} 
	for(i=0;i<n-1;i++)
	{
		a[i]=a[i+1]-a[i];
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d",a[i]);
		if ((i+1)%3==0||i==n-2) printf("\n");
		else printf(" ");
	}
}
