#include<bits/stdc++.h>
using namespace std;

int a[500],maxi=-999999,mini=999999,cnt=0;;
double sum;
void init()
{
	int b,c;
	while(cin>>b)
	{
		a[cnt]=b;
		cnt++;
		maxi=max(maxi,b);
		mini=min(mini,b);
		sum+=b;
	}
}

void printff()
{
	sum=sum/cnt;
	cout<<maxi<<" "<<mini<<" "<<sum<<"\n"; 
}

int main()
{
	init();
	printff();
}
