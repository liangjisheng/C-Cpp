// tyepcast.cpp -- torcing type changes
#include"iostream"
using namespace std;

int main() {
	int auks,bats,coots;
	// the following statement adds the values as double
	// then converts the result to int
	auks=19.99+11.99;
	// these statements ass values as int
	bats=(int)19.99+(int)11.99;	// odk C syntax
	coots=int(19.99) + int(11.99); // new C++ syntax
	cout<<"auks= "<<auks<<",bats="<<bats
		<<",coots= "<<coots<<endl;
	char ch='Z';
	cout<<"The code for "<<ch<<" is "	// print as char
		<<int(ch)<<endl;				// print as int

	return 0;
}