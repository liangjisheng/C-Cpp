
#include <cstdlib>
#include <iostream>
#include <iosfwd>

using namespace std;

int main()
{
	double x = 0, y = 0;
	cout << "Multiplication of two floating point values" << endl;

	// read first operand
	cout << "first operand: ";
	if (!(cin >> x))
	{
		cerr << "error while reading the first floating value" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	// read second operand
	cout << "second operand: ";
	if (!(cin >> y))
	{
		cerr << "error while reading the second floating value" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	cout << x << " times " << y << " equals " << x * y << endl;

	system("pause");
	return 0;
}