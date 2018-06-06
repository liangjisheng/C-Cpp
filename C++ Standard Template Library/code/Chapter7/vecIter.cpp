
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> coll;

	// insert some elements
	for (int i = 9; i >= 0; --i)
		coll.push_back(i);

	// print
	cout << "before sort" << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 如果vector的迭代器被实现为指针，则次处编译不通过，C++不允许修改任何基本
	// 类型(包括指针)的暂时值，但对于struct和class则允许。如果迭代器被实现为class
	// 则可以编译通过。deque,list,sets,maps总能编译通过，因为他们的迭代器不可能
	// 被实现为一般指针
	// 除第一个元素外的所有元素排序
	if (coll.size() > 1)
		sort(++coll.begin(), coll.end());

	// print
	cout << "after sort" << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}