
#include <iostream>

void show()
{
	void func();				// func()函数声明，必不可少，否则编译出错
	func();
}

int main()
{
	void func();				// func()函数声明，必不可少，否则编译出错
	func();
	show();

	system("pause");
	return 0;
}