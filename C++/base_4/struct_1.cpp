
#include <stdio.h>

struct data
{
	int a;
	unsigned short b;
};

// 出来栈以外，堆、只读数据区、全局变量地址增长方向都是从低到高

int main()
{
	// 一般变量都是从高到低分配内存地址，但是对于结构体来说，结构体的成员
	// 在内存中顺序存放，所占内存地址依次增高，第一个成员处于低地址处，最后
	// 一个成员处于高地址处，但结构体成员的内存分配不一定是连续的，编译器
	// 会依据对齐原则进行处理
	// mData在内存中的布局	cc cc cc cc 02 01 cc cc
	data mData;
	mData.b = 0x0102;
	char *pData = (char *)&mData;
	printf("%d %d\n", sizeof(pData), (int)(*(pData + 4)));		// 4 2

	// printf("%d\n", *(int*)(pData + 4));

	getchar();
	return 0;
}


// 不管是返回基本数据类型还是自定义的类类型,下面两种写法没有任何区别
// 如果函数返回值采用"值传递方式",由于函数会把返回值复制到外部临时的
// 存储单元中,加const修饰没有任何价值.所以对于值传递来说,加const没有
// 太多意义
// int GetInt(void);
// const int GetInt(void);

// A GetA(void);
// const A GetA(void);

