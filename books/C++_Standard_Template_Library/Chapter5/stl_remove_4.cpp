
// 就算符合条件得以使用某个算法,那也未必就一定是好,容器本身可能提供
// 功能相似而性能更佳的成员函数
// 例如对list调用remove()时,算法本身并不知道它工作于list身上,因为它
// 对所有容器都做相同的工作,改变元素值,重新排列元素的位置,实际上并不
// 真正删除元素,只是使用后面的元素覆盖要删除的元素
// 如果使用成员函数删除,这些成员函数真的删除了元素,而不是像remove()算
// 法仅仅是移动了元素,因为成员函数了解容器的细节

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// 如果想要使得代码更有效率的话,应该永远优先使用成员函数.前提是必须
// 知道某个容器确实存在有效率上明显突出才成员函数


int main()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	cout << "Before: " << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 3
	// - poor performance
	coll.erase(remove(coll.begin(), coll.end(), 3), coll.end());

	cout << "poor performance remove(): " << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 4
	// - good performance
	coll.remove(4);

	cout << "good performance erase(): " << endl;
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}