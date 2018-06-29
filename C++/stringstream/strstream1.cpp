//: ISTRING.CPP--Input strstreams
#include"strstrea.h"

int main(int argc,char* argv[])
{
	istrstream s("1.414 47 This is a test");
	int i;
	float f;
	s>>i>>f;	//Whitespace-delimited input
	char buf2[100];
	s>>buf2;
	cout<<"i="<<i<<",f="<<f;
	cout<<" buf2="<<buf2<<endl;
	cout<<s.rdbuf()<<endl;		//Get the rest...
	return 0;
}