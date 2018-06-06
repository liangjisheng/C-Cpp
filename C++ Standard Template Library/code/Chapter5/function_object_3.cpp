
// C++标准程序库包含了一些预定义的仿函数

#include <iostream>
#include <vector>
#include <algorithm>
#include "..\..\print.hpp"

using namespace std;

// 预定义仿函数negate,将元素取反
void test_negate()
{
	vector<int> coll;

	for (int i = -5; i <= 5; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll, "Before: ");

	transform(coll.begin(), coll.end(),		// source
				coll.begin(),				// destination
				negate<int>());				// operation

	PRINT_ELEMENTS(coll, "After: ");
}

// 预定义仿函数multiplies,将元素相乘
// process the square of all elements
void test_multiplies()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll, "Before: ");

	transform(coll.begin(), coll.end(),		// first source
				coll.begin(),				// second source
				coll.begin(),				// destination
				multiplies<int>());			// operation

	PRINT_ELEMENTS(coll, "After: ");
}


int main()
{
	// test_negate();
	test_multiplies();

	system("pause");
	return 0;
}