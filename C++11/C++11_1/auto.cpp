
#include<iostream>
#include<typeinfo.h>

using std::cout;
using std::endl;

// auto可以在C++14中可以作为函数的返回值
auto AddTest(int a, int b) { return a + b; }

int main()
{
	// 编译器根据上下文，确定auto变量的真正类型
	auto index = 10;
	auto str = "abc";
	auto ret = AddTest(1, 2);
	std::cout << "index:" << index << std::endl;
	std::cout << "str:" << str << std::endl;
	std::cout << "res:" << ret << std::endl;

	cout << "typeid(index) = " << typeid(index).name() << endl;
	cout << "typeid(str) = " << typeid(str).name() << endl;
	cout << "typeid(ret) = " << typeid(ret).name() << endl;

	system("pause");
	return 0;
}