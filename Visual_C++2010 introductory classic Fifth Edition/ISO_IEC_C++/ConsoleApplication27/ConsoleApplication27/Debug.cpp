// Including debug code in a program

#include <iostream>
using namespace std;
#include "Name.h"

// Function to initialize an array of random names
void init(Name* names, int count)
{
	char* firstnames[] = { "Charles","Marry","Arthur","Emily","John" };
	int firstsize = sizeof(firstnames) / sizeof(firstnames[0]);
	char* secondnames[] = { "Dickens","Shelley","Miller","Bronte","Steinbeck" };
	int secondsize = sizeof(secondnames) / sizeof(secondnames[0]);
	char* first = firstnames[0];
	char* second = secondnames[0];

	for (int i = 0; i<count; i++)
	{
		if (i % 2 != 0)
			first = firstnames[i%firstsize];
		else
			second = secondnames[i%secondsize];
		names[i] = Name(first, second);
	}
}

int main(int argc, char* argv[])
{
	Name myName("li", "shuyu");

	// Retrieve and store the name in a local char array
	char theName[10];
	cout << "\nThe name is " << myName.getName(theName) << endl;

	// Store the name in an array in the free store
	char* pName = new char[myName.getNmaeLength()];
	cout << "\nThe name is " << myName.getName(pName) << endl;

	cout << "\ntheName is " << theName << endl;
	cout << "\npName is " << pName << endl << endl;

	const int arraysize = 10;
	Name names[arraysize];

	init(names, arraysize);

	// Try out comparisons
	char* phrase = nullptr;	// Stores a comparison phrase
	char* iName = nullptr;	// Stores a complete name
	char* jName = nullptr;	// Stores a complete name

	for (int i = 0; i<arraysize; i++)	// Compare each element
	{
		// Array to hold firstname
		iName = new char[names[i].getNmaeLength() + 1];
		for (int j = i + 1; j<arraysize; j++)	// with all the others
		{
			if (names[i] < names[j])
				phrase = " less than ";
			else if (names[i] > names[j])
				phrase = " greater than ";
			else if (names[i] == names[j])
				phrase = " equal to ";

			// Array to hold second name
			jName = new char[names[j].getNmaeLength() + 1];
			cout << endl << names[i].getName(iName) << " is " << phrase
				<< names[j].getName(jName) << endl;

			delete[]jName;
			jName = nullptr;
		}
		delete[]iName;
		iName = nullptr;
	}

	system("pause");
	return 0;
}