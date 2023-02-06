#include<bits/stdc++.h>
using namespace std;

class Rectangle
{
	
	public:
		double showlength(){cout<<length<<endl;}
		double showwide(){cout<<wide<<endl;}
		double showarea(){cout<<length*wide<<endl;}
		Rectangle()
		{
			wide=1.0;
			length=3.0;
		}
		Rectangle(double ll,double ww)
		{
			length=ll;
			wide=ww;
		}
		Rectangle(Rectangle &r);
	private:
		double length,wide;
};

Rectangle::Rectangle(Rectangle &r)
{
	length=r.length;
	wide=r.wide;
	cout<<111111<<endl;
}

int main()
{
	Rectangle r1;
	Rectangle r2(3,5);
	Rectangle r3(r2);
	r1.showarea();
	r2.showarea();
	r3.showarea();
} 
