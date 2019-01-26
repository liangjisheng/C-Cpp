// instr2.cpp -- reading more than one word with getline
#include"iostream"
using namespace std;

int main() 
{
	const int size=20;
	char name[size];
	char dessert[size];

	cout<<"Enter your name: \n";
	cin.getline(name,size);
	cout<<"Enter your favarite dessert: \n";
	cin.getline(dessert,size);
	cout<<"I have some delicious "<<dessert
		<<" for you."<<name<<".\n";

	getchar();
	return 0;
}