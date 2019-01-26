
// 那些会移除remove,重排resort,修改modify元素的算法不能用于关联式容器
// 身上.如果这些算法用于关联式容器身上,会改变某位置上的值,进而破坏其
// 已序(sorted)特性,那就破坏了关联式容器的基本原则: 容器内的元素总是
// 根据某个排序准则自动排序.因此,为了保证这个原则,关联式容器的所有迭
// 代器均被声明为指向常量.只能使用关联式容器的成员函数来删除元素

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	set<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.insert(i);

	// print all elements of the collection
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 3
	// - algorithm remove() does not work
	// - instead member function erase() works
	// 返回删除元素的个数,在禁止重复的容器中set,map
	// 其返回值只能是0或1
	int num = coll.erase(3);

	cout << "number of removed elements: " << num << endl;

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}