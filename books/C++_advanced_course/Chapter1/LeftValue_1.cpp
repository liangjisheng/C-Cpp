
// 对某个变量或者表达式建立常引用，允许发生类型转换，而一般的引用则不允许

#include <iostream>

using std::cout;
using std::endl;

int test_max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	char c = 'a';
	const int &rc = c;					// 常引用发生隐式类型转换
	cout << (void*)&c << endl;
	// 这两行输出的内存地址不同，说明rc引用的是转换后的无名变量，
	// 即rc里面存储的是无名变量的地址，而不是c的地址
	cout << (void*)&rc << endl;

	int i = 7;
	const int& ri = i;
	cout << (void*)&i << endl;
	cout << (void*)&ri << endl;

	// 先将5.5转换成无名的int类型变量，然后在建立对该无名变量的常引用
	cout << test_max(rc, 5.5) << endl;

	system("pause");
	return 0;
}