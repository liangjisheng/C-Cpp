
// 第三种预定义的迭代器配接器(iterator adapters)就是reverse iterators
// 将Increment(递增)运算转换为decrement(递减)运算,反之亦然

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	cout << "Positive: ";
	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "Reverse: ";
	// rbegin()指向最后一个元素,rend()指向第一个元素的前一个元素
	// rend()位置上并没有合法元素,不能使用operator*或operator->
	// 否则会导致未定义行为
	copy(coll.rbegin(), coll.rend(),		// source
		ostream_iterator<int>(cout, " "));	// destination
	cout << endl;

	system("pause");
	return 0;
}