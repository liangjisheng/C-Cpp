
#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include "..\..\print.hpp"

using namespace std;

int main()
{
	set<int, greater<int> > coll1;
	deque<int> coll2;

	for (int i = 1; i <= 9; ++i)
		coll1.insert(i);

	PRINT_ELEMENTS(coll1, "initialized: ");

	// transform all elements into coll2 by multiplying 10
	// 使用bind2nd(),是的multiples<int>运算时,以源群集(socuce collection)
	// 的元素作为第一参数,10作为第二个参数,调用multiplies<int>()
	// 表达式,并返回结果,然后将结果插入到coll2中
	transform(coll1.begin(), coll1.end(),			// source
				back_inserter(coll2),				// destination
				bind2nd(multiplies<int>(), 10));	// operation

	PRINT_ELEMENTS(coll2, "transformed: ");

	// replace value equal to 70 with 42
	// bind2nd(equal_to<int>(), 70)被用来当做一项准则,判断哪些元素
	// 将被42替代.bind2nd以70作为第二参数,调用二元判断式(binary predicate)
	// equal_to,从而定义出一个一元判断式(unary predicate),处理群集
	// 内的每一个元素
	replace_if(coll2.begin(), coll2.end(),		// range
			bind2nd(equal_to<int>(), 70),		// replace criterion
			42);								// new value

	PRINT_ELEMENTS(coll2, "replaced: ");

	// remove all elements with values less than 50
	coll2.erase(remove_if(coll2.begin(), coll2.end(),	// range
						bind2nd(less<int>(), 50)),		// remove cirterion
				coll2.end());

	PRINT_ELEMENTS(coll2, "removed: ");

	system("pause");
	return 0;
}