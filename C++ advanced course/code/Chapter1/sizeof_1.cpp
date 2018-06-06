
#include <iostream>

using std::cout;
using std::endl;

// sizeof是一种在编译是进行的运算，而与运行是无关，所以当sizeof的参数是
// 变量或表达式是，sizeof运算真正关心的是变量或表达式的类型，而不是变量或
// 表达式的值，所以sizeof(i = 5)等价于sizeof(int),也就是说，在可执行代码
// 中，并不包含i = 5这个表达式，他早在编译阶段就被处理了，第二次输出i = 9

int main()
{
	int i = 9;
	cout << "i = " << i << endl;
	cout << "sizeof(i) = " << sizeof(i) << endl;
	cout << "sizeof(i = 5) = " << sizeof(i = 5) << endl;
	cout << "i = " << i << endl;			// i = 9
	
	system("pause");
	return 0;
}