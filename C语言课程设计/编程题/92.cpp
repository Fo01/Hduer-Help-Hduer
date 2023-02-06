#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int i,j;
int a[11][11],n,max,maxj,flag,count=0;

int right(int p)
{
	while(a[i][j]==0&&j<n)
	{
		a[i][j++]=p++;
	}
	j--;i++;
	return p; 
}

int down(int p)
{
	while(a[i][j]==0&&i<n)
	{
		a[i++][j]=p++;
	}
	i--;j--;
	return p; 
}

int left(int p)
{
	while(j>=0&&a[i][j]==0)
	{
		a[i][j--]=p++;
	}
	j++;i--;
	return p; 
}

int up(int p)
{
	while(i>=0&&a[i][j]==0)
	{
		a[i--][j]=p++;
	}
	i++;j++;
	return p; 
}

int main()
{
    sc(n);
    for(int i=0;i<11;i++)
        for(int j=0;j<11;j++)
            a[i][j]=0;
    int now=1; i=0;j=0;
    while(now<=n*n)
    {
    	now=right(now);
    	now=down(now);
    	now=left(now);
    	now=up(now);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
            printf("%3d",a[i][j]);
        printf("\n");
	}
        
}
