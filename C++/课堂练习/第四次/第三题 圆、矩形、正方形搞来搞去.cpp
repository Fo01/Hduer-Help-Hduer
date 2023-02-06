#include<bits/stdc++.h>
#define pi 3.14159265358979323846
using namespace std;

class shape{};
class circle:public shape
{
	private:
		double x,y,r;
	public:
		circle(int xx=0,int yy=0,int rr=0){x=xx; y=yy; r=rr;};
		void getarea()
		{
			cout<<"The area of this circle is "<<pi*r*r<<endl; 
		}
};
class rectangle:public shape
{
	private:
	    double x,y,z,w;
	public:
		rectangle(int xx=0,int yy=0,int zz=0,int ww=0){x=xx; y=yy; z=zz; w=ww;}
		void initrec(double xx=0,double yy=0,double zz=0,double ww=0)
		{
			this->x=xx;
			this->y=yy;
			this->z=zz;
			this->w=ww;
		}
	    void getarea()
		{
			cout<<"The area of this rectangle is "<<abs((x-z)*(y-w))<<endl; 
		} 
};
class square:public rectangle
{
	private:
	    double line; 
	public:
		square(double xx=0,double yy=0,double line=0){initrec(xx,yy,xx+line,yy+line);}
};

int main()
{
   circle circle3(2,2,2);
   circle3.getarea();
   rectangle rec2(1,1,2,3);
   rec2.getarea();
   square squ1(1,2,3);
   squ1.getarea();
} 
