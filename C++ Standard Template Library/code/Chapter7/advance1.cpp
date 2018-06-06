
// C++为迭代器提供了3个辅助函数advance(),distance()和iter_swap()
// 前面两个为所有类型的迭代器提供了原本只有Random Access迭代器才有的能力：前进(后退)多个元素
// 及处理迭代器之间的距离。第三个函数交换两个迭代器的值
// void advance(InputIterator& pos, Dist n);

// 使用advance()的另一个例子就是忽略"迭代器从输入流(input stream)中读处的某些数据"

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	// insert some elements
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	list<int>::iterator pos = coll.begin();

	// print actual element
	cout << *pos << endl;

	// step three elements forward
	advance(pos, 3);

	// print actual element
	cout << *pos << endl;

	// step one element backward
	advance(pos, -1);

	// print actual element
	cout << *pos << endl;

	system("pause");
	return 0;
}