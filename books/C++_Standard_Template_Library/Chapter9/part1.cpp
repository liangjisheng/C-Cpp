
// 将元素向前搬移
// 使op(elem)为true的元素向前移动
// 都返回另op()结果为false的第一个元素位置
// BidirectionalIterator
// partition(BidirectionalIterator beg, BidirectionalIterator end,
//			UnaryPredicate op);
// BidirectionalIterator
// stable_partition(BidirectionalIterator beg, BidirectionalIterator end,
//					UnaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;


int main()
{
	vector<int> coll1;
	vector<int> coll2;
	INSERT_ELEMETNS(coll1, 1, 9);
	INSERT_ELEMETNS(coll2, 1, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");
	cout << endl;

	// move all even elements to the front
	vector<int>::iterator pos1, pos2;
	pos1 = partition(coll1.begin(), coll1.end(),
					not1(bind2nd(modulus<int>(), 2)));

	// 保持奇偶元素的相对次序
	pos2 = stable_partition(coll2.begin(), coll2.end(),
					not1(bind2nd(modulus<int>(), 2)));

	// print collections and first odd elements
	PRINT_ELEMENTS(coll1, "coll1: ");
	cout << "first odd element: " << *pos1 << endl;
	PRINT_ELEMENTS(coll2, "coll2: ");
	cout << "first odd element: " << *pos2 << endl;

	system("pause");
	return 0;
}