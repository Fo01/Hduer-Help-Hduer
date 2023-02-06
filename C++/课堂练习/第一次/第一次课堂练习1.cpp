#include<bits/stdc++.h>
using namespace std;

void judge (int m)
{
	int c;
	c=(int)sqrt(m);
	if (c*c==m) cout<<m<<endl;
}

int main()
{
//	for(int i=30;i<=100;i++) cout<<i*i<<"\n";
	for (int i=1;i<=9;i++)
	{
		for (int j=0;j<=9;j++)
		{
			int a=i*1100+j*11;
			judge(a);
		}
	}
}
