// test_string.cpp -- using new and delete with classes
#include"iostream"
using std::cout;
#include"String.h"

void callme1(String &);
void callme2(String);

int main() {
	using std::endl;
	String headline1("Celery Stalks at Midnight");
	String headline2("Lettuce Prey");
	String sports("Spinach Leaves Bow1 for Dollars");
	cout<<endl;
	cout<<"headline1: "<<headline1<<endl;
	cout<<"headline2: "<<headline2<<endl;
	cout<<"sports: "<<sports<<endl;
	callme1(headline1);
	cout<<"headline1: "<<headline1<<endl;
	callme2(headline2);
	cout<<"headline2: "<<headline2<<endl;

	cout<<"Initialize one object to another: \n";
	String sailor=sports;
	cout<<"sailor: "<<sailor<<endl;
	cout<<"Assign one object ot another: \n";
	String knot;
	knot=headline1;
	cout<<"knot: "<<knot<<endl;

	String s1,s2,s3;
	s1="liafds";
	cout<<"s1="<<s1<<endl;
	s1("lishuyu");
	cout<<"s1="<<s1<<endl;
	s2=s1;
	cout<<"s2="<<s2<<endl;
	cout<<"s1=";
	for(int i=0;i<s1.lenght();i++)
		cout<<s1[i]<<" ";
	cout<<endl;

	char * p;
	p=s1.c_str();
	cout<<p<<endl;

	cout<<"\nEnd of main()\n";
	return 0;
}

void callme1(String & s) {
	cout<<"String passed by reference:\n";
	cout<<"\""<<s<<"\"\n";
}

void callme2(String s) {
	cout<<"String passed by value:\n";
	cout<<"\""<<s<<"\"\n";
}