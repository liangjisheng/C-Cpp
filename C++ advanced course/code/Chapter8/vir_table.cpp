
// 虚函数表的内部结构,虚函数表放在应用程序的常量区

#include <iostream>

using namespace std;

// 显示一个函数在内存中的地址,使用内联汇编可以获取类的非静态成员函数的地址
#define ShowFuncAddress(function) _asm{\
	mov eax, function}\
	_asm{mov p, eax}\
	cout << "address of " #function " is 0x" << p << endl;

// 显示一个类的虚函数表指定索引的虚函数指针
// ClassName为类名
// pObj为类的某个对象的地址
// index为虚函数的在表中的索引
void ShowVTableContent(char *ClassName, void *pObj, int index)
{
	unsigned long *pAddr = NULL;
	// 获取虚函数表的地址(即头4字节的内容)
	pAddr = reinterpret_cast<unsigned long*>(pObj);
	// 将头4字节的内容强制转换为指针,指向某个类的虚函数表在内容中的地址
	pAddr = (unsigned long *)*pAddr;
	cout << "the content of " << ClassName << "'s vtable[" << index << "]";
	cout << " is 0x" << (void*)pAddr[index] << endl;
}

// 对任意的包含虚函数的类，将虚函数的入口地址写入虚函数表，按照下列步骤进行
// 1、确定当前类所包含的虚函数的个数，一个类的虚函数有两个来源，一是继承自
// 父类(在当前类中可能被改写)，其它的是在当前类中新声明的虚函数
// 2、为所有的虚函数排序,继承自父类的所有虚函数，排在当前类新声明的虚函数之前
// 新声明的虚函数，按照在当前类中的声明顺序排列
// 3、确定虚函数的入口地址，继承自父类的虚函数，如果在当前类中被改写，则虚函数
// 的入口地址就是改写之后的地址，否则保留父类中的虚函数的入口地址，新声明的虚函数
// 其入口地址就是在当前类中的函数的入口地址
// 4、将所有虚函数的入口地址按照排定的次序一次写入虚函数表

class Base
{
	int i;
public:
	virtual void f1() { cout << "Base's f1()" << endl; }
	virtual void f2() { cout << "Base's f2()" << endl; }
	virtual void f3() { cout << "Base's f3()" << endl; }
};

class Derived : public Base
{
	// 尽管在类Derived中，f4()在f3()之前定义，但由于f3是继承在父类的虚函数
	// 而f4是新声明的虚函数,所以f3的次序排在f4之前。另外尽管函数f3定义在f1之前
	// 由于他们都继承自父类，而在父类中f1是排在f3之前的，所以类Derived中，f1()
	// 仍然排在f3()之前。再者在类Derived中，并没有其父类的虚函数f2()的改写版本
	// 所以函数f2的入口地址任然保留其父类的虚函数Base::f2的入口地址
public:
	virtual void f4() { cout << "Derived's f4()" << endl; }
	void f3() { cout << "Derived's f3()" << endl; }
	void f1() { cout << "Derived's f1()" << endl; }
};

// 尽管类Base是类Derived的父类,但他们却各自使用不同的虚函数表，所有的类都不会和
// 其它的类共享一张虚函数表
int main()
{
	Base b1;
	Derived d1;
	void *p;
	unsigned long *pAddr;

	pAddr = reinterpret_cast<unsigned long*>(&b1);
	// 需要将pAddr的内容作为指针输出,才能表示类的虚函数表在内存中的地址
	// 若直接输出pAddr,则表示的是类Base的对象b1在内存中的地址
	cout << "Address of b1 is 0x" << pAddr << endl;
	cout << "Address of vtable of Base is 0x" << (void*)*pAddr << endl;
	pAddr = reinterpret_cast<unsigned long*>(&d1);
	cout << "Address of d1 is 0x" << pAddr << endl;
	cout << "Address of vtable of Derived is 0x" << (void*)*pAddr << endl;
	cout << endl;

	ShowFuncAddress(Base::f1);
	ShowVTableContent("Base", &b1, 0);
	ShowFuncAddress(Base::f2);
	ShowVTableContent("Base", &b1, 1);
	ShowFuncAddress(Base::f3);
	ShowVTableContent("Base", &b1, 2);
	cout << endl;

	ShowFuncAddress(Derived::f1);
	ShowVTableContent("Derived", &d1, 0);
	ShowFuncAddress(Derived::f2);
	ShowVTableContent("Derived", &d1, 1);
	ShowFuncAddress(Derived::f3);
	ShowVTableContent("Derived", &d1, 2);
	ShowFuncAddress(Derived::f4);
	ShowVTableContent("Derived", &d1, 3);

	system("pause");
	return 0;
}

