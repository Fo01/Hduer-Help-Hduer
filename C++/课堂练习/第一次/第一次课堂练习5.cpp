#include<bits/stdc++.h>
using namespace std;

void swap1(int m,int n)
{
	int temp;
	temp=m;
	m=n;
	n=temp;
}

void swap2(int &m,int &n)
{
	int temp;
	temp=m;
	m=n;
	n=temp;
}

int main()
{
	int a,b;
	cin>>a>>b;
	swap1(a,b);
	cout<<a<<" "<<b<<"\n";
	swap2(a,b);
	cout<<a<<" "<<b<<"\n";

}
