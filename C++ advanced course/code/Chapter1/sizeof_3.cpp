
// 当sizeof用于指针时，不管什么类型的指针，大小一律为4(32位平台下)
// 它代表的是指针变量本身在内存中所占看空间的大小，函数指针也不例外
#include <iostream>

using std::cout;
using std::endl;

char testfunc()
{
	return 'k';
}

int main()
{
	int A[3][5];
	char c[] = "123456";
	int a = 0;
	int *q;
	double* (*d)[3][6];

	// A的数据类型是int[3][5]
	cout << sizeof(A) << endl;					// 60

	cout << endl;
	// A[1]的数据类型是int[5]
	cout << sizeof(A[0]) << endl;				// 20
	cout << sizeof(A[1]) << endl;				// 20
	cout << sizeof(A[2]) << endl;				// 20
	cout << sizeof(A[3]) << endl;				// 20
	// 尽管A[4]的下标越界，但并不会造成运行时错误，因为sizeof只关心数据类型
	// 而且在编译阶段就已经完成了
	cout << sizeof(A[4]) << endl;				// 20

	cout << endl;
	// A[0][0]的数据类型是int
	cout << sizeof(A[0][0]) << endl;			// 4
	// c的数据类型是char[7]
	cout << sizeof(c) << endl;					// 7

	cout << sizeof(a) << endl;					// 4
	cout << sizeof a << endl;					// 4
	cout << sizeof(&testfunc) << endl;			// 4
	// 对testfunc的一次调用,返回char,所以为1
	cout << sizeof((*testfunc)()) << endl;		// 1

	cout << endl;
	q = new int[10];
	cout << sizeof(q) << endl;					// 4
	cout << sizeof(d) << endl;					// 4
	// sizeof(*d)的数据类型是double*[3][6] = 3 * 6 * sizeof(double*) = 72
	cout << sizeof(*d) << endl;					// 72
	// sizeof(**d) = sizeof(double* [6]) = 6 * sizeof(double*) = 24
	cout << sizeof(**d) << endl;				// 24
	// sizeof(***d) = sizeof(double*) = 4
	cout << sizeof(***d) << endl;				// 4
	// sizeof(****d) = sizeof(double) = 8
	cout << sizeof(****d) << endl;				// 8

	system("pause");
	return 0;
}