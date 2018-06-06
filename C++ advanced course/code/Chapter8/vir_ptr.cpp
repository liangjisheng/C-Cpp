
// 动态联编指被调函数的入口地址是在运行时、而不是在编译时决定的.C++利用动态联编来完成虚函数
// 的调用,C++并没有规定如何实现动态联编,但大多数的C++编译器都是通过虚指针(vptr)和虚函数表
// (vtable)来实现动态联编的.基本思路是:为每一个包含虚函数的类建立一个虚函数表，虚函数表的
// 各个表项存放的是各虚函数在内存中的入口地址;在该类的每个对象中设置一个指向虚函数表的指针
// 在调用函数时,先利用虚函数找到虚函数表,确定虚函数的入口地址在表中的位置,获取入口地址完成
// 调用.
// 虚指针作为对象的一部分存放在对象的空间中.一个类只有一个虚函数表,因此该类的所以对象中的
// 虚指针都指向同一个地方.在不同的编译器中,虚指针在对象中的位置是不同的.两种典型的做法是
// 在Visual C++中，虚指针位于对象的起始位置;在GNU C++中,虚指针位于对象的尾部而不是头部
// 可通过下面的程序考察在Visual C++中虚指针在对象中的位置

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;

int globalv = 0;

class NoVirtual
{
	int i;
public:
	void func() { cout << "No Virtual Function" << endl; }
	NoVirtual() { i = ++globalv; }
};

class HaveVirtual : public NoVirtual
{
public:
	virtual void func() { cout << "Virtual Function" << endl; }
};


int main()
{
	NoVirtual n1, n2;
	HaveVirtual h1, h2;
	unsigned long *p;

	cout << "sizeof(NoVirtual) is :" << sizeof(NoVirtual) << endl;
	cout << "sizeof(HaveVirtual) is :" << sizeof(HaveVirtual) << endl;
	p = reinterpret_cast<unsigned long*>(&n1);
	cout << "the content of first 4 bytes of n1 is :" << p[0] << endl;
	p = reinterpret_cast<unsigned long*>(&n2);
	cout << "the content of first 4 bytes of n2 is :" << p[0] << endl;

	// 头4字节存放的是虚函数表所在的地址
	p = reinterpret_cast<unsigned long*>(&h1);
	cout << "the content of first 4 bytes of h1 is :0x" << hex << p[0] << endl;
	p = reinterpret_cast<unsigned long*>(&h2);
	cout << "the content of first 4 bytes of h2 is :0x" << hex << p[0] << endl;

	system("pause");
	return 0;
}