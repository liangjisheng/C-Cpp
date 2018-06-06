
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// remove()算法是不能自己调用相应容器的成员函数,这正是STL为了获取灵活性
// 而付出的代价.通过"以迭代器为接口",STL将数据结构和算法分离开来.然而迭
// 代器只不过是"容器中某一位置"的抽象概念而已.一般来说,迭代器对自己所属
// 的容器一无所知.任何"以迭代器访问容器元素"的算法,都不得(无法)通过迭代
// 器调用容器类型所提供的任何成员函数,迭代器是不了解容器细节的


int main()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_back(i);
		coll.push_front(i);
	}

	// print all elements of the collection
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 3 
	// - retain new end
	// newend是容器经过删除之后作为逻辑上的新终点
	list<int>::iterator newend = remove(coll.begin(), coll.end(), 3);

	copy(coll.begin(), newend, ostream_iterator<int>(cout, " "));
	cout << endl;

	// print number of resulting elements
	// distance()返回两个迭代器之间的距离,如果两个迭代器是随机迭代器
	// 则可直接利用operator-计算距离,不过list只提供双向迭代器
	cout << "number of removed elements: "
		<< distance(newend, coll.end()) << endl;

	// remove "removed" elements
	// 如果真正想删除元素,必须调用容器的相应成员函数
	coll.erase(newend, coll.end());

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}