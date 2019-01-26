
// 也可以将逆向迭代器转换为正常迭代器，逆向迭代器提供了一个base()成员函数
// iterator base() const;
// 正向迭代器与逆向迭代器的相互转换，实际位置(迭代器所指元素)维持不动，变化的是
// 逻辑位置(迭代器所指的数值)

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	// insert elements
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	// print value of the element
	cout << "pos: " << *pos << endl;

	// convert iterator to reverse iterator
	list<int>::reverse_iterator rpos(pos);

	// print value of the element to which the reverse iterator refers
	cout << "rpos: " << *rpos << endl;

	// convert reverse iterator back to normal iterator
	list<int>::iterator rrpos;
	rrpos = rpos.base();

	// print value of the element to which the normal iterator refers
	cout << "rrpos: " << *rrpos << endl;

	system("pause");
	return 0;
}