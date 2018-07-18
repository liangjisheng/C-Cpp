//: WALRUS.CPP--Freezing a strstream
#include"strstrea.h"

int main(int argc,char* argv[])
{
	ostrstream s;
	s<<"'The time has come',the walrus said,";
	s<<ends;
	cout<<s.str()<<endl;//String is frozen
	//S is frozen;destructor won't delete
	//the streambuf storage on the heap
	s.seekp(-1,ios::cur);//back up before NULL
	s.rdbuf()->freeze(0);//Unfreeze it

	s<<" 'To speak of many things'"<<ends;
	cout<<s.rdbuf()<<endl;
	return 0;
}