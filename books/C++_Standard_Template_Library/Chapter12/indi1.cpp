
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
	// create valarray for 12 elements
	valarray<double> va(12);
	for (int i = 0; i < 12; ++i)
		va[i] = (i + 1) * 1.01;
	printValarray(va, 4);

	// create array of indexes
	// note: element type has to be size_t
	valarray<size_t> idx(4);
	idx[0] = 8;
	idx[1] = 0;
	idx[2] = 3;
	idx[3] = 7;

	// use array of indexes to print the ninth, first, fourth, and eighth elements
	printValarray(valarray<double>(va[idx]), 4);

	// change the first and fourth elements and print them again indirectly
	va[0] = 11.11;
	va[3] = 44.44;
	printValarray(valarray<double>(va[idx]), 4);

	// now select the second, third, sixth, and ninth elements and assign 99 to them
	idx[0] = 1;
	idx[1] = 2;
	idx[2] = 5;
	idx[3] = 8;
	va[idx] = 99;

	printValarray(va, 4);

	system("pause");
	return 0;
}
