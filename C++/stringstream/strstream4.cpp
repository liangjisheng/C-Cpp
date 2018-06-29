//:STRMOVE.CPP-- Ostrstream memory movement
#include"strstrea.h"

int main(int argc,char* argv[])
{
	ostrstream s;
	s<<"hi";
	char* old=s.str();//Freeze s
	s.rdbuf()->freeze(0);//Unfreeze
	for(int i=0;i<100;i++)
		s<<"howdy";//should force reallocation
	cout<<"old="<<(void*)old<<endl;
	cout<<"new="<<(void*)s.str()<<endl;//Freeze
	delete s.str();//Release storage
	return 0;
}