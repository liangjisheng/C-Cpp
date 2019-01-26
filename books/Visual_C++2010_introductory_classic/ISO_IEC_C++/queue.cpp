// Exercising a priority queue container

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::string;
using std::vector;
using std::greater;

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
	priority_queue<Person,vector<Person>,greater<Person> > people;
	string first,second;
	while(true)
	{
		cout<<"Enter a first name or press Enter to end: ";
		getline(cin,first,'\n');
		if(first.empty())
			break;

		cout<<"Enter a second name: ";
		getline(cin,second,'\n');
		people.push(Person(first,second));
	}

	cout<<"\nThere are "<<people.size()
		<<" people int the queue.\n\n";

	cout<<"The name that you entered are: "<<endl;
	while(!people.empty())
	{
		people.top().ShowPerson();
		people.pop();
	}

	system("pause");
	return 0;
}