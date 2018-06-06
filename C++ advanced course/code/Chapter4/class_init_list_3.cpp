
// 初始化列表中各部分的执行顺序与他们的书写顺序无关，而是遵循这样的规则：
// 基类的构造函数最先执行，其它的成员按照他们在类中声明的顺序依次被初始化

#include <iostream>

using std::cout;
using std::endl;


class A
{
public:
	int num;
	A(int i) { num = i; cout << "In A constructor" << endl; }
};

class B
{
public:
	int num;
	B(int i) { num = i; cout << "In B constructor" << endl; }
};

class C
{
protected:
	int num;
public:
	C(int i) { num = i; cout << "In C constructor" << endl; }
};

class D : public C
{
	A a;
	int num;
	B b;
public:
	D(int i) : num(i++), b(i++), a(i++), C(i++) {}
	void show()
	{
		cout << "C::num = " << C::num << endl;
		cout << "a.num = " << a.num << endl;
		cout << "num = " << num << endl;
		cout << "b.num = " << b.num << endl;
	}
};


int main()
{
	D d(1);
	d.show();

	system("pause");
	return 0;
}