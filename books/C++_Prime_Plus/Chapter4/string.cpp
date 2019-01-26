#include"iostream"
#include"cstring"
using namespace std;

int main() 
{
	const int size=15;
	char name1[size];
	char name2[size]="C++owboy";

	cout<<"What your's name?";
	cin>>name1;
	cout<<strlen(name1)<<" letters and is stored\n";
	cout<<"in an array of "<<sizeof(name1)<<" bytes.\n";
	cout<<"Your initial is "<<name2[0]<<".\n";
	name2[3]='\0';
	cout<<"Here are the first 3 characters of my name: ";
	cout<<name2<<endl;

	getchar();
	//cin.get();
	return 0;
}