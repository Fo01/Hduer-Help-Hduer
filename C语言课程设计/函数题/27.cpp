#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff( n, m, out );   
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}

void CountOff(int n,int m,int out[])
{
	int cnt[MAXN];
	int rest=n;
	for(int i=0;i<MAXN;i++)
	{
		cnt[i]=1;
	}
	int now=0,sum=0;;
	while(rest)
	{
		sum+=cnt[now];
		now=(now+1)%n;
		if (sum==m) 
		{
		    rest--;
			out[(now-1+n)%n]=n-rest;
			cnt[(now-1+n)%n]=0;
			sum=0;
		}
	}
	return;
}
