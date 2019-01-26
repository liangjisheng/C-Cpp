
// 所谓判断式(Predicates)就是返回bool(可转换为bool)的一个函数或仿函数
// 对STL而言，并非所有返回bool值的函数都是合法的判断式

#include <iostream>
#include <list>
#include <algorithm>
#include "..\..\print.hpp"

using namespace std;

// function object that return true for the nth call
// 当第n次被调用时返回true
class Nth
{
private:
	int nth;	// call for which to return value
	int count;	// call counter
public:
	Nth(int n) : nth(n), count(0) {}

	bool operator() (int) { return ++count == nth; }
};


int main()
{
	list<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);
	PRINT_ELEMENTS(coll);

	// remove third element
	list<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(),	// range
					Nth(3));					// remove criterion
	coll.erase(pos, coll.end());

	// 本来是想把第3个元素删除了，但实际上第3个和第6个元素都删除了，
	// 因为remove_if()函数内部会保留判断式的一份副本
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}