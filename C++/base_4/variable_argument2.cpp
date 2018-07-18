
/*
 name: variable_argument2.cpp
 func: 将函数形参声明为C++11新标准中的initializer_list标准库类型,实现可变参数
*/

#include <iostream>
#include <initializer_list>

using namespace std;

// 参数必须放在一组‘{}’（大括号）内，编译器通过大括号来将这组参数转化为
// initializer_list.大括号的的一组实参与initializer_list形参对应
// 同一个initializer_list中的参数具有相同的类型。本质上来说initializer_list
// 是一个编译器支持的容器类模板，同其他容器一样，容器中的元素具有相同的类型
int sum(initializer_list<int> il)
{
	int nSum = 0;
	initializer_list<int>::iterator iter;
	for (iter = il.begin(); iter != il.end(); iter++)
		nSum += *iter;

	return nSum;
}

int main()
{
	// 必须加上大括号
	int nSum = sum({ 1, 2, 3, 4, 5 });
	cout << nSum << endl;

	getchar();
	return 0;
}
