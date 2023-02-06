#include<bits/stdc++.h>
using namespace std;

class matrix
{
	public:
		matrix(int *x,int n)
		{
			num=x;
			size=n;
		};
		matrix(matrix &a)
		{
			num=a.num;
			size=a.size;
		}
		void print()
		{
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++)
				{
					cout<<*num<<' ';
			    	num++;
				}
				cout<<endl;
			}
			num=num-size*size;
			cout<<endl;
		}
		void add(matrix &a)
		{
			for(int i=0;i<size*size;i++)
			{
				*num+=*(a.num);
				num++;
				(a.num)++;
			}
			num=num-size*size;
			a.num=a.num-a.size*a.size;
		}
	private:
		int *num,size;
};

int main()
{
	int a[9]={1,2,3,2,3,4,3,4,5};
	matrix mat1(a,3);
	mat1.print();
	matrix mat2(mat1);
	mat2.print();
	mat1.add(mat2);
	mat1.print(); 
} 
