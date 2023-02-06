#include<bits/stdc++.h>
using namespace std;

class point3
{
	public:
		point3(int xx,int yy,int zz)
		{
			x=xx;
			y=yy;
			z=zz;
			cnt++;
		}
		point3(point3 &p)
		{
			x=p.x;
			y=p.y;
			z=p.z;
			cnt++;
		}
		int getx() {return x;}
		int gety() {return y;}
		int getz() {return z;}
		static int getNum(){return cnt;}
		double len(point3 p1,point3 p2)
		{
			return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
		}
		friend double Area(point3 p1,point3 p2,point3 p3)
		{
			double l1,l2,l3,p,sum;
			l1=p1.len(p1,p2);
			l2=p1.len(p1,p3);
			l3=p1.len(p2,p3);
			p=(l1+l2+l3)/2;
			sum=sqrt(p*(p-l1)*(p-l2)*(p-l3));
			return sum;
		}
	private:
		int x,y,z;
		static int cnt;
};
int point3::cnt=0;

int main()
{
	point3 p1(0,1,1);
	point3 p2(0,4,5);
	point3 p3(12,1,1);
	cout<<point3::getNum()<<endl;
	cout<<Area(p1,p2,p3);
}
