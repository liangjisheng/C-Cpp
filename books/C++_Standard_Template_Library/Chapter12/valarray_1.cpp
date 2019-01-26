
#include <iostream>
#include <valarray>

using namespace std;

// print valarray
template<class T>
void printValarray(const valarray<T>& va)
{
	for (size_t i = 0; i < va.size(); ++i)
		cout << va[i] << ' ';
	cout << endl;
}

int main()
{
	valarray<double> va1(10), va2(10);

	for (int i = 0; i < 10; ++i)
		va1[i] = i * 1.1;

	// assign -1 to all elements of the second valarray
	va2 = -1;

	printValarray(va1);
	printValarray(va2);

	// print minimum, maximum, and sum of the first valarray
	cout << "min(): " << va1.min() << endl;
	cout << "max(): " << va1.max() << endl;
	cout << "sum(): " << va1.sum() << endl;

	// assign values of the first to the second valarray
	va2 = va1;

	// remove all element of the first valarray
	va2.resize(0);

	printValarray(va1);
	printValarray(va2);

	system("pause");
	return 0;
}
