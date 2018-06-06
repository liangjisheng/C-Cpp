
// 左值：值为可寻址的非只读单元的表达式称为左值
// 注意:(1)不能寻址的表达式不能作为左值
// (2):常变量虽然可以寻址，但由于只读的限制，不能作为左值
// (3):如果表达式运算的结果是一个临时的无名对象，则此表达式不能作为左值
// 左值一定可以作为右值，但反过来不一定

// 能建立引用的表达式一定是左值，不能作为左值的表达式只能建立常引用
// 而不能建立一般的引用

#include <iostream>

using std::cout;
using std::endl;

int g_nGlobal = 0;

int& func()
{
	return g_nGlobal;
}

// 有时候应该将函数的参数声明为常引用
int test_max(int& a, int& b)
{
	return (a > b) ? a : b;
}

int test_max_1(const int& a, const int& b)
{
	return (a > b) ? a : b;
}


int main()
{
	int i = 2;
	// i += 1的运算结果是对i的引用，所以可以作为左值
	(i += 1) = 5;
	// 返回对全局变量的引用，可以作为左值
	func() = 6;
	cout << i << endl;
	cout << g_nGlobal << endl;

	// 如果第二个参数的类型不是常引用，则会编译出错，因为对非左值只能建立常引用
	// cout << test_max(i, 5) << endl;
	cout << test_max_1(i, 50) << endl;

	system("pause");
	return 0;
}