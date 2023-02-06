#include<bits/stdc++.h>
using namespace std;

class Complex
{
	public:
		Complex(int aa,int bb)
		{
			a=aa;
			b=bb;
		}
		Complex(int aa)
		{
			a=aa+0.5;
			b=0;
		}
		Complex()
		{
			a=0;
			b=0;
		}
		Complex(Complex &c);
		void add(Complex c);
		void show(){cout<<a<<'+'<<b<<"i"<<endl;}
	private:
		double a,b;
};

Complex::Complex(Complex &c)
{
	a=c.a;
	b=c.b;
}

void Complex::add(Complex c)
{
	a+=c.a;
	b+=c.b;
}

int main()
{
	Complex c1(3,5);
	Complex c2(4);
	c1.add(c2);
	c1.show();
}
