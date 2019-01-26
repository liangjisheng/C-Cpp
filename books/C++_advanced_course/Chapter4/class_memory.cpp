
// 对象类内存实例,所有类对象的成员函数的代码都是一样的，没有必要将成员函数的
// 代码放在对象里面，成员函数的代码放在代码区，而不是数据区。类对象的尺寸是
// 由其数据成员的尺寸决定的，与成员函数的定义无关

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;
using std::dec;

// 定义一个宏将某个对象的首4个字节当做整数输出
#define PrintFirstAsInt(obj) {\
	void *p = &(obj);\
	int *q = (int*)p;\
	cout << *q << endl;}

// 定义一个宏将某个对象的首4个字节以16进制输出
#define PrintFirstAs0x(obj){\
	void *p = &(obj);\
	int *q = (int*)p;\
	cout << hex << *q << endl << dec;}

// 一个不定义任何成员的类，其大小为1
class Empty{};

class OneByte
{
	char c;
};

// 定义成员函数并不增大对象的尺寸
class OneByteWithFunction
{
	char c;
public:
	void show() { cout << c << endl; }
};


// 定义静态成员不增大对象的尺寸
class OneByteWithStatic
{
	char c;
	static int i;
};

// 对象尺寸并不一定等于个成员变量尺寸之和
class WithTwoMembers
{
	int i;		// 类的前4个字节就是存储的i
	char c;
public:
	WithTwoMembers() { i = 106; c = 'A'; }
	void show() { cout << i << endl; }
};

// 定义虚函数会导致对象尺寸增加4字节，类的前4个字节存储的是指向虚表的指针
class WithVirtualFunction
{
	int i;
	char c;
public:
	WithVirtualFunction() { i = 106; c = 'A'; }
	virtual void show() { cout << i << endl; }
};

// 派生类对象的起始位置包含一个基类对象，对象前4个字节存储的是基类对象的前4个字节
class DerivedClass : public WithTwoMembers
{
	int newmem;
public:
	DerivedClass() { newmem = 57; }
};

// 包含虚函数的派生类对象，在拒起始地址偏移量为4的位置包含一个基类对象，
// 前4个字节存储的是派生类指向虚表的指针，与基类指向虚表的指针是不一样的
class DerivedFromVirtual : public WithVirtualFunction
{
	int newmem;
public:
	DerivedFromVirtual() { newmem = 57; }
};


struct mytest{};


int main()
{
	cout << "sizeof(Empty) is " << sizeof(Empty) << endl;
	cout << "sizeof(OneByte) is " << sizeof(OneByte) << endl;
	cout << "sizeof(OneByteWithFunction) is " << sizeof(OneByteWithFunction) << endl;
	cout << "sizeof(OneByteWithStatic) is " << sizeof(OneByteWithStatic) << endl;
	cout << "sizeof(WithTwoMembers) is " << sizeof(WithTwoMembers) << endl;
	cout << "sizeof(WithVirtualFunction) is " << sizeof(WithVirtualFunction) << endl;
	cout << "sizeof(DerivedClass) is " << sizeof(DerivedClass) << endl;
	cout << "sizeof(DerivedFromVirtual) is " << sizeof(DerivedFromVirtual) << endl;

	cout << endl;
	WithTwoMembers obj1;
	PrintFirstAsInt(obj1);

	WithVirtualFunction obj2;
	PrintFirstAsInt(obj2);

	DerivedClass obj3;
	PrintFirstAsInt(obj3);

	DerivedFromVirtual(obj4);
	PrintFirstAsInt(obj4);

	obj1.show();
	obj2.show();

	cout << endl;
	Empty e1;
	PrintFirstAsInt(e1);
	PrintFirstAs0x(e1);

	cout << sizeof(mytest) << endl;

	system("pause");
	return 0;
}