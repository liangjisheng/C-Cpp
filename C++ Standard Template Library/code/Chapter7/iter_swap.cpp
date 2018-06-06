
// iter_swap()用来交换两个迭代器所指的元素值
// 两个迭代器的类型不必相同，但其所指的两个值必须可以相互赋值

#include <iostream>
#include <list>
#include <algorithm>
#include "..\..\print.hpp"

using namespace std;

int main()
{
	list<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll);

	// swap first and second value
	iter_swap(coll.begin(), ++coll.begin());

	PRINT_ELEMENTS(coll);

	// swap first and last value
	iter_swap(coll.begin(), --coll.end());

	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}