// ��һ��ӳ���������洢�绰���룬���ṩһ���ҵ�ĳ����
// �绰����Ļ��� Using a map container

#include <iostream>
#include <cstdio>
#include <string>
#include <functional>
#include <map>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ios;
using std::string;
using std::pair;
using std::map;
using std::make_pair;

class Person
{
public:
	Person(const string first = "", const string second = "")
	{
		firstname = first;
		secondname = second;
	}
	bool operator<(const Person& p) const
	{
		if (secondname < p.secondname ||
			(secondname == p.secondname && firstname < p.firstname))
			return true;
	}
	string getName() const
	{
		return firstname + " " + secondname;
	}
private:
	string firstname;
	string secondname;
};

// Read a person from cin
Person getPerson()
{
	string first, second;
	cout << "Enter a first name: ";
	getline(cin, first);
	cout << "Enter a second name: ";
	getline(cin, second);
	return Person(first, second);
}

// Add a new entry to a phone book
void addEntry(map<Person, string>& book)
{
	string number;
	Person person = getPerson();

	cout << "Enter the phone number for "
		<< person.getName() << ": ";
	getline(cin, number);
	// ����һ���Զ���make_pair<>()��һ������ģ�壬�Զ��Ƶ�ģ���������
	auto entry = make_pair(person, number);
	// insert()����ɹ������ص�������
	// pair<map<Person,string>::iterator,bool>,��һ��ָ��Ԫ����map
	// �е�λ�ã�boolָʾ�Ƿ�ɹ�,��ʧ�ܣ����һ��ָ���Ѵ��ڵ�Ԫ��
	// ��map�е�λ�ã�
	auto pr = book.insert(entry);
	if (pr.second)
		cout << "Inserting succeeded.\n";
	else
	{
		cout << "Entry exists for " << person.getName()
			<< ". The number is " << pr.first->second << endl;
	}
}

// List the contents of a phone book
void listEntries(map<Person, string>& book)
{
	if (book.empty())
	{
		cout << "The phone book is empty.\n";
		return;
	}
	cout << setiosflags(ios::left);
	for (auto iter = book.begin(); iter != book.end(); iter++)
	{
		cout << setw(30) << iter->first.getName()
			<< setw(12) << iter->second << endl;
	}
	cout << resetiosflags(ios::right);
}

// Retrieve an entry from a phone book
void getEntry(map<Person, string>& book)
{
	Person person = getPerson();
	auto iter = book.find(person);
	if (iter == book.end())
		cout << "No entry found for " << person.getName() << endl;
	else
		cout << "The number for " << person.getName()
		<< " is " << iter->second << endl;
}

// Delete an entry from a phone book
void deleteEntry(map<Person, string>& book)
{
	Person person = getPerson();
	auto iter = book.find(person);
	if (iter == book.end())
		cout << "No entry found for " << person.getName() << endl;
	else
	{
		book.erase(iter);
		cout << person.getName() << " erased." << endl;
	}
}

int main()
{
	map<Person, string> phonebook;
	char answer = 0;
	
	while (true)
	{
		cout << "Do you want to enter a phone book entry(Y or N): ";
		cin >> answer;
		cin.ignore();	// Ignore newline in buffer
		if (toupper(answer) == 'N')
			break;
		if (toupper(answer) != 'Y')
		{
			cout << "Invalid response.Try again." << endl;
			continue;
		}
		addEntry(phonebook);
	}

	// Query the phonebook
	while (true)
	{
		cout << "\nChoose from the following options: "
			<< "\nA: Add an entry \nD: Delete an entry\nG: Get an entry\n"
			<< "L: List entries\nQ: Quit\n";
		cin >> answer;
		cin.ignore();

		switch (toupper(answer))
		{
		case 'A':
			addEntry(phonebook);
			break;
		case 'B':
			getEntry(phonebook);
			break;
		case 'D':
			deleteEntry(phonebook);
			break;
		case 'L':
			listEntries(phonebook);
			break;
		case 'Q':
			return 0;
		default:
			cout << "Invalid selection.Try again." << endl;
			break;
		}
	}

	system("pause");
	return 0;
}