
// 移除性算法(Removing Algorithms)
// 根据元素值或某个准则，在一个区间内移除某些元素，这些算法并不能改变元素的数量
// 他们只是一逻辑上的思考，将原本置于后面的不移除元素向前移动，覆盖那些被移除元素
// 而已。他们都返回新区间的逻辑终点(也就是最后一个不移除元素的下一位置)

// ForwardIterator remove(ForwardIterator beg, ForwardIterator end, const T& value);
// ForwardIterator remove_if(ForwardIterator beg, ForwardIterator end, UnaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;


int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 2, 6);
	INSERT_ELEMETNS(coll, 4, 9);
	INSERT_ELEMETNS(coll, 1, 7);
	PRINT_ELEMENTS(coll, "coll: ");

	// remove all elements with value 5
	vector<int>::iterator pos;
	pos = remove(coll.begin(), coll.end(), 5);
	PRINT_ELEMENTS(coll, "size not changed: ");

	// erase the removed elements in the container
	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "size changed: ");

	// remove all elements less than 4
	coll.erase(remove_if(coll.begin(), coll.end(),
				bind2nd(less<int>(), 4)), coll.end());
	PRINT_ELEMENTS(coll, "<4 removed: ");

	system("pause");
	return 0;
}