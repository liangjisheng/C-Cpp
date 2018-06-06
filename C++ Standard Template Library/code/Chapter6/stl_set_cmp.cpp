
// 无论是将排序准则作为第二个template参数传入，或者是采用缺省的排序准则less<>，通常
// 都会讲排序准则定义为类型的一部分，但有时必须在执行期间处理排序准则，或者你可能需要
// 对同一种数据类型采用不同的排序准则，此时你就需要一个用来表现排序准则的特殊类型，
// 使得能够在执行期间传递某个准则

#include <iostream>
#include <set>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;

// type for sorting criterion
template <class T>
class RuntimeCmp
{
public:
	enum cmp_mode { normal, reverse };
private:
	cmp_mode mode;
public:
	// constructor for sorting criterion
	// -default criterion uses value normal
	RuntimeCmp(cmp_mode m = normal) : mode(m) {}

	// comparision of elements
	bool operator() (const T& t1, const T& t2) const 
	{
		return mode == normal ? t1 < t2 : t2 < t1;
	}

	// comparision of sorting criteria
	bool operator== (const RuntimeCmp& rc) { return mode == rc.mode; }
};

typedef set<int, RuntimeCmp<int> > IntSet;

// declare
void fill(IntSet& set);


int main()
{
	// create, fill, and print set with normal element order
	// - uses default sorting criterion
	IntSet coll1;
	fill(coll1);
	PRINT_ELEMENTS(coll1, "coll1: ");

	// create sorting criterion with reverse element order
	RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);

	// create, fill, and print set with reverse element order
	IntSet coll2(reverse_order);
	fill(coll2);
	PRINT_ELEMENTS(coll2, "coll2: ");

	// assign elements and sorting criterion
	// 赋值操作不仅赋值了元素，也赋值了排序准则(否则任何一个赋值操作都会轻易危及排序准则)
	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS(coll1, "coll1: ");

	// just to make sure...
	if (coll1.value_comp() == coll2.value_comp())
		cout << "coll1 and coll2 have same soring criterion" << endl;
	else
		cout << "coll1 and coll2 have different sorting criterion" << endl;

	system("pause");
	return 0;
}

void fill(IntSet& set)
{
	// fill insert elements in random order
	set.insert(4);
	set.insert(7);
	set.insert(5);
	set.insert(1);
	set.insert(6);
	set.insert(2);
	set.insert(5);
}