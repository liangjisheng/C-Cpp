#include <iostream>
#include <cstring>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Person
{
public:
	Person(const char* first="John",const char* second="Doe")
	{
		initName(first,second);
	}
	Person(const Person& p)
	{
		initName(p.firstName,p.secondName);
	}
	~Person()
	{
		delete[] firstName;
		delete[] secondName;
	}
	const Person& operator=(const Person& p)
	{
		if(this == &p)
			return *this;
		delete []firstName;
		delete []secondName;
		initName(p.firstName,p.secondName);
		return *this;
	}
	bool operator<(const Person& p)
	{
		int result = strcmp(firstName,p.firstName);
		if( result < 0 ||
			(result == 0 && strcmp(secondName,p.secondName) < 0))
			return true;
		return false;
	}
	void ShowPerson() const
	{
		cout<<firstName<<' '<<secondName<<endl;
	}
private:
	char* firstName;
	char* secondName;
	// Private helper function to avoid code duplication
	void initName(const char* first,const char* second)
	{
		size_t len=strlen(first)+1;
		firstName = new char[len];
		strcpy_s(firstName,len,first);
		len=strlen(second)+1;
		secondName = new char[len];
		strcpy_s(secondName,len,second);
	}
};

int main()
{
	/*vector<Person> people;
	const size_t maxlength(50);
	char firstname[maxlength];
	char secondname[maxlength];

	// Input all the people
	while(true)
	{
		cout<<"Enter a first name or press Enter 0 to end: ";
		cin.getline(firstname,maxlength,'\n');
		if(0 == strlen(firstname))
			break;
		cout<<"Enter the second name: ";
		cin.getline(secondname,maxlength,'\n');
		people.push_back(Person(firstname,secondname));
	}

	// Output the contents of the vector
	cout<<endl;
	auto iter(people.begin());
	while(iter != people.end())
		iter++->ShowPerson();
	cout<<endl;*/


	vector<Person*> people;
	const size_t maxlength(50);
	char firstname[maxlength];
	char secondname[maxlength];

	// Input all the people
	while(true)
	{
		cout<<"Enter a first name or press Enter 0 to end: ";
		cin.getline(firstname,maxlength,'\n');
		if(0 == strlen(firstname))
			break;
		cout<<"Enter the second name: ";
		cin.getline(secondname,maxlength,'\n');
		people.push_back(new Person(firstname,secondname));
	}

	// Output the contents of the vector
	cout<<endl;
	auto iter(people.begin());
	while(iter != people.end())
		(*(iter++))->ShowPerson();
	cout<<endl;

	// Release memory for the people
	iter =people.begin();
	while(iter != people.end())
		delete *(iter++);

	// Pointers int the vector are now invalid,so remove the contents
	people.clear();

	system("pause");
	return 0;
}