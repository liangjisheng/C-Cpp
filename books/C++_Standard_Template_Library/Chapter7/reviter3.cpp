
// 如果有个区间，由一双(而非一个)迭代器定义，那么变换操作就非常简单了，所有元素仍然有效
// rbegin() = container::reverse_iterator(end());
// rend() = container::reverse_iterator(begin())
// 常数迭代器const_iterator会被转换为const_reverse_iterator

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void print(int elem) { cout << elem << " "; }

int main()
{
	deque<int> coll;

	// insert elements
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	// find position of element with value 2
	deque<int>::iterator pos1;
	pos1 = find(coll.begin(), coll.end(), 2);

	// find position of element with value 7
	deque<int>::iterator pos2;
	pos2 = find(coll.begin(), coll.end(), 7);

	// print all elements in range [pos1, pos2)
	for_each(pos1, pos2, print);
	cout << endl;

	// convert iterator to reverse iterator
	deque<int>::reverse_iterator rpos1(pos1);
	deque<int>::reverse_iterator rpos2(pos2);

	// print all elements in range [pos1, pos2) in reverse order
	for_each(rpos2, rpos1, print);
	cout << endl;

	system("pause");
	return 0;
}