// chartype.cpp -- the char type and int type contrasted
#include"iostream"
using namespace std;

int main() {
	char ch='M';
	int i=ch;
	cout<<"The ASCII code for "<<ch<<"is "<<i<<endl;

	cout<<"Add one to the character code:"<<endl;
	ch+=1;
	i=ch;
	cout<<"The ASCII code for "<<ch<<"is "<<i<<endl;
	// using the cout.put() member function to display a char
	cout<<"Display char ch using cout.put(ch): ";
	cout.put(ch);
	cout.put('!');
	cout<<endl;
	return 0;
}