
#include "test.h"

// 改变test.c文件的编译方式，可以选择使用C编译，也可以使用C++编译
// Solution Explorer->test.c->右键->属性->C/C++ ->高级->Compile as -> C or C++
// C编译输出printf mytest extern ok n
// C++编译输出cout mytest extern ok n
// 输出什么与main.cpp的编译方式无关，只与test.c文件的编译方式有关

void mytest()
{
#ifdef __cplusplus
	cout << "cout mytest extern ok n" << endl;
#else
	printf("printf mytest extern ok n\n");
#endif
}