#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void printer(int* val, string seperator = "\n")
{
	cout << val << seperator;
	cout << *val << seperator;
}

int main()
{
	const int cint = 21;
	const int* pCint = &cint;
	int* pint = const_cast<int*>(pCint);

	cout << "constant: " << cint << endl;
	cout << "pCint: " << *pCint << endl;
	cout << "pint: " << *pint << endl;

	*pint = 7;

	cout << "constant: " << cint << endl;
	cout << "pCint: " << *pCint << endl;
	cout << "pint: " << *pint << endl;
	
	cout << "address constant: " << &cint << endl;
	cout << "address pCint: " << pCint << endl;
	cout << "address pint: " << pint << endl;


	cout << endl;
	const int c1 = 20;
	printer(const_cast<int*>(&c1));

	system("pause");
	return 0;
}
