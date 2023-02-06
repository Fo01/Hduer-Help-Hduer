#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

int CountDigit(int n, int d)
{
	if (n<0) n=-n;
	int cnt=0;
	if (n==0&&d==0) return 1;
	else
	while(n)
	{
		if (n%10==d) cnt++;
		n=n/10;
	}
	return cnt;
}
