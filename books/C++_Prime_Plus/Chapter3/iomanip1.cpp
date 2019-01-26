#include"iostream"
#include"iomanip.h"

int main() 
{
	int a=10;
	int b=010;
	int c=0x10;

	cout<<"a="<<dec<<a<<endl
		<<"b="<<oct<<b<<endl
		<<"c="<<hex<<c<<dec<<endl;
	cout<<setiosflags(ios::left);
	cout<<setw(4)<<a<<endl;
	cout<<setw(4)<<b<<endl;

	cout.width(5);
	cout.fill('$');
	cout<<a<<endl;
	cout.fill('%');
	cout.width(5);
	cout<<b<<endl;

	int e=123;
	int f=12;

	cout<<setiosflags(ios::right);
	cout<<setw(5)<<setfill('r')<<e<<endl;
	cout.width(4); cout.fill('a');
	cout<<f<<endl;

	const double pi=3.1415926;
	double r=6.779,c1,s;
	cout<<"pi="<<pi<<endl;
	c1=2*pi*r;
	s=pi*r*r;
	cout<<setiosflags(ios::scientific);
	cout<<"r="<<r<<endl;
	cout<<"c1="<<c1<<endl;
	cout<<setiosflags(ios::fixed);
	cout<<"s="<<s<<endl;
	
	return 0;
}