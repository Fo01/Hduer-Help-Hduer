#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y,n;
    char year[10]; 
	string first,last;
	cin>>first>>last>>year;
	n=strlen(year);
	y=0;
	for(int i=0;i<n;i++) 
	{
		y=y*10+(year[i]-'0');
	}
	y=2020-y-1;
	cout<<"Dear "<<first.substr(1,1)<<". "<<last<<",\n  Thank you for your message! We appreciate the wonderful "<<y<<" year for your growing up. We will reply soon.\n\nBest wishes.";
} 
