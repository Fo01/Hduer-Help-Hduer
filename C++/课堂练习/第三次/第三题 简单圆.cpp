#include<bits/stdc++.h>
#define pi 3.1415926535897932384626433
using namespace std;

class simplecircle
{
	public:
		simplecircle(int r)
		{
			*itsradius=r;
		}
		double sum(simplecircle a)
		{
			return (*(a.itsradius))*(*(a.itsradius))*pi;
		}
	private:
		int *itsradius;
};

int main()
{
	simplecircle c1(2);
	cout<<c1.sum(c1)<<endl;
}
