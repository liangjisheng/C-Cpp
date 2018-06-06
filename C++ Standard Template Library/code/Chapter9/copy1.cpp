
// 两个算法都是将源区间[sourceBeg, sourceEnd)中的所有元素赋值到以destBeg为起点
// 或以destEnd为终点的目标区间去

// OutputIterator
// copy(InputIterator sourceBeg, InputIterator sourceEnd, OutputIterator destBeg);

// BidirectionalIterator1
// copy_backward(BidirectionalIterator1 sourceBeg,
//				BidirectionalIterator1 sourceEnd,
//				BidirectionalIterator2 destEnd);

// STL没有copy_if()算法，应当使用remove_copy_if()复制符合某些特定准则的元素
// 使用reverse_copy()在复制过程中逆转元素次序
// 使用赋值运算符将容器内的所有元素赋值给另一容器(两个容器类型相同时才能这么做)
// 使用容器的assign()成员函数(两个容器类型不同时使用此方法)

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMETNS(coll1, 1, 9);

	// copy elements of coll1 into coll2
	// use back inserter to insert instead of overwrite
	copy(coll1.begin(), coll1.end(),	// source range
		back_inserter(coll2));			// destination range

	// print elements of coll2
	// copy elements to cout using an ostream iterator
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// copy elements of coll1 into coll2 in reverse order
	// now overwriting
	copy(coll1.rbegin(), coll1.rend(), coll2.begin());

	// print elements of coll2 again
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}