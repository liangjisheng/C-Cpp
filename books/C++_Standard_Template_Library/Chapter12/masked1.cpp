
#include <iostream>
#include <valarray>

using namespace std;

// print valarray line-by-line
template<class T>
void printValarray(const valarray<T>& va, int num)
{
	for (size_t i = 0; i < va.size() / num; ++i)
	{
		for (int j = 0; j < num; ++j)
			cout << va[i * num + j] << ' ';
		cout << endl;
	}
	cout << endl;
}

int main()
{
	// valarray with 12 elements
	// four rows
	// three columns
	valarray<double> va(12);
	for (int i = 0; i < 12; ++i)
		va[i] = i;
	printValarray(va, 3);

	// assign 77 to all values that are less than 5
	va[va < 5.0] = 77.0;
	printValarray(va, 3);

	// add 100 to all values that are greater than 5 and less than 9
	va[va > 5.0 && va < 9.0] = valarray<double>(va[va > 5.0 && va < 9.0]) + 100.0;
	printValarray(va, 3);

	system("pause");
	return 0;
}
