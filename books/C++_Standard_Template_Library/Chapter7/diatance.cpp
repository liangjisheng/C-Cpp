
// 返回两个迭代器之间的距离
// Dist diatance(InputIterator pos1, InputIterator pos2);

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	for (int i = -3; i <= 9; ++i)
		coll.push_back(i);

	// search element with value 5
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	if (pos != coll.end())
	{
		// process and print difference from the beginning
		// distance的第一个迭代器绝对不能位于第二个迭代器之后，否则会导致未定义行为
		// 如果不知道那个在前，那个在后，必须先计算两个迭代器分别指容器起点的距离
		// 两个迭代器必须指向相同的目标容器
		cout << "difference between beginning and 5: "
			<< distance(coll.begin(), pos) << endl;
	}
	else
		cout << "5 not found" << endl;

	system("pause");
	return 0;
}