
// Back inserters 或称为(back insert iterator)通过成员函数，将一个元素值追加于容器尾部
// 由于push_back()只存在于vectors, deques, lists, strings之中，所以C++标准库中也只有这些
// 容器支持 back inserters
// back inserter 生成时必须根据其所属容器进行初始化，可以使用 back_inserter();

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;


int main()
{
	vector<int> coll;

	// create back inserter for coll: inconvenient(不方便的) way
	// 插入迭代器调用所属容器中不同的成员函数，所以insert迭代器初始化时一定
	// 要清楚知道自己所属的容器是哪一种
	back_insert_iterator<vector<int> > iter(coll);

	// insert elements with the usual iterator interface
	// 插入迭代器的赋值就相当于插入，iter++并没有实际操作，只是简单的传回iter
	// 所以注释或者不注释iter++对插入并没有什么影响
	*iter = 1;
	//iter++;
	*iter = 2;
	//iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	// create back inserter and insert elements : convenient(方便的) way
	back_inserter(coll) = 44;
	back_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);

	// use back inserter to append all elements again
	// reserve enough memory to avoid reallocation
	coll.reserve(2 * coll.size());
	copy(coll.begin(), coll.end(),	// source
		back_inserter((coll)));		// destination

	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}
