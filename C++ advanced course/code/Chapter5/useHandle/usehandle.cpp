
// 在头文件handle.h中，用户只能在句柄类handle的定义中看到一个指向句柄所操作的
// 类wrapped对象的指针，类wrapped的类的全部实现细节在handle.cpp中，没有任何一个
// 头文件提供任何wrapped类的任何信息。由于句柄所要做的工作大致是可以固定下来的
// 所以handle.h可以不发生变化，当wrapped类的实现发生变化时，只需要重新编译
// handle.cpp其它任何使用到handle类(也就是包含了头文件handle.h)的源文件都不需要
// 重新编译

#include "handle.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
	handle u;
	cout << u.read() << endl;
	u.destory();
	u.create();
	u.change(9);
	cout << u.read() << endl;

	system("pause");
	return 0;
}

