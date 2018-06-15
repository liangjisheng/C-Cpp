// 右值通常是一些数值常量、临时变量或者无名的变量等
// 例如函数的返回值，右值引用就是针对这些右值的引用，
// C++中通过运算符&&来声明一个右值引用，而原先的&称
// 为左值引用
#include"stdio.h"

int CreateInt(int nInt)
{ return nInt; }

int main()
{
	int n=0;
	int& Lref=n;
	printf("Lref n=%d\n",Lref);
	int&& Rref=CreateInt(1);
	printf("Rref n=%d\n",Rref);

	getchar();
	return 0;
}
