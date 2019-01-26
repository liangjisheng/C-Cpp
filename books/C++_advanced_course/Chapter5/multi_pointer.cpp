
// 由指针指向的连续空间也称为"动态数组"，值有new操作分配的动态空间，而平常说的
// 数组则是静态数组，他的大小是在编译时就能静态计算出来的。多维数组各数据元素的
// 空间一定是连续的，而用动态内存分配的方式申请空间，只能在一次new操作中得到
// 连续的空间

#include <iostream>

using std::cout;
using std::endl;

void test()
{
	int A[2][3] = {1, 2, 3, 4, 5, 6};
	// p指向的是int[3]类型，即指向的是一个数组类型
	int (*p)[3];
	int i = 0, j = 0;
	p = new int[2][3];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			p[i][j] = A[i][j];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			cout << (p[i][j] == A[i][j]);
	cout << endl;

	delete []p;

	// 输出111111,说明p是一个与A的结构完全相同的动态二维数组
}


void test_1()
{
	int A[2][3] = {1, 2, 3, 4, 5, 6};
	int **p;
	int i = 0, j = 0;

	p = new int *[2];
	for(i = 0; i < 2; i++)
		p[i] = new int[3];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			p[i][j] = A[i][j];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			cout << (p[i][j] == A[i][j]);
	cout << endl;

	for(i = 0; i < 2; i++)
		delete [] p[i];
	delete [] p;
	p = NULL;
}


int main()
{
	test();
	test_1();

	system("pause");
	return 0;
}