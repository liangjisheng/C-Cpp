
#include <iostream>

using std::cout;
using std::endl;

// C++标准要mian()函数的返回值类型为int,VC++并没有强制要求main函数返回int类型
// 返回int类型，符合C++标准，程序具有可移植性

float main()
{
	cout << "hello" << endl;

	system("pause");

	// 当返回值类型为int是，如果没有下面这句话，编译器会自动在末尾添加
	// return 0;main()函数是C++经过特殊处理的函数
	return 0.0;
}