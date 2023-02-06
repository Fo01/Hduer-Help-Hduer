#include <stdio.h>

int gcd( int x, int y );

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));

    return 0;
}

int gcd( int x, int y )
{
	int c=y;
	while(c!=0)
	{
		c=x%y;
		x=y;
		y=c;
	}
	return x;
}
