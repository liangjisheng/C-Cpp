
// 仿函数是泛型编程强大威力和纯粹抽象概念的又一个例子,可以这么说
// 任何东西,只要其行为像函数,它就是个函数.因此,如果你定义了一个对象
// 行为像函数,它就可以被当做函数使用
// 所谓函数行为: 是指可以用小括号传递参数,籍以调用某个东西
// funtion(arg1, arg2);		// a function call

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// simple function object that prints the passed argument
class PrintInt
{
public:
	void operator() (int elem) const { cout << elem << ' '; }
};


int main()
{
	vector<int> coll;
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	// print all elements
	// PrintInt()产生此类的一个临时对象,当做for_each()的一个参数
	for_each(coll.begin(), coll.end(),	// range
		PrintInt());					// source
	cout << endl;

	system("pause");
	return 0;
}