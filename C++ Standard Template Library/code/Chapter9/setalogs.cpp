
// 两个序列的交集、并集、差集、补集

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	int c1[] = { 1, 2, 2, 4, 6, 7, 7, 9 };
	int num1 = sizeof(c1) / sizeof(int);
	int c2[] = { 2, 2, 2, 3, 6, 6, 8, 9 };
	int num2 = sizeof(c2) / sizeof(int);

	// print source ranges
	cout << "c1: ";
	copy(c1, c1 + num1, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "c2: ";
	copy(c2, c2 + num1, ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	// sum the ranges bu using merge()
	cout << "merge(): ";
	merge(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
	cout << endl;

	// 并集 unite the ranges bu using set_union()
	cout << "set_union(c1, c2): ";
	set_union(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "set_union(c2, c1): ";
	set_union(c2, c2 + num2, c1, c1 + num1, ostream_iterator<int>(cout, " "));
	cout << endl;

	// 交集 intersect the ranges bu using set_intersection()
	cout << "set_intersection(c1, c2): ";
	set_intersection(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "set_intersection(c2, c1): ";
	set_intersection(c2, c2 + num2, c1, c1 + num1, ostream_iterator<int>(cout, " "));
	cout << endl;

	// 差集 determine elements of first range without elements of second range
	// bu using set_difference()
	cout << "set_difference(c1, c2): ";
	set_difference(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "set_difference(c2, c1): ";
	set_difference(c2, c2 + num2, c1, c1 + num1, ostream_iterator<int>(cout, " "));
	cout << endl;

	// 补集 determine difference the ranges with set_symmetric_difference()
	cout << "set_symmetric_difference(c1, c2): ";
	set_symmetric_difference(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "set_symmetric_difference(c2, c1): ";
	set_symmetric_difference(c2, c2 + num2, c1, c1 + num1, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}