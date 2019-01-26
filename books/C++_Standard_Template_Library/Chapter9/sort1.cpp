
// void sort(RandomAccessIterator beg, RandomAccessIterator end);
// void sort(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);
// void stable_sort(RandomAccessIterator beg, RandomAccessIterator end);
// void stable_sort(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "on entry: ");

	sort(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "sorted: ");

	// sort reverse
	sort(coll.begin(), coll.end(), greater<int>());
	PRINT_ELEMENTS(coll, "sorted >: ");

	system("pause");
	return 0;
}