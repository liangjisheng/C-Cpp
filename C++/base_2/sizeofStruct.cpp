#include <stdio.h>

// 此结构体所占内存空间的大小为24，
// VC中给结构体分配内存时，会已结构体中所占字节最长的基本数据类型
// 作为分配内存的单元，先分配一个单元，存储字符c，因为VC中基本数据类型
// 的地址偏移必须是长度的整倍数，所以存储完字符c后，会在分配另外
// 一个单元，8个字节存储d，然后在分配8个字节存储n；
// 默认字节对齐方式是本结构体内所占空间最大的基本数据类型字节数对齐方式
struct test
{
	char c;
	double d;
	int n;
};


#pragma pack(push)			// 保存字节对齐状态
#pragma pack(4)				// 设定为4字节对齐

// 4字节对齐方式下，次结构体所占字节数为16字节
struct test1
{
	char c1;
	double d1;
	int n1;
};

#pragma pack(pop)			// 恢复对齐状态

int main()
{
	// printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(test));
	printf("%d\n", sizeof(test1));

	getchar();
	return 0;
}