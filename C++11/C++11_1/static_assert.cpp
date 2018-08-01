
#include <type_traits>
#include <iostream>

using namespace std;

class Base1 {};

class Base1Child : public Base1 {};

class Base2 {};

class Base2Child : public Base2 {};


// process()的模板类型要求将Base1作为基类，否则在编译是会输出错误消息
template<typename T>
void process(const T& t)
{
	static_assert(is_base_of<Base1, T>::value, "Base1 should be a base for T.");
}

int main()
{
	process(Base1());
	process(Base1Child());

	// process(Base2());		// Error
	// process(Base2Child());	// Error

	system("pause");
	return 0;
}