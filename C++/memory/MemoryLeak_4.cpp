
// 内存泄露的含义是：拿走了一块“堆”内存块，在某检查点处，发现没有归还这个内存块。
// 如果是： 地址A = malloc(N); 因为没有调用free(地址A)，所以内存泄露了
// 如果是： 地址B = new 类型T; 因为没有调用delete 地址B，所以内存泄露了
// 如果是：从用户的内存池中取一个内存块，没有调用相应的归还给内存池的操作，也认为是“内存泄露”
// 从哪里拿了一个东西，要归还到那个地方去。例如：从图书馆L中借了本书，归还给图书馆B，
// 肯定要挨骂的。同理，从图书馆L中借了本小说，却还给图书馆一本杂志，也是要挨骂的
// 函数_CrtDumpMemoryLeaks()功能：检查内存泄露并且在VC的输出窗口打印出泄露的内存块信息

// 如何自己实现内存泄露检查工具呢？思路很简单，重载new，delete运算符，使用自己宏替换malloc和free
// 所有的分配和释放动作必须经过我过手，我才能加入点私货（统计信息等）。这样就可以检查内存泄露了

#include <stdio.h>
#include <string.h>		// for memset

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

struct Test
{
	Test() 
	{
		m_p = new char[10]; 
		memset(m_p, 0, 10);
	}
	~Test() { delete [] m_p; }
	char *m_p;
};

// 全局变量也会报告内存错误，因为在调用_CrtDumpMemoryLeaks的时候，全局变量还没有离开
// 生存期，所以此时~Test()还未调用，就会报内存错误，但这个全局变量在离开生存期后，会
// 自动释放内存，此时属于误报
Test t;

// 通过_CrtSetDbgFlag函数，告知Crt库在程序完全退出时，打印一下内存泄露的情况。
// 这时，全局变量t已经析构了，所以误报没有了

void main()
{
	int *x = new int();

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	// _CrtDumpMemoryLeaks();
#endif

	getchar();
}