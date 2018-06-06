
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int A[4] = {1, 2, 3, 4};
	int B[4] = {5, 6, 7, 8};
	int (&rA)[4] = A;

	cout << A << endl;
	cout << &A << endl;
	cout << A + 1 << endl;
	cout << &A + 1 << endl;
	cout << B << endl;
	cout << rA << endl;
	cout << &rA << endl;

	// 从输出结果来看，A与&A在数值上是相等的，但A的数据类型是int[4],是一个
	// 指针常量即 int *const,而&A的数据类型是int(*)[4],他们在概念上是不同的
	// 这直接导致了A+1和&A+1的结果完全不同，A+1等于A的首地址加上sizeof(int)
	// 而&A+1在数值上等于A的首地址加上sizeof(A),rA是对数组A的引用

	system("pause");
	return 0;
}