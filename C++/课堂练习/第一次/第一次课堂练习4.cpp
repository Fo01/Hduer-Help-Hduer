#include<bits/stdc++.h>
using namespace std;

void calculate(int m)
{
	int sum=0,temp=1;
	for(int i=1;i<=m;i++)
	{
		temp=temp*i;
		sum+=temp;
	}
	cout<<sum<<"\n";
}

int main()
{
	int a;
	cin>>a;
	calculate(a);
}
