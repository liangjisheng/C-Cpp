
// 可以使用虚拟继承来实现终结类，一个基类如果被虚拟继承，那么在创建它的任何
// 后辈类(派生类的派生类)的对象时，他的构造函数都是被独立调用的，这一点和一般
// 的继承关系不同

#include <iostream>

using namespace std;

// 任何类，只要西游虚拟继承类FinalParent，就不能被继续继承，从而已一种
// 简单的方式实现了终结类

class FinalParent
{
	// 构造函数声明为protected，这样他自身不能生产任何实例，只能用作基类
protected:
	FinalParent(){}
};

// 通过私有虚拟继承产生派生类FinalClass,由于FinalParent::FinalParent的访问
// 权限是protected,所以可以在类FinalClass的构造函数中调用，这样FinalClass
// 可以被实例化，在该类中定义的任何成员的访问不受父类的影响
// 但是由于采用私有继承的方式，所以FinalParent::FinalParent在类FinalClass
// 中的访问权限就变成了private，也就是说，任何FinalClass的派生类都无法调用
// 类FinalParent的构造函数，而正是由于类FinalParent是被类FinalClass虚拟继承
// 的，所以在FinalClass的派生类的构造函数中必须直接调用类FinalParent的构造
// 函数
class FinalClass : private virtual FinalParent
{
	int num;
public:
	FinalClass() { num = 5; }
	void show() { cout << num << endl; }
};

// 在FinalChild类中必须独立调用类FinalParent的构造函数，但在类FinalClass
// 中，类FinalParent的构造函数已经变成私有的，不能被FinalChild的任何成员
// 访问，因此编译错误
class FinalChild : public FinalClass {};

int main()
{
	FinalClass obj;
	obj.show();

	FinalChild b;
	obj.show();

	system("pause");
	return 0;
}