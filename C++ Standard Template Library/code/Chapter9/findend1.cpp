
// �������㷨����������STL��һ���֣����Ǳ�����Ϊfind_end()������search_end()
// �����search_end()���ȽϾ���һ���ԣ���Ϊ�������ҵ�һ����������㷨��Ϊsearch();
// ForwardIterator 
// find_end(ForwardIterator beg, ForwardIterator end,
//			ForwardIterator searchBeg, ForwardIterator searchEnd);

// ForwardIterator
// find_end(ForwardIterator beg, ForwardIterator end,
//			ForwardIterator searchBeg, ForwardIterator searchEnd,
//			BinaryPredicate op);

// ��һ�������в�����ĳ��������ȵ����һ��������

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