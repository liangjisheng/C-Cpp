
#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::deque;

// vector并未提供push_front()，因为其时间性能根插，在vector头端安插一个
// 元素，需要移动全部元素，一般而言STL容器只提供通常具备良好时间性能
// 的成员函数(所谓良好，通常意味着具有常数复杂度或者对数复杂度)，这样
// 可以防止程序员调用性能很差的函数

int main()
{
	deque<float> coll;

	// insert elements from 1.1 to 6.6 each at the front
	for (int i = 1; i <= 6; ++i)
		coll.push_front(i * 1.1);

	// print all elements followed by a space
	for (unsigned int i = 0; i < coll.size(); ++i)
		cout << coll[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}