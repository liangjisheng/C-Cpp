
// 这两个算法并不是早期STL的一部分，他们被命名为find_end()而不是search_end()
// 如果是search_end()，比较具有一致性，因为用来查找第一个子区间的算法名为search();
// ForwardIterator 
// find_end(ForwardIterator beg, ForwardIterator end,
//			ForwardIterator searchBeg, ForwardIterator searchEnd);

// ForwardIterator
// find_end(ForwardIterator beg, ForwardIterator end,
//			ForwardIterator searchBeg, ForwardIterator searchEnd,
//			BinaryPredicate op);

// 在一个序列中查找与某个序列相等的最后一个子序列

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	list<int> subcoll;

	INSERT_ELEMETNS(coll, 1, 7);
	INSERT_ELEMETNS(coll, 1, 7);
	INSERT_ELEMETNS(subcoll, 3, 6);
	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(subcoll, "subcoll: ");

	// search last occurrence of subcoll in coll
	deque<int>::iterator pos(coll.end());
	pos = find_end(coll.begin(), coll.end(),		// range
				subcoll.begin(), subcoll.end());	// subrange

	// loop while subcoll found as subrange of coll
	deque<int>::iterator posEnd(coll.end());
	while (pos != posEnd)
	{
		// print position of first element
		cout << "subcoll found starting with element "
			<< distance(coll.begin(), pos) + 1 << endl;

		// search next occurrence of subcoll
		posEnd = pos;
		pos = find_end(coll.begin(), posEnd,				// range
						subcoll.begin(), subcoll.end());	// subrange
	}

	system("pause");
	return 0;
}