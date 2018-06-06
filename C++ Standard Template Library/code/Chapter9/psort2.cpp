
// copy()与partial_sort()的组合
// 将元素从源区间[sourceBeg, sourceEnd)复制到目标区间[destBeg, destEnd),同时进行排序
// 被排序(被复制)的元素数量是源区间和目标区间两个所含元素数量的较小值
// 两者都返回目标区间内"最后一个被复制元素"的下一个位置(也就是第一个未被覆盖的元素)

// RandomAccessIterator
// partial_sort_copy(InputIterator sourceBeg,
//					InputIterator sourceEnd,
//					RandomAccessIterator destBeg,
//					RandomAccessIterator destEnd);
// RandomAccessIterator
// partial_sort_copy(InputIterator sourceBeg,
//					InputIterator sourceEnd,
//					RandomAccessIterator destBeg,
//					RandomAccessIterator destEnd,
//					BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll1;
	vector<int> coll6(6);
	vector<int> coll30(30);

	INSERT_ELEMETNS(coll1, 3, 7);
	INSERT_ELEMETNS(coll1, 2, 6);
	INSERT_ELEMETNS(coll1, 1, 5);
	PRINT_ELEMENTS(coll1);

	// copy elements of coll1 sorted into coll6
	vector<int>::iterator pos6;
	pos6 = partial_sort_copy(coll1.begin(), coll1.end(),
							coll6.begin(), coll6.end());

	// print all copied elements
	copy(coll6.begin(), coll6.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// copy elements of coll1 sorted into coll30
	vector<int>::iterator pos30;
	pos30 = partial_sort_copy(coll1.begin(), coll1.end(),
							coll30.begin(), coll30.end(),
							greater<int>());

	// print all copied elements
	copy(coll30.begin(), coll30.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(coll30.begin(), pos30, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}