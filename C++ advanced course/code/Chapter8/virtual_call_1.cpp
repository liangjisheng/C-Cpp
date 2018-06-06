
// 虚调用是想对于实调用而言的，他的本质是动态联编，在发生函数调用的时候，如果
// 函数的入口地址是在编译阶段静态确定的，就是实调用，反之，函数的入口地址要是
// 在运行时通过查询虚函数表的方式获得，就是虚调用
// 虚调用不能简单的理解成对虚函数的调用，因为对虚函数的调用很有可能是实调用

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

// 虽然show()被定义为虚函数，但是由于a是类A的一个实例，而不是指向
// 类A对象的指针或引用，所以函数调用a.show()是实调用，函数的入口地址
// 是在编译阶段静态决定。
void func(A a) { a.show(); }

int main()
{
	B b;
	// b调用类A的复制构造函数产生一个类A的对象a进入func(),
	// 在func()内，a是一个纯粹的类A对象，与类型B毫无关系，所以
	// a.show()是实调用
	func(b);

	system("pause");
	return 0;
}