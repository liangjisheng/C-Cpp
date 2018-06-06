
// 要想存储或改变仿函数的最终状态，有两个办法
// 1.以by reference的方式传递仿函数
// 2.运用for_each()算法的返回值

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;

class IntSequence
{
private:
	int value;
public:
	IntSequence(int initialValue) : value(initialValue) {}

	// function call
	int operator() () { return value++; }
};


int main()
{
	list<int> coll;
	IntSequence seq(1);		// integral sequence starting with 1

	// insert value from 1 to 4
	// pass function object by reference
	// so that it will continue with 5
	generate_n<back_insert_iterator<list<int> >, int, IntSequence&>
		(back_inserter(coll),		// start
		4,							// numbers of elements
		seq);						// generates values

	PRINT_ELEMENTS(coll);

	// insert values from 42 to 45
	generate_n(back_inserter(coll), 4, IntSequence(42));
	PRINT_ELEMENTS(coll);

	// continue with first sequence
	// pass function object by value
	// so that it will continues with 5 again
	generate_n(back_inserter(coll), 4, seq);
	PRINT_ELEMENTS(coll);

	generate_n(back_inserter(coll), 4, seq);
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}
