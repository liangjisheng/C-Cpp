
// 需要注意的是，与参数相关的名字空间域，有时会多于一个，这样在进行KL查找时
// 同样可能引起麻烦

#include <iostream>

using namespace std;

namespace NS2 { class Derived; }		// 声明

namespace NS1
{
	class Base{};

	void func(NS2::Derived &obj) { cout << "in namespace1" << endl; }
}

namespace NS2
{
	class Derived : public NS1::Base {};

	void func(Derived& obj) { cout << "in namespace2" << endl; }
}


int main()
{
	NS2::Derived obj;
	// 与实参相关的名字空间域有两个，一个是NS2,一个是NS1，这两个里面都有定义函数func
	// 导致编译器无法形成有效的重载决议
	func(obj);

	system("pause");
	return 0;
}
