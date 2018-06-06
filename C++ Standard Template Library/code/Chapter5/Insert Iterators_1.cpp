
// 迭代器适配器的第一个例子是insert iterator,或称为inserts
// inserts可以使算法以插入(insert)方式而非覆写(overwrite)
// 方式使用,使用insert可以解决目标空间不足问题,会使得目标
// 空间的大小按需要成长

#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	list<int> coll1;
	list<int>::iterator iter1;

	for (int i = 1; i <= 9; ++i)
		coll1.push_back(i);

	cout << "coll1: ";
	for (iter1 = coll1.begin(); iter1 != coll1.end(); ++iter1)
		cout << *iter1 << ' ';
	cout << endl;

	// copy the elements of coll1 into coll2 by appending them
	vector<int> coll2;
	vector<int>::iterator iter2;

	// back inserts的内部调用push_back(),在容器尾端插入元素
	// 这样的容器有3中:vector,list,deque
	copy(coll1.begin(), coll1.end(),		// source
			back_inserter(coll2));			// destination

	cout << "coll2: ";
	for (iter2 = coll2.begin(); iter2 != coll2.end(); ++iter2)
		cout << *iter2 << ' ';
	cout << endl;

	// copy the elements of coll1 into coll3 by inserting them at
	// the front - reverses the order of the elements
	deque<int> coll3;
	deque<int>::iterator iter3;

	// front inserts的内部调用push_front(),将元素插入元素最前面
	// 这样的容器有list,deque
	copy(coll1.begin(), coll1.end(),		// source
			front_inserter(coll3));			// destination

	cout << "coll3: ";
	for (iter3 = coll3.begin(); iter3 != coll3.end(); ++iter3)
		cout << *iter3 << ' ';
	cout << endl;

	// copy elements of coll1 into coll4
	// - only inserter that works for associative collections
	set<int> coll4;
	set<int>::iterator iter4;

	// inserts内部调用成员函数insert(),并以新值和新位置作为参数
	// STL容器都提供有insert()成员函数,这是唯一可用于关联式容器
	// 身上的一种预先定义好的inserter.在关联式容器中,插入时所给
	// 出的位置只是一个提示,帮助它确定从什么地方开始搜寻正确的
	// 插入位置,如果不正确,效率上的表现会比没有提示更糟糕
	copy(coll1.begin(), coll1.end(),			// source
			inserter(coll4, coll4.begin()));	// destination

	cout << "coll4: ";
	for (iter4 = coll4.begin(); iter4 != coll4.end(); ++iter4)
		cout << *iter4 << ' ';
	cout << endl;

	system("pause");
	return 0;
}

