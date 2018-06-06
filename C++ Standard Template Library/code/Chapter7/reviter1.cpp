
// reverse迭代器是一种迭代器适配器，重新定义递增运算和递减运算
// 所有标准容器都允许使用reverse迭代器来遍历元素

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void print(int elem) { cout << elem << ' '; }

int main()
{
	list<int> coll;

	// insert elements from 1 to 9
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	// print all elements in normal order
	for_each(coll.begin(), coll.end(), print);
	cout << endl;

	// print all elements in reverse order
	for_each(coll.rbegin(), coll.rend(), print);
	cout << endl;

	system("pause");
	return 0;
}