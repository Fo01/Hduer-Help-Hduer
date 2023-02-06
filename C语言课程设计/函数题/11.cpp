#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

int narcissistic(int n)
{
	int a[7]={153,370,371,407,1634,8208,9474};
	int flag=0;
	for(int i=0;i<7;i++)
	{
		if (n==a[i]) flag=1;
	}
	return flag;
}

void PrintN(int m,int n)
{
	int a[7]={153,370,371,407,1634,8208,9474};
	int flag=0;
	for(int i=0;i<7;i++)
	{
		if (a[i]>m&&a[i]<n) printf("%d\n",a[i]);
	}
}
