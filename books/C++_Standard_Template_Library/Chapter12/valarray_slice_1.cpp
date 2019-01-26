
#include <iostream>
#include <valarray>

using namespace  std;

// print valarray
template<class T>
void printValarray(const valarray<T>& va, int columns = 3)
{
	for (size_t i = 0; i < va.size(); ++i)
	{
		cout << va[i] << ' ';
		if ((i + 1) % columns == 0)
			cout << endl;
	}
	cout << endl;
}

int main()
{
	valarray<double> va(12);
	for (int i = 0; i < 12; ++i)
		va[i] = i;
	printValarray(va, 3);

	// first column = second column raised to the third column
	va[slice(0, 4, 3)] = pow(valarray<double>(va[slice(1, 4, 3)]),
							valarray<double>(va[slice(2, 4, 3)]));
	printValarray(va, 3);

	// create valarray with three times the third element of va
	valarray<double> vb(va[slice(2, 4, 0)]);
	printValarray(vb);
	cout << endl;

	// multiply the third column by the elements of vb
	va[slice(2, 4, 3)] *= vb;
	printValarray(va, 3);

	// print the square root of the elements in the second row
	printValarray(sqrt(valarray<double>(va[slice(3, 3, 1)])), 3);

	// double the elements in the third column
	va[slice(2, 4, 3)] = valarray<double>(va[slice(2, 4, 3)]) * 2.0;

	printValarray(va, 3);

	system("pause");
	return 0;
}
