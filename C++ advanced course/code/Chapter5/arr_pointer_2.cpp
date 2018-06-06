
#include <iostream>

using std::cout;
using std::endl;

// 在C语言中，对数组的下标是不做越界检查，因此在函数的参数中，int[5]和int[1]
// 都会被理解成int[]也就是int*
void show(int A[5])
{
	A++;
	cout << A[0] << endl;
}

void show1(int A[1])
{
	A++;
	cout << A[0] << endl;
}


// 如果函数的形参是数组实参的引用，那么数组的长度精被作为类型的一部分，实际上
// 对数组建立引用，就是对数组的首地址建立一个常引用，int(&)[5],int(&)[6]被认为
// 是不同的数据类型
void show2(int (&A)[5])
{
	cout << "The type is int(&)[5]" << endl;
}

void show2(int (&A)[6])
{
	cout << "The type is int(&)[6]" << endl;
}


int main()
{
	int d[5] = {1, 2, 3, 4, 5};
	show(d);
	show1(d);

	show2(d);

	system("pause");
	return 0;
}