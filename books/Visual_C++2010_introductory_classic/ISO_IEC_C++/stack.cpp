// Exercising a stack container

#include <iostream>
#include <stack>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::list;
using std::string;

class Person
{
public:
	Person(const string first = "li",const string second = "shuyu")
	{
		firstname = first;
		secondname = second;
	}
	Person(const Person& p)
	{
		firstname = p.firstname;
		secondname = p.secondname;
	}
	bool operator<(const Person& p) const
	{
		if(secondname < p.secondname ||
			(secondname == p.secondname && firstname < p.firstname))
			return true;
	}
	bool operator>(const Person& p) const
	{
		return *this > p;
	}
	void ShowPerson() const
	{
		cout<<firstname<<' '<<secondname<<endl;
	}
private:
	string firstname;
	string secondname;
};

int main()
{
	stack<Person,list<Person> > people;
	string first,second;
	
	while(true)
	{
		cout<<"Enter a first name or press Enter to end: ";
		getline(cin,first);
		if(first.empty())
			break;

		cout<<"Enter a second name: ";
		getline(cin,second);
		people.push(Person(first,second));
	}

	cout<<"\nThere are "<<people.size()<<" people in the stack.\n\n";
	while(!people.empty())
	{
		people.top().ShowPerson();
		people.pop();
	}

	system("pause");
	return 0;
}