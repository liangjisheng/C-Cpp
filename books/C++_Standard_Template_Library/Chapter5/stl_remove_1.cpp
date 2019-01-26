
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	// print all elements of the collection
	cout << "pre: ";
	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all element with value 3
	// 并没有真正的删除元素,而是将3后面的值向前移,将3覆盖掉
	// remove()返回一个新的终点,可以利用该终点获得新区间,删除后容器的大小
	// 或者是被删除元素的个数
	remove(coll.begin(), coll.end(), 3);

	cout << "post: ";
	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}