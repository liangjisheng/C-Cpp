
// 移除连续重复元素
// 将区间[beg, end)内所有与前一元素相等的元素移除
// 返回被变动后的序列新终点(逻辑终点，也就是最后一个未被移除的元素的下一个位置)
// ForwardIterator unique(ForwardIterator beg, ForwardIterator end);

// 将每一个位于元素e之后并且是二元判断式op(elem, e)为true的所有elem元素移除
// ForwardIterator unique(ForwardIterator beg, ForwardIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	// source data
	int source[] = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
	int sourceNum = sizeof(source) / sizeof(source[0]);

	list<int> coll;
	// initialize coll with elements from source
	copy(source, source + sourceNum,
		back_inserter(coll));
	PRINT_ELEMENTS(coll);

	// remove consecutive duplicates
	list<int>::iterator pos;
	pos = unique(coll.begin(), coll.end());

	// print elements not removed
	// use new logical end
	copy(coll.begin(), pos,
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	// reinitialize coll with elements from source
	copy(source, source + sourceNum,
		coll.begin());
	PRINT_ELEMENTS(coll);

	// remove elements if there was a previous greater element
	coll.erase(unique(coll.begin(), coll.end(), greater<int>()), coll.end());
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}