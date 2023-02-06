#include<bits/stdc++.h>
using namespace std;

void trans(int m)
{
	int cnt=0;
	while(m>1)
	{
		if (m%2) m=m*3+1;
		else m/=2;
		cnt++;
	}
	cout<<cnt<<"\n";
}

int main()
{
	int a;
	cin>>a;
	trans(a);
}
