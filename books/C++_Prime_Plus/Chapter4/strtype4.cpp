// strtype4.cpp -- line input

#include"iostream"
using namespace std;
#include"string"
#include"cstring"

int main() 
{
	char charr[20];
	string str;
	cout<<"Length of string in charr before input: "
		<<strlen(charr)<<endl;
	cout<<"Length of string in str before input: "
		<<str.size()<<endl;
	cin.getline(charr,20);	// indicate maximum length
	cout<<"You entered: "<<charr<<endl;
	cout<<"Enter another line of test:\n";
	getline(cin,str);	// cin now an argument; no length specifier
	cout<<"You entered: "<<str<<endl;
	cout<<"Length of string in charr after intpu: "
		<<strlen(charr)<<endl;
	cout<<"Length of string in str after input: "
		<<str.size()<<endl;

	return 0;
}