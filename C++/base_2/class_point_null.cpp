
#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	int m;
	void print() { cout << "A\n"; }
};

int main()
{
	A *pa = NULL;
	// 下面的这句话可以正常运行，尽管没有为指针pa分配内存.
	// 并不是类没有初始化就不能调用类的成员函数，如果成员函数只是简单的打印东西
	// 没有调用类成员啥的，就不会报错
	pa->print();

	system("pause");
	return 0;
}