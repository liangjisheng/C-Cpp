
// 合并两个区间到目标区间，目标区间内的元素都将按顺序排列
// OutputIterator
// merge(InputIterator source1Beg, InputIterator source1End,
//		InputIterator source2Beg, InputIterator source2End,
//		OutputIterator destBeg);
// OutputIterator
// merge(InputIterator source1Beg, InputIterator source1End,
//		InputIterator source2Beg, InputIterator source2End,
//		OutputIterator destBeg, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll1;
	set<int> coll2;

	// fill both collections with some sorted elements
	INSERT_ELEMETNS(coll1, 1, 6);
	INSERT_ELEMETNS(coll2, 3, 8);
	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");

	// print merged sequence
	cout << "merged: ";
	merge(coll1.begin(), coll1.end(), coll2.begin(), coll2.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}