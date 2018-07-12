
// 如果是.c文件则默认以C语言的方式编译和链接，此时不能加
// extern "C"因为C语言中没有extern "C";
// 如果是.cpp文件则默认以C++的方式编译和链接，此时如果想以
// C函数的方式调用test.h中声明的变量和函数，必须加上extern "C"

//extern "C"
//{
	#include "test.h"
//};

int add(int x, int y) { return x + y; }