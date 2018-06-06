
// 下面展示了仿函数如何模拟函数在同一时刻下拥有多个状态

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

	// insert values from 1 to 9
	generate_n(back_inserter(coll),		// start
		9,								// number of elements
		IntSequence(1));				// generates values

	PRINT_ELEMENTS(coll);

	// replace second to last element but one with values
	// starting at 42
	generate(++coll.begin(),	// start
		--coll.end(),			// end
		IntSequence(42));		// generates values

	PRINT_ELEMENTS(coll);
	cout << endl;


	// 仿函数是passed by value(传值),不是passed by reference(传址)，
	// 因此，算法并不会改变随参数而来的仿函数的状态，改变的只是仿函数的副本而已
	list<int> coll1;
	IntSequence seq(1);		// integral sequence starting with value 1

	// insert sequence beginning with 1
	generate_n(back_inserter(coll1), 9, seq);
	PRINT_ELEMENTS(coll1);

	// insert sequence beginning with 1 again
	generate_n(back_inserter(coll1), 9, seq);
	PRINT_ELEMENTS(coll1);

	system("pause");
	return 0;
}
