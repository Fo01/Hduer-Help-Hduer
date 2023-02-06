#include<bits/stdc++.h>
#define n 5
using namespace std;

class point 
{
	public:
		point(int xx=0,int yy=0)
		{
			x=xx;
			y=yy;
		}
		int getx(){return x;}
		int gety(){return y;}
	private:
		int x,y;
};

point p[5];

int geta1()
{
	int a1=0;
	for(int i=0;i<n;i++)
	{
		a1+=p[i].getx();
	}
	a1=a1*2;
	return a1;
}
		
int geta2()
{
	int a1=0;
	for(int i=0;i<n;i++)
	{
		a1+=p[i].getx()*p[i].getx();
	}
	a1=a1*2;
	return a1;
}
		
int getc1()
{
	int a1=0;
	for(int i=0;i<n;i++)
	{
		a1-=p[i].gety();
	}
	a1=a1*2;
	return a1;
}
		
int getc2()
{
	int a1=0;
	for(int i=0;i<n;i++)
	{
		a1-=p[i].getx()*p[i].gety();
	}
	a1=a1*2;
	return a1;
}

int main()
{
	for (int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		p[i]=point(a,b);
	} 
	int a[2][3]={geta1(),2*n,getc1(),geta2(),geta1(),getc2()};
	double x,y;
	y=((a[1][2]*a[0][0]-a[0][2]*a[1][0])*1.0)/((a[0][1]*a[1][0]-a[1][1]*a[0][0])*1.0);
	x=((a[1][2]*a[0][1]-a[0][2]*a[1][1])*1.0)/((a[0][0]*a[1][1]-a[1][0]*a[0][1])*1.0);
	cout<<"a="<<x<<endl<<"b="<<y<<endl;
}
