
// 算法有一种特殊的辅助函数叫做Predicates(判断式).所谓Predicates
// 就是返回bool的函数.通常用来被指定排序准则和查找准则.
// 并非所有返回bool的函数都是Predicates,STL要求,面对相同的值
// Predicates必须得出相同的结果,这个要求将那些"被调用时,会改变自己
// 内部状态"的函数清除出场
// Unary Predicates会检查唯一参数的某项特性
// Binary predicates(二元判别式)的典型用途是,比较两个参数的特定属性

#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>		// for abs()

using namespace std;


// predicate,which returns whether an integer is a prime number
bool isPrime(int number)
{
	// ignore negative sign
	number = abs(number);

	// 0 and 1 are prime numbers
	if (0 == number || 1 == number)
		return true;

	// find divisor that divides without a remainder
	int divisor;
	for (divisor = number / 2; number % divisor != 0; --divisor) {}

	// if no divisor greater than 1 is found,it is a prime number
	return 1 == divisor;
}


int main()
{
	list<int> coll;

	for (int i = 24; i <= 30; ++i)
		coll.push_back(i);

	// search for prime number
	list<int>::iterator pos;
	// find_if()算法在给定区间内寻找使"被传入的一元判断式"运算结果
	// 为true的第一个元素,返回给定区间内的第一个素数
	// 如果不存在,返回coll.end()
	pos = find_if(coll.begin(), coll.end(),		// range
					isPrime);					// predicate

	if(pos != coll.end())
		cout << *pos << " is first prime number found" << endl;
	else
		cout << "no prime number found" << endl;

	system("pause");
	return 0;
}