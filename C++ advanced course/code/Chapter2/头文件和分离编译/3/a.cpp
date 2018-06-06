
#include <iostream>

class Demo
{
	int num;
public:
	void func1();
	void func2();
	void func3() { std::cout << "This is func3" << std::endl; }
};

void Demo::func1() { std::cout << "This is func1" << std::endl; }

