
// 带有纯虚函数的类称为抽象类。抽象类是一种特殊的类，它是为了抽象和设计的目的而
// 建立的，它处于继承层次结构的较上层。抽象类是不能定义对象的，在实际中为了强调
// 一个类是抽象类，可将该类的构造函数说明为保护的访问控制权限

// 抽象类的主要作用是将有关的组织在一个继承层次结构中，由它来为它们提供一个公共
// 的根，相关的子类是从这个根派生出来的。

// 抽象类刻画了一组子类的操作接口的通用语义，这些语义也传给子类。一般而言，抽象
// 类只描述这组子类共同的操作接口，而完整的实现留给子类

// 抽象类只能作为基类来使用，其纯虚函数的实现由派生类给出。如果派生类没有重新定义
// 纯虚函数，而派生类只是继承基类的纯虚函数，则这个派生类仍然还是一个 抽象类。
// 如果派生类中给出了基类纯虚函数的实现，则该派生类就不再是抽象类了，它是一个可以
// 建立对象的具体类了

// 抽象类的规定
// 1.抽象类只能用作其他类的基类，不能建立抽象类对象
// 2.抽象类不能用作参数类型、函数返回类型或显式转换的类型
// 3.可以定义指向抽象类的指针和引用，此指针可以指向它的派生类，进而实现多态性

#include <iostream>

using std::cout;
using std::endl;

const double PI = 3.14159;

// 抽象类
class Shape
{
protected:
	int x, y;
public:
	void setvalue(int d, int w = 0) { x = d; y = w; }
	virtual void disp() = 0;		// 纯虚函数
};

class Square : public Shape
{
public:
	virtual void disp() { cout << "矩形面积: " << x * y << endl; }
};

class Circle : public Shape
{
public:
	virtual void disp() { cout << "圆面积: " << PI * x * x << endl; }
};


int main()
{
	Shape *ptr[2];	// 对象指针数组
	Square s1;
	Circle c1;

	ptr[0] = &s1;
	ptr[0]->setvalue(10, 5);
	ptr[0]->disp();

	ptr[1] = &c1;
	ptr[1]->setvalue(10);
	ptr[1]->disp();

	system("pause");
	return 0;
}