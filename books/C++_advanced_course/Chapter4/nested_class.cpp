
// 出来作用域上的联系之外，其实外围类与嵌套类是两个完全独立的类，并没有其它
// 特殊的关系，也就是说，嵌套类的成员和外围类的成员没有任何关系，他们不能够
// 相互访问，也不存在友元的关系

#include <iostream>

using std::endl;
using std::cout;

class A
{
public:
	class B
	{
	public:
		B(char *name) 
		{ cout << "Constructing B:" << name << endl; }
	};
	B b;
	A() : b("In class A") 
	{ cout << "Constructing A" << endl; }
};


int main()
{
	A a;
	A::B b("Outside class A");

	system("pause");
	return 0;
}