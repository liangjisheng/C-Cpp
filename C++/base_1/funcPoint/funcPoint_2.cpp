
#include <stdio.h>

static void func(int nNum);
// 定义一个函数指针类型, 有了FunType类型后，我们就可以同样地、
// 很方便地用FunType类型来申明多个同类型的函数指针变量
typedef void (*FuncType)(int);
FuncType pFunc;

void test2()
{
	func(0);
	pFunc = func;
	(*pFunc)(10);
	pFunc(20);

	printf("\n");
}

static void func(int nNum) { printf("%d\n", nNum); }
