
// copy()和rotate()的组合
// OutputIterator
// rotate(ForwardIterator sourceBeg, ForwardIterator newBeg,
//		ForwardIterator sourceEnd,
//		OutputIterator destBeg);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	set<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	// print elements rotated one element to the left
	set<int>::iterator pos = coll.begin();
	// 将迭代器pos指向下一个位置，此pos不是随机存取迭代器，只能使用这个函数
	advance(pos, 1);
	rotate_copy(coll.begin(),
				pos,
				coll.end(),
				ostream_iterator<int>(cout, " "));
	cout << endl;

	// print elements rotated two elements to the right
	pos = coll.end();
	advance(pos, -2);
	rotate_copy(coll.begin(),
				pos,
				coll.end(),
				ostream_iterator<int>(cout, " "));
	cout << endl;

	// print elements rotated so that element with value 4 is the beginning
	rotate_copy(coll.begin(),
				coll.find(4),	// 成员函数find()比find()算法具有更好的性能
				coll.end(),
				ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}