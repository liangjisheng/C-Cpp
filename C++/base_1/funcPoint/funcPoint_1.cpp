
#include <stdio.h>

static void func(int nNum);		// 声明一个函数
static void (*pFunc)(int);		// 声明一个函数指针静态变量

void test1()
{
	// 一个函数名也可以像一个函数指针那样调用
	(*func)(0);

	func(10);
	pFunc = &func;
	pFunc(20);

	pFunc = NULL;
	pFunc = func;
	pFunc(30);

	printf("\n");
}

static void func(int nNum) { printf("%d\n", nNum); }

// func与pFunc一样，都是函数指针，func函数名是一个函数指针常量，而pFunc是一个函数指针变量
// 但函数名调用如果都得如(*func)(0);这样，那书写与读起来都是不方便和不习惯的
// 所以C语言的设计者们才会设计成又可允许func(0);这种形式地调用,这样方便多了并与数学中的
// 函数形式一样,为统一起见，pFunc函数指针变量也可以pFunc(20)的形式来调用
// 赋值时，即可pFunc=&func形式，也可pFunc=func

// 补充说明一点：在函数的申明处
// void func(int );		//不能写成void (*func)(int)
// void (*pFunc)(int);  //不能写成void pFunc(int)
