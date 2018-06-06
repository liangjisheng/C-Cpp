
// 由于虚调用是通过查询函数表来实现的，而拥有虚函数的对象都可以访问到所属类
// 的虚函数表，所以尽管不常见，但的确可以实现这种形式的虚调用：通过指向派生
// 类对象的指针调用基类对象的虚函数，或通过派生类对象的引用调用基类对象的虚函数

#include <iostream>

using namespace std;

class A
{
public:
	virtual void show() { cout << "in A" << endl; }
};

class B : public A
{
public:
	virtual void show() { cout << "in B" << endl; }
};

int main()
{
	A a;
	B &rb = static_cast<B&>(a);
	rb.show();

	system("pause");
	return 0;
}