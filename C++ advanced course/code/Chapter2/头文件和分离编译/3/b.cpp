
#include <iostream>

class Demo
{
	int num1;
public: 
	void func1();
	void func2();
	void func3() { std::cout << "This is func3" << std::endl; }
};

//void Demo::func1() { std::cout << "This is func1" << std::endl; }

void Demo::func2() { std::cout << "This is func2" << std::endl; }


int main()
{
	Demo obj;
	obj.func1();
	obj.func2();
	obj.func3();

	std::cout << sizeof(Demo) << std::endl;

	system("pause");
	return 0;
}

