#include<bits/stdc++.h>
using namespace std;

class student
{
	public:
		void set_information(string nnumber,string nname,string nmajor);
		void show_information();
		void show_same_major(student k);
	private:
		string number,name,major;
};

student s[200];
int maxi=0;

void student::set_information(string nnumber,string nname,string nmajor)
{
	name=nname;
	number=nnumber;
	major=nmajor;
}

void student::show_information()
{
	cout<<name<<"  "<<number<<"  "<<major<<"\n";
}

//void student::show_same_major(student p)
//{
//	int i=0;
//	while (i<maxi)
//	{
//		if (s[i].major==p.major) s[i].show_information();
//	}
//}


int main()
{
	int i;
	while (1)
	{
		string a,b,c;
		cout<<"若输入已完成，请输入三个-1，若仍需输入，请依次输入姓名、学号及专业:";
		cin>>a>>b>>c;
		if (a=="-1"&&b=="-1"&&c=="-1") break;
		s[i].set_information(b,a,c);
		s[i].show_information();
		maxi++;
	}
}
