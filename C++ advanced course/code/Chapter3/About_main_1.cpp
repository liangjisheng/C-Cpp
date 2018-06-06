
// 通过环境变量errorlevel可以获取用C++开发的应用程序的main()函数的返回值

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int i = 0;
	cout << "input a number:";
	cin >> i;

	system("pause");
	// exit(i);执行的效果和return i;的效果是一样的，都是将i作为程序的返回结果
	// 但在C++中exit()可能会破会程序对象的析构函数的调用，在C++中应当使用异常
	// 处理机制
	return i;
}