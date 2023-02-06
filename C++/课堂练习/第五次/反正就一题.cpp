#include<bits/stdc++.h>
using namespace std;

class animal
{
	public:
		string name;
		int length,weight;
		animal(string n,int l,int w):name(n),length(l),weight(w){};
};

class ter_animal:virtual public animal
{
	public:
	    int run_speed;
	    ter_animal(string s,int a,int b,int c):animal(s,a,b),run_speed(c){};
};

class aqu_animal:virtual public animal
{
	public:
	    int swim_speed;
	    aqu_animal(string s,int a,int b,int d):animal(s,a,b),swim_speed(d){};
};

class amp_animal:public ter_animal,public aqu_animal
{
	public:
		amp_animal(string s,int a,int b,int c,int d):animal(s,a,b),aqu_animal(s,a,b,d),ter_animal(s,a,b,c){};
		void show()
		{
			cout<<"name:"<<name<<endl<<"length:"<<length<<endl<<"weight:"<<weight<<endl<<"run_speed:"<<run_speed<<endl<<"swim_speed:"<<swim_speed<<endl;
		}
};

int main()
{
	string s;
	int a,b,c,d;
	cout<<"please input the name,length(cm),weight(kg),run speed(m/s),swim speed(m/s) in order"<<endl;
	cin>>s>>a>>b>>c>>d;
	amp_animal frog(s,a,b,c,d);
	frog.show();
	
} 
