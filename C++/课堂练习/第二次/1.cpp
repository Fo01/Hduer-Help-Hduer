#include<bits/stdc++.h>
using namespace std;

class student
{
	public:
		void set_information(string nnumber,string nname,string nmajor);
		void show_information();
		void show_same_major(student k);
		student()
		{
			name="sb";
			number="250250250";
			major="不读书的么"; 
		}
		student(string aa,string bb,string cc)
		{
			name=aa;
			number=bb;
			major=cc;
		}
		student (student &s);
	private:
		string number,name,major;
};

student::student(student &s)
{
	name=s.name;
	number=s.number;
	major=s.major;
}

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

int main()
{
	student s2("张逸轩","19061440","网络工程");
	student s3(s2);
	int i;
	string a,b,c;
	cin>>a>>b>>c;
	student s1(a,b,c);
	s1.show_information();
	s2.show_information();
	s3.show_information();
}
