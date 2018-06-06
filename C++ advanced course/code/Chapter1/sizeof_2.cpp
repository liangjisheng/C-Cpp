
#include <iostream>

using std::cout;
using std::endl;

// 不允许有长度为0的数据类型存在，即使在类中不定义任何数据成员，
// 该类的对象在内存中任然要占1个字节
class Small {};

// 类的成员函数并不影响对象所占空间的大小，类对象的大小是由它的数据成员决定的
// 类LessFunc和下面的MoreFunc类的对象所占内存大小是一样的
class LessFunc
{
	int num;
	void func1() {}
};

class MoreFunc
{
	int num;
	void func1() {}
	int func2() { return 1; }
};

class NeedAlign
{
	char c;
	double d;
	int i ;
};

// 编译器会插入一个指向虚函数表的指针，以实现虚函数的动态调用
// 如果使用数据成员之间的对齐，那么至少包含一个数据成员的、拥有
// 虚函数的类对象的大小最小为8
class Virtual
{
	int num;
	virtual void func() {}
};


int main()
{
	cout << sizeof(Small) << endl;			// 1
	cout << sizeof(LessFunc) << endl;		// 4
	cout << sizeof(MoreFunc) << endl;		// 4
	cout << sizeof(NeedAlign) << endl;		// 24
	cout << sizeof(Virtual) << endl;		// 8

	system("pause");
	return 0;
}
