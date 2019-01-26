// instr1.cpp -- reading more than one string

#include"iostream"
using namespace std;

int main() 
{
	const int size=20;
	char name[size];
	char dessert[size];

	cout<<"Enter your name: \n";
	cin>>name;
	cout<<"Enter your favarite dessert: \n";
	cin>>dessert;
	cout<<"I have some delicious "<<dessert
		<<" for you."<<name<<".\n";

	getchar();
	return 0;
}