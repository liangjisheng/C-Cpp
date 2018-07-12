
// 一个进程的内存地址空间被划分为8块，并且各块内存不是聚集在
// 一起形成连续内存块，而是按需加载使用内存

// 下面是一个进程空间的8个内存块，及其作用
// Image			映像内存			exe，dll等加载到这里
// Mapped File		内存映射文件		共享内存，用于进程间通讯
// Shareable		可共享内存
// Head(Managed Heap)内存堆				堆内存，new/new[]/malloc()等都在堆内存分配，默认为1MB，
//										Managed Heap供CLR使用的堆
// Stack			堆栈				栈内存，用作函数参数，局部变量的存储空间，默认为1MB
// Private Data		私有数据
// Page Table		内存页表			内存分配页表
// Free				自由内存			可用的内存空间

// 每个应用程序默认有一个Heap，用户也可以创建自己的Heap
// Free即进程空间中的整个可用地址空间，它会已两种方式被使用，
// 一种是Heap自动分配和回收，一种是直接使用VirtualAlloc/VirtualFree
// 分配和回收，用户对它的直接使用是用于分配连续大块内存，
// 分配和释放的速度比使用 Heap 更快;

// 字节序列，网络字节序列又叫大端序列，字节序列简单的将是对大于一个
// 字节的数据在内存中如何存放的问题，
// 端序					第一字节	中间字节	最末字节	备注
// 大端(Big Endian)		最高位字节	......		最低位字节	类似于正常书写数字表示
// 小端(Little Endian)	最低位字节	......		最高位字节	类似于数学计算法则，反序列

// 端序		内存案例(0x44332211)		处理器家族
// 大端		0x44 0x33 0x22 0x11			SUM SPARC/IBM PowerPC
// 小端		0x11 0x22 0x33 0x44			Intel 80x86系列

#include <stdio.h>
#include <iostream>
#include <stdint.h>			// for int_64

using std::cout;
using std::endl;


//#pragma pack(1)

struct type1
{
	char c;
	double d;
	char c1;
	int i;
};


struct type2
{
	char c;
	int d;
	char c1;
	int i;
};

//#pragma pop


// 测试有端序产生的问题
void test_Endian()
{
	int64_t a = 1;
	int b = 2;
	// %d每次会查找4个字节，但a占8个字节，如果处理器是x86架构的话，在内存中是以小端
	// 序列存储的，所以四个字节是1，紧跟着这4个字节的是a的高4字节为0，在接下来就是
	// 存储b的四个字节，随意会有下面的输出结果
	printf("%d, %d\n", a, b);			// 1, 0
	printf("%d, %d, %d\n", a, b, b);	// 1, 0, 2
}


// 参数传递顺序分位从左到右，从右到左两种，
// 从左到右，对函数的多个输入参数从左到右求值并压入栈
// 从右到左传递，对函数的多个输入参数从右到左求值并压入栈
// 参数传递方式有值传递，引用传递，指针传递，三种参数本质上都是值传递
// 参数传递顺序和传递方式组合形成了几种不同的函数调用约定
// cdecl C调用约定，参数从右到左求值并入栈，调用函数清理堆栈，实现
// 可变参数的函数(printf,scanf)
// thiscall C++成员函数调用约定，this指针存放于ECX寄存器中，参数
// 从右到左求值入栈，被调函数在退出时清理堆栈
// stdcall WindowAPI 的默认调用方式，参数从右到左求值入栈，
// 被调函数在退出时清理堆栈


int main()
{
	// cout << "test" << endl;
	// cout << sizeof(type1) << endl;
	// cout << sizeof(type2) << endl;

	test_Endian();

	system("pause");
	return 0;
}

