// 用于修改类型的const 或者 volatile属性
// 用法 ： const_cast<type_id>(expression)
// 常量指针被转化成非常量的指针，并且仍然指向原来的对象；
// 常量引用被转换成非常量的引用，并且仍然指向原来的对象；
//const_cast一般用于修改底指针。如const char *p形式。

#include <iostream>

class B
{
public:
	B(int num = 0) : mNum(num) {}
	int mNum;
};

void foo()
{
	const B b1;
	std::cout << b1.mNum << std::endl;
	B* b2 = const_cast<B*>(&b1);
	B& b3 = const_cast<B&>(b1);

	b2->mNum = 1;
	std::cout << b1.mNum << std::endl;
	b3.mNum = 2;
	std::cout << b1.mNum << std::endl;
}

int main()
{
	foo();

	system("pause");
	return 0;
}