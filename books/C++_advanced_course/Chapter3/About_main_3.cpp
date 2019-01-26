
#include <iostream>

using std::endl;
using std::cout;

// 所有的外部对象的构造函数都是先于main()函数执行的，如果要对类中的静态成员
// 对象进行初始化，那么这些对象的构造函数也是在main()函数之前执行的，如果这些
// 构造函数中还调用了其它函数的话，就可以使更多的函数先于main()执行

class A
{
public:
	A() { cout << "In constructor" << endl; }
};

A a;

int main()
{
	cout << "In main()" << endl;

	system("pause");
	return 0;
};