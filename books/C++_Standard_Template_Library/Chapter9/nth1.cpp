
// 根据第n个元素排序
// 两种形式都对区间[beg, end)内的元素进行排序，使第n个位置上的元素就位
// 也就是说，所有在位置n之前的元素都小于等于它，所有在位置n之后的元素
// 都大于等于它，这样，就得到了根据n位置上的元素分割开来的两个子序列
// void nth_element(RandomAccessIterator beg, RandomAccessIterator nth,
//					RandomAccessIterator end);
// void nth_element(RandomAccessIterator beg, RandomAccessIterator nth,
//					RandomAccessIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;

	INSERT_ELEMETNS(coll, 3, 7);
	INSERT_ELEMETNS(coll, 2, 6);
	INSERT_ELEMETNS(coll, 1, 5);
	PRINT_ELEMENTS(coll);

	// extract the four lowest elements
	nth_element(coll.begin(),		// beginning of range
				coll.begin() + 3,	// element that should be sorted correctly
				coll.end());		// end of range

	// print them
	cout << "the four lowest elements are: ";
	copy(coll.begin(), coll.begin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	// extract the four highest elements
	nth_element(coll.begin(),		// beginning of range
				coll.end() - 4,		// element that should be sorted correctly
				coll.end());		// end of range

	// print them
	cout << "the four highest elements are: ";
	copy(coll.end() - 4, coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// extract the four highest elements (second version)
	nth_element(coll.begin(),		// beginning of range
				coll.begin() + 3,	// element that should be sorted correctly
				coll.end(),			// end of range
				greater<int>());	// sorting criterion

	// print them
	cout << "the four highest elements are: ";
	copy(coll.begin(), coll.begin() + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}