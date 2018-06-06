
#include "test.h"			// mian.cpp文件中没有定义宏TEST_CPP,相当于对myVar变量的引用
// 应该是先预编译test.cpp,在这个过程中，此编译单元定义了TEST_CPP宏，所以就定义
// 了myVar这个变量，然后在预编译main.cpp的时候，并没有定义TEST_CPP宏，所以在这个
// 编译单元中，就相当于对myVar变量的引用

int main()
{
	Print();			// 0
	myVar = 1;
	Print();			// 1

	return 0;
}