
// 互换元素内容，返回第二区间中最后一个被交换元素的下一位置，
// 如果两个容器类型相同，应使用swap()成员函数，成员函数具有常数复杂度
// ForwardIterator2
// swap_ranges(ForwardIterator1 beg1, ForwardIterator1 end1,
//				ForwardIterator2 beg2);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll1;
	deque<int> coll2;

	INSERT_ELEMETNS(coll1, 1, 9);
	INSERT_ELEMETNS(coll2, 11, 23);
	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");

	// swap elements of coll1 with corresponding elements of coll2
	deque<int>::iterator pos;
	pos = swap_ranges(coll1.begin(), coll1.end(),	// first range
					coll2.begin());					// second range

	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");

	if (pos != coll2.end())
		cout << "first element not modified: " << *pos << endl;

	// mirror first three with last three elements in coll2
	swap_ranges(coll2.begin(), coll2.begin() + 3,	// first range
				coll2.rbegin());					// second range

	PRINT_ELEMENTS(coll2, "coll2: ");

	system("pause");
	return 0;
}