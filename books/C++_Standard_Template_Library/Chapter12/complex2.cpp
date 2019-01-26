
#include <iostream>
#include <complex>
#include <cstdlib>
#include <limits>

using namespace std;


int main()
{
	complex<long double> c1, c2;

	cout << "complex number c1: ";
	while (cin.peek() != EOF)
	{
		// read first complex number
		cin >> c1;
		if (!cin)
		{
			cerr << "input error" << endl;
			return EXIT_FAILURE;
		}

		// read second complex number
		cout << "complex number c2: ";
		cin >> c2;
		if (!cin)
		{
			cerr << "input error" << endl;
			return EXIT_FAILURE;
		}

		if (c1 == c2)
			cout << "c1 and c2 are equal" << endl;

		cout << "c1 raised to the c2: " << pow(c1, c2) << endl << endl;

		// skip rest of line
		cin.ignore(numeric_limits<int>::max(), '\n');

		cout << "complex number c1: ";
	}

	system("pause");
	return 0;
}