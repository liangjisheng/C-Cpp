
// front inserter 通过成员函数push_front()将一个元素值加在容器头部，由于只有
// deque和list中有push_front(),所以C++标准库中也只有这两个容器支持front inserter
// front inserter 生成时必须根据其所属容器进行初始化，可以使用front_inserter();

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;


int main()
{
	list<int> coll;

	// create front iterator for coll
	// inconvenient way
	front_insert_iterator<list<int> > iter(coll);

	// insert elements with the usual iterator interface
	// 和 back inserter 一样，有没有 iter++ 都一样
	*iter = 1;
	// iter++;
	*iter = 2;
	// iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create front inserter and insert elements
	// convenient way
	front_inserter(coll) = 44;
	front_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);

	// use front inserter to insert all elements again
	copy(coll.begin(), coll.end(),		// source
		front_inserter(coll));			// destination

	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}
