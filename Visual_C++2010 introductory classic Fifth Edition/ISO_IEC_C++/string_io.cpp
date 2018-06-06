// string io
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

// List names and ages
void Listnames(string names[],string ages[],size_t count)
{
	cout<<"\nThe names you entered are: "<<endl;
	for(size_t i=0;i<count && !names[i].empty();i++)
		cout<<names[i]+" aged "+ages[i]+'.'<<endl;
}

int main(void)
{
	const size_t count=100;
	string names[count];
	string ages[count];
	string firstname,secondname;

	for(size_t i=0;i<count;i++)
	{
		cout<<"\nEnter a first name or press Enter to end: ";
		getline(cin,firstname,'\n');
		if(firstname.empty())
		{
			Listnames(names,ages,i);
			cout<<"Done\n";
			return 0;
		}

		cout<<"Enter a second name: ";
		getline(cin,secondname,'\n');

		names[i]=firstname+' '+secondname;
		cout<<"Enter "+firstname+"'s age: ";
		getline(cin,ages[i],'\n');
	}
	cout<<"No space for more names.\n";
	Listnames(names,ages,count);

	system("pause");
	return 0;
}