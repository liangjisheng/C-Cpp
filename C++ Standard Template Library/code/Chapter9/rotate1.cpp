
// 旋转序列内的元素
// 将区间[beg, end)内的元素进行旋转，执行后*newBeg成为新的第一元素
// 必须确保newBeg是区间[beg, end)内的一个有效位置，否则引发未定义
// void rotate(ForwardIterator beg, ForwardIterator newBeg,
//				ForwardIterator end);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// rotate one element to the left
	// 只有随机存取迭代器才能进行算术运算，其他迭代器需要使用advance()
	rotate(coll.begin(),		// beginning of range
			coll.begin() + 1,	// new first element
			coll.end());		// end of range
	PRINT_ELEMENTS(coll, "one left: ");

	// rotate two elements to the right
	rotate(coll.begin(),
		coll.end() - 2,
		coll.end());
	PRINT_ELEMENTS(coll, "two right: ");

	// rotate so that element with value 4 is the beginning
	rotate(coll.begin(),
		find(coll.begin(), coll.end(), 4),
		coll.end());
	PRINT_ELEMENTS(coll, "4 first: ");

	system("pause");
	return 0;
}