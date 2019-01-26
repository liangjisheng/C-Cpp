
// 返回最后一个被转换元素的下一个位置，就是第一个未被覆盖的元素的位置
// source1Beg, source2Beg, destBeg可以相同，所以，可以让元素自己和自己
// 结合，然后将结果覆盖至某个序列中
// OutputIterator
// transform(InputIterator1 source1Beg, InputIterator1 source1End,
//			InputIterator2 source2Beg,
//			OutputIterator destBeg,
//			BinaryFunc op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMETNS(coll1, 1, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");

	// square each element
	transform(coll1.begin(), coll1.end(),		// first source range
				coll1.begin(),					// second source range
				coll1.begin(),					// destination range
				multiplies<int>());				// operation
	PRINT_ELEMENTS(coll1, "coll1: ");

	// add each element traversed forward with each element traversed backward
	// and insert result into coll2
	transform(coll1.begin(), coll1.end(),		// first source range
			coll1.rbegin(),						// second source range
			back_inserter(coll2),				// destination range
			plus<int>());						// operation
	PRINT_ELEMENTS(coll2, "coll2: ");

	// print differences of two corresponding elements
	cout << "diff: ";
	transform(coll1.begin(), coll1.end(),
			coll2.begin(),
			ostream_iterator<int>(cout, " "),
			minus<int>());
	cout << endl;

	system("pause");
	return 0;
}