
// 查找某些元素的第一次出现地点
// ForwardIterator1
// find_first_of(ForwardIterator1 beg, ForwardIterator1 end,
//				ForwardIterator2 searchBeg, ForwardIterator2 searchEnd);

// ForwardIterator1
// find_first_of(ForwardIterator1 beg, ForwardIterator1 end,
//				ForwardIterator2 searchBeg, ForwardIterator2 searchEnd,
//				BinaryPredicate op)

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	list<int> searchcoll;

	INSERT_ELEMETNS(coll, 1, 11);
	INSERT_ELEMETNS(searchcoll, 3, 5);
	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(searchcoll, "searchcoll: ");

	// search first occurrence of an element of searchcoll in coll
	vector<int>::iterator pos(coll.end());
	pos = find_first_of(coll.begin(), coll.end(),		// range
						searchcoll.begin(), searchcoll.end());	// subrange

	if (pos != coll.end())
		cout << "first element of searchcoll in coll is element "
			<< distance(coll.begin(), pos) + 1 << endl;

	// search last occurrence of an element of searchcoll in coll
	vector<int>::reverse_iterator rpos(coll.rend());
	rpos = find_first_of(coll.rbegin(), coll.rend(),			// range
						searchcoll.begin(), searchcoll.end());	// subrange

	if (rpos != coll.rend())
		cout << "last element of searchcoll in coll is element "
			<< distance(coll.begin(), rpos.base()) << endl;

	system("pause");
	return 0;
}