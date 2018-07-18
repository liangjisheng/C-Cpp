
/***********************************************************
 * @name: volatile_1.cpp
 * @brief: test volatile
 * @author: Jisheng Liang
 * @date: 2018/7/10 15:25:32
 * @version: 1.0
 **********************************************************/

//对于 volatile 类型的变量，系统每次用到他的时候都是直接从对应的内存当中提取，而
//不会利用 cache 当中的原有数值，以适应它的未知何时会发生的变化，系统对这种变量的处
//理不会做优化——显然也是因为它的数值随时都可能变化的情况

#include <stdio.h>

// Debug:10 10, Release:10 10
void test1()
{
	int i = 10;
	int a = i;
	printf("i = %d\n", a);

	// 下面汇编语句的作用就是改变内存中 i 的值，但是又不让编译器知道
	__asm {
		mov dword ptr[ebp - 4], 20h
	}
	int b = i;
	printf("i = %d\n", b);
}

// Debug:10 10, Release:10 32
void test2()
{
	volatile int i = 10;
	int a = i;
	printf("i = %d\n", a);

	// 下面汇编语句的作用就是改变内存中i的值，但是又不让编译器知道
	__asm {
		mov dword ptr[ebp - 4], 20h
	}
	int b = i;
	printf("i = %d\n", b);
}

void main()
{
	printf("no volatile\n");
	test1();
	printf("\nvolatile\n");
	test2();

	getchar();
}
