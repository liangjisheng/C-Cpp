// Implementation of the Name class
#include "Name.h"
#include "DebugStuff.h"
#include <cstring>
#include <cassert>
#include <iostream>
using namespace std;

Name::Name()
{
#ifdef CONSTRUCTOR_TRACE
	// Trace constructor calls
	cerr << "\nDefault Name constructor called.\n";
#endif
	pFirstname = pSecondname = "\0";
}

Name::Name(const char* pFirst, const char* pSecond)
{
	// Verify that arguments are not null
	assert(pFirst);
	assert(pSecond);

#ifdef CONSTRUCTOR_TRACE
	cout << "\nName constructor called.\n";
#endif

	int len = strlen(pFirst) + 1;
	pFirstname = new char[len];
	strcpy_s(pFirstname, len, pFirst);
	pFirstname[len - 1] = '\0';

	len = strlen(pSecond) + 1;
	pSecondname = new char[len];
	strcpy_s(pSecondname, len, pSecond);
	pSecondname[len - 1] = '\0';
}

Name::Name(const Name& name)
{
	assert(name.pFirstname);
	assert(name.pSecondname);

#ifdef CONSTRUCTOR_TRACE
	cout << "\nName copy constructor called.\n";
#endif

	int len = strlen(name.pFirstname) + 1;
	pFirstname = new char[len];
	strcpy_s(pFirstname, len, name.pFirstname);
	pFirstname[len - 1] = '\0';

	len = strlen(name.pSecondname) + 1;
	pSecondname = new char[len];
	strcpy_s(pSecondname, len, name.pSecondname);
	pSecondname[len - 1] = '\0';
}

Name& Name::operator=(const Name& name)
{
	assert(name.pFirstname);
	assert(name.pSecondname);

#ifdef CONSTRUCTOR_TRACE
	cout << "\nName assignment called.\n";
#endif

	if (this == &name)
		return *this;

	delete[]pFirstname;
	int len = strlen(name.pFirstname) + 1;
	pFirstname = new char[len];
	strcpy_s(pFirstname, len, name.pFirstname);
	pFirstname[len - 1] = '\0';

	delete[]pSecondname;
	len = strlen(name.pSecondname) + 1;
	pSecondname = new char[len];
	strcpy_s(pSecondname, len, name.pSecondname);
	pSecondname[len - 1] = '\0';

	return *this;
}

Name::~Name()
{
#ifdef CONSTRUCTOR_TRACE
	cout << "\nName destructor called.\n";
#endif
	delete[]pFirstname;
	delete[]pSecondname;
	pFirstname = nullptr;
	pSecondname = nullptr;
}

// Return a complete name as a string containing first name,
// space ,surname.The argument must be the address of a char 
// array sufficient to hold the name
char* Name::getName(char* pName) const
{
	assert(pName);

#ifdef FUNCTION_TRACE
	// Trace function calls
	// __FUNCTION__预定义宏，输出时，自动被所在函数的函数名替换
	cout << "\n" << __FUNCTION__ << " called.\n";
#endif

	unsigned int len = strlen(pFirstname) + strlen(pSecondname) + 2;
	if (strlen(pName) < len)
	{
		delete[]pName;
		pName = new char[len];
	}
	strcpy_s(pName, len, pFirstname);
	strcat_s(pName, len, " ");
	strcat_s(pName, len, pSecondname);
	pName[len - 1] = '\0';

	return pName;
}

// Return the total length of a name
size_t Name::getNmaeLength() const
{
#ifdef FUNCTION_TRACE
	// Trace function calls
	cout << "\n" << __FUNCTION__ << " called.\n";
#endif

	return strlen(pFirstname) + strlen(pSecondname) + 2;
}

bool Name::operator<(const Name& name) const
{
	int result = strcmp(pSecondname, name.pSecondname);
	if (result < 0)
		return true;
	if (0 == result && strcmp(pFirstname, name.pFirstname) < 0)
		return true;
	else
		return false;
}

bool Name::operator>(const Name& name) const
{
	return *this < name;
}

bool Name::operator==(const Name& name) const
{
	if (0 == strcmp(pFirstname, name.pFirstname) &&
		0 == strcmp(pSecondname, name.pSecondname))
		return true;
	else
		return false;
}