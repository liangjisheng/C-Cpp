
// General inserter或称为(General insert iterator)根据两个参数初始化(1):容器,(2)插入的位置
// 迭代器内部以待插入位置为参数，调用成员函数insert(),
// inserter()则提供了更方便的手段来产生general inserter并初始化
// general inserter对所有标准容器都使用，应为所有标准容器都提供了insert(),对关联容器而言
// (sets,maps)，插入位置只是个提示
// general inserter返回刚刚被插入的那个元素的位置，这是为了确保该迭代器的位置始终有效
// 因为每一次插入操作都会(至少可能会)使得指向容器的所有迭代器失效

#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;


int main()
{
	set<int> coll;

	// create insert iterator for coll
	// inconvenient way
	insert_iterator<set<int> > iter(coll, coll.begin());

	// insert elements with the usual iterator interface
	*iter = 1;
	// iter++;
	*iter = 2;
	// iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create inserter and insert elements
	// convenient way
	inserter(coll, coll.end()) = 44;
	inserter(coll, coll.end()) = 55;

	PRINT_ELEMENTS(coll);

	// use inserter to insert all elements into a list
	list<int> coll2;
	copy(coll.begin(), coll.end(),			// source
		inserter(coll2, coll2.begin()));	// destination

	PRINT_ELEMENTS(coll2, "list: ");

	// use inserter to reinsert all elements into the list before the second element
	copy(coll.begin(), coll.end(),			// source
		inserter(coll2, ++coll2.begin()));	// destination

	PRINT_ELEMENTS(coll2, "list: ");

	system("pause");
	return 0;
}
