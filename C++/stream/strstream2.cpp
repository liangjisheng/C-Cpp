//:	OSTRING.CPP--Output strstreams
#include"strstrea.h"
#define SZ 100

int main(int argc,char* argv[])
{
	cout<<"type an int,a float and a string:";
	int i;
	float f;
	cin>>i>>f;
	cin>>ws;	//Throw away white space 
	char buf[SZ];
	cin.getline(buf,SZ);//Get rest of the line(cin.rdbuf() would be awkward)
	ostrstream os(buf,SZ, ios::app);
	os<<endl;
	os<<"integer= "<<i<<endl;
	os<<"float= "<<f<<endl;
	os<<ends;
	cout<<buf;
	cout<<os.rdbuf()<<endl;//Same effect 
	cout<<os.rdbuf()<<endl;//NOT the same effect
	return 0;
}